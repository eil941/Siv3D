# include <Siv3D.hpp>

// ボタンを描画する関数
bool Button(const Rect& rect, const Texture& texture, const Font& font, const String& name, const String& desc, int32 count, bool enabled)
{
	// マウスカーソルがボタンの上にある場合
	if (enabled && rect.mouseOver())
	{
		// マウスカーソルを手の形にする
		Cursor::RequestStyle(CursorStyle::Hand);
	}

	// テキストの色
	const ColorF textColor{ 0.4, 0.3, 0.2 };

	// ボタンの背景の角丸四角形
	const RoundRect roundRect = rect.rounded(6);

	// 影と背景を描く
	roundRect
		.drawShadow(Vec2{ 2, 2 }, 12, 0)
		.draw(ColorF{ 0.9, 0.8, 0.6 });

	// 枠を描く
	rect.stretched(-3).rounded(3)
		.drawFrame(2, ColorF{ 0.4, 0.3, 0.2 });

	// 絵文字を描く
	texture.scaled(0.5).drawAt(rect.leftCenter().movedBy(50, 0));

	// 設備の名前を描く
	font(name).draw(30, rect.pos.movedBy(100, 15), textColor);

	// 設備の説明を描く
	font(desc).draw(18, rect.pos.movedBy(102, 60), textColor);

	// 所有数を描く
	font(count).draw(50, Arg::rightCenter = rect.tr().movedBy(-20, 50), textColor);

	// 無効の場合は
	if (not enabled)
	{
		// グレーの半透明を重ねる
		roundRect.draw(ColorF{ 0.8, 0.6 });
	}

	// ボタンが押されたら true を返す
	return (enabled && rect.leftClicked());
}

// ゲームの進行状況
struct GameInfo
{
	// クッキーの数
	double cookies = 0.0;

	// 農場の数
	int32 farmCount = 0;

	// 工場の数
	int32 factoryCount = 0;

	// 毎秒のクッキー生産量 (cookies per second)
	int32 getCPS() const
	{
		return (farmCount + factoryCount * 10);
	}

	// 農場の価格
	int32 getFarmCost() const
	{
		return (10 + farmCount * 10);
	}

	// 工場の価格
	int32 getFactoryCost() const
	{
		return (100 + factoryCount * 100);
	}
};

// 背景を描く関数
void DrawBackground()
{
	Rect{ 800, 600 }.draw(Arg::top(0.6, 0.5, 0.3), Arg::bottom(0.2, 0.5, 0.3));
}

// クッキーの枚数と CPS を表示する関数
void DrawCookieCount(const GameInfo& game, const Font& font)
{
	// クッキーの数を整数で表示する
	font(U"{:.0f}"_fmt(game.cookies)).drawAt(60, Vec2{ 170, 100 });

	// クッキーの生産量を表示する
	font(U"{} CPS"_fmt(game.getCPS())).drawAt(24, Vec2{ 170, 160 });
}

void Main()
{
	const Texture cookieEmoji{ U"🍪"_emoji };
	const Texture farmEmoji{ U"🌾"_emoji };
	const Texture factoryEmoji{ U"🏭"_emoji };

	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };

	// クッキーのクリック円
	const Circle cookieCircle{ 170, 300, 90 };

	// ゲームの進行状況
	GameInfo game;

	// クッキーの表示サイズ（倍率）
	double cookieScale = 1.5;

	// ゲームの経過時間の蓄積（秒）
	double accumulatedTime = 0.0;

	while (System::Update())
	{
		/////////////////////////////////
		//
		//	更新
		//
		/////////////////////////////////

		const double deltaTime = Scene::DeltaTime();

		// ゲームの経過時間を加算する
		accumulatedTime += deltaTime;

		// 0.1 秒以上蓄積していたら
		if (0.1 <= accumulatedTime)
		{
			// 0.1 秒分のクッキー生産を加算する
			game.cookies += (game.getCPS() * 0.1);

			accumulatedTime -= 0.1;
		}

		// クッキー円上にマウスカーソルがあれば
		if (cookieCircle.mouseOver())
		{
			Cursor::RequestStyle(CursorStyle::Hand);
		}

		// クッキー円が左クリックされたら
		if (cookieCircle.leftClicked())
		{
			cookieScale = 1.3;

			game.cookies += 1;
		}

		// クッキーの表示サイズを回復する
		cookieScale = Min((cookieScale + deltaTime), 1.5);

		/////////////////////////////////
		//
		//	描画
		//
		/////////////////////////////////

		// 背景を描く
		DrawBackground();

		// クッキーの数と CPS を表示する
		DrawCookieCount(game, font);

		// クッキーを描画する
		cookieEmoji.scaled(cookieScale).drawAt(cookieCircle.center);

		// 農場ボタン
		if (Button(Rect{ 340, 40, 420, 100 }, farmEmoji, font, U"クッキー農場", U"C{} / 1 CPS"_fmt(game.getFarmCost()), game.farmCount, (game.getFarmCost() <= game.cookies)))
		{
			game.cookies -= game.getFarmCost();
			++game.farmCount;
		}

		// 工場ボタン
		if (Button(Rect{ 340, 160, 420, 100 }, factoryEmoji, font, U"クッキー工場", U"C{} / 10 CPS"_fmt(game.getFactoryCost()), game.factoryCount, (game.getFactoryCost() <= game.cookies)))
		{
			game.cookies -= game.getFactoryCost();
			++game.factoryCount;
		}
	}
}

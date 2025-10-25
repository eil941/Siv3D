# include <Siv3D.hpp>

bool Button(const Rect& rect, const Texture& emoji, const Font& font, const String& text, bool enabled)
{
	// マウスカーソルがボタンの上にある場合
	if (enabled && rect.mouseOver())
	{
		// マウスカーソルを手の形にする
		Cursor::RequestStyle(CursorStyle::Hand);
	}

	const RoundRect roundRect = rect.rounded(6);

	// 影と背景を描く
	roundRect
		.drawShadow(Vec2{ 2, 2 }, 12, 0)
		.draw(ColorF{ 0.9, 0.8, 0.6 });

	// 枠を描く
	rect.stretched(-3).rounded(3)
		.drawFrame(2, ColorF{ 0.4, 0.3, 0.2 });

	// 絵文字を描く
	emoji.scaled(0.4).drawAt((rect.x + 60), rect.center().y);

	// テキストを描く
	font(text).drawAt(40, rect.center().movedBy(30, 0), ColorF{ 0.4, 0.3, 0.2 });

	// 無効の場合は
	if (not enabled)
	{
		// グレーの半透明を重ねる
		roundRect.draw(ColorF{ 0.8, 0.8 });
	}

	// ボタンが押されたら true を返す
	return (enabled && rect.leftClicked());
}

void Main()
{
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Texture breadEmoji{ U"🍞"_emoji };
	const Texture riceEmoji{ U"🍚"_emoji };

	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };

	while (System::Update())
	{
		if (Button(Rect{ 80, 300, 300, 80 }, breadEmoji, font, U"Bread", true))
		{
			Print << U"Bread";
		}

		if (Button(Rect{ 420, 300, 300, 80 }, riceEmoji, font, U"Rice", true))
		{
			Print << U"Rice";
		}
	}
}

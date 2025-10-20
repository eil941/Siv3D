# include <Siv3D.hpp> // Siv3D v0.6.16

void PrintRandomNumber()
{
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };

	// ダイスの正方形領域
	const Rect diceRect{ Arg::center(400, 300), 200 };

	// ダイスの目
	int32 result = 1;

	// 回転中かどうか
	bool isRolling = true;

	while (System::Update())
	{
		// 回転中であれば
		if (isRolling)
		{
			// ダイスの目をランダムな値に変更する
			result = Random(1, 6);
		}

		// マウスカーソルがダイスの上にある場合
		if (diceRect.mouseOver())
		{
			// マウスカーソルを手の形に変更する
			Cursor::RequestStyle(CursorStyle::Hand);
		}

		// ダイスが左クリックされたら
		if (diceRect.leftClicked())
		{
			// 回転中の状態を反転させる
			isRolling = (not isRolling);
		}

		// ダイスの正方形を描画する
		diceRect.draw();

		// ダイスの数字を描画する
		font(U"{}"_fmt(result)).drawAt(120, Vec2{ 400, 300 }, ColorF{ 0.1 });
	}
}
void practiceRandom()
{
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Texture emoji0{ U"😄"_emoji };
	const Texture emoji1{ U"😵‍💫"_emoji };
	const Texture emoji2{ U"😭"_emoji };
	const Texture emoji3{ U"😋"_emoji };

	// 絵文字の番号
	int32 emojiIndex = 0;

	const Texture emoji4{ U"🛸"_emoji };

	Vec2 pos{ 400, 300 };

	while (System::Update())
	{
		// 1 以上 6 以下の乱数を出力する
		if (KeySpace.down()) {
			Print << Random(1.0, 6.0);
		}


		if (MouseL.down())
		{
			// 新しい絵文字の番号をランダムに選ぶ
			emojiIndex = Random(0, 3);

			// 絵文字の番号を出力する
			Print << emojiIndex;
		}

		if (emojiIndex == 0)
		{
			emoji0.drawAt(400, 300);
		}
		else if (emojiIndex == 1)
		{
			emoji1.drawAt(400, 300);
		}
		else if (emojiIndex == 2)
		{
			emoji2.drawAt(400, 300);
		}
		else
		{
			emoji3.drawAt(400, 300);
		}

		/*******************************/
		if (MouseR.down())
		{
			pos = Vec2{ Random(100, 700), Random(100, 500) };
		}

		emoji4.drawAt(pos);
	}
}

void Main()
{
	//practiceRandom();

	PrintRandomNumber();
}

//
// - Debug ビルド: プログラムの最適化を減らす代わりに、エラーやクラッシュ時に詳細な情報を得られます。
//
// - Release ビルド: 最大限の最適化でビルドします。
//
// - [デバッグ] メニュー → [デバッグの開始] でプログラムを実行すると、[出力] ウィンドウに詳細なログが表示され、エラーの原因を探せます。
//
// - Visual Studio を更新した直後は、プログラムのリビルド（[ビルド]メニュー → [ソリューションのリビルド]）が必要な場合があります。
//

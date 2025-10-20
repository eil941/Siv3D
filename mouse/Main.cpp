# include <Siv3D.hpp> // Siv3D v0.6.16

void Main()
{
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });
	const Texture texture{ U"🐥"_emoji };
	Vec2 pos{ 400, 300 };

	const Circle circle{ 500, 150, 100 };

	const Rect rect{ 400, 300, 200, 100 };


	const Texture emoji{ U"🍎"_emoji };

	const Circle circle2{ 200, 150, 60 };
	while (System::Update())
	{

		//クリック判定と描画は無関係


		// 左クリックしたら
		if (MouseL.down())
		{
			// 絵文字の表示位置をマウスカーソルの位置に変更する
			pos = Cursor::Pos();
			Print << U"Left Click";
		}

		// 右クリックしたら
		if (MouseR.down())
		{
			// 絵文字の表示位置を画面中央にリセットする
			pos = Vec2{ 400, 300 };
			Print << U"Right Click";
		}
		// 円を左クリックしたら
		if (circle.leftClicked())
		{
			Print << U"Circle";
		}

		// 長方形を左クリックしたら
		if (rect.leftClicked())
		{
			Print << U"Rect";
		}


		//マウスカーソルを手の形にする
		if (circle.mouseOver())
		{
			Cursor::RequestStyle(CursorStyle::Hand);
		}

		if(rect.mouseOver())
		{
			Cursor::RequestStyle(CursorStyle::Hand);
		}



		//絵文字の判定
		// 円の上にマウスカーソルがあれば
		if (circle2.mouseOver())
		{
			// マウスカーソルを手のアイコンにする
			Cursor::RequestStyle(CursorStyle::Hand);
		}

		// 円を左クリックしたら
		if (circle2.leftClicked())
		{
			Print << U"Apple";
		}

		emoji.drawAt(circle2.center);

		// 円は描かない
		//circle2.draw();



		texture.drawAt(pos);
		//図形の上にマウスカーソルがあるかどうかの判定
		circle.draw(circle.mouseOver() ? Palette::Seagreen : Palette::White);
		rect.draw(rect.mouseOver() ? ColorF{ 0.8 } : ColorF{ 0.6 });






		// 左ボタンが押されていたら
		/*if (MouseL.pressed())
		{
			Print << U"Left Pressed";
		}
		*/

		// 右ボタンが押されていたら
		/* if (MouseR.pressed())
		{
			Print << U"Right Pressed";
		}
		*/

	}
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

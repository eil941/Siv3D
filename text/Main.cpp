# include <Siv3D.hpp> // Siv3D v0.6.16

void Main()
{
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });
	const Font font{ FontMethod::MSDF, 48 };
	//フォーマット文字列を使う方法
	int32 score = 12345;
	Print << U"スコア: {} 点"_fmt(score);

	int32 year = 2025;
	int32 month = 12;
	int32 day = 31;
	Print << U"{} 年 {} 月 {} 日"_fmt(year, month, day);

	//フォーマット文字列を使わない方法
	Print << U"スコア: " << score << U" 点";
	Print << year << U" 年 " << month << U" 月 " << day << U" 日";

	while (System::Update())
	{
		font(U"Hello, Siv3D!").draw(10, Vec2{ 80, 100 }, ColorF{ 0.2 });


		// 同梱フォントファイルから太字のフォントを作成する
		static const Font font{ FontMethod::MSDF, 48, Typeface::Bold };

		font(U"C++\nProgramming").draw(10, Vec2{ 80, 300 });


		//位置を指定してテキストを描く
		font(U"ココが中心").drawAt(60, Vec2{ 400, 300 }, ColorF{ 4.7 });
		font(U"Siv3D").drawAt(80, Cursor::Pos());


		font(U"TopLeft").draw(40, Arg::topLeft(20, 20), ColorF{ 0.1 });
		font(U"TopRight").draw(40, Arg::topRight(780, 20), ColorF{ 0.1 });

		font(U"BottomLeft").draw(40, Arg::bottomLeft(20, 580), ColorF{ 0.1 });
		font(U"BottomRight").draw(40, Arg::bottomRight(780, 580), ColorF{ 0.1 });

		Rect{ 200, 100, 400, 200 }.draw(ColorF{ 0.8, 0.9, 1.0 });
		font(U"LeftCenter").draw(20, Arg::leftCenter(200, 200), ColorF{ 0.1 });
		font(U"RightCenter").draw(20, Arg::rightCenter(600, 200), ColorF{ 0.1 });

		// マウスカーソル位置を下辺中央とするようにテキストを描画する
		font(U"BottomCenter").draw(40, Arg::bottomCenter = Cursor::Pos(), ColorF{ 0.1 });
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

# include <Siv3D.hpp>

void Main()
{
	while (System::Update())
	{


		/*
		.drawFrame(太さ, color)
		.drawFrame(内側方向の太さ, 外側方向の太さ, color)
		*/
		Circle{ 100, 300, 30 }.draw(); // 色を指定しない場合は白色

		Circle{ 200, 300, 30 }.drawFrame(8,Palette::Green);

		Circle{ 300, 300, 30 }.drawFrame(4,4,ColorF{ 1.0, 0.8, 0.0 });

		Circle{ 400, 300, 40 }.draw(ColorF{ 0.8 });

		Circle{ 500, 300, 40 }.draw(HSV{ 160.0, 0.5, 1.0 });

		Circle{ 600, 300, 40 }.draw(HSV{ 160.0 });

		// マウスカーソルに追随する半透明の円を描く
		Circle{ Cursor::Pos(), 100 }.draw(ColorF{ 0.0, 0.6, 0.2, 0.5 });

		Rect{ 20, 40, 400, 100 }.draw(Arg::top = ColorF{ 0.5, 0.7, 0.9 }, Arg::bottom = ColorF{ 0.5, 0.9, 0.7 });;

		Rect{ 100, 200, 80 }.draw(Palette::Orange);

		Rect{ 400, 300, 360, 260 }.draw(ColorF{ 0.8, 0.9, 1.0 });

		//座標や大きさを double 型で扱いたい場合
		const double w = (Scene::Time() * 20.0);

		RectF{ 0, 250, w, 100 }.draw(Arg::left(1.0), Arg::right(0.0));;


	}
}

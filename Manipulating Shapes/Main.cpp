# include <Siv3D.hpp> // Siv3D v0.6.16

//図形の移動
void move_shape() {

	/*
	.movedBy(X軸方向の移動量, Y軸方向の移動量)	指定したベクトルで平行移動した図形を作成して返します
	.movedBy(移動量)							指定したベクトルで平行移動した図形を作成して返します

	.moveBy(X軸方向の移動量, Y軸方向の移動量)	指定したベクトルで平行移動します
	.moveBy(移動量)								指定したベクトルで平行移動します

	*/
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Rect rect{ 100, 100, 300 };

	Circle circle{ 600, 100, 100 };

	Circle circle1{ 650, 150, 50 };

	while (System::Update())
	{
		circle.moveBy(0, (Scene::DeltaTime() * 100.0));

		rect.draw();

		rect.movedBy(40, 40).draw(Palette::Seagreen);


		circle1.y += (Scene::DeltaTime() * 100.0);
		circle.draw(ColorF{ 0.2 });
		circle1.draw(Palette::Orange);
	}
}
//図形の拡大縮小（ピクセル指定）
void resize_shape_pixel(){
	/*
	rect.stretched(上下左右)			長方形（Rect または RectF）の上下左右方向の拡大縮小量（ピクセル）を指定して新しい長方形を作成して返します
	rect.stretched(左右, 上下)			長方形（Rect または RectF）の左右方向と上下方向の拡大縮小量（ピクセル）を指定して新しい長方形を作成して返します
	rect.stretched(上, 右, 下, 左)		長方形（Rect または RectF）の上右下左方向の拡大縮小量（ピクセル）を指定して新しい長方形を作成して返します
	line.stretched(両端)				線分（Line）の始点と終点の拡大縮小量（ピクセル）を指定して新しい線分を作成して返します
	line.stretched(始点, 終点)			線分（Line）の始点と終点の拡大縮小量（ピクセル）を指定して新しい線分を作成して返します
	*/

	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Rect rect{ 100, 100, 300 };

	const Line line{ 500, 100, 600, 500 };

	while (System::Update())
	{
		rect.draw();

		rect.stretched(-20).draw(ColorF{ 0.2 });

		line.stretched(40).draw(12);

		line.draw(4, ColorF{ 0.2 });
	}
}
//図形の拡大縮小（倍率指定）
void resize_shape_scale(){
	/*
	.scaled(倍率)											図形を指定した倍率で拡大縮小した新しい図形を作成して返します
	.scaled(幅の倍率, 高さの倍率)							図形を指定した幅と高さの倍率で拡大縮小した新しい図形を作成して返します
	.scaledAt(拡大縮小の基準点, 倍率)						図形を指定した倍率で拡大縮小した新しい図形を作成して返します
	.scaledAt(拡大縮小の基準点, 幅の倍率, 高さの倍率)		図形を指定した幅と高さの倍率で拡大縮小した新しい図形を作成して返します
	*/
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Rect rect{ 100, 100, 300 };

	const Circle circle{ 600, 300, 100 };

	while (System::Update())
	{
		rect.draw();

		rect.scaled(0.5).draw(Palette::Seagreen);

		rect.scaledAt(rect.pos, 0.5).draw(ColorF{ 0.2 });

		circle.draw();

		circle.scaled(0.8).draw(ColorF{ 0.2 });
	}
}
//図形の回転
void rotate_shape(){
	/*
	.rotated(回転角度)						図形を指定した角度で回転した新しい図形を作成して返します
	.rotatedAt(回転の基準点, 回転角度)		図形を指定した角度で回転した新しい図形を作成して返します

	.rotate(回転角度)						図形を指定した角度で回転します
	.rotateAt(回転の基準点, 回転角度)		図形を指定した角度で回転します

	*/
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Triangle triangle{ Vec2{ 200, 300 }, 200 };

	const Polygon polygon = Shape2D::Star(200, Vec2{ 600, 300 });

	double angle = 0_deg;

	while (System::Update())
	{
		angle += (Scene::DeltaTime() * 30_deg);

		triangle.rotated(angle).draw(ColorF{ 0.2 });

		polygon.rotatedAt(Vec2{ 600, 300 }, angle).draw(ColorF{ 0.2 });
	}
}
//多角形を太らせる
void fatten_shape(){
	/*
	.calculateBuffer(太さ)			多角形を指定した太さで太らせた新しい多角形を作成して返します
	.calculateRoundBuffer(太さ)		多角形を指定した太さで太らせた新しい多角形を作成して返します（角を丸めます）
	*/
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Polygon polygon1 = Shape2D::Star(150, Vec2{ 200, 300 });
	const Polygon polygon2 = polygon1.calculateBuffer(20);

	const Polygon polygon3 = Shape2D::Star(150, Vec2{ 600, 300 });
	const Polygon polygon4 = polygon3.calculateRoundBuffer(20);

	while (System::Update())
	{
		polygon2.draw(ColorF{ 0.2 });
		polygon1.drawFrame(4);

		polygon4.draw(ColorF{ 0.2 });
		polygon3.drawFrame(4);
	}
}
//長方形の構成要素の取得
void rectangle_elements() {
	/*
	.center()										長方形の中心座標を返します
	.tl()											長方形の左上の座標を返します
	.tr()											長方形の右上の座標を返します
	.br()											長方形の左下の座標を返します
	.bl()											長方形の右下の座標を返します
	.topCenter()									長方形の上辺の中心座標を返します
	.rightCenter()									長方形の右辺の中心座標を返します
	.bottomCenter()									長方形の下辺の中心座標を返します
	.leftCenter()									長方形の左辺の中心座標を返します
	.leftX()										長方形の左辺の X 座標を返します
	.rightX()										長方形の右辺の X 座標を返します
	.topY()											長方形の上辺の Y 座標を返します
	.bottomY()										長方形の下辺の Y 座標を返します
	.getRelativePoint(相対座標 X, 相対座標 Y)		長方形の相対座標を絶対座標に変換して返します。左上を (0,0), 右下を (1,1) とします
	.area()											長方形の面積を返します
	*/
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };

	const Rect rect{ 100, 100, 600, 400 };

	while (System::Update())
	{
		rect.draw();

		rect.top().draw(4, HSV{ 0 });
		rect.right().draw(4, HSV{ 90 });
		rect.bottom().draw(4, HSV{ 180 });
		rect.left().draw(4, HSV{ 270 });

		font(U"TL").drawAt(40, rect.tl(), ColorF{ 0.2 });
		font(U"TC").drawAt(40, rect.topCenter(), ColorF{ 0.2 });
		font(U"TR").drawAt(40, rect.tr(), ColorF{ 0.2 });

		font(U"LC").drawAt(40, rect.leftCenter(), ColorF{ 0.2 });
		font(U"C").drawAt(40, rect.center(), ColorF{ 0.2 });
		font(U"RC").drawAt(40, rect.rightCenter(), ColorF{ 0.2 });

		font(U"BL").drawAt(40, rect.bl(), ColorF{ 0.2 });
		font(U"BC").drawAt(40, rect.bottomCenter(), ColorF{ 0.2 });
		font(U"BR").drawAt(40, rect.br(), ColorF{ 0.2 });

		font(U"(0.8, 0.2)").drawAt(40, rect.getRelativePoint(0.8, 0.2), ColorF{ 0.2 });
	}
}
//円座標
void circle_coordinates() {
	/*
	Circular{ r, theta }					原点を中心として半径 r, 角度 theta の位置を表します
	OffsetCircular{ offset, r, theta }		offset を中心として半径 r, 角度 theta の位置を表します
	*/

	Scene::SetBackground(ColorF{ 1.0, 0.98, 0.96 });

	double angle = 0_deg;

	while (System::Update())
	{
		angle += (Scene::DeltaTime() * 30_deg);

		for (int32 i = 0; i < 12; ++i)
		{
			const double theta = (i * 30_deg + angle);

			const Vec2 pos = OffsetCircular{ Vec2{ 400, 300 }, 200, theta };

			pos.asCircle(28)
				.drawShadow(Vec2{ 0, 4 }, 12, 4)
				.draw(HSV{ (i * 30), 0.8, 1.0 })
				.drawFrame(3, 2, ColorF{ 1.0 });
		}
	}
}

void Main()
{
	while(System::Update())
	{
		///* 図形の移動 */move_shape();
		///* 図形の拡大縮小（ピクセル指定）*/resize_shape_pixel();
		///* 図形の拡大縮小（倍率指定）*/resize_shape_scale();
		///* 図形の回転 */rotate_shape();
		///* 多角形を太らせる */fatten_shape();
		///* 長方形の構成要素の取得 */rectangle_elements();
		/* 円座標 */circle_coordinates();
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

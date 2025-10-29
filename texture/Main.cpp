/*
* テクスチャを描く
* https://siv3d.github.io/ja-jp/tutorial2/texture/
*/
# include <Siv3D.hpp> // Siv3D v0.6.16



String windmillImagePath = U"windmill.pngのパスを記述";
String siv3dKunImagePath = U"siv3d-kun.pngのパスを記述";
String bayImagePath = U"bay.jpgのパスを記述";
String siv3d_kun_16ImagePath = U"siv3d-kun-16.pngのパスを記述";

//絵文字から作成
void emoji() {
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Texture emoji1{ U"🐈"_emoji };
	const Texture emoji2{ U"🍎"_emoji };

	while (System::Update())
	{
		emoji1.drawAt(100, 100);
		emoji1.drawAt(400, 300);

		emoji2.drawAt(200, 300);
		emoji2.drawAt(Cursor::Pos());
	}
}
//アイコンから作成
void icon() {
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Texture icon1{ 0xF0493_icon, 100 };
	const Texture icon2{ 0xF0787_icon, 100 };
	const Texture icon3{ 0xF018C_icon, 100 };

	while (System::Update())
	{
		icon1.drawAt(200, 200);
		icon2.drawAt(400, 200, Palette::Seagreen);
		icon3.drawAt(600, 200, ColorF{ 0.2 });
		icon1.drawAt(Cursor::Pos());
	}
}
//画像ファイルから作成
void imagefile() {
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	// 風車の画像
	const Texture texture1{ windmillImagePath };

	// Siv3D くん（Siv3D の公式マスコットキャラクター）の画像
	const Texture texture2{siv3dKunImagePath};

	while (System::Update())
	{
		texture1.draw(40, 20);

		texture2.draw(400, 100);
	}
}
//画像データから作成
Image MakeImage()
{
	Image image{ 256, 256 };

	for (int32 y = 0; y < image.height(); ++y)
	{
		for (int32 x = 0; x < image.width(); ++x)
		{
			image[y][x] = ColorF{ (x / 255.0), (y / 255.0), 0.0 };
		}
	}

	return image;
}
void imagedata() {
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Texture texture{ MakeImage() };

	while (System::Update())
	{
		texture.draw();
	}
}
//テクスチャのサイズ
void textureSize() {
	const Texture texture{ windmillImagePath };
	const Texture emoji{ U"🐈"_emoji };

	Print << texture.width();
	Print << texture.height();
	Print << emoji.size();

	while (System::Update())
	{

	}
}
//空のテクスチャ
void emptyTexture() {
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	Texture texture1;

	Print << texture1.isEmpty();

	// テクスチャを代入する
	texture1 = Texture{ U"🐈"_emoji };

	Print << texture1.isEmpty();

	// 存在しない画像ファイルを指定する
	const Texture texture2{ U"example/aaa.png" };

	if (not texture2)
	{
		Print << U"Failed to load a texture";
	}

	while (System::Update())
	{
		// 空のテクスチャを描画する（16x16 の黄色い画像）
		texture2.drawAt(400, 300);
	}
}
//ミップマップの生成
void mipmap()
{
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });
	const Font font{ FontMethod::MSDF, 48 };

	const Texture texture1{ windmillImagePath };
	const Texture texture2{ windmillImagePath, TextureDesc::Mipped };

	while (System::Update())
	{
		const double scale = Periodic::Sine0_1(12s);

		font(U"No mipmaps").draw(30, Vec2{ 20, 20 }, ColorF{ 0.2 });
		font(U"Mipmaps").draw(30, Vec2{ 20, 300 }, ColorF{ 0.2 });

		texture1.scaled(scale).draw(240, 20);
		texture2.scaled(scale).draw(240, 300);
	}
}
//左上座標を指定した描画
void drawAtTopLeft()
{
	/*
	.draw(色 = Palette::White)										テクスチャを座標 (0, 0) から描画する
	.draw(x, y, 色 = Palette::White)								テクスチャを座標 (x, y) から描画する
	.draw(pos, 色 = Palette::White)									テクスチャを座標 pos から描画する
	.draw(x, y, Arg::top = 上側の色, Arg::bottom = 下側の色)		上下の色を指定して描画する
	.draw(x, y, Arg::left = 左側の色, Arg::right = 右側の色)		左右の色を指定して描画する
	.draw(pos, Arg::top = 上側の色, Arg::bottom = 下側の色)			上下の色を指定して描画する
	.draw(pos, Arg::left = 左側の色, Arg::right = 右側の色)			左右の色を指定して描画する
	*/

	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Texture texture1{ U"🐈"_emoji };
	const Texture texture2{ windmillImagePath };

	while (System::Update())
	{
		texture1.draw();

		texture2.draw(400, 300);
	}
}
//中心座標を指定した描画
void drawAtCenter()
{
	/*
	* .drawAt(x, y, 色 = Palette::White)							テクスチャを座標 (x, y) を中心に描画する
	.drawAt(pos, 色 = Palette::White)								テクスチャを座標 pos を中心に描画する
	.drawAt(x, y, Arg::top = 上側の色, Arg::bottom = 下側の色)		上下の色を指定して描画する
	.drawAt(x, y, Arg::left = 左側の色, Arg::right = 右側の色)		左右の色を指定して描画する
	.drawAt(pos, Arg::top = 上側の色, Arg::bottom = 下側の色)		上下の色を指定して描画する
	.drawAt(pos, Arg::left = 左側の色, Arg::right = 右側の色)		左右の色を指定して描画する
	*/

	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Texture texture1{ U"🐈"_emoji };
	const Texture texture2{ windmillImagePath };

	while (System::Update())
	{
		texture1.drawAt(0, 0);

		texture2.drawAt(400, 300);
	}
}
//それ以外の座標を指定した描画
void drawAtOther()
{
	/*
	Arg::topLeft		テクスチャの左上。.draw() と同じ
	Arg::topCenter		上辺の中央
	Arg::topRight		右上
	Arg::leftCenter		左辺の中央
	Arg::center			中心。.drawAt() と同じ
	Arg::rightCenter	右辺の中央
	Arg::bottomLeft		左下
	Arg::bottomCenter	下辺の中央
	Arg::bottomRight	右下
	*/

	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Texture texture1{ U"🐈"_emoji };
	const Texture texture2{ windmillImagePath };

	while (System::Update())
	{
		texture1.draw(Arg::topRight = Vec2{ 800, 0 });

		texture2.draw(Arg::bottomLeft(20, 580));

		texture1.draw(Arg::topLeft = Vec2{ 800, 0 });
		texture1.draw(Arg::topCenter = Vec2{ 800, 0 });
		texture1.draw(Arg::topRight = Vec2{ 800, 0 });
		texture1.draw(Arg::leftCenter = Vec2{ 800, 0 });
		texture1.draw(Arg::center = Vec2{ 800, 0 });
		texture1.draw(Arg::rightCenter = Vec2{ 800, 0 });
		texture1.draw(Arg::bottomLeft = Vec2{ 800, 0 });
		texture1.draw(Arg::bottomCenter = Vec2{ 800, 0 });
		texture1.draw(Arg::bottomRight = Vec2{ 800, 0 });

	}
}
//色を乗算した描画(RGB 各成分を乗算)
void drawWithColorMul_RGB()
{
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Texture texture{ windmillImagePath };
	const Texture icon{ 0xF0493_icon, 80 };

	while (System::Update())
	{
		texture.draw(40, 40, ColorF{ 0.4 });

		texture.draw(40, 300, ColorF{ 1,0,0 });


		icon.draw(600, 40, ColorF{ 0.5, 0.0, 0.0 });

		icon.draw(600, 140, ColorF{ 0.0, 0.5, 0.0 });
	}
}
//色を乗算した描画(アルファ値の使用)
void drawWithColorMul_Alpha()
{
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Texture texture{ windmillImagePath };
	const Texture icon{ 0xF0493_icon, 80 };

	while (System::Update())
	{
		texture.draw(40, 40, ColorF{ 1.0, 0.5 });

		icon.draw(500, 40, ColorF{ 0.5, 0.0, 0.0, 0.3 });

		icon.draw(500, 140, ColorF{ 0.0, 0.5, 0.0, 0.3 });
	}
}
//拡大縮小した描画
void drawScaled()
{
	/*
	.scaled(s)					テクスチャを縦横 s 倍の大きさに拡大縮小した TextureRegion を作成する
	.scaled(sx, sy)				テクスチャを縦横 sx, sy 倍の大きさに拡大縮小した TextureRegion を作成する
	.resized(size)				テクスチャの長辺を size（ピクセル）の大きさに拡大縮小した TextureRegion を作成する
	.resized(width, height)		テクスチャを幅 width（ピクセル）, 高さ height（ピクセル）の大きさに拡大縮小した TextureRegion を作成する
	*/

	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Texture texture{ windmillImagePath, TextureDesc::Mipped };
	const Texture emoji{ U"🍎"_emoji };

	while (System::Update())
	{
		texture.scaled(0.25).draw(40, 40);
		texture.scaled(0.8, 0.5).draw(40, 140);
		texture.scaled(2).draw(40, 340);

		emoji.resized(40).draw(500, 40);
		emoji.resized(120, 40).draw(600, 40);
		emoji.resized(40, 120).draw(500, 140);
	}
}
//長方形内に収めた描画
void drawFitted()
{
	/*
	.fitted(size)				テクスチャのアスペクト比を保ったまま、幅 size.x, 高さ size.y 以内に収まり、最大限大きくなるよう拡大縮小した TextureRegion を返す
	.fitted(width, height)		テクスチャのアスペクト比を保ったまま、幅 width , 高さ height 以内に収まり、最大限大きくなるよう拡大縮小した TextureRegion を返す
	*/

	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Texture texture1{ windmillImagePath , TextureDesc::Mipped };
	const Texture texture2{ siv3dKunImagePath, TextureDesc::Mipped };

	const Rect rect1{ 50, 100, 320, 200 };
	const Rect rect2{ 400, 200, 300 };

	while (System::Update())
	{
		rect1.drawFrame(0, 4, Palette::Seagreen);
		texture1.fitted(rect1.size).drawAt(rect1.center());

		rect2.drawFrame(0, 4, Palette::Seagreen);
		texture2.fitted(rect2.size).drawAt(rect2.center());
	}
}
//回転した描画
void drawRotated()
{
	/*
	.rotated(angle)				テクスチャを angle（ラジアン）だけ回転させた TexturedQuad を作成する
	.rotatedAt(x, y, angle)		テクスチャを座標 (x, y) を軸に angle（ラジアン）だけ回転させた TexturedQuad を作成する
	.rotatedAt(pos, angle)		テクスチャ上の pos を軸に angle（ラジアン）だけ回転させた TexturedQuad を作成する
	*/

	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Texture texture{ windmillImagePath };
	const Texture emoji{ U"🍎"_emoji };

	while (System::Update())
	{
		const double angle = (Scene::Time() * 30_deg);

		texture.rotated(angle).drawAt(200, 300);

		emoji.rotatedAt(Vec2{ 58, 13 }, angle).drawAt(600, 300);
	}
}
//上下・左右反転した描画
void drawFlipped()
{
	/*
	.flipped()				テクスチャを上下反転した TextureRegion を作成する
	.flipped(onOff)			テクスチャを上下反転した TextureRegion を作成する。onOff が true のとき反転する
	.mirrored()				テクスチャを左右反転した TextureRegion を作成する
	.mirrored(onOff)		テクスチャを左右反転した TextureRegion を作成する。onOff が true のとき反転する
	*/

	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Texture emoji{ U"🐈"_emoji };

	while (System::Update())
	{
		emoji.drawAt(100, 100);
		emoji.mirrored().drawAt(300, 100);
		emoji.mirrored(false).drawAt(500, 100);
		emoji.mirrored(true).drawAt(700, 100);

		emoji.drawAt(100, 300);
		emoji.flipped().drawAt(300, 300);
		emoji.flipped(false).drawAt(500, 300);
		emoji.flipped(true).drawAt(700, 300);
	}
}
//部分描画
void drawPartial()
{
	/*
	(x, y, w, h)		テクスチャの (x, y) から幅 w, 高さ h を切り出した TextureRegion を作成する
	(rect)				テクスチャの rect の領域を切り出した TextureRegion を作成する
	.uv(u, v, w, h)		テクスチャの UV 座標 (u, v) から幅 w, 高さ h を切り出した TextureRegion を作成する
	.uv(rect)			テクスチャの UV 座標 rect の領域を切り出した TextureRegion を作成する
	*/

	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Texture texture{ windmillImagePath };
	const Texture emoji{ U"🍎"_emoji };

	while (System::Update())
	{
		// 画像の (250, 100) から幅 200, 高さ 150 の部分を描画する
		texture(250, 100, 200, 150).draw(40, 40);

		// 画像の UV 座標 (0.5, 0.0) から幅 0.5, 高さ 0.75 の部分を描画する
		emoji.uv(0.5, 0.0, 0.5, 0.75).drawAt(400, 300);
	}
}
//敷き詰め描画
void tiledDrawing()
{
	/*
	* 敷き詰め描画 *
	.mapped(幅, 高さ)				テクスチャを指定した幅、高さで敷き詰めた TextureRegion を作成する
	.mapped(サイズ)					テクスチャを指定したサイズで敷き詰めた TextureRegion を作成する
	.repeated(X 回数, Y 回数)		テクスチャを横に X 回、縦に Y 回敷き詰めた TextureRegion を作成する

	* テクスチャアドレスモード *
	
	*/
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Texture emoji{ U"🌳"_emoji };

	while (System::Update())
	{
		{
			// テクスチャアドレスモードをリピートに設定する
			const ScopedRenderStates2D sampler{ SamplerState::RepeatLinear };

			emoji.mapped(300, 400).draw();

			emoji.repeated(2.5, 4).draw(400, 0);
		}
	}
}
//角を丸めた描画
void drawRounded()
{
	/*
	.rounded(半径)		テクスチャの角を 半径 で丸めた TexturedRoundRect を作成する
	*/

	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Texture texture{ windmillImagePath };

	while (System::Update())
	{
		texture.rounded(20).drawAt(400, 300);
	}
}
//操作の組み合わせ
void combinedOperations()
{
	/*
	操作				戻り値				Texture		TextureRegion	TexturedQuad
	.scaled()			TextureRegion		✅			✅				❌
	.resized()			TextureRegion		✅			✅				❌
	.fitted()			TextureRegion		✅			✅				❌
	.rotated()			TexturedQuad		✅			✅				❌
	.rotatedAt()		TexturedQuad		✅			✅				❌
	.flipped()			TextureRegion		✅			✅				❌
	.mirrored()			TextureRegion		✅			✅				❌
	(x, y, w, h)		TextureRegion		✅			❌				❌
	.uv(u, v, w, h)		TextureRegion		✅			❌				❌
	.mapped()			TextureRegion		✅			❌				❌
	.repeated()			TextureRegion		✅			❌				❌
	.rounded()			TexturedRoundRect	✅			✅				❌

	*/

	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Texture texture{ windmillImagePath };
	const Texture emoji{ U"🐈"_emoji };

	while (System::Update())
	{
		texture
			.uv(0.5, 0.5, 0.5, 0.5)
			.scaled(2.0)
			.rotated(20_deg)
			.draw(20, 20);

		emoji
			.mirrored()
			.flipped()
			.drawAt(600, 300);
	}
}
//図形の形に合わせた描画
void drawShaped()
{
	/*
	rect(texture)			長方形（Rect または RectF）にテクスチャ（Texture または TextureRegion）を貼り付けた TexturedQuad を作成する
	circle(texture)			Circle にテクスチャ（Texture または TextureRegion）を貼り付けた TexturedCircle を作成する
	quad(texture)			Quad にテクスチャ（Texture または TextureRegion）を貼り付けた TexturedQuad を作成する
	roundRect(texture)		角丸長方形（RoundRect）にテクスチャ（Texture または TextureRegion）を貼り付けた TexturedRoundRect を作成する
	*/

	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Texture texture1{ windmillImagePath, TextureDesc::Mipped };
	const Texture texture2{ siv3dKunImagePath, TextureDesc::Mipped };

	const Rect rect{ 430, 50, 100, 100 };
	const Circle circle{ 480, 240, 50 };
	const RoundRect roundRect{ 430, 330, 100, 100, 25 };

	while (System::Update())
	{
		Rect{ 50, 50, 350, 400 }(texture1).draw();

		rect
			.drawShadow(Vec2{ 2, 2 }, 12, 1)
			.draw(HSV{ 0, 0.5, 1.0 });
		rect(texture2(90, 3, 110, 110)).draw();

		circle
			.drawShadow(Vec2{ 2, 2 }, 12, 1)
			.draw(HSV{ 240, 0.5, 1.0 });
		circle(texture2(90, 3, 110, 110)).draw();

		roundRect
			.drawShadow(Vec2{ 2, 2 }, 12, 1)
			.draw(HSV{ 120, 0.5, 1.0 });
		roundRect(texture2(90, 3, 110, 110)).draw();
	}
}
//Polygon に合わせた描画
void drawShaped_Polygon()
{
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Texture texture1{ windmillImagePath, TextureDesc::Mipped };
	const Texture texture2{ siv3dKunImagePath, TextureDesc::Mipped };

	const Polygon star = Shape2D::Star(180, Vec2{ 200, 200 });
	const Polygon hexagon = Shape2D::Hexagon(60, Vec2{ 480, 380 });

	while (System::Update())
	{
		const double xOffset = (200 + Periodic::Sine1_1(5s) * 80.0);

		// star に対し、(xOffset, 200) を画像の中心とするようにテクスチャを貼り付けて描画する
		star.toBuffer2D(Arg::center(xOffset, 200+ Periodic::Sine1_1(8s) * 80.0), texture1.size())
			.draw(texture1);

		hexagon.draw(HSV{ 240, 0.5, 1.0 });

		// hexagon に対し、(515, 562) を画像の中心とするようにテクスチャを貼り付けて描画する
		hexagon.toBuffer2D(Arg::center = Vec2{ 515, 562 }, texture2.size())
			.draw(texture2);
	}
}
//大きな画像の事前縮小
void preResizeLargeImage()
{
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	// 画像を 1/4 に縮小してテクスチャを作成する
	const Texture texture{ Image{ bayImagePath}.scaled(0.25) };

	Print << texture.size();

	while (System::Update())
	{
		texture.draw();
	}
}
//テクスチャ描画に関するトラブル
void pixelart_caution1()
{
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Texture texture{ siv3d_kun_16ImagePath };

	while (System::Update())
	{
		{
			texture(20, 0, 20, 28).scaled(8).drawAt(200, 200);
		}

		{
			const ScopedRenderStates2D rs{ SamplerState::ClampNearest };

			texture(20, 0, 20, 28).scaled(8).drawAt(600, 200);
		}
	}
}
//テクスチャ描画に関するトラブル
Image PremultiplyAlpha(Image image)
{
	Color* p = image.data();
	const Color* const pEnd = (p + image.num_pixels());

	while (p != pEnd)
	{
		p->r = static_cast<uint8>((static_cast<uint16>(p->r) * p->a) / 255);
		p->g = static_cast<uint8>((static_cast<uint16>(p->g) * p->a) / 255);
		p->b = static_cast<uint8>((static_cast<uint16>(p->b) * p->a) / 255);
		++p;
	}

	return image;
}
void pixelart_caution2()
{
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Texture emoji1{ U"⛄"_emoji };
	const Texture emoji2{ PremultiplyAlpha(Image{ U"⛄"_emoji }) };

	while (System::Update())
	{
		{
			emoji1.scaled(3).drawAt(200, 300);
		}

		// アルファ乗算済み描画
		{
			const ScopedRenderStates2D rs{ BlendState::Premultiplied };

			emoji2.scaled(3).drawAt(600, 300);
		}
	}
}

void Main()
{
	///* 絵文字から作成 */ emoji();
	///* アイコンから作成 */ icon();
	///* 画像ファイルから作成 */ imagefile();
	///* 画像データから作成 */ imagedata();
	///* テクスチャのサイズ */ textureSize();
	///* 空のテクスチャ */ emptyTexture();
	///* ミップマップの生成 */ mipmap();
	///* 左上座標を指定した描画 */ drawAtTopLeft();
	///* 中心座標を指定した描画 */ drawAtCenter();
	///* それ以外の座標を指定した描画 */ drawAtOther();
	///* 色を乗算した描画(RGB 各成分を乗算) */ drawWithColorMul_RGB();
	///* 色を乗算した描画(アルファ値の使用) */ drawWithColorMul_Alpha();
	///* 拡大縮小した描画 */ drawScaled();
	///* 長方形内に収めた描画 */ drawFitted();
	///* 回転した描画 */ drawRotated();
	///* 上下・左右反転した描画 */ drawFlipped();
	///* 部分描画 */ drawPartial();
	///* 敷き詰め描画 */ tiledDrawing();
	///* 角を丸めた描画 */ drawRounded();
	///* 操作の組み合わせ */ combinedOperations();
	///* 図形の形に合わせた描画 */ drawShaped();
	///* Polygon に合わせた描画 */ drawShaped_Polygon();
	///* 大きな画像の事前縮小 */ preResizeLargeImage();
	///* テクスチャ描画に関するトラブル */ pixelart_caution1();
	/* テクスチャ描画に関するトラブル */ pixelart_caution2();
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

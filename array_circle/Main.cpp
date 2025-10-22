# include <Siv3D.hpp> // Siv3D v0.6.16

//クリックによる Circle の追加・削除
void addCircle_click() {
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	Array<Circle> circles;

	while (System::Update())
	{
		// 左クリックされたら
		if (MouseL.down())
		{
			// クリックした位置に、ランダムな半径の円を追加する
			circles.push_back(Circle{ Cursor::Pos(), Random(5.0, 40.0) });
		}
		// 左クリックされた円を削除する
		//circles.remove_if([](const Circle& circle) { return circle.rightClicked(); });

		//クリックによる Circle 削除（イテレータ方式）
		// 各円について
		for (auto it = circles.begin(); it != circles.end();)
		{
			// その円が左クリックされたていたら
			if (it->rightClicked())
			{
				// その円を削除する
				it = circles.erase(it);
			}
			else
			{
				++it;
			}
		}


		// すべての円を描画する
		for (const auto& circle : circles)
		{
			circle.draw();
		}
	}
}

//所定の位置に移動した Circle の削除
void removeCircle_atPosition()
{
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	Array<Circle> circles;

	for (int32 i = 0; i < 6; ++i)
	{
		circles << Circle{ (100 + i * 100), Random(0.0, 200.0), 30 };
	}

	while (System::Update())
	{
		const double deltaTime = Scene::DeltaTime();

		for (auto& circle : circles)
		{
			circle.y += (deltaTime * 100.0);
		}

		// Y 座標が 500.0 を超えた円を削除する
		circles.remove_if([](const Circle& circle) { return (500.0 < circle.y); });

		// すべての円を描画する
		for (const auto& circle : circles)
		{
			circle.draw();
		}
	}
}

//一定時間ごとの Circle 追加
void addCircle_periodically()
{
Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

Array<Circle> circles;

// 円が出現する周期（秒）
const double spawnInterval = 0.5;

// 円の数の上限（個）
const size_t maxCircles = 10;

// 蓄積時間（秒）
double accumulatedTime = 0.0;

while (System::Update())
{
	// 前フレームからの経過時間（秒）
	const double deltaTime = Scene::DeltaTime();

	// 蓄積時間を増やす
	accumulatedTime += deltaTime;

	// 蓄積時間が周期を超えたら
	if (spawnInterval < accumulatedTime)
	{
		// 円の数が上限数に達していなければ
		if (circles.size() < maxCircles)
		{
			// 円を追加する
			circles << Circle{ Random(100, 700), Random(100, 500), 30 };
		}

		// 蓄積時間を周期分減らす
		accumulatedTime -= spawnInterval;
	}

	for (const auto& circle : circles)
	{
		circle.draw();
	}
}
}

//自作クラスの配列（1）
struct ColorCircle
{
	Circle circle;

	double hue;

	// 円を描画する関数
	void draw() const
	{
		circle.draw(HSV{ hue, 0.75, 0.9 });
	}
};
void createclass1() {
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	Array<ColorCircle> circles;

	while (System::Update())
	{
		// 左クリックされたら
		if (MouseL.down())
		{
			// ColorCircle を追加する
			//circles << ColorCircle{ Circle{ 円のx,y座標, 円の大きさ }, 色相(0°～360°) }
			circles << ColorCircle{ Circle{ Cursor::Pos(), Random(5.0, 40.0) }, Random(0.0, 360.0) };
		}

		// すべての ColorCircle を描画する
		for (const auto& circle : circles)
		{
			circle.draw();
		}
	}
}

//自作クラスの配列（2）
struct RectCounter
{
	Rect rect;

	int32 count = 0;

	// カウンターを更新する関数
	void update()
	{
		if (rect.mouseOver())
		{
			Cursor::RequestStyle(CursorStyle::Hand);
		}

		if (rect.leftClicked())
		{
			++count;
		}
	}

	// カウンターを描画する関数
	void draw(const Font& font) const
	{
		rect.draw();
		rect.drawFrame(2, ColorF{ 0.1 });
		font(U"{}"_fmt(count)).drawAt(rect.center(), ColorF{ 0.1 });
	}
};
void createclass2() {
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });
	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };

	Array<RectCounter> rectCounters;
	rectCounters << RectCounter{ Rect{ 100, 100, 100, 100 } };
	rectCounters << RectCounter{ Rect{ 300, 100, 100, 100 } };
	rectCounters << RectCounter{ Rect{ 500, 100, 100, 100 } };

	while (System::Update())
	{
		// すべての RectCounter を更新する
		for (auto& rectCounter : rectCounters)
		{
			rectCounter.update();
		}

		// すべての RectCounter を描画する
		for (const auto& rectCounter : rectCounters)
		{
			rectCounter.draw(font);
		}
	}
}


void Main()
{
	//クリックによるCircleの追加・削除
	//addCircle_click();

	//所定の位置に移動した Circle の削除
	//removeCircle_atPosition();

	//一定時間ごとの Circle 追加
	//addCircle_periodically();

	//自作クラスの配列（1）
	//createclass1();

	//自作クラスの配列（2）
	createclass2();
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

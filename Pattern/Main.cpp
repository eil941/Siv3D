# include <Siv3D.hpp> // Siv3D v0.6.16

//円を並べる
void lineup() {
	Scene::SetBackground(Palette::White);

	while (System::Update())
	{
		for (int32 i = 0; i < 6; ++i)
		{
			Circle{ (i * 100), 100, 30 }.draw(Palette::Skyblue);
		}

		for (int32 i = 0; i < 6; ++i)
		{
			Circle{ (50 + i * 100), 200, 30 }.draw(Palette::Seagreen);
		}
	}
}
//二重ループで円を並べる
void lineup2() {
	Scene::SetBackground(Palette::White);

	while (System::Update())
	{
		for (int32 y = 0; y < 40; ++y) // 縦方向
		{
			for (int32 x = 0; x < 60; ++x) // 横方向
			{
				Circle{ (x * 100), (y * 100), 30 }.draw(Palette::Skyblue);
			}
		}
	}
}
//少し複雑に
void lineup3() {
	Scene::SetBackground(Palette::White);

	while (System::Update())
	{
		for (int32 y = 0; y < 40; ++y)
		{
			for (int32 x = 0; x < 60; ++x)
			{
				if (IsEven(x + y)) // x + y が偶数なら
				{
					// 大きい円を描く
					Circle{ (x * 100), (y * 100), 30 }.draw(Palette::Skyblue);
				}
				else // 奇数なら
				{
					// 小さい円を描く
					Circle{ (x * 100), (y * 100), 10 }.draw(Palette::Skyblue);
				}
			}
		}
	}
}

//長方形を並べる
void lineupRect() {
	Scene::SetBackground(Palette::White);

	while (System::Update())
	{
		for (int32 x = 0; x < 60; ++x)
		{
			Rect{ (x * 100), 0, 80, 600 }.draw(Palette::Skyblue);
		}
	}
}
//サイズを徐々に変える
void lineupReact2() {
	Scene::SetBackground(Palette::White);

	while (System::Update())
	{
		for (int32 x = 0; x < 60; ++x)
		{
			Rect{ (x * 100), 0, 80, ((x + 1) * 100) }.draw(Palette::Skyblue);
		}
	}
}
//色を徐々に変える
void lineupRect3() {
	Scene::SetBackground(Palette::White);

	while (System::Update())
	{
		for (int32 x = 0; x < 60; ++x)
		{
			Rect{ (x * 100), 0, 80, 600 }.draw(ColorF{ 0.0, (x * 0.15), (x * 0.15) });
		}
	}
}
//色相を徐々に変える
void lineupRect4() {
	Scene::SetBackground(Palette::White);

	while (System::Update())
	{
		for (int32 x = 0; x < 10; ++x)
		{
			Rect{ (x * 80), 0, 80, 600 }.draw(HSV{ (x * 40), 0.5, 1.0 });
		}
	}
}

//波紋
void ripples() {
	Scene::SetBackground(Palette::White);

	while (System::Update())
	{
		for (int32 i = 0; i < 60; ++i)
		{
			Circle{  100, 300, (i * 10) }.drawFrame(4, Palette::Skyblue);
		}
	}
}
//市松模様
void checkerboard() {
	Scene::SetBackground(Palette::White);
	while (System::Update())
	{
		for (int32 i = 0; i < 10; i++) {
			for (int32 j = 0; j < 10; j++) {
				Rect(i * 60, j * 60, 60,60).draw(((i + j)%2==0) ? Palette::Black : Palette::White);
			}
		}
	}
}
//マス目
void grid() {
	Scene::SetBackground(Palette::White);
	constexpr int32 cellSize = 40; // マスのサイズ
	constexpr int32 cols = 60;    // 列数
	constexpr int32 rows = 40;    // 行数
	while (System::Update())
	{
		for (int32 y = 0; y < rows; ++y)
		{
			for (int32 x = 0; x < cols; ++x)
			{
				Rect{ x * cellSize, y * cellSize, cellSize, cellSize }.drawFrame(1, Palette::Black);
			}
		}
	}
}

void Main()
{
	//円を並べる
	//lineup();
	//二重ループで円を並べる
	//lineup2();
	//少し複雑に
	//lineup3();

	//長方形を並べる
	//lineupRect();
	//サイズを徐々に変える
	//lineupReact2();
	//色を徐々に変える
	//lineupRect3();
	//色相を徐々に変える
	//lineupRect4();

	//波紋
	//ripples();
	//市松模様
	//checkerboard();
	//マス目
	grid();
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

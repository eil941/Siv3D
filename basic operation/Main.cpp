# include <Siv3D.hpp> // Siv3D v0.6.16

void Main()
{

	// 画面を 1280x720 にリサイズする
	Window::Resize(1280, 720);

	// 背景を白色にする
	//Scene::SetBackground(Palette::White);

	// 背景色を RGB で指定する
	Scene::SetBackground(ColorF{ 0.8, 0.9, 1.0 }); //（r: 80 %, g: 90 %, b: 100 %）

	// 背景色を HSV で指定する
	//Scene::SetBackground(HSV{ 220.0, 0.4, 1.0 });

	// [PrintScreen] キーまたは [P] キーが押されたときのみスクリーンショットを保存するよう設定する
	ScreenCapture::SetShortcutKeys({ KeyPrintScreen, KeyP });

	// 終了操作を設定しない
	System::SetTerminationTriggers(UserAction::NoAction);


	int32 count = 0;


	while (System::Update())
	{

		const double hue = (Scene::Time() * 60);

		// 背景色を HSV で指定する
		Scene::SetBackground(HSV{ hue });

		// 古い出力（以前のフレームの出力）を消去する
		ClearPrint();
		Print << count;
		++count;
		Print << U"Hello, " << U"Siv3D"; // 複数に分けても OK


		// 現在のマウスカーソル座標を表示する
		Print << Cursor::Pos();

		const Point pos = Cursor::Pos();
		//const Vec2 pos = Cursor::Pos();

		// 現在のマウスカーソル座標を X 座標と Y 座標で分けて表示する
		Print << U"X: " << pos.x;
		Print << U"Y: " << pos.y;

		const Vec2 pos1{ 123.4, 567.8 };

		Print << pos1;

		// Vec2 → Point に変換する
		const Point pos2 = pos1.asPoint();

		Print << pos2;



		// プログラムの開始から 5 秒経過したら
		if (1.0 <= Scene::Time())
		{
			// デフォルトの終了操作に戻す
			System::SetTerminationTriggers(UserAction::Default);
		}


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
/*
int8	1 バイト	符号付き 8 ビット整数	-128 ～ 127
uint8	1 バイト	符号なし 8 ビット整数	0 ～ 255
int16	2 バイト	符号付き 16 ビット整数	-32,768 ～ 32,767
uint16	2 バイト	符号なし 16 ビット整数	0 ～ 65,535
int32 	4 バイト	符号付き 32 ビット整数	-2,147,483,648 ～ 2,147,483,647
uint32	4 バイト	符号なし 32 ビット整数	0 ～ 4,294,967,295
int64	8 バイト	符号付き 64 ビット整数	-9,223,372,036,854,775,808 ～ 9,223,372,036,854,775,807
uint64	8 バイト	符号なし 64 ビット整数	0 ～ 18,446,744,073,709,551,615
size_t 	8 バイト	符号なし 64 ビット整数	0 ～ 18,446,744,073,709,551,615

float	4 バイト	単精度浮動小数点数	3.4E +/- 38	7 桁
double 	8 バイト	倍精度浮動小数点数	1.7E +/- 308	15 桁

bool 	1 バイト	真偽値	true または false

char32 	4 バイト	UTF-32 エンコードの文字	0 ～ 0x10FFFF

std::array<Type, N>	固定長配列
Array<Type> 	動的配列（C++ 標準の std::vector に相当）
Grid<Type>	動的二次元配列

Optional<Type>	任意の型に無効値の表現を追加するクラス（C++ 標準の std::optional に相当）
HashSet<Type>	ハッシュテーブルによる Set（C++ 標準の std::unordered_set に相当）
HashTable<Key, Value>	ハッシュテーブルによる Map（C++ 標準の std::unordered_map に相当）

*/

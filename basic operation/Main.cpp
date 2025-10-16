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

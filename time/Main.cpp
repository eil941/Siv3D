# include <Siv3D.hpp> // Siv3D v0.6.16

void Main()
{
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Font font{ FontMethod::MSDF, 48 };

	// プログラム開始からの経過時間（秒）
	double time = 0.0;

	// カウントダウン時間（秒）
	const double countdownTime = 10.0;

	// 残り時間（秒）
	double remainingTime = countdownTime;

	// レベルが上がる周期（秒）
	const double levelUpInterval = 2.0;

	// 蓄積時間（秒）
	double accumulatedTime = 0.0;

	// レベル
	int32 level = 0;


	while (System::Update())
	{
		// 前フレームからの経過時間（秒）
		const double deltaTime = Scene::DeltaTime();

		// time に deltaTime を加算する
		time += deltaTime;

		// time を表示する
		font(U"time: {:.2f}"_fmt(time)).draw(40, Vec2{ 40, 40 }, ColorF{ 0.1 });

		// deltaTime を表示する
		font(U"deltaTime: {:.4f}"_fmt(deltaTime)).draw(40, Vec2{ 40, 100 }, ColorF{ 0.1 });

		// 残り時間を減らす
		remainingTime -= deltaTime;

		if (0.0 < remainingTime) // 残り時間がある場合
		{
			font(U"time: {:.2f}"_fmt(remainingTime)).draw(40, Vec2{ 40, 200 }, ColorF{ 0.1 });
		}
		else // 残り時間がなくなった場合
		{
			font(U"Time's up!").draw(40, Vec2{ 40, 200 }, ColorF{ 0.1 });
			font(U"Press Enter to restart").draw(30, Vec2{ 40, 300 }, ColorF{ 0.1 });

			// Enter キーを押したら
			if (KeyEnter.down())
			{
				// 残り時間をリセットして再スタート
				remainingTime = countdownTime;
			}
		}

		// 蓄積時間を増やす
		accumulatedTime += deltaTime;

		// 蓄積時間が周期を超えたら
		if (levelUpInterval < accumulatedTime)
		{
			// レベルを上げる
			++level;

			// 蓄積時間を周期分減らす
			accumulatedTime -= levelUpInterval;

			Print << U"Level up!";
		}

		// 現在のレベルを表示する
		font(U"Level: {}"_fmt(level)).draw(40, Vec2{ 300, 40 }, ColorF{ 0.1 });


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

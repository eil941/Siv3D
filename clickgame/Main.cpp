# include <Siv3D.hpp> // Siv3D v0.6.16

void Main()
{
	// 背景の色を設定する | Set the background color
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	// 絵文字からテクスチャを作成する | Create a texture from an emoji
	const Texture emoji{ U"🍎"_emoji };
	const Texture nise{ U"🌶"_emoji };


	// 太文字のフォントを作成する | Create a bold font with MSDF method
	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };


	const int32 emoji_size = 48;

	Vec2 applePos{ 300,400 };
	Vec2 nisePos{ 300,400 };
	Circle appleArea{ applePos, emoji_size };
	Circle niseArea{ nisePos, emoji_size };


	int32 score = 0;
	int32 AddScore = 100;

	bool hyoujiflag = false;

	// 残り時間
	double remainingTime = 10.0;


	while (System::Update())
	{

		const double deltaTime = Scene::DeltaTime();

		// 残り時間を減らす
		remainingTime -= deltaTime;

		if (0 < remainingTime) // 残り時間がある場合
		{


			if (appleArea.leftClicked())
			{
				// クリックされたら、リンゴをランダムな位置に移動する | If clicked, move the apple to a random position
				applePos.set(Random(emoji_size, Scene::Width() - emoji_size), Random(emoji_size, Scene::Height() - emoji_size));
				appleArea.setCenter(applePos);

				// スコアを加算する | Increase the score
				score += AddScore;

				if (Random(1, 100) < 50) {
					hyoujiflag = true;
				}
			}
			if (appleArea.mouseOver())
			{
				// マウスカーソルを手の形に変更する
				Cursor::RequestStyle(CursorStyle::Hand);
			}

			if (hyoujiflag) {

				if (niseArea.leftClicked()) {
					// クリックされたらランダムな位置に移動する
					nisePos.set(Random(emoji_size, Scene::Width() - emoji_size), Random(emoji_size, Scene::Height() - emoji_size));
					niseArea.setCenter(nisePos);

					// スコアを加算する | Increase the score
					score -= 150;
					hyoujiflag = false;
				}
				if (niseArea.mouseOver())
				{
					// マウスカーソルを手の形に変更する
					Cursor::RequestStyle(CursorStyle::Hand);
				}
			}
		}
		else {
			if (KeyEnter.down()) {
				// リセットする | Reset
				remainingTime = 10.0;
				score = 0;
				hyoujiflag = false;
				applePos={ 300,400 };
				nisePos={ 300,400 };
				appleArea.setCenter(applePos);
				niseArea.setCenter(nisePos);
			}
		}

		if(hyoujiflag) {
			// 偽物を描く | Draw the fake
			nise.drawAt(nisePos);
		}

		// プレイヤーを描く | Draw the player
		emoji.drawAt(applePos);


		if (0 < remainingTime) // 残り時間がある場合
		{
			// 残り時間を表示する
			font(U"TIME: {:.1f}"_fmt(remainingTime)).draw(40, Arg::topRight(760, 40), ColorF{ 0.1 });			}
		else // 時間切れの場合
		{
			// 時間切れのメッセージを表示する
			font(U"TIME'S UP!").drawAt(60, Vec2{ 400, 300 }, ColorF{ 0.1 });
			font(U"Press [Enter] to restart").drawAt(30, Vec2{ 400, 400 }, ColorF{ 0.1 });
		}
			// スコアを表示する
			font(U"SCORE: {}"_fmt(score)).draw(40, Vec2{ 40, 40 }, ColorF{ 0.1 });
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

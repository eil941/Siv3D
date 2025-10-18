# include <Siv3D.hpp>

//円を右から左に動かす
void circle_righttoleft(){
	// 円の X 座標
	double x = 0.0;

	while (System::Update())
	{
		x += (Scene::DeltaTime() * 100.0);

		Circle{ x, 300, 50 }.draw();
	}
}

//絵文字を右から左に動かす
void emoji_righttoleft(){
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Texture emoji{ U"🐥"_emoji };

	// 絵文字を描画する位置
	Vec2 pos{ 100, 300 };

	while (System::Update())
	{
		// 位置を毎秒 100 ピクセルの速度で右に移動させる
		pos.x += (Scene::DeltaTime() * 100.0);

		// 絵文字を現在の位置に描画する
		emoji.drawAt(pos);
	}
}

//往復移動
void round_trip() {
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Texture emoji{ U"🐥"_emoji };

	// 絵文字を描画する位置
	Vec2 pos{ 100, 300 };

	// 絵文字の移動速度
	double velocity = 100.0;

	while (System::Update())
	{
		// 位置を更新する
		pos.x += (Scene::DeltaTime() * velocity);

		if (((0.0 < velocity) && (740 < pos.x)) // 画面右端に到達するか
			|| ((velocity < 0.0) && (pos.x < 60))) // 画面左端に到達したら
		{
			// 速度を反転する
			velocity *= -1;
		}

		emoji.drawAt(pos);
	}
}

//斜め移動 + バウンド
void bound() {
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Texture emoji{ U"🐥"_emoji };

	// 絵文字を描画する位置
	Vec2 pos{ 100, 300 };

	// 絵文字の移動速度
	Vec2 velocity{ 100.0, 100.0 };

	while (System::Update())
	{
		// 位置を更新する
		pos += (Scene::DeltaTime() * velocity);

		if (((0.0 < velocity.x) && (740 < pos.x)) // 画面右端に到達するか
			|| ((velocity.x < 0.0) && (pos.x < 60))) // 画面左端に到達したら
		{
			// x 方向の速度を反転する
			velocity.x *= -1;
		}

		if (((0.0 < velocity.y) && (540 < pos.y)) // 画面下端に到達するか
			|| ((velocity.y < 0.0) && (pos.y < 60))) // 画面上端に到達したら
		{
			// y 方向の速度を反転する
			velocity.y *= -1;
		}

		emoji.drawAt(pos);
	}
}

//回転
void rotate() {
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Texture emoji{ U"🍣"_emoji };

	// 絵文字の回転角度
	double angle = 0_deg;

	while (System::Update())
	{
		// 角度を更新する
		angle += (Scene::DeltaTime() * 180_deg);

		// 絵文字を現在の位置と角度で描画する
		emoji.rotated(angle).drawAt(400, 300);
	}
}

//図形を動かす
void move_shape() {
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	Circle circle{ 400, 300, 10 };
	RectF rect{ 100, 200, 100, 200 };

	while (System::Update())
	{
		const double deltaTime = Scene::DeltaTime();
		circle.r += (deltaTime * 40.0);
		rect.x += (deltaTime * 100.0);

		circle.draw();
		rect.draw(ColorF{ 0.8, 0.9, 1.0 });
	}
}
void Main()
{
	//emoji_righttoleft();
	//round_trip();
	//bound();
	//rotate();
	move_shape();
}

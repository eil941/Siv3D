# include <Siv3D.hpp> // Siv3D v0.6.16

// 現在のフレームでの移動量を計算する関数
Vec2 GetMovement(double speed)
{
	Vec2 move{ 0, 0 };

	if (KeyA.pressed()) // [A] キー
	{
		move.x -= speed;
	}

	if (KeyD.pressed()) // [D] キー
	{
		move.x += speed;
	}
	if (KeyW.pressed()) // [W] キー
	{
		move.y -= speed;
	}
	if (KeyS.pressed()) // [S] キー
	{
		move.y += speed;
	}

	return move;
}

// キー入力によって選択中のアイテムインデックスを変更する関数
int32 UpdateSelectIndex(int32 itemIndex, int32 maxIndex)
{
	// 一番左でない状態で [←] キーが押されたら、インデックスを 1 減らす
	if ((0 < itemIndex) && KeyLeft.down())
	{
		--itemIndex;
	}

	// 一番右でない状態で [→] キーが押されたら、インデックスを 1 増やす
	if ((itemIndex < maxIndex) && KeyRight.down())
	{
		++itemIndex;
	}

	// 新しいインデックスを返す
	return itemIndex;
}


void Main()
{
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Texture emoji{ U"🐥"_emoji };
	const Texture emoji0{ U"🍣"_emoji };
	const Texture emoji1{ U"🍜"_emoji };
	const Texture emoji2{ U"🍔"_emoji };
	const Texture emoji3{ U"🍛"_emoji };

	int32 itemIndex = 0;

	// 絵文字の位置
	Vec2 pos{ 400, 300 };

	while (System::Update())
	{

		// 前フレームからの経過時間（秒）* 200
		const double move = (Scene::DeltaTime() * 200);

		pos += GetMovement(move);

		emoji.drawAt(pos);

		// A キーが押されたら
		if (KeyA.down())
		{
			Print << U"A";
		}

		// スペースキーが押されたら
		if (KeySpace.down())
		{
			Print << U"Space";
		}

		// 1 キーが押されたら
		if (Key1.down())
		{
			Print << U"1";
		}


		emoji0.drawAt(100, 200);
		emoji1.drawAt(300, 200);
		emoji2.drawAt(500, 200);
		emoji3.drawAt(700, 200);

		itemIndex = UpdateSelectIndex(itemIndex, 3);

		Rect{ Arg::center((100 + 200 * itemIndex), 200), 150 }
		.drawFrame(6, ColorF{ 0.2 });

		//キーが押されている間true
		/*
		// A キーが押されていたら
		if (KeyA.pressed())
		{
			Print << U"A";
		}

		// スペースキーが押されていたら
		if (KeySpace.pressed())
		{
			Print << U"Space";
		}

		// 1 キーが押されていたら
		if (Key1.pressed())
		{
			Print << U"1";
		}*/

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

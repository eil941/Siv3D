# include <Siv3D.hpp> // Siv3D v0.6.16

//交差した図形を削除する（.remove_if() 方式）
void remove_if_example()
{
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	// 敵の円の配列
	Array<Circle> enemyCircles = {
		Circle{ 200, 200, 60 },
		Circle{ 400, 200, 60 },
		Circle{ 600, 200, 60 },
		Circle{ 300, 400, 60 },
		Circle{ 500, 400, 60 },
	};

	while (System::Update())
	{
		// プレイヤーの円
		const Circle playerCircle{ Cursor::Pos(), 20 };

		// プレイヤーの円と交差している要素を配列から削除する
		enemyCircles.remove_if([&](const Circle& enemyCircle)
			{
				return playerCircle.intersects(enemyCircle);
			});

		// すべての敵の円を描く
		for (const auto& enemyCircle : enemyCircles)
		{
			enemyCircle.draw(ColorF{ 0.5 });
		}

		// プレイヤーの円を描く
		playerCircle.draw(ColorF{ 0.0, 0.6, 1.0 });
	}
}

//交差した図形を削除する（イテレータ方式）
void remove_iterator_example()
{
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	// 敵の円の配列
	Array<Circle> enemyCircles = {
		Circle{ 200, 200, 60 },
		Circle{ 400, 200, 60 },
		Circle{ 600, 200, 60 },
		Circle{ 300, 400, 60 },
		Circle{ 500, 400, 60 },
	};

	while (System::Update())
	{
		// プレイヤーの円
		const Circle playerCircle{ Cursor::Pos(), 20 };

		for (auto it = enemyCircles.begin(); it != enemyCircles.end();)
		{
			// プレイヤーの円と敵の円が交差している場合
			if (playerCircle.intersects(*it))
			{
				Print << U"Hit!";

				// その円を削除する
				// erase() は削除後の次の要素を指すイテレータを返す
				it = enemyCircles.erase(it);
			}
			else
			{
				++it;
			}
		}

		// すべての敵の円を描く
		for (const auto& enemyCircle : enemyCircles)
		{
			enemyCircle.draw(ColorF{ 0.5 });
		}

		// プレイヤーの円を描く
		playerCircle.draw(ColorF{ 0.0, 0.6, 1.0 });
	}
}

void Main()
{
	// 交差した図形を削除する（.remove_if() 方式）
	//remove_if_example();

	// 交差した図形を削除する（イテレータ方式）
	remove_iterator_example();
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

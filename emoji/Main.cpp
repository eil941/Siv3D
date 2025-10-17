# include <Siv3D.hpp> // Siv3D v0.6.16

void Main()
{
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Texture emoji1{ U"🐈"_emoji };
	const Texture emoji2{ U"🍎"_emoji };

	while (System::Update())
	{
		emoji1.scaled(2).drawAt(100, 100);
		
		const int32 cursorX = Cursor::Pos().x;
		emoji1.mirrored(400 <= cursorX).drawAt(400, 300);

		emoji2.rotated(-45_deg).drawAt(200, 300);
		emoji2.scaled(0.5).rotated(180_deg).drawAt(Cursor::Pos());
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

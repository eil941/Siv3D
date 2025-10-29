/*
* https://siv3d.github.io/ja-jp/tutorial2/video/
* 動画を描く
*/
# include <Siv3D.hpp> // Siv3D v0.6.16

String riverVideoPath = U"river.mp4のパスを記述";
String gifPath = U"test.gifのパスを記述";

//動画の描画
void movie() {
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	// ループする場合は Loop::Yes, ループしない場合は Loop::No
	const VideoTexture videoTexture{ riverVideoPath, Loop::Yes };

	while (System::Update())
	{
		ClearPrint();

		// 再生位置（秒） / 動画の長さ（秒）
		Print << U"{:.2f}/{:.2f}"_fmt(videoTexture.posSec(), videoTexture.lengthSec());

		// 動画の時間を進める (デフォルトでは Scece::DeltaTime() 秒)
		videoTexture.advance();

		videoTexture
			.scaled(0.5).draw();

		videoTexture
			.scaled(0.5)
			.rotated(Scene::Time() * 30_deg)
			.drawAt(Cursor::Pos());
	}
}
//音声付きの動画への対応
void movieWithSound() {
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	// 音声付きの動画ファイルのパス（プロジェクトには同梱されていません）
	const FilePath path = U"test.mp4";

	if (not FileSystem::Exists(path))
	{
		throw Error{ U"{} が見つかりませんでした"_fmt(path) };
	}

	// ループする場合は Loop::Yes, ループしない場合は Loop::No
	const VideoTexture videoTexture{ path, Loop::Yes };

	// 動画の音声を再生するための Audio オブジェクト
	const Audio audio{ Audio::Stream, path, Loop::Yes };

	// 音声の読み込みに成功したら
	if (not audio)
	{
		throw Error{ U"音声の読み込みに失敗しました" };
	}

	// 音声を再生する
	audio.play();

	while (System::Update())
	{
		ClearPrint();

		// 動画の再生位置（秒）
		const double videoTime = videoTexture.posSec();

		// 音声の再生位置（秒）
		const double audioTime = audio.posSec();

		Print << U"{:.2f}/{:.2f}/{:.2f}"_fmt(videoTime, audioTime, videoTexture.lengthSec());

		// 動画の再生位置と音声の再生位置の差が 0.1 秒以上ある場合
		if (0.1 < AbsDiff(audioTime, videoTime))
		{
			// 音声の再生位置を動画の再生位置に合わせる
			audio.seekTime(videoTime);
		}

		// 動画の時間を進める (デフォルトでは Scece::DeltaTime() 秒)
		videoTexture.advance();

		videoTexture
			.scaled(0.5).draw();
	}
}
//GIF アニメーションの描画
void gifAnimation() {
	/**** ゲームのアニメーションとしての使用は非推奨 ****/

	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	// GIF アニメーション画像を開く
	const AnimatedGIFReader gif{ gifPath };

	// 各フレームの画像と、次のフレームへのディレイ（ミリ秒）をロードする
	Array<Image> images;
	Array<int32> delays;
	gif.read(images, delays);

	// 各フレームの Image から Texure を作成する
	const Array<Texture> textures = images.map([](const Image& image) { return Texture{ image }; });

	// 画像データはもう使わないため、消去してメモリ消費を減らす
	images.clear();

	while (System::Update())
	{
		ClearPrint();

		// フレーム数
		Print << textures.size() << U" frames";

		// 各フレームのディレイ（ミリ秒）一覧
		Print << U"delays: " << delays;

		// アニメーションの経過時間
		const double t = Scene::Time();

		// 経過時間と各フレームのディレイに基づいて、何番目のフレームを描けばよいかを計算する
		const size_t frameIndex = AnimatedGIFReader::GetFrameIndex(t, delays);

		// 現在のフレーム番号
		Print << U"frameIndex: " << frameIndex;

		textures[frameIndex].draw(200, 200);
	}
}

void Main()
{
	///* 動画の描画 */movie();
	///* 音声付きの動画への対応 */movieWithSound();
	/* GIF アニメーションの描画 */gifAnimation();
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

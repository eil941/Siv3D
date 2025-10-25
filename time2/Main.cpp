//時間と動き
# include <Siv3D.hpp> // Siv3D v0.6.16

//経過時間の蓄積
void elapsedtime_sum() {
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };

	while (System::Update())
	{
		font(U"Time: {:.2f}"_fmt(Scene::Time())).draw(40, Vec2{ 40, 40 }, ColorF{ 0.2 });
	}
}
//時間に基づくモーション
void motion() {
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };

	const Texture emoji{ U"🍎"_emoji };

	while (System::Update())
	{
		const double t = Scene::Time();

		RectF{ (t * 50), 40, 40, 200 }.draw(ColorF{ 0.2 });

		Circle{ 200, 400, (t * 20) }.draw(Palette::Seagreen);

		emoji.rotated(t * 90_deg).drawAt(600, 400);

		font(U"Time: {:.2f}"_fmt(Scene::Time())).draw(40, Vec2{ 40, 40 }, ColorF{ 0.2 });
	}
}
//一定時間おきに何かをする
void interval_action() {
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };

	const double interval = 0.5;

	double accumlatedTime = 0.0;

	int32 count = 0;

	while (System::Update())
	{
		accumlatedTime += Scene::DeltaTime();

		if (interval <= accumlatedTime)
		{
			Print << ++count;

			accumlatedTime -= interval;
		}
		font(U"Time: {:.2f}"_fmt(Scene::Time())).draw(40, Vec2{ 40, 40 }, ColorF{ 0.2 });
	}
}
//一定時間おきに何かをする（イベント周期が短い：1フレームの時間より短い）
void interval_action2 (){
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });
	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };
	const double interval = 0.01;

	double accumlatedTime = 0.0;

	int32 count = 0;

	while (System::Update())
	{
		accumlatedTime += Scene::DeltaTime();

		while (interval <= accumlatedTime)
		{
			Print << ++count;

			accumlatedTime -= interval;
		}
		font(U"Time: {:.2f}"_fmt(Scene::Time())).draw(40, Vec2{ 40, 40 }, ColorF{ 0.2 });
		font(U"accumlated time: {:.2f}"_fmt(accumlatedTime)).draw(40, Vec2{ 40, 100 }, ColorF{ 0.2 });
	}
}
//ストップウォッチ
void stopwatch() {

	/*
	.start()			計測を開始・再開する
	.pause()			計測を一時停止する
	.resume()			一時停止中の計測を再開する
	.reset()			計測を停止して経過時間を 0 にリセットする
	.restart()			計測をリセットして再び 0 から計測を開始する
	.isRunning()		計測中かどうかを bool 型で返す
	.isPaused()			一時停止中かどうかを bool 型で返す
	.isStarted()		計測が開始されているかどうかを bool 型で返す
	.min()				経過時間を分単位で int32 型で返す
	.s()				経過時間を分単位で int32 型で返す	
	.s64()				経過時間を秒単位で int64 型で返す
	.sF()				経過時間を秒単位で double 型で返す
	.ms()				経過時間をミリ秒単位で int32 型で返す
	.ms64()				経過時間をミリ秒単位で int64 型で返す
	.msF()				経過時間をミリ秒単位で double 型で返す	
	.us()				経過時間をマイクロ秒単位で int32 型で返す
	.us64()				経過時間をマイクロ秒単位で int64 型で返す
	.usF()				経過時間をマイクロ秒単位で double 型で返す
	.fotmat(...)		経過時間を指定したフォーマットで文字列化して返す

	*/

	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };

	// 作成と同時に計測を開始
	Stopwatch stopwatch{ StartImmediately::Yes };

	while (System::Update())
	{
		if (MouseL.down())
		{
			if (stopwatch.isPaused())
			{
				// 再開
				stopwatch.resume();
			}
			else
			{
				// 一時停止
				stopwatch.pause();
			}
		}

		if (MouseR.down())
		{
			// リスタート
			stopwatch.restart();
		}

		RectF{ 0, 200, (stopwatch.sF() * 100), 200 }.draw();

		font(stopwatch.format(U"mm:ss.xx")).draw(40, Vec2{ 40, 40 }, ColorF{ 0.2 });
	}
}
//時間型
void time_type() {
	/*
	Days または DaysF						日
	Hours または HoursF						時
	Minutes または MinutesF					分
	Seconds または SecondsF					秒
	Milliseconds または MillisecondsF		ミリ秒
	Microseconds または MicrosecondsF		マイクロ秒
	Nanoseconds または NanosecondsF			ナノ秒
	Duration								SecondsF の別名

	サフィックス	時間
	_d				日
	h				時
	min				分
	s				秒
	ms				ミリ秒
	us				マイクロ秒
	ns				ナノ秒
	*/

	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const MinutesF m = 3min;

	const SecondsF s = 5.5s;

	Print << (m + s);

	const Seconds s2 = DurationCast<Seconds>(s);

	Print << s2;

	const Duration d = 123.456s;

	Print << d;

	while (System::Update())
	{

	}
}
//タイマー
void timer_class() {
	/*
	.start()			タイマーを開始・再開する
	.pause()			タイマーを一時停止する
	.resume()			一時停止中のタイマーを再開する
	.reset()			タイマーを停止して残り時間をリセットする
	.restart()			タイマーをリセットして再び開始する
	.isRunning()		計測中かどうかを bool 型で返す
	.isPaused()			一時停止中かどうかを bool 型で返す
	.isStarted()		計測が開始されているかどうかを bool 型で返す
	.reachedZero()		残り時間が 0 に達したかどうかを bool 型で返す
	.min()				残り時間を分単位で int32 型で返す
	.s()				残り時間を秒単位で int32 型で返す
	.s64()				残り時間を秒単位で int64 型で返す
	.sF()				残り時間を秒単位で double 型で返す
	.ms()				残り時間をミリ秒単位で int32 型で返す
	.ms64()				残り時間をミリ秒単位で int64 型で返す
	.msF()				残り時間をミリ秒単位で double 型で返す
	.us()				残り時間をマイクロ秒単位で int32 型で返す
	.us64()				残り時間をマイクロ秒単位で int64 型で返す
	.usF()				残り時間をマイクロ秒単位で double 型で返す
	.progress1_0()		タイマーの進み具合（1.0 で始まり 0.0 で終わる）を double 型で返す
	.progress0_1()		タイマーの進み具合（0.0 で始まり 1.0 で終わる）を double 型で返す

	*/

	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };

	// 作成と同時に計測を開始
	Timer timer{ 10s, StartImmediately::Yes };

	while (System::Update())
	{
		if (MouseL.down())
		{
			if (timer.isPaused())
			{
				// 再開
				timer.resume();
			}
			else
			{
				// 一時停止
				timer.pause();
			}
		}

		if (MouseR.down())
		{
			// リスタート
			timer.restart();
		}

		RectF{ 0, 200, (timer.progress1_0() * 800), 200 }.draw();

		if (timer.reachedZero())
		{
			font(U"Time's up!").draw(40, Vec2{ 40, 40 }, Palette::Red);
		}
		else
		{
			font(timer.format(U"mm:ss.xx")).draw(40, Vec2{ 40, 40 }, ColorF{ 0.2 });
		}
	}
}
//時間の比較
void time_comparison() {
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };

	// 作成と同時に計測を開始
	Stopwatch stopwatch{ StartImmediately::Yes };

	while (System::Update())
	{
		// 2 秒以上経過していたら
		if (2s <= stopwatch)
		{
			Circle{ 200, 300, 50 }.draw();
		}

		// 4 秒以上経過していたら
		if (4s <= stopwatch)
		{
			Circle{ 400, 300, 50 }.draw();
		}

		// 6 秒以上経過していたら
		if (6s <= stopwatch)
		{
			Circle{ 600, 300, 50 }.draw();
		}

		font(stopwatch.format(U"mm:ss.xx")).draw(40, Vec2{ 40, 40 }, ColorF{ 0.2 });
	}
}
//周期的なモーション
void periodic_motion() {
	/*
	周期的に 0 ↔ 1 または -1 ↔ 1 の間で変化する値が必要な場合、Periodic:: 名前空間に用意されている周期関数を使うと便利

	Periodic::Square0_1()¶
		指定した周期で 0.0 か 1.0 を交互に返します
		周期の前半では 1.0 を、残りの半分では 0.0 を返します
	Periodic::Triangle0_1()¶
		0.0 から一定の速度で値が大きくなって 1.0 に、そこから一定の速度で小さくなって 0.0 に、という変化を指定した周期で繰り返します
	Periodic::Sine0_1()¶
		指定した周期で、0.0～1.0 の範囲で正弦波（サインカーブ）を描く数値の変化を返します
	Periodic::Sawtooth0_1()¶
		指定した周期で、0.0 → 1.0 への変化を繰り返します
	Periodic::Jump0_1()¶
		指定した周期で、地面からジャンプしたときの速度のような数値変化を繰り返します
	*/

	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	while (System::Update())
	{
		//指定した周期で 0.0 か 1.0 を交互に返します
		//周期の前半では 1.0 を、残りの半分では 0.0 を返します
		const double p0 = Periodic::Square0_1(2s);
		//0.0 から一定の速度で値が大きくなって 1.0 に、そこから一定の速度で小さくなって 0.0 に、という変化を指定した周期で繰り返します
		const double p1 = Periodic::Triangle0_1(2s);
		//指定した周期で、0.0～1.0 の範囲で正弦波（サインカーブ）を描く数値の変化を返します
		const double p2 = Periodic::Sine0_1(2s);
		//指定した周期で、0.0 → 1.0 への変化を繰り返します
		const double p3 = Periodic::Sawtooth0_1(2s);
		//指定した周期で、地面からジャンプしたときの速度のような数値変化を繰り返します
		const double p4 = Periodic::Jump0_1(2s);

		Line{ 100, 0, 100, 600 }.draw(2, ColorF{ 0.2 });
		Line{ 700, 0, 700, 600 }.draw(2, ColorF{ 0.2 });

		Circle{ (100 + p0 * 600), 100, 20 }.draw(ColorF{ 1.0, 0, 0 });
		Circle{ (100 + p1 * 600), 200, 20 }.draw(ColorF{ 0, 1.0, 0 });
		Circle{ (100 + p2 * 600), 300, 20 }.draw(ColorF{ 0, 0, 1.0 });
		Circle{ (100 + p3 * 600), 400, 20 }.draw(ColorF{ 0.5, 0.5, 0.5 });
		Circle{ (100 + p4 * 600), 500, 20 }.draw(ColorF{ 0.5, 0.0, 0.5 });
	}
}
//イージング
void easing_functions() {
	/*
	イージングの効果一覧
	https://easings.net/
	*/

	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	// スタート位置
	Vec2 from{ 100, 100 };

	// ゴール位置
	Vec2 to{ 700, 500 };

	Stopwatch stopwatch{ StartImmediately::Yes };

	while (System::Update())
	{
		// 移動の割合 0.0～1.0
		const double t = Min(stopwatch.sF(), 1.0);

		// イージング関数を適用
		const double e = EaseInOutExpo(t);

		// スタート位置からゴール位置へ e の割合だけ進んだ位置
		const Vec2 pos = from.lerp(to, e);

		if (MouseL.down())
		{
			// スタート位置を現在の位置に
			from = pos;

			// ゴール位置をマウスカーソルの位置に
			to = Cursor::Pos();

			stopwatch.restart();
		}

		pos.asCircle(40).draw(ColorF{ 0.2 });
		to.asCircle(50).drawFrame(5, ColorF{ 0.2 });
	}
}
//SmoothDamp
void smooth_damp() {
	/*
	Vec2 Math::SmoothDamp(const Vec2& from, const Vec2& to, Vec2& velocity, double smoothTime, const Optional<double>& maxSpeed = unspecified, double deltaTime = Scene::DeltaTime());`
	from:			現在位置
	to:				目標位置
	velocity:		現在の速度（速度を保存している変数を参照で渡す）
	smoothTime:		平滑化時間（最大速度で目標に向かうときに期待される所要時間）。動く目標を追いかけるときの遅延時間で、小さいと目標に早く到達する
	maxSpeed:		最大速度。無制限の場合は unspecified を指定する
	deltaTime:		前回からの経過時間（デフォルトは Scene::DeltaTime()）
	戻り値:			次の位置
	*/


	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	// 現在位置
	Vec2 currentPos{ 100, 100 };

	// 移動速度
	Vec2 velocity{ 0, 0 };

	while (System::Update())
	{
		// 目標位置
		const Vec2 targetPos = Cursor::Pos();

		currentPos = Math::SmoothDamp(currentPos, targetPos, velocity, 0.5);

		currentPos.asCircle(40).draw(ColorF{ 0.2 });

		targetPos.asCircle(50).drawFrame(4, ColorF{ 0.2 });
	}
}
//アプリケーションの起動時間の取得
void timer_app_start_time() {
	/*
	Time::GetSec()			アプリケーションの起動からの経過時間を秒単位で返す
	Time::GetMillisec()		アプリケーションの起動からの経過時間をミリ秒単位で返す
	Time::GetMicrosec()		アプリケーションの起動からの経過時間をマイクロ秒単位で返す
	Time::GetNanosec()		アプリケーションの起動からの経過時間をナノ秒単位で返す
	*/
	while (System::Update())
	{
		ClearPrint();
		Print << Time::GetSec();
		Print << Time::GetMillisec();
		Print << Time::GetMicrosec();
		Print << Time::GetNanosec();
	}
}
// UNIX 時間の取得
void unix_time() {
	/*
	Time::GetSecSinceEpoch()			現在の UNIX 時間を秒単位で返す
	Time::GetMillisecSinceEpoch()		現在の UNIX 時間をミリ秒単位で返す
	Time::GetMicrosecSinceEpoch()		現在の UNIX 時間をマイクロ秒単位で返す
	*/
	while (System::Update())
	{
		ClearPrint();
		Print << Time::GetSecSinceEpoch();
		Print << Time::GetMillisecSinceEpoch();
		Print << Time::GetMicrosecSinceEpoch();
	}
}
//日付と時刻クラス
void date_time_class() {
	/*
	時間型の値を使って加減算ができます
	DateTime::Now() は現在の日付と時刻を DateTime 型で返します
	*/

	// 現在の日付と時刻を取得
	const DateTime t = DateTime::Now();
	Print << t;
	Print << t.year;
	Print << t.month;
	Print << t.day;
	Print << t.hour;
	Print << t.minute;
	Print << t.second;
	Print << t.milliseconds;

	// 30 分前
	Print << (t - 30min);

	// 来週
	Print << (t + 7_d);

	// 2030 年まであと
	const Duration s = (DateTime{ 2030, 1, 1 } - t);
	Print << s;
	Print << DaysF{ s };
	Print << DurationCast<Days>(s);

	while (System::Update())
	{

	}
}
//時差の取得
void timezone_offset() {
	Print << Time::UTCOffsetMinutes();

	while (System::Update())
	{

	}
}

void test() {
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	// スタート位置
	Vec2 from{ 100, 100 };

	// ゴール位置
	Vec2 to{ 700, 500 };

	Stopwatch stopwatch{ StartImmediately::Yes };

	while (System::Update())
	{
		// 移動の割合 0.0～1.0
		const double t = Min(stopwatch.sF(), 1.0);

		// イージング関数を適用
		const double e = EaseInOutExpo(t);

		// スタート位置からゴール位置へ e の割合だけ進んだ位置
		const Vec2 pos = from.lerp(to, e);

		
		{
			// スタート位置を現在の位置に
			from = pos;

			// ゴール位置をマウスカーソルの位置に
			to = Cursor::Pos();

			stopwatch.restart();
		}

		pos.asCircle(40).draw(ColorF{ 0.2 });
		to.asCircle(50).drawFrame(5, ColorF{ 0.2 });
	}
}
void Main()
{
	///* 経過時間の蓄積 */elapsedtime_sum();
	///* 時間に基づくモーション */motion();
	///* 一定時間おきに何かをする */interval_action();
	///* 一定時間おきに何かをする（イベント周期が短い：1フレームの時間より短い） */interval_action2();
	///* ストップウォッチ */stopwatch();
	///* 時間型 */time_type();
	//* タイマー */timer_class();
	///* 時間の比較 */time_comparison();
	///* 周期的なモーション */periodic_motion();
	///* イージング */easing_functions();
	///* SmoothDamp */smooth_damp();
	///* アプリケーションの起動時間の取得 */timer_app_start_time();
	///* UNIX 時間の取得 */unix_time();
	///* 日付と時刻クラス */date_time_class();
	/* 時差の取得 */timezone_offset();
	//test();
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

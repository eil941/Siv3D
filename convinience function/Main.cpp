# include <Siv3D.hpp>

//https://siv3d.github.io/ja-jp/tutorial2/utility/



//角度の正規化
void Angle_Normalization() {
	const double a = (Scene::Time() * -90_deg);
	const double b = (Scene::Time() * 90_deg);

	ClearPrint();

	Print << U"角度の正規化";
	Print << a;
	// 角度を [0.0, 2π) の範囲に正規化した値を返す
	Print << Math::NormalizeAngle(a);
	// 角度を [-π, π) の範囲に正規化した値を返す
	Print << Math::NormalizeAngle(a, 0.0);

	Print << U"----";

	Print << b;
	// 角度を [0.0, 2π) の範囲に正規化した値を返す
	Print << Math::NormalizeAngle(b);
	// 角度を [-π, π) の範囲に正規化した値を返す
	Print << Math::NormalizeAngle(b, 0.0);
}


void Main()
{

	//最小値・最大値
	Print << U"最小値・最大値";
	Print << Min(10, 20);
	Print << Max(10, 20);

	Print << Min(12.3, 45.6);
	Print << Max(12.3, 45.6);

	String s = U"Hello";
	Print << Min<size_t>(s.size(), 4);
	Print << Max<size_t>(s.size(), 4);

	//指定した範囲に収める
	Print << U"指定範囲に収める";
	Print << Clamp(-20, 0, 100);
	Print << Clamp(50, 0, 100);
	Print << Clamp(120, 0, 100);


	//範囲内にあるか判定
	Print << U"範囲内にあるか判定";
	Print << InRange(50, 0, 100);
	Print << InRange(120, 0, 100);

	//奇数・偶数の判定
	Print << U"奇数・偶数の判定";
	Print << IsOdd(3);
	Print << IsOdd(4);
	Print << IsEven(3);
	Print << IsEven(4);

	//絶対値
	Print << U"絶対値";
	Print << Abs(-10);
	Print << Abs(10);
	Print << Abs(-3.14);
	Print << Abs(3.14);
	//差の絶対値
	Print << AbsDiff(10, 20);
	Print << AbsDiff(20, 10);
	Print << AbsDiff(3.14, 2.71);
	Print << AbsDiff(2.71, 3.14);

	//インデックス付き範囲for文
	Print << U"インデックス付き範囲for文";
	const Array<String> animals = { U"cat", U"dog", U"bird" };

	for (auto&& [i, animal] : Indexed(animals))
	{
		Print << U"{}: {}"_fmt(i, animal);
	}

	//インデックス付き範囲 for 文（参照）
	Print << U"インデックス付き範囲 for 文（参照）";
	Array<int32> numbers = { 10, 20, 30 };

	for (auto&& [i, number] : IndexedRef(numbers))
	{
		number += i;
	}

	for (const auto& number : numbers)
	{
		Print << number;
	}

	//ループの短縮記述
	Print << U"ループの短縮記述";
	for (auto i : step(3))
	{
		Print << i;
	}
	Print << U"---";
	for (auto i : Range(5, 10))
	{
		Print << i;
	}

	//文字列の性質
	/*
	bool IsASCII(char32)	ASCII 文字であるかを返す
	bool IsDigit(char32)	10 進数の数字であるかを返す
	bool IsLower(char32)	アルファベットの小文字であるかを返す
	bool IsUpper(char32)	アルファベットの大文字であるかを返す
	bool IsAlpha(char32)	文字がアルファベットであるかを返す
	bool IsAlnum(char32)	文字がアルファベットもしくは数字であるかを返す
	bool IsXdigit(char32)	文字が 16 進数の数字であるかを返す
	bool IsControl(char32)	文字が制御文字であるかを返す
	bool IsBlank(char32)	文字が空白文字 (' ', '\t', および全角空白) であるかを返す
	bool IsSpace(char32)	文字が空白類文字 (' ', '\t', '\n', '\v', '\f', '\r', および全角空白) であるかを返す
	bool IsPrint(char32)	文字が印字可能文字であるかを返す
	char32 ToLower(char32)	アルファベットの大文字を小文字にする
	char32 ToUpper(char32)	アルファベットの小文字を大文字にする
	*/
	Print << U"文字列の性質";
	Print << IsASCII(U'A') << U' ' << IsASCII(U'あ');
	Print << IsUpper(U'A') << U' ' << IsUpper(U'a');
	Print << IsAlnum(U'4') << U' ' << IsAlnum(U'#');
	Print << IsSpace(U' ') << U' ' << IsSpace(U'-');
	Print << ToLower(U'A') << U' ' << ToUpper(U'a');

	//数学定数
	/*
	* double型
	Math::E	自然対数の底	2.718281828459045235360287471352662498
	Math::Log2E	2 を底とする e の対数	1.442695040888963407359924681001892137
	Math::Log10E	10 を底とする e の対数	0.434294481903251827651128918916605082
	Math::Pi	π（円周率）	3.141592653589793238462643383279502884
	Math::QuarterPi	π/4	0.785398163397448309615660845819875721
	Math::OneThirdPi	π/3	1.047197551196597746154214461093167628
	Math::HalfPi	π/2	1.570796326794896619231321691639751442
	Math::TwoPi	2π	6.283185307179586476925286766559005768	
	Math::Tau	τ（2π）	6.283185307179586476925286766559005768
	Math::InvTwoPi	1/(2π)	0.159154943091895335768883763372514362
	Math::InvPi	1/π	0.318309886183790671537767526745028724	
	Math::InvSqrtPi	1/√π	0.564189583547756286948079451560772586
	Math::Ln2	2 の自然対数	0.693147180559945309417232121458176568
	Math::Ln10	10 の自然対数	2.302585092994045684017991454684364208
	Math::Sqrt2	√2	1.414213562373095048801688724209698078
	Math::Sqrt3	√3	1.732050807568877293527446341505872366
	Math::InvSqrt2	1/√2	0.707106781186547524400844362104849039
	Math::InvSqrt3	1/√3	0.577350269189625764509148780501957456
	Math::EGamma	オイラーの定数	0.577215664901532860606512090082402431
	Math::Phi	黄金数 (φ)	1.618033988749894848204586834365638117
	Math::QNaN	Quiet NaN	QNaN
	Math::NaN	Signaling NaN	SNaN
	Math::Inf	Inf	Inf

	* float型
	Math::PiF	π（円周率）	3.141592653589793238462643383279502884
	Math::QuarterPiF	π/4	0.785398163397448309615660845819875721
	Math::OneThirdPiF	π/3	1.047197551196597746154214461093167628
	Math::HalfPiF	π/2	1.570796326794896619231321691639751442
	Math::TwoPiF	2π	6.283185307179586476925286766559005768
	Math::TauF	τ（2π）	6.283185307179586476925286766559005768
	Math::InvTwoPiF	1/(2π)	0.159154943091895335768883763372514362
	Math::InvPiF	1/π	0.318309886183790671537767526745028724
	Math::InvSqrtPiF	1/√π	0.564189583547756286948079451560772586
	Math::QNaNF	Quiet NaN	QNaN
	Math::NaNF	Signaling NaN	SNaN
	Math::InfF	Inf	Inf
	*/

	Print << U"数学定数";
	// 円周率
	Print << Math::Pi;

	// 黄金比
	Print << Math::Phi;

	// NaN
	Print << Math::QNaN;

	//角度の表現
	/*
	_deg	度数法	Math::Pi / 180.0
	_pi		π		Math::Pi
	_tau	τ		Math::TwoPi
	*/
	Print << U"角度の表現";
	Print << U"{}"_fmt(180_deg);
	Print << U"{}"_fmt(1_pi);
	Print << U"{}"_fmt(0.5_tau);

	//ラジアンと度数法の変換
	Print << U"ラジアンと度数法の変換";
	const double angle = 45_deg;

	Print << angle;
	Print << Math::ToDegrees(angle);
	Print << Math::ToRadians(Math::ToDegrees(angle));

	//列挙型から整数への変換
	Print << U"列挙型から整数への変換";
	enum class State
	{
		Menu,
		Game,
		Result
	};
	State state = State::Game;
	const int32 n = FromEnum(state);
	Print << n;

	//エラー
	Print << U"エラー処理";
	/*const Texture texture{U"aaa.png"};

	if (not texture)
	{
		// 例外を送出する
		throw Error{ U"Failed to load `aaa.png`" };
	}
	*/

	//コマンドライン引数の取得
	Print << U"コマンドライン引数の取得";
	const Array<String> commands = System::GetCommandLineArgs();

	for (const auto& command : commands)
	{
		Print << command;
	}

	//コンソール出力
	Print << U"コンソール出力";
	Array<int32> v = { 10,20,30,40,50 };

	Print << v;

	// コンソール出力
	Console << v;
	Console << U"Hello, Siv3D!";

	//ログ出力
	Print << U"ログ出力";
	Array<int32> vl = { 10,20,30,40,50 };

	Print << vl;

	// ログ出力
	Logger << vl;

	Logger << U"Hello, Siv3D!";

	while (System::Update())
	{
		//角度の正規化
		//Angle_Normalization();
	}
}

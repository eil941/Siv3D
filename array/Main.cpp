# include <Siv3D.hpp> // Siv3D v0.6.16

/*************************************************************
Siv3D では Array<Type> で動的配列を扱います
Array は std::vector と同等の機能を提供するほか、追加のメンバ関数を持ちます
std::vector のように要素がメモリ上に連続していることが保証されています

//int32 型の値を格納する配列
Array<int32> a = { 10, 20, 30, 40, 50 };

// double 型の値を格納する配列
Array<double> b = { 1.1, 2.2, 3.3, 4.4, 5.5 };

// String 型の値を格納する配列
Array<String> c = { U"Apple", U"Bird", U"Cat", U"Dog" };
*************************************************************/

void Main()
{
	// パターン ①: 空の配列を作成
	{
		Array<int32> v;
		Print << v;
		Print << U"Size: " << v.size();
		Print << U"IsEmpty: " << v.isEmpty();
		//末尾に追加
		v.push_back(100);
		Print << v;
		v << 200;
		Print << v;
		//末尾の要素を削除
		v.pop_back();
		Print << v;
	}
	Print << U"------------------------------";
	// パターン ②: リストから配列を作成
	{
		Array<int32> v = { 10, 50, 30, 20, 40 };
		Print << v;
		Print << U"Size: " << v.size();
		Print << U"IsEmpty: " << v.isEmpty();

		//全ての要素を削除
		v.clear();
		Print << v;
	}
	Print << U"------------------------------";
	// パターン ③: 個数 × 値 で配列を作成
	{
		Array<int32> v(7, -5);
		Print << v;
		Print << U"Size: " << v.size();
		Print << U"IsEmpty: " << v.isEmpty();

		//要素数の変更
		v.resize(3);
		Print << v;
		v.resize(5);
		Print << v;

		//指定したインデックスの要素へのアクセス
		Print << v[0];
		Print << v[4];
		v[1] = 500;
		Print << v;

		//先頭・末尾の要素へのアクセス
		Print << v.front();
		Print << v.back();

		v.front() = 100;
		v.back() = 400;
		Print << v;

	}
	Print << U"------------------------------";
	// パターン ④: 個数 × デフォルト値で配列を作成
	{
		Array<int32> v(9);
		Print << v;
		Print << U"Size: " << v.size();
		Print << U"IsEmpty: " << v.isEmpty();
	}

	Print << U"------------------------------";
	//先頭・終端位置のイテレータ取得
	Array<int32> v = { 10, 50, 30, 20, 40 };
	Print << v;
	auto it = v.begin();
	Print << *it;
	++it;
	Print << *it;


	for (const auto& elem : v)
	{
		//Print << elem;
	}


	{
		Array<int32> v = { 10, 20, 30, 40, 50 };

		v.push_front(5);
		Print << v;

		v.pop_front();
		Print << v;
	}


	//その他の挿入・削除操作
	/*
	.push_front(値) で、先頭に要素を追加します
	.pop_front() で、先頭の要素を削除します
	.insert(イテレータ, 値) で、指定したイテレータの位置に要素を挿入します
	.append(配列) で、別の配列を末尾に追加します
	.erase(イテレータ) で、指定したイテレータの位置の要素を削除します
	.erase(イテレータ1, イテレータ2) で、指定した範囲の要素を削除します
	.先頭や途中への要素の挿入・削除は、それ以降の既存要素の移動を伴うため、うしろの要素数に比例したコストがかかります
		通常は避けるか、小さい配列でのみ使用するべきです

	*/
	{
		//insert 
		Array<int32> v = { 10, 20, 30, 40, 50 };

		v.insert((v.begin() + 2), 25);
		Print << v;
	}

	{
		//append
		Array<int32> v1 = { 10, 20, 30 };
		Array<int32> v2 = { 40, 50 };

		v1.append(v2);
		Print << v1;
	}

	{
		//erase
		Array<int32> v = { 10, 20, 30, 40, 50 };

		v.erase(v.begin() + 2);
		Print << v;

		v.erase(v.begin(), (v.begin() + 2));
		Print << v;
	}

	//条件を満たす要素の削除（イテレータ方式）
	v = { 10, 50, 30, 20, 40 };
	Print << U"------------------------------";
	Print << v;
	for (auto it = v.begin(); it != v.end();)
	{
		if (*it < 30)
		{
			it = v.erase(it);
		}
		else
		{
			++it;
		}
	}

	Print << v;



	//条件を満たす要素の削除（.remove_if() 方式）
	{
		Print << U"------------------------------";
		Array<int32> v = { 11, 22, 33, 44, 55 };

		Print << v;
		// 偶数の要素を削除する
		v.remove_if(IsEven);

		Print << v;
	}

	{
		Print << U"------------------------------";
		Array<int32> v = { 10, 50, 30, 20, 40 };
		Print << v;
		// 30 未満の要素を削除する
		v.remove_if([](int32 x) { return x < 30; });

		Print << v;
	}

	//配列のソート
	{
		Print << U"------------------------------";
		Array<int32> v = { 10, 50, 30, 20, 40 };

		Print << v;
		// 昇順にソート
		v.sort();
		Print << v;
	}

	{
		Print << U"------------------------------";
		Array<String> v = { U"Bird", U"Dog", U"Apple", U"Cat" };

		Print << v;
		// 降順にソート
		v.rsort();
		Print << v;
	}

	
	{
		Print << U"------------------------------";
		Array<int32> v = { 10, 50, 30, 20, 40 };
		Print << v;
		//配列の逆順
		v.reverse();
		Print << v;

		//配列の要素のシャッフル
		v.shuffle();
		Print << v;

		//配列の要素の合計
		Print << v.sum();

		//すべての要素に同じ値を代入
		v.fill(100);
		Print << v;

	}

	//すべての要素に関数を適用した結果の取得
	{
		Print << U"-----------------------------------";
		Array<int32> v1 = { 10, 50, 30, 20, 40 };

		Array<double> v2 = v1.map([](int32 x) { return (x * 1.01); });

		Print << v2;

	}

	while (System::Update())
	{

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

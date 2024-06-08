#pragma once

#include "MyString.h"
#include "MyArray.h"
#include "MyVector.h"

void TestString()
{
	using namespace mystd;
	using namespace std;

	cout << "--------------STRING--------------" << endl;
	String bad(nullptr);

	String a;
	cout << a << endl;

	String b("some text");
	cout << b << endl;

	String c(b);
	cout << c << endl;

	String d = (move(String("temp object")));
	cout << d << endl;

	d[0] = 'z';
	d[3] = 'z';
	for (size_t i = 0; i < d.Size(); i++)
	{
		cout << d[i];
	}
	cout << endl;

	const auto& ref = d;
	cout << "FIRST: " << ref.First() << "----" << "LAST: " << ref.Last() << endl;
	for (size_t i = 0; i < ref.Size(); i++)
	{
		cout << ref[i];
	}
	cout << endl;
	for (size_t i = 0; i < ref.Size(); i++)
	{
		cout << ref.At(i);
	}
	cout << endl;

	a = nullptr;
	cout << (a.IsEmpty() ? "YES" : "NO") << endl;
	a = "some text";
	cout << (a.IsEmpty() ? "YES" : "NO") << endl;
	a = "some other text";
	cout << a << endl;

	String e;
	e = e;
	e = a;
	e = b;
	cout << e << endl;


	String f;
	f = move(f);
	f = move(String("something"));
	f = move(String("moved again"));
	cout << f << endl;
	cout << (f.IsEmpty() ? "YES" : "NO") << endl;
	f.Clear();
	cout << (f.IsEmpty() ? "YES" : "NO") << endl;
	cout << f << endl;

	String s1, s2, s3, s4;

	/*cin >> s1;
	cout << s1 << endl;

	cin >> s2;
	cout << s2 << endl;

	cout << (s1 == s2 ? "SAME!" : "NOT SAME") << endl;

	cin >> s3;
	cout << s3 << endl;

	cin >> s4;
	cout << s4 << endl;

	cout << (s3 != s4 ? "NOT SAME!" : "SAME") << endl;*/

	cout << "----------------------------------" << endl;
}

void TestArray()
{
	using namespace mystd;
	using namespace std;

	cout << "--------------ARRAY!--------------" << endl;
	Array<int, 10> a1;
	for (size_t i = 0; i < a1.Size(); i++)
	{
		a1[i] = (int)i + 1;
	}
	int& ref1 = a1[0];
	ref1 = -99;
	int& ref2 = a1.Last();
	ref2 = -99;
	int& ref3 = a1.At(4);
	ref3 = -99;

	cout << a1 << endl;
	int a = 5;

	ref1 = 1;
	ref2 = 10;
	ref3 = 5;

	Array<int, 10> a2;
	for (size_t i = 0; i < a1.Size(); i++)
	{
		a2[i] = (int)i + 1;
	}
	cout << (a1 == a2 ? "SAME" : "NOT SAME") << endl;
	cout << a1 << endl << a2 << endl;
	int& ref4 = a2.First();
	ref4 = 15;

	cout << (a1 != a2 ? "NOT SAME" : "SAME") << endl;
	cout << a1 << endl << a2 << endl;

	Array<String, 10> a3;
	for (size_t i = 0; i < a1.Size(); i++)
	{
		a3[i] = "Array!";
	}
	cout << a3 << endl;
	a3[4] = "Hello World!";
	cout << a3 << endl;

	auto a4(a3);
	cout << (a3 == a4 ? "SAME" : "NOT SAME") << endl;

	a1[0] = 2500;
	Array<int, 10> a5;
	a5 = a1;
	cout << a5 << std::endl;
	cout << "----------------------------------" << endl;
}

void TestVector()
{
	using namespace mystd;
	using namespace std;

	cout << "--------------VECTOR--------------" << endl;
	Vector<int> v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.PushBack((int)i + 1);
	}
	int& ref1 = v1[0];
	ref1 = -99;
	int& ref2 = v1.Last();
	ref2 = -99;
	int& ref3 = v1.At(4);
	ref3 = -99;

	cout << v1 << endl;
	int a = 5;

	ref1 = 1;
	ref2 = 10;
	ref3 = 5;

	Vector<int> v2;
	for (size_t i = 0; i < 10; i++)
	{
		v2.PushBack((int)i + 1);
	}
	cout << (v1 == v2 ? "SAME" : "NOT SAME") << endl;
	cout << v1 << endl << v2 << endl;
	int& ref4 = v2.First();
	ref4 = 15;

	cout << (v1 != v2 ? "NOT SAME" : "SAME") << endl;
	cout << v1 << endl << v2 << endl;

	Vector<String> v3;
	for (size_t i = 0; i < v1.Size(); i++)
	{
		v3.PushBack("Array!");
	}
	cout << v3 << endl;
	v3[4] = "Hello World!";
	cout << v3 << endl;

	cout << v3.Size() << " " << v3.Capacity() << endl;

	{
		Vector<String> v4(10);
		for (size_t i = 0; i < 15; i++)
		{
			v4.PushBack("Some Text");
		}
		cout << v4 << endl;
	}

	cout << v3 << endl;
	v3.Clear();
	v3.PushBack("Marko Car");
	v3.PushBack("Najveci");
	cout << v3 << endl;

	cout << "----------------------------------" << endl;
}
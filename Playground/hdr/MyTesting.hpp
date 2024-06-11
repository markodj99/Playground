#pragma once

#include "MyString.hpp"
#include "MyArray.hpp"
#include "MyVector.hpp"
#include "MyList.hpp"
#include "MyScopetPtr.hpp"
#include "MyTimer.hpp"

#include <string>
#include <cmath>

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

void TestList()
{
	using namespace mystd;
	using namespace std;

	cout << "---------------LIST---------------" << endl;
	List<int> l1;

	l1.PushFront(1);
	l1.PushFront(2);
	l1.PushFront(3);
	l1.PushFront(4);
	l1.PushFront(5);
	l1.InsertAt(-99, -1);
	l1.InsertAt(-99, 100);
	l1.InsertAt(88, 0);
	l1.InsertAt(88, 7);
	l1.InsertAt(88, 3);
	l1.PopFront();
	l1.PopBack();
	l1.DeleteAt(2);
	l1.DeleteAt(-1);
	l1.DeleteAt(100);
	l1.DeleteAt(0);
	l1.DeleteAt(4);

	cout << l1 << endl;

	List<int> l2;

	l2.PushBack(1);
	l2.PushBack(2);
	l2.PushBack(3);
	l2.PushBack(4);
	l2.PushBack(5);
	l2.InsertAt(-99, -1);
	l2.InsertAt(-99, 100);
	l2.InsertAt(88, 0);
	l2.InsertAt(88, 7);
	l2.InsertAt(88, 3);
	l2.PopFront();
	l2.PopBack();
	l2.DeleteAt(2);
	l2.DeleteAt(-1);
	l2.DeleteAt(100);
	l2.DeleteAt(0);
	l2.DeleteAt(4);

	List<int>& ref = l2;

	const int* const constFirstt = ref.First();
	const int* const constLastt = ref.Last();
	const int* const constFifthh = ref.At(5);
	const int* const constSecondd = ref.At(1);

	int* firstt = l2.First();
	int* lastt = l2.Last();
	int* fifthh = l2.At(5);
	int* secondd = l2.At(1);
	*firstt = 1;
	*lastt = 3;
	*secondd = 2;

	cout << l2 << endl;

	List<int> l3;
	int* first = l3.First();
	int* last = l3.Last();
	int* fifth = l3.At(5);

	const List<int>& l4 = l3;
	const int* const constFirst = l4.First();
	const int* const constLast = l4.Last();
	const int* const constFifth = l4.At(5);

	l2.Clear();
	l3.Clear();

	cout << "l2: " << l2 << endl;
	cout << "l3: " << l3 << endl;

	l2.PushBack(1);
	l2.PushBack(2);
	l2.PushBack(3);
	l2.PushBack(4);
	l2.PushBack(5);

	l3.PushBack(1);
	l3.PushBack(2);
	l3.PushBack(3);
	l3.PushBack(4);
	l3.PushBack(5);

	cout << (l2 == l3 ? "SAME" : "NOT SAME") << endl;

	int* fourth = l3.At(3);
	*fourth = 15;

	cout << (l2 != l3 ? "NOT SAME" : "SAME") << endl;

	cout << "l2: " << l2 << endl;
	cout << "l3: " << l3 << endl;

	List<String> ls;
	ls.PushBack("marko");
	ls.PushBack("loves");
	ls.PushBack("to");
	ls.PushBack("play");
	ls.PushBack("billiard");

	cout << ls << endl;

	auto head = ls.GetHead();
	for (auto el = head; el != nullptr; el = el->next)
	{
		cout << el->data << " ";
	}
	cout << endl;

	auto tail = ls.GetTail();
	for (auto el = tail; el != nullptr; el = el->prev)
	{
		cout << el->data << " ";
	}
	cout << endl;

	List<String>& refToLs = ls;

	auto constHead = refToLs.GetHead();
	for (auto el = constHead; el != nullptr; el = el->next)
	{
		cout << el->data << " ";
	}
	cout << endl;

	auto constTail = refToLs.GetTail();
	for (auto el = constTail; el != nullptr; el = el->prev)
	{
		cout << el->data << " ";
	}
	cout << endl;
	cout << "----------------------------------" << endl;
}

void TestScopedPtr()
{
	using namespace mystd;
	using namespace std;

	cout << "------------SCOPERDPTR-------------" << endl;
	ScopedPtr<String> sp;
	sp = new String("test");
    sp->operator[](3) = 'T';
	cout << sp << endl;

	ScopedPtr<int> sp1 = new int;

	int* ptr = sp1.Get();
	*ptr = 5;
	cout << sp1 << endl;

	ScopedPtr<int>& ref = sp1;
	auto ptrRef = ref.Get();
	*ptrRef = 0;
	cout << sp1 << endl;
	*sp1 = 15;
	cout << sp1 << endl;

	if (sp1)
	{
		cout << "if " << sp1 << endl;
	}

	ScopedPtr<String> sp2 = new String("Marko Marko");
	cout << sp2 << endl;
	cout << "size: " << sp2->Size() << endl;
	(*sp2)[1] = 'A';
	cout << sp2 << endl;

	ScopedPtr<string> stdString = new string("marko");
	cout << stdString << endl;
	stdString->operator[](1) = 'A';
	cout << stdString << endl;

	cout << "-----------------------------------" << endl;
}

void TestTimer()
{
	using namespace mystd;
	using namespace std;

	cout << "---------------TIMER---------------" << endl;

	{
		Timer t("TIMER_1");
		Vector<String> v;
		for (size_t i = 0; i < 10000000; i++)
		{
			v.PushBack(to_string(sqrt(i) * pow(i, 1 / 3)).c_str());
		}
	}
	{
		Timer t("TIMER_2");
		Vector<String> v(10000000);
		for (size_t i = 0; i < 10000000; i++)
		{
			v.PushBack(to_string(i * 2).c_str());
		}
	}
	cout << "-----------------------------------" << endl;
}

void Test()
{
	using namespace std;

	TestString();
	cout << endl;

	TestArray();
	cout << endl;

	TestVector();
	cout << endl;

	TestList();
	cout << endl;

	TestScopedPtr();
	cout << endl;

	TestTimer();
	cout << endl;
}
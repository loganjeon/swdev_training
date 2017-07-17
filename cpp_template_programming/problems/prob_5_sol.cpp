
/*-----------------------------------------------------------------------------
 * ���� 5. TypeList �����
 * 1~3�� TypeList ������ �� �а�, ������ �ذ��� ������. ������ ������ �κп� ����˴ϴ�.
 *
 * ����. �Ʒ� �ڵ尡 ����ǵ��� TypeAt, IndexOf, Erase, Replace �� ����� ������
 * int main()
 * {
 *	 typedef MakeTypelist<int, char, double, short>::Result myType;
 *	 // (1) TypeAt : N��° Ÿ���� ���� Ÿ������ �˾Ƴ��� ���ø� �Դϴ�.
 *	 TypeAt<myType, 1>::Result n; // n�� char Ÿ���̾�� �մϴ�.
 *	 // (2) IndexOf : Ư�� Ÿ���� ���° �ִ��� ã�� ���� ���ø��Դϴ�.
 *	 cout << IndexOf<myType, double>::value << endl; // 2�� ���;� �մϴ�.
 *	 // (3) Erase : Ư�� Ÿ���� ������ ���ο� TypeList �����
 *	 //���� �߰ߵȰ� �ϳ��� ����
 *	 typedef Erase<myType, char>::Result myType2;
 *	 cout << typeid(myType2).name() << endl; // int, double, short �� TypeList�Դϴ�.
 *	 // (4) Replace : Ư�� Ÿ���� �ٸ� Ÿ������ ��ü�� TypeList �����
 *	 typedef Replace<myType, char, float>::Result myType3;
 *	 cout << typeid(myType3).name() << endl; // int, float, double, short
 *	 }
 * } 
 *-----------------------------------------------------------------------------*/

#include <iostream>
#include <typeinfo>
using namespace std;

// ���� 5. typelist �����


// TypeList �� "Modern C++ Design" å�� ������ "Andrei Alexandrescu" �� ���� "loki" ���̺귯���� �ִ� �ڵ� �Դϴ�.

// ���� "face book"�� ���� �����Ͼ�μ� ���̽����� ����ϴ� "C++���̺귯��"�� ���� ������ �Դϴ�.


// TypeList�� ��ü �ڵ�� https://sourceforge.net/projects/loki-lib/files/Loki/  ���� ������ �ֽ��ϴ�.

struct NullType {};

template <class T, class U>
struct Typelist
{
	typedef T Head;
	typedef U Tail;
};

template
<
	typename T1 = NullType, typename T2 = NullType, typename T3 = NullType,
	typename T4 = NullType, typename T5 = NullType, typename T6 = NullType,
	typename T7 = NullType, typename T8 = NullType, typename T9 = NullType,
	typename T10 = NullType, typename T11 = NullType, typename T12 = NullType,
	typename T13 = NullType, typename T14 = NullType, typename T15 = NullType,
	typename T16 = NullType, typename T17 = NullType, typename T18 = NullType
>
struct MakeTypelist
{
private:
	typedef typename MakeTypelist
		<
		T2, T3, T4,
		T5, T6, T7,
		T8, T9, T10,
		T11, T12, T13,
		T14, T15, T16,
		T17, T18
		>
		::Result TailResult;

public:
	typedef Typelist<T1, TailResult> Result;
};

template<> struct MakeTypelist<>
{
	typedef NullType Result;
};


// Length
template <class TList> struct Length;
template <> struct Length<NullType>
{
	enum { value = 0 };
};

template <class T, class U>
struct Length< Typelist<T, U> >
{
	enum { value = 1 + Length<U>::value };
};


// TypeAt
template <class TList, unsigned int index> struct TypeAt;

template <class Head, class Tail>
struct TypeAt<Typelist<Head, Tail>, 0>
{
	typedef Head Result;
};

template <class Head, class Tail, unsigned int i>
struct TypeAt<Typelist<Head, Tail>, i>
{
	typedef typename TypeAt<Tail, i - 1>::Result Result;
};


// IndexOf
template <class TList, class T> struct IndexOf;

template <class T>
struct IndexOf<NullType, T>
{
	enum { value = -1 };
};

template <class T, class Tail>
struct IndexOf<Typelist<T, Tail>, T>
{
	enum { value = 0 };
};

template <class Head, class Tail, class T>
struct IndexOf<Typelist<Head, Tail>, T>
{
private:
	enum { temp = IndexOf<Tail, T>::value };
public:
	enum { value = (temp == -1 ? -1 : 1 + temp) };
};


// Append
template <class TList, class T> struct Append;

template <> struct Append<NullType, NullType>
{
	typedef NullType Result;
};

template <class T> struct Append<NullType, T>
{
	typedef Typelist<T, NullType> Result;
};

template <class Head, class Tail>
struct Append<NullType, Typelist<Head, Tail> >
{
	typedef Typelist<Head, Tail> Result;
};

template <class Head, class Tail, class T>
struct Append<Typelist<Head, Tail>, T>
{
	typedef Typelist<Head,
		typename Append<Tail, T>::Result>
		Result;
};


// Erase
template <class TList, class T> struct Erase;

template <class T>                         // Specialization 1
struct Erase<NullType, T>
{
	typedef NullType Result;
};

template <class T, class Tail>             // Specialization 2
struct Erase<Typelist<T, Tail>, T>
{
	typedef Tail Result;
};

template <class Head, class Tail, class T> // Specialization 3
struct Erase<Typelist<Head, Tail>, T>
{
	typedef Typelist<Head,
		typename Erase<Tail, T>::Result>
		Result;
};


// Replace
template <class TList, class T, class U> struct Replace;

template <class T, class U>
struct Replace<NullType, T, U>
{
	typedef NullType Result;
};

template <class T, class Tail, class U>
struct Replace<Typelist<T, Tail>, T, U>
{
	typedef Typelist<U, Tail> Result;
};

template <class Head, class Tail, class T, class U>
struct Replace<Typelist<Head, Tail>, T, U>
{
	typedef Typelist<Head,
		typename Replace<Tail, T, U>::Result>
		Result;
};

int main()
{

	typedef MakeTypelist<int, char, double, short>::Result myType;

	// (1) TypeAt : N��° Ÿ���� ���� Ÿ������ �˾Ƴ��� ���ø� �Դϴ�.
	TypeAt<myType, 1>::Result  n; // n�� char Ÿ���̾�� �մϴ�.

	// (2) IndexOf : Ư�� Ÿ���� ���° �ִ��� ã�� ���� ���ø��Դϴ�.
	cout << IndexOf<myType, double>::value << endl; // 2�� ���;� �մϴ�.

	// (3) Erase : Ư�� Ÿ���� ������ ���ο� TypeList �����.   ���� �߰ߵȰ� �ϳ��� ����
	typedef Erase<myType, char>::Result myType2;

	cout << typeid(myType2).name() << endl; // int, double, short �� TypeList�Դϴ�.

	// (4) Replace : Ư�� Ÿ���� �ٸ� Ÿ������ ��ü�� TypeList �����
	typedef Replace<myType, char, float>::Result myType3;

	cout << typeid(myType3).name() << endl; // int, float, double, short

}



#include <iostream>
#include <utility>
#include <map>
using namespace std;

template<typename ... Types> void foo()
{
	pair<Types...> p1;	// pair<int, char>
	tuple<Types...> t1;	// tuple<int, char>

	tuple<pair<Types...>> t2;	// tuple<pair<int, char>>
	pair<tuple<Types>...> p2;	// pair<tuple<int>, tuple<char>>

	//tuple<pair<Types>...> t3;	// tuple<pair<int>, pair<char>> error...
	tuple<pair<int, Types>...>t4;	// tuple< pair<int, int>, pair<int, char> >
}

int main()
{
	foo<int, char>();
}

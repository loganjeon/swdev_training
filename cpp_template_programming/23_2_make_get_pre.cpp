
#include <iostream>
#include <tuple>

using namespace std;

struct Base
{
	int value = 10;
};

struct Derived : public Base
{
	int value = 20;

};

int main()
{
	Derived d;
	std::cout << d.value << std::endl; 	// 20
	//std::cout << (static_cast<Base>(d)).value << std::endl;	// 10. 임시객체 생성
	std::cout << (static_cast<Base&>(d)).value << std::endl;	

	//(static_cast<Base>(d)).value = 30;		// error. 임시객체는 lvalue가 될수 없다
	(static_cast<Base&>(d)).value = 30;		// ok.
	std::cout << (static_cast<Base&>(d)).value << std::endl;	
}

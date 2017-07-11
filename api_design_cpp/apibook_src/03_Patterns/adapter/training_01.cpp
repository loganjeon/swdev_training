#include "adapter.h"
#include "original.h"
#include <iostream>

using std::cout;
using std::endl;

Adapter::Adapter() : mOrig(new Original)
{
	cout << "iAllocated new Original object inside Adapter " << endl;
}

Adapter::~Adapter()
{
	delete mOrig;
	cout << "Destroyed Original object inside Adapter" << endl;
}

bool Adapter::DoSomething(int value)
{
	mOrig->DoOperation(value, true);
	return true;
}

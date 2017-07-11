
#include <iostream>
#include <vector>

using namespace std;

template<size_t size>
constexpr size_t arraySize (const int (&arrayRef) [size]) {
	return size;
}

template<typename T>
struct IsArray
{
	static constexpr bool value = false;
	static constexpr int size = -1;
};

template<typename T, int N>
struct IsArray<T[N]>
{
	static constexpr bool value = true;
	static constexpr int size = N;
};

template<typename T>
void foo(const T& a)
{
	if (IsArray<T>::value)
		std::cout << "Array size :" << IsArray<T>::size << std::endl;
	else
		std::cout << "Not Array" << std::endl;
}

template<typename T>
int average(const T& in)
{
	int ret_avg = 0;
	int sum = 0;
	int in_size = 0;
	
	if (IsArray<T>::value)
	{
		std::cout << "Array size :" << IsArray<T>::size << std::endl;
		in_size = IsArray<T>::size;
		
		for (int i = 0; i < in_size; i++)
		{
			sum += in[i];
		}
		ret_avg = sum / in_size;
		
	} else {
		std::cout << "Not Array" << std::endl;
		
		//for ( int i = 0 ; i < in.size(); i++)  // error... why?
		for ( auto i : in)
		{
			sum += i;
			++in_size;
		}
		ret_avg = sum / in_size;
		//ret_avg = sum / in.size();	// error... why?
	}

	return ret_avg;
}

int main()
{
	int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	std::cout << average(x) << std::endl;
	std::cout << average(v) << std::endl;
	//foo(v);

	return 0;
}


/*-----------------------------------------------------------------------------
 * Coding_dojang problem 406.
 * 게시판 페이징
 *
 * A씨는 게시판 프로그램을 작성하고 있다.
 *
 * A씨는 게시물의 총 건수와 한 페이지에 보여줄 게시물수를 입력으로 주었을 때 총 페이지수를 리턴하는 프로그램이 필요하다고 한다.
 *
 * 입력 : 총건수(m), 한페이지에 보여줄 게시물수(n) (단 n은 1보다 크거나 같다. n >= 1)
 * 출력 : 총페이지수
 * A씨가 필요한 프로그램을 작성하시오.
 *
 *-----------------------------------------------------------------------------*/

#include <iostream>

using namespace std;

inline int page(int m, int n) { return m%n>0 ? m/n+1 : m/n; }

int main()
{
    int m = 0, n = 0;
    int num_page = 0;
	
	while(1) {
		cin >> m >> n;
		
		if (m == 0 || n == 0) {
			std::cout << "zero is not proper." << std::endl;
			continue;
		}
		num_page = page(m, n);
		cout << m << " " << n << " " << num_page << endl;
	}

    return 0;
}

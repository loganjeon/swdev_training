
/*-----------------------------------------------------------------------------
 *  Coding_dojang problem 410.
 *  문자열 압축하기
 *
 *  문자열을 입력받아서, 같은 문자가 연속적으로 반복되는 경우에 그 반복 횟수를 표시하여 문자열을 압축하기.
 *
 *  입력 예시: aaabbcccccca
 *
 *  출력 예시: a3b2c6a1
 *-----------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string compress_string(const string &in_str)
{
	int count = 0;
	char prev_char = in_str.at(0);
	stringstream ss;

	if(in_str.length() == 0)
		return "";

	for (auto c : in_str) {
		if (prev_char != c) {
			ss << prev_char << count;
			prev_char = c;
			count = 1;
		} else {
			++count;
		}
	}
	ss << prev_char << count;
	return ss.str();
}


int main()
{
	string org_str = "";
	string compressed_str = "";

	getline(cin, org_str);

	compressed_str = compress_string(org_str);

	cout << compressed_str << endl;
}

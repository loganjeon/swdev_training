
/*-----------------------------------------------------------------------------
 * Coding_dojang problem 410.
 * 사이냅소프트 면접문제
 *
 * 주어진 문자열(공백 없이 쉼표로 구분되어 있음)을 가지고 아래 문제에 대한 프로그램을 작성하세요.
 *
 * 이유덕,이재영,권종표,이재영,박민호,강상희,이재영,김지완,최승혁,이성연,박영서,박민호,전경헌,송정환,김재성,이유덕,전경헌
 * 김씨와 이씨는 각각 몇 명 인가요?
 * "이재영"이란 이름이 몇 번 반복되나요?
 * 중복을 제거한 이름을 출력하세요.
 * 중복을 제거한 이름을 오름차순으로 정렬하여 출력하세요.
 *
 *-----------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string names[] = {"이유덕", "이재영", "권종표", "이재영", "박민호",
		       "강상희", "이재영", "김지완", "최승혁", "이성연",
		       "박영서", "박민호", "전경헌", "송정환", "김재상",
		       "이유덕", "전경헌"};
// problem 1.
int cntKimAndLee(const vector<string>& strs_name)
{
	string f_name = "";
	int cnt = 0;

	for (auto s : strs_name ) {
		f_name = s.substr(0,3);
		
		if(f_name == "김" || f_name == "이") {
			std::cout << f_name << std::endl;
			++cnt;
		}
	}

	return cnt;
}

// problem 2.
int findName(const vector<string>& strs_name, const string& nameTofind)
{
	int cnt = 0;

	for (auto s : strs_name) {
		if ( s == nameTofind)
			++cnt;
	}
	return cnt;
}

int main()
{
	vector<string> name_vec;
	
	for (int i=0; i < 17; i++ ) {
		name_vec.push_back(names[i]);
	}
	
	std::cout << "num of 김 or 이 : " << cntKimAndLee(name_vec) << std::endl;
	std::cout << "num of 이재영 : " << findName(name_vec, "이재영") << std::endl;
	
	return 0;
}

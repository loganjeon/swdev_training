
/*-----------------------------------------------------------------------------
 *  Coding_dojang problem 405
 *  탭을 공백 문자로 바꾸기
 *
 *  A씨는 개발된 소스코드를 특정업체에 납품하려고 한다. 
 *  개발된 소스코드들은 탭으로 들여쓰기가 된것, 공백으로 들여쓰기가 된 것들이 섞여 있다고 한다. 
 *  A씨는 탭으로 들여쓰기가 된 모든 소스를 공백 4개로 수정한 후 납품할 예정이다.
 *
 *  A씨를 도와줄 수 있도록 소스코드내에 사용된 탭(Tab) 문자를 공백 4개(4 space)로 바꾸어 주는 프로그램을 작성하시오.
 *-----------------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string indent_tabTospace(const string& strLine)
{
	string strTemp = strLine;
	int cnt_tabs = 0;

	for (int i = 0; i < strTemp.length(); i++) {
		if (strTemp[i] == '\t') 
			cnt_tabs += 1;
		 else
			break;
	}
	strTemp.erase(0, cnt_tabs);

	for (int i = 0; i < cnt_tabs; i++)	
		strTemp.insert(0, "    ");
	
	return strTemp;	
}

int main(int argc, char** argv)
{
	ifstream fin;
	ofstream fout;
	string strTemp  = "";
	
	fin.open(argv[1]);
	fout.open("output.txt"); 
	
	vector<string> lineString;

	while(!fin.eof())
	{
		getline(fin, strTemp);
		lineString.push_back(strTemp);
	}

	for ( auto s : lineString )
	{
		strTemp  = indent_tabTospace(s);
		fout << strTemp << endl;;
	}

	fin.close();
	fout.close();

	return 0;
}

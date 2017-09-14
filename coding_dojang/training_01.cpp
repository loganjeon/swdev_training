

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string compress_string(const string& in_str)
{
	int count = 0;
	char prev_char = in_str.at(0);
	stringstream ss;

	if (in_str.length() == 0)
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
	string org_str {};
	string comp_str {};

	getline(cin, org_str);

	comp_str = compress_string(org_str);

	std::cout << comp_str << std::endl;
}	

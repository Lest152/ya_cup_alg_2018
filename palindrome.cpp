#include <iostream>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

void palindrome(string_view sv)
{
	bool isPalindrome { false };
	int         pos   { 0 };
	string_view res   { sv };

	for (auto i = begin(sv); i < end(sv) - 1; i++, pos++) {
		if (auto substr = sv.substr(pos, 2);                        *i == *(i + 1) && substr < res && substr.size() <= res.size()) res = substr;
		if (auto substr = sv.substr(pos, 3);  (i + 2) != end(sv) && *i == *(i + 2) && substr < res && substr.size() <= res.size()) res = substr;

		if (*i == *(i + 1) || ((i + 2) != end(sv) && *i == *(i + 2)))
			isPalindrome = true;
	}

	if (isPalindrome) cout << res;
	else              cout << "-1"s;
}

int main()
{
	palindrome("abcabadhg"s);
}
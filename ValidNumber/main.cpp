#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Solution {
public:
	bool isNumber(string s) {
		int len = s.size();
		int left = 0, right = len - 1;
		bool eExisted = false;
		bool dotExisted = false;
		bool digitExisited = false;
		// Delete spaces in the front and end of string
		while (s[left] == ' ') ++left;
		while (s[right] == ' ') --right;
		// If only have one char and not digit, return false
		if (left >= right && (s[left] < '0' || s[left] > '9')) return false;
		//Process the first char
		if (s[left] == '.') dotExisted = true;
		else if (s[left] >= '0' && s[left] <= '9') digitExisited = true;
		else if (s[left] != '+' && s[left] != '-') return false;
		// Process the middle chars
		for (int i = left + 1; i <= right - 1; ++i) {
			if (s[i] >= '0' && s[i] <= '9') digitExisited = true;
			else if (s[i] == 'e' || s[i] == 'E') { // e/E cannot follow +/-, must follow a digit
				if (!eExisted && s[i - 1] != '+' && s[i - 1] != '-' && digitExisited) eExisted = true;
				else return false;
			}
			else if (s[i] == '+' || s[i] == '-') { // +/- can only follow e/E
				if (s[i - 1] != 'e' && s[i - 1] != 'E') return false;
			}
			else if (s[i] == '.') { // dot can only occur once and cannot occur after e/E
				if (!dotExisted && !eExisted) dotExisted = true;
				else return false;
			}
			else return false;
		}
		// Process the last char, it can only be digit or dot, when is dot, there should be no dot and e/E before and must follow a digit
		if (s[right] >= '0' && s[right] <= '9') return true;
		else if (s[right] == '.' && !dotExisted && !eExisted && digitExisited) return true;
		else return false;
	}
};
int main()
{
	return 0;
}
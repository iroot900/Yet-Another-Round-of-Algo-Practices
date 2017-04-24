#include <iostream>
#include <vector>
using namespace std;

string minus1(string left, string right) {
	//
	string ret = "";

	reverse(left.begin(), left.end());
	reverse(right.begin(), right.end());

	// 3-  digit for this gay. 10 - 3 %1
	//

	bool negative = false;
	int borrow = 0;
	int l = 0; int r = 0;

	if (left.size() <  right.size() || (left.size()  == right.size() && left < right)) {
		negative = true;
		string	tmp = left;
		left = right;
		right = tmp;
	}

	while (l < left.size() && r < right.size()) {
		int num1 = left[l] - '0';
		int num2 = right[r] - '0';

		int digit  = (10 + num1 - borrow - num2) % 10;
		
		borrow =  (num1 - borrow - num2 < 0);
		++l; ++r;
		ret =  to_string(digit) + ret;
	}

	//now one side is gone.
	
	while (l < left.size()) {
		int num1 = left[l] - '0'; 
		int num2 = 0;
		++l;

		int digit  = (10 + num1 - borrow - num2) % 10;
		ret =  to_string(digit) + ret;
		
		borrow =  (num1 - borrow - num2 < 0);
	}

	while (r < right.size()) { //still have to goone. num1 is zero now.
		int num1 = 0; 
		int num2 = right[r] - '0';
		++r;

		int digit  = (10 + num1 - borrow - num2) % 10;
		ret =  to_string(digit) + ret;
		
		borrow =  (num1 - borrow - num2 < 0);
	}

	if (negative) return "-" + ret;
	return ret;
}

int main() {
	cout << minus1("123", "456") << endl;
	cout << minus1("1230", "456") << endl;
}

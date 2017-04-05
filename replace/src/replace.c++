//
//
//You are given an integer X. You must choose two adjacent digits and replace them with the larger of these two digits.
//
//For example, from the integer X = 233614, you can obtain:
//33614 (by replacing 23 with 3);
//23614 (by replacing 33 with 3 or 36 with 6);
//23364 (by replacing 61 with 6 or 14 with 4);
//
//You want to find the smallest number that can be obtained from X by replacing two adjacent digits with the larger of the two. In the above example, the smallest such number is 23364.
//
//Write a function:
//
//class Solution {public int solution (int X);}
//that, given a positive integer X, returns the smallest number that can be obtained from X by replacing two adjacent digits with the larger of the two.
//
//For example, given X = 233614, the function should return 23364, as explained above.
//
//Assume that:
//
//X is an integer within the range [10..1,000,000,000].
//
//In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment
//
//


#include <iostream>
#include <vector>
using namespace std;

//// n     n 
//	 or n 12 left + right.  str compare. actually this is n. so   n ^ 2. -- not so good.
//   if we can get rid of one larger and move up one small

string replace(vector<int> nums) {
	if (nums.size() < 2) return "";
	string ret;
	for (int i = 0; i < nums.size(); ++i) { //for all these numbers. what should we do.
		if (i > 1 && nums[i - 1] > nums[i] && nums[i - 2] >= nums[i - 1]) {
			//i-1 i-2,  max of these two.
			for (int t = 0; t < nums.size(); ++t) {
				if (t == i - 2) {
					ret += to_string(max(nums[t], nums[t + 1]));
					++t;
				} else {
					ret += to_string(nums[t]);
				}
			}
			return ret;
		}
	}

	for (int i = 0; i + 2 < nums.size(); ++i) {
		ret += to_string(nums[i]);
	}
	ret += to_string(std::max(nums[nums.size() - 2], nums[nums.size() - 1]));
	return ret;
}

string toString(const vector<int>& nums) {
	string ret;
	for (int i = 0; i < nums.size(); ++i) {
		ret += to_string(nums[i]);
	}
	return ret;
}


//
//233614 -> can't find, replace 4 with 14
//177763 -> 7 >= 7 > 6, replace 7 with 77
//52231 -> can't find, replace 3 with 31
//654321 -> 6 >= 5 >4, replace 65 with 6
//

int main() {
	vector<int> test1 = {2,3,3,6,1,4};
	vector<int> test2 = {1,7,7,7,6,3};
	vector<int> test3 = {5,2,2,3,1};
	vector<int> test4 = {6,5,4,3,2,1};

	cout << toString(test1) << " : " <<  replace(test1) << endl << endl;
	cout << toString(test2) << " : " <<  replace(test2) << endl << endl;
	cout << toString(test3) << " : " <<  replace(test3) << endl << endl;
	cout << toString(test4) << " : " <<  replace(test4) << endl << endl;
}

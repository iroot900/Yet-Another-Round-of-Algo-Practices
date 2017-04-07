#include <iostream>
#include <vector>
using namespace std;


// T(n) = T(n - 1) + [k,  + 1]
// you could + k or next time k + 1
//
//
// T(n) = T(n-1) + k
// T(n) = 1 + T(n - 2) + k + 1
//
//
// T(n) = T(n-1) + K
// T(n) = T(n-2) + k + 2;
//  T(n) + T(n-2) + k + N;
//  n.. that's it.  haliiluya.!

// left most small number.. 
//Suppose you are given an array [2, 1, 3, 2, 1, 3]
//output should be [-1, -1, 2, 1, -1, 2]?


// 5 3 1 7  --- 7 is two big. i don't like it.  7 is smlaer. then 5 is way more small. 


vector<int> leftMostSmall(const vector<int>& nums) {
	vector<int> ret;
	vector<int> prevs;

	for (int i = 0; i < nums.size(); ++i) {
		if (prevs.size() == 0 || nums[i] < prevs[prevs.size() - 1]) { //num is mall.  jno previos
			ret.push_back(-1);
			prevs.push_back(nums[i]);
		} else {
			int candi = -1;
			for (int j = prevs.size() - 1; j >= 0; --j) {
				if (prevs[j] < nums[i]) {
					candi = prevs[j];
				} else {
					break;
				}
			}
			ret.push_back(candi);
		}
	}

	return ret;
}


template<typename T>
void print(T data) {
	auto it = data.begin(); 
	while (it != data.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main() {

	vector<int> test = {2, 1, 3, 2, 1, 3};
	vector<int> ret = leftMostSmall(test);
	print(ret);
}

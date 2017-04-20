#include <iostream>
#include <vector>
using namespace std;

vector<int> n4(vector<int>& nums) {
	vector<int> ret;
	int n = nums.size();
	if (n == 0) return ret;

	//aparen more than 0 times
	if (n < 4) return nums;
	
	int len = n / 4; //12 / 4 = 3 every 3 number.   skip    every len number do a check.  if previous == cur . then found it. otherwise

	int left = 0;


	//len = 3 * 4 = 12
	// 15 / 4 = 3
	//
	//123[4] 567[8] 91011[12] 13 14 15 
	//
	//12 already check ok. nothing to check any more. 
	
	while (true) {
		//cout << left << " " << len << endl;
		int right = left + len;
		if (right >= nums.size()) break;
		//we have left and right. 

		//do a binary search here. 
		int p = right; //do a binary search.
		int l = left;
		int r = min(right + len, (int)nums.size() - 1);

		//binary search to left
		// l and p...  do a binary search.

		int ll = l; int rr = p - 1;
		while (ll < rr) {
			int mid = (ll + rr) >> 1;
			if (nums[mid] == nums[p]) {
				rr = mid;
			} else {
				ll = mid + 1;
			}
		}
		if (nums[ll] != nums[p]) { ll = ll + 1; }

		int leftC = p - ll;

		ll = p + 1, rr = r;
		while (ll < rr) {
			int mid = (ll + rr) >> 1;
			if (nums[mid] == nums[p]) {
				ll = mid;
				if (ll == mid) break;
			} else {
				rr = mid - 1;
			}
		}
		if (nums[ll] != nums[p]) { ll = ll - 1; }

		int rightC = ll - p;


		int count = leftC + rightC + 1;
		if (count > len) {
			//cout << len << " : " << leftC << ", " << rightC << "---->" << nums[p] << "____" << p << endl;
			ret.push_back(nums[p]);
		}

		left = right + 1;
	}
	

	//3 number. 
	// (122[2]23456)
	// not the same. [2].  1 2 3 4       2 3 4  only 4 has the potential to be that thing. 
	//
	// // for 4. do a binary search. to left and right.  left and right. then do another binary earxh

	return ret;
}

int main() {
	vector<int> test1 = {1,2,3,4};
	auto ret1 = n4(test1);
	for (int i = 0; i < ret1.size(); ++i) {
		cout << ret1[i] << endl;
	}

	vector<int> test2 = {1,1,3,3,3,3,3,4,4,5,5,6,6,7,7};
	auto ret2 = n4(test2);
	for (int i = 0; i < ret2.size(); ++i) {
		cout << ret2[i] << endl;
	}


	vector<int> test3 = {1,1,1,2,2,2,3,4,4,4,4,4,5};
	auto ret3 = n4(test3);
	for (int i = 0; i < ret3.size(); ++i) {
		cout << ret3[i] << endl;
	}
}

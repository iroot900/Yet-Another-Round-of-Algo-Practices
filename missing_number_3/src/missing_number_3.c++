#include <iostream>
#include <vector>
using namespace std;

int missing_number(vector<int> nums) {
	//111222333
	//pos..   
	//012 345
	//i % 3 -- 012
	//012 should be the same.
	//
	
	// if same the not this one. otherwise. have to before this dude there was missing number. then 
	//
	//11
	//11122333
	//
	//
	//11
	//11122
	//22333
	int l = 0;
	int r = nums.size() - 1;
	//012
	while (l + 2 < r) {
		int mid = (l + r) >> 1;

		int remain = mid % 3;
	
		//012 3xx if only one number
		if (remain == 0) { // compare with next two.  there must be one number. 
			if (mid + 2 == nums.size()) {
				return nums[mid];
			} else  {
				if (nums[mid] == nums[mid + 1] && nums[mid + 1] == nums[mid + 2]) {
					l = mid + 3; //jump to next start... every time, jump to next pure good start. and if bad them it will stuck there.
				} else {
					r = mid;
				}
			}
			//at 1 previous 1 yes there must be previous. ok and there must be next ?!
		} else if (remain == 1) { //check previous and next. next yes. but previous?1
			if (nums[mid -1] == nums[mid] && nums[mid + 1] == nums[mid]) { //the same. ok we're good
				l = mid + 2;//012
			} else {
				r = mid;
			}
		} else if (remain == 2) { //compare with previous two. is there two number before?-- there are two before this guy.
			if (nums[mid -1] == nums[mid] && nums[mid - 2] == nums[mid]) { //the same. ok we're good
				l = mid + 1;//012
			} else {
				r = mid;
			}
		}
	}
	return nums[l];
}

int main() {
	vector<int> test1 = {1,1};
	cout << missing_number(test1) << endl;

	vector<int> test2 = {1,1,2,2,2};
	cout << missing_number(test2) << endl;

	vector<int> test3 = {1,1,1,2,2};
	cout << missing_number(test3) << endl;

	vector<int> test4 = {1,1,1,2,2,3,3,3};
	cout << missing_number(test4) << endl;

	vector<int> test5 = {1,1,1,2,2,2,3,3,3,4,4,4,5,5,6,6,6};
	cout << missing_number(test5) << endl;
}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
 *
 *每个element可以最多backward移动k个位置，但forward可以移动任意个位置，让尽可能的将这个数组排序，在时间复杂度上讨论了很久，从最初的n^2算法，到k*n算法，最后改进到logk*n算法
 *
 */

//hard question. what he's aksing? not sure. then ask and ask to make sure you know what needs to be done
//
//hard question. what to do?!  what's the best solution
//
////start with trivial case. the best trivail case. then drive it.
//
//don't solve it (dirve it form tirval thats' how great mind works. great minds dont' solve it. but drive thorught it )


vector<int> ksort(vector<int>& nums, int k) {
	int n = nums.size();
	vector<int> ret(n);
	if (n <= k - 1) {
		sort(nums.begin(), nums.end());
		return ret;
	}

	if (k <= 0) return nums;

	class MyComp {
		public:
			bool operator() (int left, int right) const {
				if (left <= right) return false;
				return true;
			}
	};

	priority_queue<int, vector<int>, MyComp> que;
	int i = 0;
	for (; i < k; ++i) {
		que.push(nums[i]);
	}

	for (; i < n; ++i) {
		que.push(nums[i]);
		ret[i-k] = que.top(); que.pop();
	}

	while (que.size() != 0) {
		ret[i-k] = que.top() ; ++i; que.pop();
	}

	return ret;
}

int main() {
	vector<int> nums = {2, 5, 3, 1, 4};
	auto ret = ksort(nums, 2);
	for (int i = 0; i < ret.size(); ++i) {
		cout << ret[i] << " " ;
	}
	cout << endl;
}

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int count(const string& pre) {
	//cout << pre.size() << endl;
	//cout << ":" << pre << endl;
	//pre[0]/ root .then left and right. 
	if (pre.size() == 1) return 1;
	if (pre.size() == 0) return 1;
	int ret = 0;
	for (int i = 1; i < pre.size() + 1; ++i) {
		int left = count(pre.substr(1,i-1));
		int right = count(pre.substr(i));
		ret +=  left * right;
	}
	return ret;
}


int count(int n) {

	if (n <= 1) return 1;

	vector<map<int,int>> f(n + 1);
	f[0][0] = 1;
	f[1][1] = 1;

	for (int len = 2; len <= n; ++len) {
		for (int left = 0; left < len; ++left) {
			int right = len - 1 - left;

			//problabaly don't have to go throught whoe left , right...   for balance.   when diff is larnge cna't find balande.
			//left len right lefn   left's 
			//
			map<int, int> leftHeights = f[left];
			map<int, int> rightHeights = f[right];

			for (auto leftHeight : leftHeights) {
				int height = leftHeight.first;
				int count = leftHeight.second;

				auto validH = {height, height - 1, height + 1};
				for (int h : validH) {
					auto it = rightHeights.find(h);
					if (it != rightHeights.end()) {
						f[len][max(h, height) + 1] += count * it->second;
					}
				}
			}
			//for (
		}
	}

	int ret = 0;
	for (auto pir : f[n]) {
		ret += pir.second;
	}
	
	return ret;
}

//split into two parts. then   left  right f[left] * f[right]  , also need to check f[left] height.  if diff <= 1 then ok. we get one for f[len][height] this much. 

//DP
//
///state 
//
//balancedTree
//
//length, height  
//
//// f[len]
//
//
//// f[8] = f[8]  + f[0]
//
//// f[7]  f[1]
//
//// need the height.


//     	1
//    2   3
//   4     6
//
//
//
///    1
////  2  3
//
///  4 6

//

int main() {
	cout << count("12") << endl;
	cout << count("123") << endl;
	cout << count(1) << endl;
	cout << count(2) << endl;
	cout << count(3) << endl;
	cout << count(4) << endl;
	cout << count(3) << endl;


	//1
	///
	//
	//
	//5
}



#include <iostream>
#include <vector>
using namespace std;


//
//aaa bb cc ddddd
//6



//DP.. do you know how to do it?   no!!!
//
//
//if i give you it do you know how to get next?!  maybe?!! OK. this is it!! (easier thought path)
int cost(const vector<string>& strs, int k) {
	int n = strs.size();
	if (n == 0) return 0;

	vector<int> f(n, 0);

	//put last word in a new line
	//put last two words in a new line
	//try if last few words can be in a line. 
	for (int i = 0; i < n; ++i) {
		int len = strs[i].size();

		//if (i == n - 1) {
		//	f[i] = (i == 0 ? 0 : f[i - 1]);
		//} else {
			f[i] =  ((i == 0 ? 0 : f[i - 1]) + (k - len) * (k - len));
		//}
		cout << f[i] << endl;

		for (int j = i - 1 ; j >= 0; --j) {
			if (len + 1 + strs[j].size() <= k) {
				len += 1 + strs[j].size();
		//		if (i == n - 1) {
		//			f[i] = min(f[i], (j == 0 ? 0 : f[j - 1])); 
		//		} else {
					f[i] = min(f[i], (j == 0 ? 0 : f[j - 1]) + (k - len) * (k - len));
		//		}
			} else {
				break;
			}
		}
	}

	return f[n - 1];
}

int main() {
	vector<string> words = {"aaa", "bb", "cc", "ddddd"};
	cout << cost(words, 6) << endl; 
}

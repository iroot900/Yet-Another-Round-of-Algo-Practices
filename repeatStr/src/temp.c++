#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix(const string& str) {
	int n = str.size(); 
	vector<int> pre(n, 0);

	for (int i = 1;i < n; ++i) {
		int p = pre[i - 1]; //last len. 
		while ( p!= 0 && str[i] != str[p]) { //compare with last guy. if equlas. we're good. just ,  if not then?@ p     p = len. 3   p
			p = pre[p - 1];
		}

		if (str[i] == str[p]) {
			pre[i] = p + 1;
		}
		//how to do this?!
	}
	return pre;
}

bool repeatString(const string& str) {
	vector<int> pre = prefix(str);
	int n = str.size();
	int len = pre[n - 1];
	//cout << str << " : -- " << len << endl;
	int strLen = n - len;

	if (strLen == n) return false;

	if (n % strLen != 0) return false;

	const string pattern = str.substr(0, strLen);
	//cout << str << " " << pattern << endl;
	for (int i = 0; i < n; i += strLen) {
		string sub = str.substr(i, strLen);
		if (sub != pattern) return false;
	}

	return true;
}

int main() {
	cout << repeatString("abab") << endl;
	cout << repeatString("abcabcabc") << endl;
	cout << repeatString("aa") << endl;
	cout << repeatString("a") << endl;
	cout << repeatString("ab") << endl;
	cout << repeatString("ababc") << endl;
}

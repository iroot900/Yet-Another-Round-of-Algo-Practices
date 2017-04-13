#include <iostream>
#include <vector>
using namespace std;

int ways(int n) { 
	if (n < 1) return 0;
	int sum = (1 + n) * n / 2;
	if ((sum & 1) != 0) return 0;

	int mid = sum / 2;
	vector<int> f(mid + 1, 0);
	f[0] = 1;

	for (int i = 1; i <= n; ++i) {
		for (int j = mid; j >= 1; --j) {
			int last = j - i; //  how many ways to go to n  if we use i
			if (last >= 0) {
				f[j] += f[last];
			}
		}
	}

	return f[mid] / 2;
}

int main() {
	cout << ways(7) << endl;
}

#include <iostream>
#include <vector>
using namespace std;


/*
 *
	 Two players and one line of coins. Each player can either pick one or two coins from left side, or one or two coins from right side. The player who ends up getting the highest value wins. Return whether the first player (pick first) can win.

	e.g., coins [1,2,3,4,5,6,7,1,2,3]. First player can win.
	e.g., coins[1,1,10,1,1]. First player cannot win.*
	 *
 */

//take left 1 or 2
//take right 1 or 2. 
bool canWin(const vector<int>& coins) {
	int n = coins.size();
	vector<vector<int>> f(n, vector<int>(n, 0));
	int sum = 0;

	for (int coin : coins) {
		sum += coin;
	}

	int subsum = 0;
	for (int len = 1; len <= n; ++len) {
		subsum += coins[len - 1];
		for (int i = 0; i + len <= n; ++i) {

			int j = i + len - 1;

			if (i != 0) {
				subsum -= coins[i - 1];
				subsum += coins[j];
			}

			if (len == 1) {
				f[i][j] = coins[i];
			} else if (len == 2) {
				f[i][j] = coins[i] + coins[j];
			} else {
				//left 1
				f[i][j] = max(f[i][j], coins[i] + (subsum - coins[i] - f[i + 1][j])); //take left one. then for the remaing.    sum - they take the most.  
				//left 2
				f[i][j] = max(f[i][j], coins[i] + coins[i + 1] + (subsum - coins[i] - coins[i + 1] - (i + 2 > j ? 0 : f[i + 2][j])));


				//right 1
				f[i][j] = max(f[i][j], coins[j] +  (subsum - coins[j] - f[i][j - 1]) );
				f[i][j] = max(f[i][j], coins[j - 1] + coins[j] + (subsum - coins[j] - coins[j - 1] - (i > j - 2 ? 0 : f[i][j - 2])));
			}
		}
	}

	return f[0][n - 1] > (sum - f[0][n - 1]);
}

int main() {
	vector<int> test1 = {1,2,3,4,5,6,7,1,2,3};

	vector<int> test2 = {1,1,10,1,1};
	vector<int> test3 = {1,1};
	vector<int> test4 = {1,1, 2,2};

	cout << canWin(test1) << endl;
	cout << canWin(test2) << endl;
	cout << canWin(test3) << endl;
	cout << canWin(test4) << endl;
}

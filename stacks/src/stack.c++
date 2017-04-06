#include <iostream>
#include <stack>
#include <vector>
using namespace std;


//this is a great question. I mean pretty standard thoght. DP mn.
// you have to thing about method. DP. tree. Stack Queue.   O(n).  and trivail
//
// //you can't solve a quesiton by thingk out a solution......    not.  it's not linear.  it' CS wasy. or algo way or leetcode way. not linear way. 
//   triavl DP. DPFS. que. stack. Tree binary. BFS. ...  O(n).. 
//
int stacksKSum(vector<stack<int>> stacks, int k) {
	int n = stacks.size();
	
	vector<vector<int>> f(n + 1, vector<int>(k + 1, 0));

	//f[0][k] = 0;
	//f[n][0] = 0;

	for (int i = 1; i <= n; ++i) { //with i + 1 stakcs. 
		for (int j = 1; j <= k; ++j) { //take at most j number, how larnge can we get.
			//f[i][j]   i stacks. with 1 number 2 number 3 number, to k number.


			stack<int> sta = stacks[i - 1]; // take how many from this stack.
			f[i][j] = f[i - 1][j]; // last one get zero
			int sum = 0;
			for (int t = 1; t <= j; ++t) { //take 1 to k from last stack 
				if (sta.size() > 0) {
					sum += sta.top(); sta.pop();
				}
				f[i][j] = max(f[i - 1][j - t] + sum,  f[i][j]);
			}
		}
	}
	return f[n][k]; //n stack k number.
}

///n  1 2 3 4  6 
//
//n + 1,    n + 1 na 1 ge n + 1 2, rest from previous. 
// n + 1, 

vector<stack<int>> toStack(vector<vector<int>>& vecs) {
	vector<stack<int>> stas;
	for (int i = 0; i < vecs.size(); ++i) {
		stack<int> sta;
		for (int j = 0; j < vecs[i].size(); ++j) {
			sta.push(vecs[i][j]);
		}
		stas.push_back(sta);
	}
	return stas;
}

int main() {
	vector<vector<int>> vecs = { 
	{9, -3},
    {-2, 4, 6},
    {},
    {1, 2},
    {3}
	};

	auto stacks = toStack(vecs);

	for (int i = 0; i < 10; ++i) {
		cout << stacksKSum(stacks, i) << endl;
	}
}

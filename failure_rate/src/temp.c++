#include <iostream>
#include <vector>
using namespace std;

//1 	2 		3 		4

//HOW CS think differntely.. :
//
//// Loop
//// Recursive
//// DP
////

//1/10	2/10	3/10	4/10

// wow!!! Amazing... Mind game.. --- k. n.. what hapnes. man. DP DP DPD PD DP DPD DPD DP shouwl be inyour blood. stuck then DP.. 

//if f[10][3] = 0.33

//down one more machine. come from this new one or come from last. bc
// 9 machines f[9][3]
// f[10][4] = f[9][3]
//
//
// f[10][4] = f[9][4] *up + f[9][3]*[down] 

// //10 mahine 4 down.  9 machien 4down. this new one up.  ok 
// 10 machine.  down   4.        probilb of 9 machine down 4. and this one up  previous donw 3, and this one donw 1

double failure_rate(vector<double> rates, int k) {
	double ret = 0.0;
	int n = rates.size();
	vector<vector<double> > f(n + 1, vector<double>(n + 1, 0.0));
	//0 macine 0 fail
	f[0][0] = 1;
	//n machine 0 fail
	
	for (int i = 1; i <= n; ++i) { //f[0][0] = 1..    nothing fails.  1 *  2/3 * 4/5 * 43/
		f[i][0] = f[i - 1][0] * (1 - rates[i - 1]);//0 fail not fail not fail not fail
	}
	//cout << f[3][0] << endl;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) { //how many fail. 1 fail 2 fail 3 fail 
			f[i][j] = f[i - 1][j-1] * rates[i - 1] + f[i - 1][j] * (1 - rates[i - 1]); // 4 2 fail    3 1 fail * this one fail
			//1 machine 1 donw.    0 one 0 donw. i donw.  --  0 machine 1 donw. 0 
			///4 4 machine how to get ti?   3 3 * 3 3 * fail.  4 4  3 3     3 4
			// 4 3,    42 * i went down.  + 3,3 * this guy is update.
		}
	}


	//f[2][1] fail  f[1][0] * fail + f[1][1] * not fail
	//  f[1][0] * fail + f[1][1] * not fail

	//4 machine fail. the rate of four machine fail
	//// the rate of 6 machine fail?1
	for (int i = k; i <= n; ++i) {
		ret += f[n][i];
	}


	/*
	cout << " " << endl;
	for (int i = 0; i <= n; ++i) {
		cout << "fail : " << i  << " machines, p:" << f[n][i] << endl;
	}
	cout << " " << endl;
	*/

	//k 0  if 0 is down then 
	////0 down 1 down
	return ret;
}

int main() {
	vector<double> rates = {1/3.0, 1/4.0, 1/6.0};
	cout << failure_rate(rates, 0) << endl;
	cout << failure_rate(rates, 1) << endl;
	cout << failure_rate(rates, 2) << endl;
	cout << failure_rate(rates, 3) << endl;
	cout << failure_rate(rates, 4) << endl;
}

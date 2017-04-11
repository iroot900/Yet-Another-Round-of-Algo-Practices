#include <iostream>
#include <vector>
using namespace std;

/*
	Given a length n, return the number of strings of length n that can be made up of the letters 'a', 'b', and 'c', where there can only be a maximum of 1 'b's and can only have up to two consecutive 'c's

	Example:
	findStrings(3) returns 19
	since the possible combinations are: aaa,aab,aac,aba,abc,aca,acb,baa,bac,bca,caa,cab,cac,cba,cbc,acc,bcc,cca,ccb
	and the invalid combinations are:
	abb,bab,bba,bbb,bbc,bcb,cbb,ccc
 */

int ways(int n) {

	vector<vector<vector<int>>> f(n,  vector<vector<int>> (4, vector<int>(2)));
	//a : *
	//b : 1 
	//c : 2 conse
	
	if (n == 0) return 1;
	if (n == 1) return 3;
	
	//0 end with  a b c, used a b c 
	f[0][0][0] = 1; //not use b
	f[0][1][0] = 0;
	f[0][2][0] = 1;
	f[0][3][0] = 0;

	f[0][0][1] = 0;
	f[0][1][1] = 1;
	f[0][2][1] = 0;
	f[0][3][1] = 0;

	for (int i = 1; i < f.size(); ++i) {
		
		//not use 'b'
		// end with a b c / cc
		f[i][0][0] = f[i - 1][0][0]  + f[i - 1][1][0] + f[i - 1][2][0] + f[i - 1][3][0];
		f[i][1][0] = 0;

		//not b. end with one c.
		////last is a
		f[i][2][0] = f[i-1][0][0]; 
		//not b, end with two c. last is c;
		f[i][3][0] = f[i-1][2][0]; 

		//use 'b',   end with a.   last is 
		//all the used b now 
		f[i][0][1] = f[i - 1][0][1]  + f[i - 1][1][1] + f[i - 1][2][1] + f[i - 1][3][1]; 

		//use b, and end with b. last is not b, and not use, currently use ti. 
		f[i][1][1] =  f[i - 1][0][0] + f[i - 1][2][0] + f[i - 1][3][0];

		//use b, and end with c,  used b plus c
		f[i][2][1] = f[i-1][0][1] + f[i-1][1][1]; 
		f[i][3][1] = f[i - 1][2][1]; 
	}

	int all = 0;

	for (int i = 0; i < 4; ++i) {
		all += f[n-1][i][0];
		all += f[n-1][i][1];
	}
	return all;
}

int main() {
	for (int i = 0; i < 15; ++i) {
		cout << ways(i) << endl;;
	}
	return 0;
}

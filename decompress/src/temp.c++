#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//Eg. : a3[b2[c1[d]]]e will be decompressed as abcdcdbcdcdbcdcde.
//Assume the string is well formed and number will always be followed by a [].
//
//
//[ and ]
////ok . the point is [ ] 
//
//// a2[b2[c]]3[d]      abccbccddd
//  using stack. then probabaly better. 

string decompressed(string str) {
	string ret;

	// num[xx] -- so every times ] , we can expect there would be a number. 
	// then we just take that number and get this multiple times. then get it back. 
	// there could be 3[xx] 2[xxfds]  3[2[xx]] c2[xx]
	//
	//   ], then there must be number. before we hit number  + and +, when hit number.   times. then put it back.  -- in the end. get them all togher. 
	//   str,  when number   number(xxxx)     number (
	
	stack<string> sta;
	string cur;
	for (int i = 0; i < str.size(); ) {
		char c = str[i];
		if (isdigit(c)) {
			sta.push(cur); cur = "";
			//get the number.
			int start = i;
			while (i < str.size() && isdigit(str[i])) {
				++i;
			}
			string num = str.substr(start, i - start); //get all the substring
			sta.push(num); //[  get rid of this. -- could be str or number ater ]  when ] comes in what happnes.  will be multiple times then get it back.
		} else if (c == '[') {
			//don't care about this.aaa3[2[aad]]
			++i;
		} else if (c == ']') {
			string top = "";
			while (true) {
				top = sta.top(); sta.pop();
				if (isdigit(top[0])) {
				   break;	
				} else {
					cur = top + cur;
				}
			}
			int times = stoi(top);
			//cout << times << " " << cur << endl;
			string tmp = "";
			for (int t = 0; t < times; ++t) {
				tmp += cur;
			}
			sta.push(tmp);
			cur = "";
			++i;
		} else { //just regular 
			cur.push_back(c); //cur string.
			++i;
		}
	}


	while (!sta.empty()) {
		cur = sta.top() + cur; sta.pop();
	}

	return cur;
}

int main() {
	string test1 = "a3[b2[c1[d]]]e";
	string test2 = "a2[b2[c]]3[d]";
	string test3 = "3[d]2[c]";

	cout << decompressed(test1) << endl;
	cout << endl;
	cout << decompressed(test2) << endl;
	cout << endl;
	cout << decompressed(test3) << endl;
}

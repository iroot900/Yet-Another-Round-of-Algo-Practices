#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


//the point is. at ech posiiotn. you have to put all the current possible solution. 
//might not from the last one. thought last one is the one you need to try it out. 
//from what could be used as next.
/*
void sub(vector<int>& solu, vector<vector<int> >& ret, unordered_set<int>& digits) {
	int n = solu.size();
	int last = solu[n - 1];

	bool stop = true;
	unordered_set<int> local;
	for (int i = 0; i + 1 < solu.size(); ++i) { //also for this digits. one is enough.
		int diff = abs(last - solu[i]);	
		auto it = digits.find(diff);

		if (it == digits.end()) {
			auto itt = local.find(diff);
			if (itt == local.end()) {
				local.insert(diff);
			} else {
				continue;
			}
			stop = false;
			//no such number. then what do we do?
			solu.push_back(diff);
			digits.insert(diff);
			sub(solu, ret, digits);
			solu.pop_back();
			digits.erase(diff);
			//here, what do we do... we need to remove this number.
		} else {
			//has it. ignore this.
		}
	}
	//when to stop
	if (stop) {
		ret.push_back(solu);
	}
};
*/

//what's the possible value for pos i.    it could be 4, 5, 9, 1 ,2 -- use it. after use it. what's the possible value. remove tis. new place -- for this check is there would be new possbile. then do it gain.  

//what's the current posiiont 's possible value.  use it. a seuqen.ce then what' the possible.     abc posooble try one.   .. possbile -1 then new possble then ry one.  sequnce is diff 
void sub(unordered_set<int> possible, unordered_set<int>& used, vector<int>& solu, vector<vector<int>>& ret) {
	//update current possint.
	int n = solu.size();
	for (int i = 0; i < n - 1; ++i) {
		int diff = abs(solu[n - 1] - solu[i]); //if new the nw possbe
		auto it = used.find(diff);
		if (it == used.end()) possible.insert(diff);
	}

	if (possible.size() == 0) {
		ret.push_back(solu);
		return;
	}

	unordered_set<int> nextP = possible;
	for (int next : possible) {
		nextP.erase(next);
		used.insert(next);
		solu.push_back(next);
		sub(nextP, used, solu, ret);
		solu.pop_back();
		used.erase(next);
		nextP.insert(next);
	}
}

vector<vector<int> > sub(const vector<int>& nums) {
	//a b 
	

	// a and b. then what do we do to get the next?!
	// bad ones
	// set ()
	// for each number you should interact with the previous all nujber.
	//
	vector<vector<int>> ret;	
	vector<int> solu = {nums[0], nums[1]};
	unordered_set<int> possible;
	unordered_set<int> used = {nums[0], nums[1]};
	sub(possible, used, solu,ret);

	return ret;
};

void print(vector<vector<int>>& ret) {
	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; j < ret[i].size(); ++j) {
			cout << ret[i][j] << " " ;
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	vector<int> test1 = {2, 7};
	auto ret = sub(test1);	
	print(ret);
}

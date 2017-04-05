//
//
//You are given a positive integer array and a list of update operations as pairs (index, newValue).
//
//Return a list containing the mode of the array after each update.
//
//


#include <list>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;



//another impletementaiont 
//
//   map<int< list<>::iterator> numToListIter;
//   list<pair<int, unordered_set<int>> freqList;
//   
//   oldval freq-1 ; newval frequ + 1
//
//   oldval. move it from and iter to adcent iter is present. 
//   then update it's iter.
//key value,    value property  ranking.
vector<vector<int> > array_mode(vector<int>& nums, const vector<pair<int, int> >& opers) {
	//frequency map. we have frequency map. then what do we do?!
	unordered_map<int, int> numToFreq;
	//frequncey list.
	map<int, unordered_set<int>>  freqToNums;

	for (int i = 0; i < nums.size(); ++i) {
		numToFreq[nums[i]]++; //frequncey 1 first. then 
	}

	for (auto & pir : numToFreq) {
		int num = pir.first;
		int fre = pir.second;
		freqToNums[fre].insert(num); //1 4 5 2 1
	}


	vector<vector<int> > ret;

	for (auto & pir : opers) {
		int i = pir.first;
		int val = pir.second;

		//now update it
		int oldVal = nums[i];
		nums[i] = val;
		if (val == oldVal) continue; //same value

		//for old value , frequncey -1
		int oldFre = numToFreq[oldVal];
		numToFreq[oldVal]--;
		if (oldFre == 1) { //old frequncy is 1, this number is gond
			numToFreq.erase(oldVal);
		}
		freqToNums[oldFre].erase(oldVal);
		if (freqToNums[oldFre].size() == 0) {
			freqToNums.erase(oldFre);
		}
		
		if (oldFre - 1 > 0) {
			freqToNums[oldFre - 1].insert(oldVal);
		}

		//for value, frequency +1 which has frequncey + 1
		//5 's frequncey -1
		//6's frequnce + 1
		//
		oldFre = numToFreq[val]; //orignla freqnce /+1
		numToFreq[val]++;

		freqToNums[oldFre].erase(val);
		if (freqToNums[oldFre].size() == 0) {
			freqToNums.erase(oldFre);
		}
		freqToNums[oldFre + 1].insert(val);
		auto it = freqToNums.rbegin();
		ret.push_back({it->second.begin(), it->second.end()});
	}

	return ret;
}

int main() {
	vector<int> test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	//0 1 2 3 4
	//1 1 2 3 4 0 
	//1 1 3 3 4 1
	//3 1 3 3 4 2
	//3 1 3 1
	vector<pair<int, int>> opers1 = {{0,1}, {2,3}, {0, 3}, {3,1}};
 	auto ret = array_mode(test, opers1);

	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; j < ret[i].size(); ++j) {
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
}

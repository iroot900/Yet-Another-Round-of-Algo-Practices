#include <iostream>
#include <vector>
using namespace std;

/*
A robot is placed on a 2D grid at origin (0, 0) facing North.
 
 The robot receives three possible commands:
 
 M = Move forward one step in the direction it is facing.
 L = Rotate left 90 degrees.
 R = Rotate right 90 degrees.
 Given a sequence of commands, the robot will loop through these commands indefinitely.
 
 Given a string which describes the sequence of commands, determine if it is possible to trap the robot in a circle of finite radius.
 
 For example,
 
 Given s = "GGGL",
 
 Return true. Because the robot loops in a rectangle.
 
 Given s = "GGLGGR",
 
 Return false. Because the robot keeps moving toward the north west direction, farther and farther away from the origin.*
 */


vector<int> getLastPosition(const string& str) {
	vector<int> ret(3, 0);
	int direction = 0;
	int pos[2] = {0, 0};//position. direction. check current posisiotn.  

	for (int i = 0; i < str.size(); ++i) {
		char c = str[i];
		if (c == 'L') {
			direction -= 1;
			if (direction < 0) direction += 4;
		} else if (c == 'R') {
			direction += 1;
			if (direction >= 4) direction -= 4;
		} else {
			//move in current direction.
			switch (direction) {
				case 0 : 
					pos[0] += 0; //go north.
					pos[1] += 1;
					;break;
				case 1 :
					pos[0] += 1; //go east.
					pos[1] += 0;
					;break;
				case 2 :
					pos[0] += 0; //go south.
					pos[1] += -1;
					;break;
				case 3:
					pos[0] += -1; //go west.
					pos[1] += 0;
					;break;
			}
		}
	}

	ret[0] = direction;
	ret[1] = pos[0];
	ret[2] = pos[1];
	return ret;
}


bool bounded(const string & str ) {
	auto status = getLastPosition(str);
	if (status[1] == 0 && status[2] == 0) return true; 
	if (status[0] == 0) return false;
	return true;
}

//moved or not. not moved. the done
////moved, same dire . false
////move, opp true
////moved,  angle. 45' true
// check the direction right. and ankle. 

int main() {
	cout <<  bounded("GGL") << endl;
	cout <<  bounded("GGLGGR") << endl;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

const int neibs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};


//give a post. i want to know ok
//
//


//pos[i]
//
//  go to    0	 	1	 	2	 3 
//			 left	right  down  up
// 0, 1
// 2 3

int neibWall(int dir) {
	switch(dir) {
		case 0 : return 1;
		case 1 : return 0;
		case 2 : return 3;
		case 3 : return 2;
	}
	return -1;
}

void mazeGen(int w, int l, vector<vector<vector<int>>>& maze, int x, int y) {
	///cout << x << " " << y << " : " << endl;
	//randomly choose one
	
	vector<int> pos = {0, 1,2, 3};
	shuffle(pos.begin(), pos.end(), std::default_random_engine(time(0)));

	int index  = 0;
	for (int i = 0; i < pos.size(); ++i) {

		auto neib = neibs[pos[i]];
		int xx = neib[0] + x;
		int yy = neib[1] + y;
		//cout << "---  "<< xx << " " << yy << " : " << endl;

		if (xx == 4 && yy == 4) {
			//cout << " ? " <<endl;
		}

		if (xx < 0 || yy < 0 || xx >= w || yy >= l || maze[xx][yy][4] == 0) {
			//cout << "what " << endl;
		} else {
			maze[x][y][pos[i]] = 0; //remove wall
			maze[xx][yy][neibWall(pos[i])] = 0;
            
			maze[xx][yy][4] = 0; //visited
			mazeGen(w, l, maze, xx, yy);
		}
		++index;
	}
}

vector<vector<vector<int>>> mazeGen(int w, int l) {
	vector<vector<vector<int>>> maze (w, vector<vector<int>> (l, vector<int>(5, 1))); //wall , 1111 1 not visited 
	maze[0][0][4] = 0;
	mazeGen(w, l, maze, 0, 0);
	return maze;
}

string tostring(const vector<int>& cell) {
	string ret;
	ret +=  to_string(cell[0]) + to_string(cell[1]) + to_string(cell[2]) + to_string(cell[3]) + to_string(cell[4]);
	return ret;
}

void print(vector<vector<vector<int>>> & maze) {
	int m = maze.size();
	int n = maze[0].size();
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << tostring(maze[i][j]) << " ";
		}
		cout << endl << endl;
	}
}

//only one rule.  unvisited njme.r vsitied and remove all
int main() {
	auto maze = mazeGen(5,5);
	print(maze);
}

#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int left;
	int right;
	int up;
	int down;
	int maxValue = -1;

	Node() {}
	Node(int left, int right, int up, int down) {
		this->left = left;
		this->right = right;
		this->up = up;
		this->down = down;
	}

	Node* left1 = nullptr;
	Node* right1 = nullptr;
	Node* left2 = nullptr;
	Node* right2 = nullptr;
};

//start from root. compare. 


//must have bound. 
//
//then go to child, if child not there then creat a child. then do the same thing.
class SegmentTree {
	public:
		SegmentTree(int w, int h) {
			root = new Node(0, w - 1, 0, h - 1);
		}

		void put(int x, int y, int val) {
			put(x, y, val, root);
		}

		int getMax(int left, int right, int up, int down) {
			return getMax(left, right, up, down, root);
		}

		int getMax(int left, int right, int up, int down, Node* node) {

			if (node == nullptr) return -1;

			//cout << left << "," << right << "," << up << "," << down << endl;
			//cout << "				" << node->left << "," << node->right << "," << node->up << "," << node->down << endl; 
			if (right < node->left) return -1;
			if (left > node->right) return -1;

			if (down < node->up) return -1;
			if (up > node->down) return -1;

			if (node->left >= left && node->right <= right && node->up >= up && node->down <= down) {
				//cout << "? " << endl;
				return node->maxValue;
			}
			int maxVal = -1;
			int a = getMax(left, right, up, down, node->left1);
			int b = getMax(left, right, up, down, node->left2);
			int c = getMax(left, right, up, down, node->right1);
			int d = getMax(left, right, up, down, node->right2);
			//if node is in the range, then return node.max. 
			//other wise get to each child
			
			//if child has no inter then return -1;
			//could be not child

			maxVal = max(maxVal, a);
			maxVal = max(maxVal, b);
			maxVal = max(maxVal, c);
			maxVal = max(maxVal, d);
			return maxVal;
		}

		void put(int x, int y, int val, Node* node) {
			//first check current node. if it's the end. then set it val. then go back. otherwise go into next split. 
			
			//cout << x << " : " << y << " = " << node->maxValue << endl;
			int left = node->left; int right = node->right; int up = node->up; int down = node->down;
			//cout << left << " : " <<  right << " : " << up << " : " << down << endl;

			if (left == right && up == down && left == x && up == y) {
				node->maxValue = val; //node is the last one. 
			} else { //must split this?!
				//split?!
				//if not. create one child at then check all child for max.
				int midX = (left + right) >> 1;
				int midY = (up + down) >> 1;

				if (x <= midX && y <= midY) { //left up

					if (node->left1 == nullptr) {
						node->left1 = new Node(left, midX, up, midY);
					}
					put(x, y, val, node->left1);

				} else if (x <= midX && y > midY) { //left down

					if (node->left2 == nullptr) {
						node->left2 = new Node(left, midX, midY + 1, down);
					}
					put(x, y, val, node->left2);

				} else if (x > midX && y <= midY) {//right up

					if (node->right1 == nullptr) {
						node->right1 = new Node(midX + 1, right, up, midY);
					}
					put(x, y, val, node->right1);

				} else { //right down

					if (node->right2 == nullptr) {
						node->right2 = new Node(midX + 1, right, midY +1, down);
					}
					put(x, y, val, node->right2);
				}
				
				int maxVal = -1;
				if (node->left1 != nullptr) {
					maxVal = max(maxVal, node->left1 ->maxValue);
				}

				if (node->right1 != nullptr) {
					maxVal = max(maxVal, node->right1->maxValue);
				}

				if (node->left2 != nullptr) {
					maxVal = max(maxVal, node->left2 ->maxValue);
				}

				if (node->right2 != nullptr) {
					maxVal = max(maxVal, node->right2->maxValue);
				}

				node->maxValue = maxVal;
			}
		}

		int getMax() {
			return root->maxValue;
		}

	private:
		Node* root = nullptr; 
};

int main() {
	SegmentTree grid(10, 10);
	grid.put(0,0, 1);
	cout << grid.getMax() << endl;

	grid.put(9, 9, 2);
	cout << grid.getMax() << endl;

	grid.put(2, 2, 3);
	cout << grid.getMax() << endl;

	grid.put(6, 8, 4);
	cout << grid.getMax() << endl;

	grid.put(4, 2, 5);
	cout << grid.getMax() << endl;

	grid.put(8, 3, 6);
	cout << grid.getMax() << endl;

	grid.put(7, 7, 7);
	cout << grid.getMax() << endl;

	grid.put(9, 9, 8);
	cout << grid.getMax() << endl;

	cout << grid.getMax(0, 9, 0, 9) << endl;

	cout << grid.getMax(0, 3, 0, 3) << endl;

	cout << grid.getMax(3, 6, 3, 6) << endl;

	cout << grid.getMax(5, 8, 2, 5) << endl;
}

#include <iostream>
using namespace std;


class Node {
	public:
	int val; int count; int leftCount;
	Node* left; Node* right;
	Node(int val) { this->val = val; count = 1; leftCount = 0; left = nullptr; right = nullptr;}

};

class CountTree {
	public:

		void add(int val) {
			root = add(val, root);
		}

		int getKth(int k) const {
			return getKth(k , root);
		}

		void remove(int val) {
			root = remove(val, root);
		}

	private:

		Node* remove(int val, Node* node) { //well find nothing. so. 
			if (node == nullptr) return node;
			if (node->val == val) { //remove this node.
				if (node->count > 1) {
					node->count -= 1;
				} else { //remove this node.
					if (node->right == nullptr) {
						return node->left;
					} else if (node->left == nullptr) {
						return node->right;
					} else { //remove this node... 
						Node* next = findNext(node);
						node->val = next->val; //val change. left count not change.
						node->count = next->count; //count change. 
						int leftC = next->count;
						for (int i = 0; i < leftC; ++i) {
							node->right = remove(next->val, node->right);
						}
						return node;
					}
				}
			} else if (val < node->val) {
				node->leftCount -= 1;
				node->left = remove(val, node->left);
			} else {
				node->right = remove(val, node->right);
			}
			return node;
		}

		//      6
		//   5
		// 3   4
		//1   3.5

		Node* findNext(Node* node) {
			node = node->right;
			while (node->left != nullptr) node = node->left;
			return node;
		}

		Node* add(int val, Node* node) {
			if (node == nullptr) {
				return new Node(val);
			}

			if (val == node->val) {
				node->count += 1; return node;
			} else if (val > node->val) {
				node->right = add(val, node->right);
			} else {
				node->leftCount += 1;
				node->left = add(val, node->left);
			}
			return node;
		}

		int getKth(int k, Node* node) const {
			if (node == nullptr) return -1;
			int leftCount = node->leftCount;
			int count = node->count;
			//3 + count
			if (leftCount < k && leftCount + count >= k) return node->val;
			if (leftCount >= k) return getKth(k, node->left);

			//
			return getKth(k - leftCount - count, node->right);
		}

		Node* root = nullptr;
};

int main() {
	auto test = {3,4,1,5,2,6,7,9,8,  3,4,1,5,2,6,7,9,8};
	CountTree tree;
	for (int val : test) tree.add(val);
	for (int i = 1; i <= 18 ; ++i) {
		cout << tree.getKth(i) << endl;
	}


	for (auto val : test) {
		tree.remove(val);
		cout << val << " : ";
			for (int i = 1; i <= 18 ; ++i) {
				cout << tree.getKth(i) << " " ;
			}
			cout << endl;
	}
}

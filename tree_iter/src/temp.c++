#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class BST {
	public:

		struct Node {
			Node(int val) {
				this->val = val;
			}
			int val;
			Node* leftNode;
			Node* rightNode;
		};

		BST(vector<int>& val) {
			for (int i = 0; i < val.size(); ++i) {
				add(val[i]);
			}
		}

		void add(int val) {
			root = add(val, root);
		}


		void print() {
			print(root);
			cout << endl;
		}

	private:
		void print(Node* node) {
			if (node == nullptr) return; 
			print(node->leftNode);
			cout << node->val << " " ;
			print(node->rightNode);
		}

		Node* add(int val, Node* node) {
			if (node == nullptr) {
				return new Node(val);
			}

			if (val > node->val) {
				node->rightNode = add(val, node->rightNode);
			} else {
				node->leftNode = add(val, node->leftNode);
			}
			return node;
		}


		Node* root = nullptr;
		friend class Iter;
};

class Iter {
	public:
		Iter(const BST& tree) {
			BST::Node* root = tree.root;
			while (root != nullptr) {
				sta.push(root);
				root = root->leftNode;
			}
		}

		bool hasNext() {
			return sta.size() != 0;
		}

		int next() {
			BST::Node* node = sta.top(); sta.pop();
			BST::Node* right = node->rightNode;
			while (right != nullptr) {
				sta.push(right);
				right = right->leftNode;
			}
			return node->val;
		}

	private:

		stack<BST::Node*> sta;
};


//what's next.  right is next.
//
///what's prev. left if previous. 
//for the node. node''s  previous 
//previous In next. 
//
//have to remember what's previous . 



class Iterator {
	public:

	private:

};


//node.  i just visited tis guy
//
//current node.   current ndoe'next. next 2 3  has next. yest. 2 ok. visited 2.  
// has next yes. tha't 3
// yoru next is 3.   do you have previous?1  . yes. the previous is 1

int main() {
	vector<int> vals = {5, 3,7,1,4,6,8,9};
	BST tree(vals);
	tree.print();

	Iter iter(tree);
	while (iter.hasNext()) {
		cout << iter.next() << " ";
	}
	cout << endl;
}

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

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

	public:
		Node* root = nullptr;
};


//   () val ()

vector<int> to_vector(const string & str) {
	vector<int> ret;
	for (int i = 0;  i < str.size();) {
		char c = str[i];
		if (isdigit(c)) {
			int start = i;
			while (i < str.size() && isdigit(str[i])) {
				++i;
			} 
			string num = str.substr(start, i - start);
			ret.push_back(stoi(num));
		} else {
			++i;
		}
	}
	return ret;
}



string subtress(BST::Node* node, vector<vector<int>>& duplicates, unordered_set<string>& subs) {
	if(node == nullptr) return "";
	string left = subtress(node->leftNode, duplicates, subs);
	string right = subtress(node->rightNode, duplicates, subs);
	string str = to_string(node->val) + "(" + left + ")" + "(" + right + ")";
	cout << str << endl;
	auto it = subs.find(str);
	if (it != subs.end()) {
		duplicates.push_back(to_vector(str));
	} else {
		subs.insert(str);
	}
	return str;
}

//	2
//1		3
//
//1#2#3
//

vector<vector<int>> subtress(BST::Node* node) {
	vector<vector<int>> ret;
	unordered_set<string> subs;
	subtress( node, ret, subs);
	return ret;
}

int main() {
	//vector<int> vals = {5, 3,7,1,4,6,8,9};
//	vector<int> vals = {1,2,4,3,2,4,4};
//	BST tree(vals);
//	tree.print();

	typedef BST::Node Node;

	Node* root = new Node(1);
	root->leftNode = new Node(2);
	root->rightNode = new Node(3);

	root->leftNode->leftNode = new Node(4);
	root->rightNode->leftNode = new Node(2);
	root->rightNode->leftNode->leftNode = new Node(4);
	root->rightNode->rightNode = new Node(4);

	vector<vector<int>> ret = subtress(root);

	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; j < ret[i].size(); ++j) {
			cout << ret[i][j] << "  ";
		}
		cout << endl;
	}
}

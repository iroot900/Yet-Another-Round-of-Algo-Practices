#include <iostream>
#include <vector>
#include <queue>
using namespace std;


//dictionary
//
////return search once type in someting, return the most frequeuncy 5. then anything used then we count + 1;


class Trie {
	private:
		struct Node {
			Node() : children(26, nullptr) {}
			bool leaf = false;
			int count = 0;
			vector<Node*> children;
		};
		Node* root = new Node();

	public : 
		void add(const string& word) { //multiple add then count + 1;
			Node* cur = root;
			for (int i = 0; i < word.size(); ++i) {
				char c = word[i];
				if(cur->children[c - 'a'] == nullptr) {
					cur->children[c - 'a'] = new Node();
				}
				cur = cur->children[c - 'a'];
			}
			cur->leaf = true;
			cur->count += 1;
		}

		class myComp {
			public:
				bool operator () (pair<int, string>& left, pair<int, string>& right) const {
					return left.first > right.first;
				}
		};

		vector<string> typeIn(const string& word) const {
			priority_queue<pair<int, string>, vector<pair<int,string>>, myComp> pq;

			Node* cur = root;
			for (int i = 0; i < word.size(); ++i) {
				char c = word[i];
				if(cur->children[c-'a'] == nullptr) return {};
				cur = cur->children[c-'a'];
			}

			typeIn(word, cur, pq);

			vector<string> ret;
			//:cout << " ? "  <<  pq.size() << endl;
			while (pq.size() != 0) {

				ret.push_back(pq.top().second); pq.pop();
			}

			return ret;
		}

		void typeIn(string word, Node* node, priority_queue<pair<int, string>, vector<pair<int,string>>, myComp>& pq, int size = 5) const {
			//cout << word << endl;
			if (node == nullptr) return;
			if (node->leaf == true) {
				if (pq.size() < 5 || pq.top().first < node->count) {
					pq.push({node->count, word});
				}
				if (pq.size() > 5)
				pq.pop();
			}

			for (int i = 0; i < node->children.size(); ++i) {
				typeIn(word + string(1, (char)(i + 'a')), node->children[i], pq);
			}
		}

};

int main() {
	vector<int> ve(23,1);
	Trie trie;
	trie.add("a");
	trie.add("ab");
	trie.add("abc");
	trie.add("abcd");
	trie.add("abcde");
	trie.add("abcdef");
	trie.add("abcdef");
	trie.add("abcdef");
	trie.add("abcdefg");
	trie.add("abcdefgh");
	trie.add("abcdefgh");

	vector<string> test1 = trie.typeIn("a");
		cout << test1.size() << " " << endl;;
	for (string str : test1) {
		cout << str << endl;
	}
}

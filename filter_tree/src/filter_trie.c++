#include <iostream>
#include <vector>
using namespace std;


class Trie {
	public:
		class Node {
			public :
			Node () {
				for (int i = 0; i < 27; ++i) {
					children[i] = nullptr;
				}
			}
			Node* children[27];
			bool leaf = false;	
		};

	private:
		Node* root = new Node();
	public:
		void add(const string& word) {
			Node* cur = root;
			for (int i = 0; i < word.size(); ++i) {
				char c = word[i];
				int index = 0;
				if (c == '*') index = 26; 
				else index  = c - 'a';
				if (cur->children[index] == nullptr) 
					cur->children[index] = new Node();
				cur = cur->children[index];
			}
			cur->leaf = true;
		}

		bool filtered(const string& word) const { 
			return filtered(word, root);
		}

		bool filtered(const string& word, Node* cur) const {
			//cur == nullptr
			for (int i = 0; i < word.size(); ++i) { //let's do it.. this is fun.
				char c = word[i];
				if (cur->children[26] != nullptr) {
					for (int j = i; j <= word.size(); ++j) { // for i and j.. so all the j and i..
						if (filtered(word.substr(j), cur->children[26])) {
							return true;
						}
					}
				}

				if (cur->children[c - 'a'] == nullptr) {
					return false;
				} 
				cur = cur->children[c - 'a'];
			}
			if (cur->children[26] != nullptr && cur->children[26]->leaf) return true; //this guy next 

			return cur->leaf;
		}
};

vector<bool> filter(vector<string>& filters, vector<string> & words) {
	Trie trie;
	for (string& filter : filters) {
		trie.add(filter);
	}

	vector<bool> ret;
	for (int i = 0; i < words.size(); ++i) {
		ret.push_back(trie.filtered(words[i]));
	}
	return ret; 
}


void print(vector<string>& filters, vector<string>& words, vector<bool>& ret) {
	cout << "filters : " ;
	for (int i = 0; i < filters.size(); ++i) {
		cout << filters[i] << " , ";
	}
	cout << endl;


	cout << "words: " ;
	for (int i = 0; i < words.size(); ++i) {
		cout << words[i] << " , ";
	}
	cout << endl;

	cout << "ret: " ;
	for (int i = 0; i < ret.size(); ++i) {
		cout << ret[i] << " , ";
	}
	cout << endl;



}

int main() {
	vector<string> test1;
	test1.push_back("abc");

	vector<string> words1;
	words1.push_back("abc");
	words1.push_back("ab");

	auto ret1 = filter(test1, words1);
	print(test1, words1, ret1);

	test1.push_back("ab*");
	test1.push_back("a*bc");

	words1.push_back("abcd");
	words1.push_back("ac");
	words1.push_back("adc");

	words1.push_back("af");
	words1.push_back("ef");
	words1.push_back("abc");
	words1.push_back("a1bc");
	words1.push_back("a12bc");
	words1.push_back("a");
	auto ret2 = filter(test1, words1);
	print(test1, words1, ret2);
}

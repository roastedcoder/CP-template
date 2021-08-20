const int size = 26; // please change

class TrieNode {
	public:
	bool isEnd;
	TrieNode* child[size];
	TrieNode() {
		isEnd = false;
		for(int i = 0; i<size; i++) {
			child[i] = NULL;
		}
	}
	/*
		-> it is just a node
	*/
};

class trie {
	public:
	TrieNode *getNode() {
		TrieNode *node = new TrieNode();
		return node;
	}
	
	void insert(TrieNode *root, string a) {
		TrieNode *curr = root;
		for(int i = 0; i<(int)a.length(); i++) {
			if(curr->child[a[i]-'a'] == NULL) {
				curr->child[a[i]-'a'] = getNode();
			}
			
			curr = curr->child[a[i]-'a'];
		}
		curr->isEnd = true;
	}
	
	bool search(TrieNode *root, string a) {
		TrieNode *curr = root;
		for(int i = 0; i<(int)a.length(); i++) {
			if(curr->child[a[i]-'a'] == NULL) return false;
			curr = curr->child[a[i]-'a'];
		}
		if(curr->isEnd)
			return true;
		return false;
	}
	
	bool hasPrefix(TrieNode *root, string a) {
		TrieNode *curr = root;
		for(int i = 0; i<(int)a.length(); i++) {
			if(curr->child[a[i]-'a'] == NULL) return false;
			curr = curr->child[a[i]-'a'];
		}
		return true;
	}
	/*
		-> create a root first
		-> eg: trie Trie;
		-> use Trie.getNode() to get a node
		-> TrieNode* root = Trie.getNode();
		-> use Trie.insert(root, string) to insert
		-> use Trie.search(root, string) to search a complete word
		-> use Trie.hasPrefix(root, string) to check if any string is there as prefix
		-> *change size accordingingly
		-> uses (after modification):
			-> search sugggestion
			-> dictionary
			-> spell checker
			-> to solve many XOR related problem
	*/
};
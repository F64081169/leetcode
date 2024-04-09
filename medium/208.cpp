class Trie {
private:
    struct Node {
        Node* arr[26]; // NULL
        bool flag = false;
    };
	Node *root;

public:   
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        int n = word.size();
		Node* node = root;  // creted dummpy root so that root doesnot alter
		for (int i = 0; i < n; i++) {
			if (node->arr[word[i] - 'a'] == NULL) {
				node->arr[word[i] - 'a'] = new Node();
			}
			node = node->arr[word[i] - 'a'];
		}
		node->flag = true;
    }
    
    bool search(string word) {
        int n = word.size();
		Node* node = root;
		for (int i = 0; i < n; i++) {
			if (node->arr[word[i] - 'a'] == NULL) {
				return false;
			}
			node = node->arr[word[i] - 'a'];
		}
		return node->flag;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();
		Node* node = root;
		for (int i = 0; i < n; i++) {
			if (node->arr[prefix[i] - 'a'] == NULL) {
				return false;
			}
			node = node->arr[prefix[i] - 'a'];
		}
		return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

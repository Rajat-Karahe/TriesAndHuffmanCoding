//Given a list of n words and a pattern p that we want to search. Check if the pattern p is present the given words or not.
//Return true or false.

#include <string>
#include <vector>
class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
	TrieNode *root;

	public :
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}
    
    bool searchWord(TrieNode *root, string word){
        if(word.size() == 0){
            return true;
        }
        
        int index = word[0] - 'a';
        TrieNode *child;
        if(root->children[index] != NULL){
            child = root->children[index];
            return searchWord(child, word.substr(1));
        }
        
        return false;
    }
    
    bool search(string word) {
        return searchWord(root, word);
    }

	bool insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			if (!root->isTerminal) {
				root -> isTerminal = true;
				return true;	
			} else {
				return false;
			}
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		// Recursive call
		return insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		if (insertWord(root, word)) {
			this->count++;
		}
	}

	bool patternMatching(vector<string> vect, string pattern) {
		for(int i=0; i<vect.size(); i++){
            string temp = vect[i];
            for(int j=0; j<temp.size(); j++){
                insertWord(temp.substr(j));
            }
        }
        
        return search(pattern);
	}
};

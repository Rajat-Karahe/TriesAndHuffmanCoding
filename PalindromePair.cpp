//Givan n number of words, you need to find if there exist any two words which can be joined to make a palindrome or any word itself is a palindrome.
//Return true or false.

#include <string>
#include <vector> 
class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;
	int childCount;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
		childCount = 0;
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
			root->childCount++;
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

	bool searchWord(TrieNode *root, string word){
        if(word.size() == 0){
            return root->isTerminal;
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

	bool findIfPalindromePair(vector<string> arr) {
        for(int i=0; i<arr.size(); i++){
            string word = arr[i];
            string reverse = "";
            for(int j=word.size()-1; j>=0; j--){
                reverse += word[j];
            }
            insertWord(reverse);
        }
        
        for(int i=0; i<arr.size(); i++){
            string word = arr[i];
            if(search(word) || search(word.substr(0, word.size()-1))){
                return true;
            }
        }
        
        return false;
	}
};

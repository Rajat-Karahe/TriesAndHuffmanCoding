//Givan n number of words and an incomplete word w. You need to auto-complete that word w.
//That means, find and print all the possible words which can be formed using the incomplete word w.

// #include "TrieNode.h"
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
    
    TrieNode* findWord(TrieNode* root, string word){
        if(word.size() == 0){
            return root;
        }
        
        int index = word[0] - 'a';
        TrieNode *child;
        if(root->children[index] != NULL){
            child = root->children[index];
            return findWord(child, word.substr(1));
        }
        
        return NULL;
    }
    
    void printAllWords(TrieNode *root, string ans){
        if(root->isTerminal){
            cout << ans << endl;
        }
        
        for(int i=0; i<26; i++){
            if(root->children[i] != NULL){
                string childStr = ans;
                TrieNode *child = root->children[i];
                childStr += child->data;
                printAllWords(child, childStr);
            }
        }
    }
    
    void autoComplete(vector<string> input, string pattern) {
        for(int i=0; i<input.size(); i++){
            string word = input[i];
            insertWord(word);
        }
        
        TrieNode *output = findWord(root, pattern);
        if(output == NULL){
            return;
        }
        
        string ans = pattern;
        printAllWords(output, ans);
    }
    
};

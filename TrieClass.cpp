class TrieNode {
    public:
    char data;
    TrieNode** children;
    bool isTerminal;
    
    TrieNode(char data){
        this->data = data;
        children = new TrieNode*[26];
        for(int i=0 i<26; i++){
          children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    TrieNode *root;
    
    public:
    Trie(){
        root = new TrieNode('\0');
    }
    
    void insertWord(TrieNode *root, string word){
        //Base Case
        if(word.size() == 0){
            root->isTerminal = true;
            return;
        }
        
        //Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        
        //Recursive Call
        insertWord(child, word.substr(1));
    }
    
    //For user
    void insertWord(string word){
        insertWord(root, word);
    }
};



// Created on : 14 May, 2020

// Title : Implement Trie (prefix tree)

// Author : Shiwangi Garg

class TrieNode{
public:
    char data;
    TrieNode **children;
    bool isTerminal;
    TrieNode(char data){
        this->data = data;
        children = new TrieNode*[26];
        for(int i = 0;i < 26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    Trie() {
        root = new TrieNode('\0');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        insertHelper(word,root);
    }
    
    void insertHelper(string word,TrieNode *root){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if(root->children[index] == NULL){
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }else{
            child = root->children[index];
        }
        insertHelper(word.substr(1),child);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchHelper(word,root);
    }
    
    bool searchHelper(string word,TrieNode *root){
        if(root == NULL){
            return false;
        }
        if(word.length() == 0){
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        if(root->children[index] == NULL){
            return false;
        }else{
            return searchHelper(word.substr(1),root->children[index]);
        }
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return startsWithHelper(prefix,root);
    }
    
    bool startsWithHelper(string prefix,TrieNode *root){
        if(prefix.length() == 0){
            return true;
        }
        if(root == NULL){
            return false;
        }
        int index = prefix[0] - 'a';
        if(root->children[index] == NULL){
            return false;
        }else{
            return startsWithHelper(prefix.substr(1),root->children[index]);
        }
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

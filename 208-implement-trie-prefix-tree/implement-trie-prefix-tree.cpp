class Trie {
private:
    struct TrieNode {
        TrieNode *children[26];
        int wordCount;

        TrieNode() : children(), wordCount(0) {}
    };

    TrieNode *root;

public:
    Trie() {
        this->root = new TrieNode();
    }
    
    void insert(string word) {
        
        TrieNode *temp = this->root;

        for (char ch : word) {
            if (!temp->children[ch - 'a'])
                temp->children[ch - 'a'] = new TrieNode();

            temp = temp->children[ch - 'a'];
        }

        temp->wordCount++;

    }
    
    bool search(string word) {

        TrieNode *temp = this->root;

        for (char ch : word)
            if (temp->children[ch - 'a'])
                temp = temp->children[ch - 'a'];
            else
                return false;
        
        return (temp->wordCount > 0);
        
    }
    
    bool startsWith(string prefix) {

        TrieNode *temp = this->root;

        for (char ch : prefix)
            if (temp->children[ch - 'a'])
                temp = temp->children[ch - 'a'];
            else
                return false;
        
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
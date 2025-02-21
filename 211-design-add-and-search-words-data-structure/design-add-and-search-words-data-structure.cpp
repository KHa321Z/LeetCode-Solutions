class WordDictionary {
private:
    struct TrieNode {
        TrieNode *children[26];
        int wordCount;

        TrieNode() : children(), wordCount(0) {}
    };

    TrieNode *root;

    bool ambSearch(string& word, TrieNode* node, int index) {

        if (!node)
            return false;

        if (index == word.length())
            return (node->wordCount > 0);

        if (word[index] != '.')
            return this->ambSearch(word, node->children[word[index] - 'a'], index + 1);
        
        else
            for (int i = 0; i < 26; i++)
                if (this->ambSearch(word, node->children[i], index + 1))
                    return true;
        
        return false;

    }

public:
    WordDictionary() {
        this->root = new TrieNode();
    }
    
    void addWord(string word) {

        TrieNode *temp = this->root;

        for (char ch : word) {
            if (!temp->children[ch - 'a'])
                temp->children[ch - 'a'] = new TrieNode();

            temp = temp->children[ch - 'a'];
        }

        temp->wordCount++;
        
    }
    
    bool search(string word) {
        return this->ambSearch(word, this->root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
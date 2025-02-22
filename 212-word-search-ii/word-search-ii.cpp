class Solution {
private:
    class Trie {
    public:
        struct TrieNode {
            TrieNode *children[26];
            int wordEnd;

            TrieNode() : children(), wordEnd(-1) {}
        };

        TrieNode *root;

        Trie() : root(new TrieNode()) {}

        void add(string& word, int index) {

            TrieNode *temp = this->root;

            for (char ch : word) {
                if (!temp->children[ch - 'a'])
                    temp->children[ch - 'a'] = new TrieNode();

                temp = temp->children[ch - 'a'];
            }

            temp->wordEnd = index;

        }

        void search(vector<string>& words, vector<string>& result, vector<vector<char>>& board, vector<vector<bool>>& isVisited, pair<int, int> coords, TrieNode* node) {

            if (!node->children[board[coords.first][coords.second] - 'a'])
                return;

            node = node->children[board[coords.first][coords.second] - 'a'];

            if (node->wordEnd != -1)
                result.push_back(words[node->wordEnd]), 
                node->wordEnd = -1;

            isVisited[coords.first][coords.second] = true;

            for (int i = -1; i <= 1; i += 2) {
                if ((coords.first + i >= 0) && (coords.first + i < board.size()) && !isVisited[coords.first + i][coords.second])
                    search(words, result, board, isVisited, { coords.first + i, coords.second }, node);

                if ((coords.second + i >= 0) && (coords.second + i < board[coords.first].size()) && !isVisited[coords.first][coords.second + i])
                    search(words, result, board, isVisited, {coords.first, coords.second + i}, node);
            }

            isVisited[coords.first][coords.second] = false;
            
        }

    };

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        Trie trie;
        vector<string> result;

        for (int i = 0; i < words.size(); i++)
            trie.add(words[i], i);

        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++) {
                vector<vector<bool>> isVisited(board.size(), vector<bool>(board[i].size()));
                trie.search(words, result, board, isVisited, { i, j }, trie.root);
            }

        return result;

    }
};
class Trie {
public:
    /** Initialize your data structure here. */
    vector<Trie*> children;
    int prefix_count, leaf_count;
    
    Trie() {
        children.resize(26, NULL);
        prefix_count = 0;
        leaf_count = 0;
    }
    
    void insert_util(Trie* node, string &word, int i){
        if(i == word.size()){
            node->prefix_count++;
            node->leaf_count++;
            return;
        }
        node->prefix_count++;
        if(!node->children[word[i] - 'a'])
            node->children[word[i] - 'a'] = new Trie();
        insert_util(node->children[word[i] - 'a'], word, i + 1);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if(!word.size())
            return;
        insert_util(this, word, 0);
    }
    bool search_util(Trie* node, string& word, int i){
        if(!node)
            return false;
        if(i == word.size())
            return node->leaf_count > 0;
        return search_util(node->children[word[i] - 'a'], word, i + 1);
    }
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if(!word.size())
            return true;
        return search_util(this, word, 0);
    }  
    
     bool startsWith_util(Trie* node, string& prefix, int i){
        if(!node)
            return false;
        if(i == prefix.size())
            return node->prefix_count > 0;
        return startsWith_util(node->children[prefix[i] - 'a'], prefix, i + 1);
    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(!prefix.size())
            return true;
        return startsWith_util(this, prefix, 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

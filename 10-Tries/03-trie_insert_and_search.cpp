void insert(struct TrieNode *root, string word)
{
    TrieNode *node = root;
    for(int i = 0; i < word.size(); i++) {
        int ind = word[i] - 'a';
        
        if(!node->children[ind])  
            node->children[ind] = getNode();
        
        node = node->children[ind];
    }
    node->isLeaf = true;
}

bool search(struct TrieNode *root, string key) 
{
    TrieNode *node = root;
    for(int i = 0; i < key.size(); i++) {
        if(!node->children[key[i] - 'a']) 
            return false;
        else
            node = node->children[key[i] - 'a'];
    }
    return node->isLeaf;
}
class Solution{
    class Node{
    public:
        char data;
        Node* children[26];
        bool isTerminal;
        Node(char ch)
        {
            data = ch;
            for(int i = 0; i < 26; i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
    };
    class Trie{
        public:
        Node* root;
        Trie()
        {
            root = new Node('\0');
        }
        void insert(Node* root, string key)
        {
            if(key.length() == 0)
            {
                root -> isTerminal = true;
                return;
            }
            int index = key[0] - 'a';
            Node* child;
            if(root -> children[index] != NULL)
                child = root -> children[index];
            else
            {
                child = new Node(key[0]);
                root -> children[index] = child;
            }
            insert(child, key.substr(1));
        }
        void insertWord(string word)
        {
            insert(root, word);
        }
        void printSuggestions(Node* curr, vector<string> &temp, string prefix)
        {
            if(curr -> isTerminal)
                temp.push_back(prefix);
            for(char ch = 'a'; ch <= 'z'; ch++)
            {
                Node* next = curr -> children[ch-'a'];
                if(next != NULL)
                {
                    prefix.push_back(ch);
                    printSuggestions(next, temp, prefix);
                    prefix.pop_back();
                }
            }
        }
        vector<vector<string> > getSuggestions(string str)
        {
            Node* prev = root;
            vector<vector<string>> output;
            string prefix = "";
            int i = 0;
            for(int i = 0; i < str.length(); i++)
            {
                char lastch = str[i];
                prefix.push_back(lastch);
                Node* curr = prev->children[lastch - 'a'];
                if(curr == NULL)
                    break;
                vector<string> temp;
                printSuggestions(curr, temp, prefix);
                output.push_back(temp);
                temp.clear();
                prev = curr;
            }
            if( i < str.size()){
                while( i < str.size()){
                    output.push_back({"0"});
                    i++;
                }
            }
            return output;
        }
    };
    public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Trie *t = new Trie();
        for(int i = 0; i < n; i++)
        {
            string str = contact[i];
            t->insertWord(str);
        }
        return t->getSuggestions(s);
    }
};
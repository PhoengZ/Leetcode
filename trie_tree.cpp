class Trie {
public:
    int n;
    set<string>s;
    vector<string>v;
    Trie() {
        n = 0;
    }
    
    void insert(string word) {
        n++;
        v.push_back(word);
        s.insert(word);
    }
    
    bool search(string word) {
        if (s.count(word)){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        for (int i =0;i<n;i++){
            if (v[i].starts_with(prefix)){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
class TrieNode{
    public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode(){
        for(int i=0;i<26;i++) children[i]=NULL;
        isEnd=false;
    }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root= new TrieNode();
    }
    
    void addWord(string word) {
        int n= word.size();
        TrieNode* parent= root;
        for(int i=0;i<n;i++){
            int idx= word[i]-'a';
            if(parent->children[idx]==NULL){
                parent->children[idx]=new TrieNode();
            }
            parent= parent->children[idx];
        }
        parent->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode* parent= root;
        return find(word,0,parent);    
    }
    //word[i] ko find krna hai in children of parent node.
    bool find(string &word, int i, TrieNode* parent){
        if(i==word.size()) return parent->isEnd;
         if(word[i]=='.'){ 
            for(int j=0;j<26;j++){
                if(parent->children[j]!=NULL){
                   if(find(word,i+1,parent->children[j])==true) return true;
                }
            }
        }
        else {
            int idx= word[i]-'a';
            if(parent->children[idx]!=NULL){
                if(find(word, i+1,parent->children[idx])==true) return true;
            }
        }
        return false;
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
struct Node{
    Node *links[26];
    bool flag=false;

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node *node){
        links[ch-'a']=node; 
    }
    Node *get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};

class WordDictionary {
private:
    Node *root;
public:
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    bool searchHelper(string &word,int idx,Node *node){
        if(idx==word.size()) return node->isEnd();
        char ch=word[idx];
        if(ch=='.'){
            for(int i=0;i<26;i++){
                if(node->links[i] && searchHelper(word,idx+1,node->links[i]))
                return true;
            }
            return false;
        }

        if(!node->containsKey(word[idx])) return false;

        return searchHelper(word,idx+1,node->get(ch));
    }
    
    bool search(string word) {
        return searchHelper(word,0,root);
    }
};

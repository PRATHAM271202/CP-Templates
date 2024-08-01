class Node{
     
    public:

    Node* links[26];
    bool flag=false;
    int endsWith=0;
    int cnt=0;

    bool containsKey(char c){
        return links[c-'a']!=NULL;
    }

    void put(char c,Node* node){
        links[c-'a']=node;
    }
    
    Node* get(char c){
        return links[c-'a'];
    }

    void setEnd(){
        flag=true;
    }
    
    bool getEnd(){
        return flag;
    }
     
};

class Trie {
public:
    Node *root;
    Trie() {
       root= new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                 node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            (node->cnt)++;
        }
        node->setEnd();
        (node->endsWith)++;
    }
    
    bool search(string word) {
         Node* node=root;
         for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])) return false;
            node=node->get(word[i]);
         }
         return node->getEnd();
    }
    
    bool startsWith(string prefix) {
         Node* node=root;
         for(int i=0;i<prefix.size();i++){
            if(!node->containsKey(prefix[i])) return false;
            node=node->get(prefix[i]);
         }
         return true;
    }

    int countWordsEqualTo(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])) return false;
            node=node->get(word[i]);
        }
        return node->endsWith;
    }

    int countWordsStartingWith(string &word){
         Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])) return 0;
            node=node->get(word[i]);
        }
        return node->cnt;
    }

    void erase(string &word){
          Node* node=root;
        for(int i=0;i<word.size();i++){
            
            node=node->get(word[i]);
            (node->cnt)--;
        }
        (node->endsWith)--;
    }
};
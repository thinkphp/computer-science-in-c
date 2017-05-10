#include <iostream>
#include <string>
#define ALPHABET 26

using namespace std;

typedef struct trie {

   bool isleaf;
   struct trie *arr[ALPHABET];     

} trienode;

trienode* create_trie(){

          trienode *temp = (trienode*)malloc(sizeof(trienode));

          for(int i = 0; i < ALPHABET; i++) {
          
                  temp->arr[ i ] = NULL;  
          }      

          return temp;
}

void insert_trie(trienode *root, string str){

     int n = str.length();

     for(int i = 0; i < n; ++i) {

             if(!root->arr[str[i]-'a']) {

                 trienode *temp = create_trie();

                 root->arr[str[i]-'a'] = temp;
             }

             root = root->arr[str[i]-'a'];
     }  

     root->isleaf = true; 
}

int search_trie(trienode *root, string str){

     int n = str.length();

     for(int i = 0; i < n; ++i) {

         if(root->arr[str[i]-'a']) root = root->arr[str[i]-'a'];

                else return 0;   
     } 

     if(root->isleaf) return 1;

     return 0; 
}

int main() {
    int T;
    cin>>T;
    while(T--){
    int n;    
    cin>>n;
    string str;
    trienode *root = create_trie();
    for(int i = 0; i < n; ++i) {
        cin>>str;
        insert_trie(root, str);
    }
    string findstr; 
    cin>>findstr;
    int val = search_trie(root,findstr);
    cout<<val<<endl;
    }
return(0);
}

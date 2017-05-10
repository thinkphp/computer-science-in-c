/**
 *  Trie Data Structure
 */
#include <fstream>
#include <iostream>
#include <string>
#define FIN "trie.in"
#define FOUT "trie.out"
#define MAXC 26

using namespace std;

struct Trie {
       
       int num_words,

           num_prefixes;  

       struct Trie *next[ MAXC ];

       Trie() {

           num_words = num_prefixes = 0;

           for(int i = 0; i < MAXC; ++i) next[ i ] = NULL;
       }; 

       void insert_word(string word) {

            struct Trie *root = this;

            int next_char; 

            int n = word.length();

            for(int i = 0; i < n; i++) {

                next_char = word[ i ] - 'a';

                if(root->next[ next_char ] == NULL) root->next[ next_char ] = new struct Trie();

                 root = root->next[ next_char ];   

                 root->num_prefixes++;  
            }

            root->num_words++;   
       };

       int search(string word) {

            struct Trie *root = this;

            int next_char; 

            int n = word.length();

            for(int i = 0; i < n; i++) {

                next_char = word[ i ] - 'a';

                if(root->next[ next_char ] == NULL) return 0;

                 root = root->next[ next_char ];   
            }

            return root->num_words; 
       };

       int request_longest_common_prefix(string word) {

            struct Trie *root = this;

            int next_char, 

                longest_prefix = 0,

                n = word.length(); 

            for(int i = 0; i < n; i++) {

                next_char = word[ i ] - 'a';

                if(root->next[ next_char ] == NULL) return longest_prefix;

                 root = root->next[ next_char ];

                if(root->num_prefixes == 0) return longest_prefix;

                longest_prefix++;
            }

            return longest_prefix; 

       };
  
       void remove_word(string word) {

            struct Trie *root = this;

            int next_char; 

            int n = word.length();

            for(int i = 0; i < n; i++) {

                next_char = word[ i ] - 'a';

                if(root->next[ next_char ] == NULL) root->next[ next_char ] = new struct Trie();

                 root = root->next[ next_char ];   

                 root->num_prefixes--;  
            }

            root->num_words--;   
       };
};

typedef unsigned int  uint;

int main() {

    int type; 

    string str;

    ifstream fin( FIN );

    ofstream fout( FOUT );

    struct Trie *root = new struct Trie();

    while( fin>>type>>str ) {

           switch( type ) {

                   case 0: root->insert_word( str );
                   break; 

                   case 1: root->remove_word( str );
                   break; 

                   case 2: fout<<root->search( str )<<"\n";
                   break; 

                   case 3: fout<<root->request_longest_common_prefix( str )<<"\n";
                   break; 
           }
    }

    fin.close();

    fout.close();

    return(0); 
};

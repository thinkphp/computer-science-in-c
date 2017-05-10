/**
 *
 *  Trie is an efficient information reTRIEval Data Structure.
 *
 */
#include <fstream>
#include <cstring>
#define FIN "trie.in"
#define FOUT "trie.out"
#define ALPHABET_SIZE 26
#define C (*s - 'a') 

using namespace std;

struct Trie {
 
       int words,

           pref;
 
       Trie *sons[ ALPHABET_SIZE ];

       Trie() {

           words = pref = 0; 

           memset(sons, 0, sizeof(sons)); 
       }
};

struct Trie *T = new struct Trie();

void add_word(struct Trie *node, char *s) {

     if(*s == '\0') { 
 
         node->words++; 

         return;
     }

     if(node->sons[ C ] == 0) {

        node->sons[ C ] = new Trie;
 
        node->pref++; 
     }

     add_word(node->sons[ C ], s + 1);      
};

bool delete_word(struct Trie *node, char *s) {

     if(*s == '\0') { 

               node->words--;
     }

     else {

          if(delete_word(node->sons[ C ], s + 1)) {

             node->pref--;

             node->sons[ C ] = NULL;
          }
     }  

     if(node->pref == 0 && node->words == 0 && node != T) {

        delete node;

        return 1;    
     }

     return 0;  
};

int count_words(struct Trie *node, char *s) {

     if(*s == '\0') return node->words; 

     if(node->sons[ C ] == 0) return 0;

     return count_words( node->sons[ C ], s + 1 );      
};

int longest_common_prefix(struct Trie *node, char *s, int prefix) {

     if(*s == '\0' || node->sons[ C ] == 0)

               return prefix; 

     if( node->sons[ C ] != 0 )

               return longest_common_prefix( node->sons[*s - 'a'], s + 1, prefix + 1 );

};

int main() {

    int type; 

    char str[ ALPHABET_SIZE ];

    ifstream fin( FIN );

    ofstream fout( FOUT );    

    while( fin>>type>>str ) {

           switch( type ) {

                   case 0: add_word(T, str);
                   break; 

                   case 1: delete_word(T, str);
                   break; 

                   case 2: fout<<count_words(T, str)<<"\n";
                   break; 

                   case 3: fout<<longest_common_prefix(T, str, 0)<<"\n";
                   break; 
           }
    }

    fin.close();

    fout.close();

    return(0); 
};

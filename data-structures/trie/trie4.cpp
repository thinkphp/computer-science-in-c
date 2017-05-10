#include <fstream>
#include <iostream>
#include <cstring>
#define FIN "trie.in"
#define FOUT "trie.out"
#define ENG_ALPHABET 26
#define ALPHABET_SIZE 'z'-'a'+1

using namespace std;

class Trie {

      public:
      int num_words, num_sons;
      Trie *sons[ ALPHABET_SIZE ];
 
      Trie() {
 
          num_words = 0; num_sons = 0;

          memset(sons, 0, sizeof( sons ));
      };

      void insert(string word); 
      void remove(string word); 
      int search_occurence(string word);  
      int longest_prefix(string word);  
};

void Trie::insert(string word) {

     int i, 

         n = int( word.length() );

     Trie *root = this;

     for(i = 0; i < n; i++) {

         if(!root->sons[ word[i] - 'a' ]) { 

             root->sons[ word[i] - 'a' ] = new Trie();
         }

         root = root->sons[ word[i] - 'a' ];

         root->num_sons++; 
     }

     root->num_words++;
};

void Trie::remove(string word) {

     int i, 

         n = int( word.length() );

     Trie *root = this, 

          *temp;

     for(i = 0; i < n; i++) {

         if(!root->sons[ word[ i ] - 'a' ]) return;

         temp = root;

         root = root->sons[ word[i] - 'a' ];

         root->num_sons--;

         if(temp->num_sons == 0) delete temp;

            else    

         if(root->num_sons == 0) temp->sons[ word[i] - 'a'] = 0;  
     }

     root->num_words--;

     if( root->num_sons == 0 ) delete root; 

};

int Trie::search_occurence(string word) {

     int i, 

         n = int( word.length() );

     Trie *root = this;

     for(i = 0; i < n; i++) {

         if(!root->sons[ word[i] - 'a' ]) return 0;

         root = root->sons[ word[i] - 'a' ];  
     }

     return root->num_words;
};

int Trie::longest_prefix(string word) {

     int i, 

         n = int( word.length() );

     Trie *root = this;

     for(i = 0; i < n; i++) {

         if(!root->sons[ word[i] - 'a' ]) return i;

         root = root->sons[ word[i] - 'a' ];  
     }

     return i;
};

void solve() {

     ifstream fin( FIN );

     ofstream fout( FOUT );

     if(!fin || !fout) {

         cout<<"Error Opening Files"<<endl;
     }

    int type; 

    char str[ ALPHABET_SIZE ];

    Trie *trie = new Trie(); trie->num_sons = 1;

    while( fin>>type>>str ) {

           switch( type ) {

                   case 0: trie->insert( str );
                   break; 

                   case 1: trie->remove( str );
                   break; 

                   case 2: fout<<trie->search_occurence( str )<<"\n";
                   break; 

                   case 3: fout<<trie->longest_prefix( str )<<"\n";
                   break; 
           }
    }    

     fin.close();

     fout.close();
};
 
int main() {

    solve();  

    return(0);
};
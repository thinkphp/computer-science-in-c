#include <stdio.h>
#include <malloc.h>
#define FIN "trie.in"
#define FOUT "trie.out"

struct Trie {

       int num_prefixes,

           num_words;

       struct Trie *sons[ 26 ];

       Trie() {
           
           num_prefixes = num_words = 0;

           for(int i = 0; i < 26; i++) sons[ i ] = 0;
       }; 

       void add(char *s) {

            struct Trie *root = this; 

            while(*s != '\0') {

                   if(root->sons[*s - 'a'] == 0) root->sons[*s - 'a'] = new Trie();

                   root = root->sons[*s - 'a'];

                   root->num_prefixes++; 

                   s++;
            }

            root->num_words++; 
       };

       void erase(char *s) {

            struct Trie *root = this; 

            while(*s != '\0') {

                   root = root->sons[*s - 'a'];

                   root->num_prefixes--; 

                   s++;
            }

            root->num_words--; 
       };

       int search(char *s) {

            struct Trie *root = this; 

            while(*s != '\0') {

                   if(root->sons[*s - 'a'] == 0) return 0;

                   root = root->sons[*s - 'a'];

                   s++;
            }

            return root->num_words; 
       };

       int prefix(char *s) {

            struct Trie *root = this; 

            int longest_prefix = 0;

            while(*s != '\0') {

                   if(root->sons[*s - 'a'] == 0) return longest_prefix;

                   root = root->sons[*s - 'a'];

                   if(root->num_prefixes == 0) return longest_prefix;

                   longest_prefix++;

                   s++;
            }

            return longest_prefix; 
       };

} *root;

int main() {

    freopen(FIN, "r", stdin);

    freopen(FOUT, "w", stdout);

    char str[ 26 ];

    int type; 

    root = new Trie;
 
    while(scanf("%d %s",&type,&str) > 0) {

          switch(type) {

                 case 0: 
                 root->add(str);
                 break;

                 case 1:
                 root->erase(str);
                 break;   

                 case 2:
                 printf("%d\n", root->search(str));
                 break;   

                 case 3:
                 printf("%d\n", root->prefix(str));
                 break;   
          }          
    } 

    fclose( stdin );   

    fclose( stdout );

    return(0);
};
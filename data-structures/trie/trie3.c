#include <stdio.h>
#include <malloc.h>
#define FIN "trie.in"
#define FOUT "trie.out"
#define ALPHABET_SIZE 26
#define SIZE 'z'-'a' + 1
#define CH (*s - 'a')

struct Trie {

       int num_prefixes,
           num_words;
  
       struct Trie *sons[ ALPHABET_SIZE ];
};

struct Trie* createNode() {

       int i;

       struct Trie *node = (struct Trie*)malloc(sizeof(struct Trie));

       node->num_words = node->num_prefixes = 0; 

       for(i = 0; i < ALPHABET_SIZE; i++) node->sons[ i ] = 0;

       return node;          
};

void add(struct Trie* node, char *s) {

         while(*s != '\0') {

               if(node->sons[ CH ] == 0) node->sons[ CH ] = createNode(); 

               node = node->sons[ CH ];

               node->num_prefixes++;
  
               s++;
         }

         node->num_words++; 
};

void erase(struct Trie *node, char *s) {


         while(*s != '\0') {

               node = node->sons[ CH ];

               node->num_prefixes--;
  
               s++;
         }

         node->num_words--; 

};

int search(struct Trie *node, char *s) {

         while(*s != '\0') {

               if(node->sons[ CH ] == 0) return 0;

               node = node->sons[ CH ];
  
               s++;
         }

         return node->num_words; 
};


int prefix(struct Trie *node, char *s) {

         int pref = 0;

         while(*s != '\0') {

               if(node->sons[ CH ] == 0) return pref;

               node = node->sons[ CH ];
  
               if(node->num_prefixes == 0) return pref;

               s++;

               pref++;
         }

         return pref; 
};

int main() {

    struct Trie* T = createNode();

    int type;

    char str[ SIZE ];

    freopen(FIN, "r", stdin); 

    freopen(FOUT, "w", stdout); 

    while( scanf("%d%s", &type, str) > 0 ) {

           switch( type ) {

                   case 0: 
                   add(T, str);
                   break;

                   case 1: 
                   erase(T, str);
                   break;

                   case 2: 
                   printf("%d\n", search(T, str));
                   break;

                   case 3: 
                   printf("%d\n", prefix(T, str));
                   break;
           }
    }

    free( T );

    fclose( stdin );

    fclose( stdout );

    return(0);
};
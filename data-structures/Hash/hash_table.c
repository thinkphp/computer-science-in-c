//Hash Table
/**
 *  Hash Table Data Structure
 */
#include <stdio.h>
#include <malloc.h>
#define FIN "hashuri.in"
#define FOUT "hashuri.out"
#define ins 1
#define del 2
#define find 3
#define U 666013

struct set {
   int key,
       value;
};

struct set *array;

int size = 0;

int capacity = 1000001;

int hashFunction(int key) {

    return key % U;
}

int checkPrime( int n ) {

}

int getPrime( int n ) {

    return n;
}

int searching( int key ) {

    int index = hashFunction( key );

    return array[ index ].key != 0;
}

void init() {

  capacity = getPrime( capacity );

  array = (struct set*)malloc((capacity) * sizeof(struct set)) ;

  for ( size_t i = 0; i <= (capacity); i++ ) {

        array[i].key = 0;

        array[i].value = 0;
  }
}

void insert_value(int key, int value) {

     int index = hashFunction( key );

     if(searching(value) == 1) return;

     else if(array[ index ].key == 0) {

        //printf("\n Key (%d) has been inserted \n", key);
        array[index].key = key;
        array[index].value = value;
        size++;

     } else if(array[index].key == key) {

            printf("%s\n", "Equal!");

            array[index].value = value;

     } else {

            printf("%s\n", "Collision occured!");
     }
}

void remove_element(int key) {

  if( searching( key ) == 1 ){

    int index = hashFunction(key);

    array[index].key = 0;

    array[index].value = 0;

    size--;
  }
}

int size_hashtable() {

    return size;
}

int get(int key) {

   int index = hashFunction( key );

   if(searching(key) == 1) return array[index].value;

         else
                           return 0;
}

void display() {

     for(int i = 0; i < capacity; ++i) {

       if(array[i].value == 0) {
         printf("array[%d]: __ \n", i);
       } else {
         printf("key: %d; value: %d \n", array[ i ].key, array[ i ].value);
       }

     }
}

int main(int argc, char const *argv[]) {

  init();

  int N, op, x;

  freopen(FIN, "r", stdin);
  freopen(FOUT, "w", stdout);

  scanf("%d\n", &N);

  while(N--) {

    scanf("%d %d", &op, &x);
    if(op == ins) {
       insert_value(x,x);
    } else if(op == del) {
       remove_element(x);
    } else if(op == find) {
       printf("%d\n",searching(x));
    }
  }

  return 0;
}

#include <cstdio>
#include <vector>
#include <queue>
#include <bitset>
#define MAXN 50005
#define oo ((1LL<<31)-1)
#define FIN "bellmanford.in"
#define FOUT "bellmanford.out"

using namespace std;

vector<int> V[ MAXN ];
int distMin[ MAXN ];
queue<int> Queue;
bitset<MAXN> inQueue(0);
int countQueue[ MAXN ];

int nodes,
    edges, 
    ok = 1;

//prototpes functions
void readData();
void BellmanFord();
void writeData();
void display1();
void display2();

//main function
int main() {

    readData();
    BellmanFord();
    writeData();

    return(0);
};

void readData() {

     int x,
         y,
         cost;

     freopen(FIN, "r", stdin);

     scanf("%d %d", &nodes, &edges);

     for(int ed = 1; ed <= edges; ed++) {

         scanf("%d %d %d", &x, &y, &cost);

         V[ x ].push_back( y ); 
         V[ x ].push_back( cost ); 
     }

     fclose( stdin );
};

void BellmanFord() {

     for(int i = 2; i <= nodes; i++) distMin[ i ] = oo;

     distMin[ 1 ] = 0;
  
     Queue.push( 1 );

     inQueue[ 1 ] = true;

     while(!Queue.empty() && ok) {

            int curr = Queue.front();

            Queue.pop();

            inQueue[ curr ] = false;    

            for(int i = 0; i < V[ curr ].size(); i +=2) {

                    int y = V[ curr ][ i + 0 ];

                    int cost = V[ curr ][ i + 1 ];

                    if(distMin[ y ] > distMin[ curr ] + cost) {

                       distMin[ y ] = distMin[ curr ] + cost;

                       if(!inQueue[ y ]) {

                           if(countQueue[ y ] > nodes) {

                              ok = 0; 

                           } else {

                              countQueue[ y ]++;

                              Queue.push( y );

                              inQueue[ y ] = true;
                           }
                       }

                    }
            } 
     }
};

void writeData() {

     if( ok ) {

        display1();

     } else {

        display2();
     } 
}

void display1() {

     freopen(FOUT, "w", stdout);

     for(int i = 2; i <= nodes; i++) printf("%d ", distMin[ i ]);

     fclose( stdout );
};

void display2() {

     freopen(FOUT, "w", stdout);

     printf("%s", "Ciclu negativ!");

     fclose( stdout );
};

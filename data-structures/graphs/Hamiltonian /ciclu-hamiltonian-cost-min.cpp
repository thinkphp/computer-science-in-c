#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream input("hamilton.in");
ofstream output("hamilton.out");

const int INF = 1 << 29;

int main()
{
    int N, M;
    input >> N >> M;

    vector<vector<int>> d(1<<N, vector<int>(N, INF));
    vector<vector<int>> edgeCost(N, vector<int>(N, INF));

    for(int i = 0; i < M; i++){
        int a, b, c;
        input >> a >> b >> c;
        edgeCost[a][b] = c;
    }
    /*
    for(int i = 0; i < N; i++){
        d[0][i] = 0;
    }*/
    d[1][0] = 0;
    for(int i = 0; i < (1<<N); i++){
        for(int j = 0; j < N; j++){
            if((i & (1 << j)) == 0){
                continue;
            }
            for(int k = 0; k < N; k++){
                if(i & (1 << k) == 0 || k == j || edgeCost[k][j] == INF){
                    continue;
                }
                if(d[i][j] > d[i ^ (1 << j)][k] + edgeCost[k][j]){
                    d[i][j] = d[i ^ (1 << j)][k] + edgeCost[k][j];
                }
            }
        }
    }
    int minim = INF;
    for(int i = 1; i < N; i++){
        if(minim > d[(1<<N) - 1][i] + edgeCost[i][0]){
            minim = d[(1<<N) - 1][i] + edgeCost[i][0];
        }
    }
    if(minim == INF){
        output << "Nu exista solutie";
    }
    else{
        output << minim;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
int V = 5; // number of vertices
    vector<vector<int>> adjMatrix(V, vector<int>(V, 0)); //int arr[m][n]
 
    // edges: 0-1, 0-2, 1-3
    adjMatrix[0][1] = adjMatrix[1][0] = 1;
    adjMatrix[0][2] = adjMatrix[2][0] = 1;
    adjMatrix[1][3] = adjMatrix[3][1] = 1;
    adjMatrix[1][4] = adjMatrix[4][1] = 1;
    
    // print matrix
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++)
            cout << adjMatrix[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
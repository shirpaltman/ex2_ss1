
#include <stdio.h>
#include "my_mat.h"
int dist[4][4];
int matrix[4][4];
int floydRun=0;
int V = 4;
int main() {
    scanMatrix();
    ifHasPath(0,0);
    floydWarshall();
    printMatrix();
    
    return 0;
}

void scanMatrix() {
    printf("Enter values to the matrix:");
    int scanfChar = 0;
    for(int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d\t", &scanfChar);
            matrix[i][j] = scanfChar;
            dist[i][j] = scanfChar;
        } 
    }
    printf("finished");
}

void floydWarshall() {
    int  i, j, k;

    
    // Add all vertices one by one to the set of intermediate vertices.
    // Before start of an iteration, we have shortest distances between all pairs of vertices such that
    // the shortest distances consider only the vertices in set {0, 1, 2, .. k-1} as intermediate vertices.
    // After the end of an iteration, vertex no. k is added to the set of intermediate vertices and
    // the set becomes {0, 1, 2, .. k}.
    for (k = 0; k < V; k++) {
        // Pick all vertices as source one by one.
        for (i = 0; i < V; i++) {
            // Pick all vertices as destination for the above picked source.
            for (j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][k] != 0 && dist[k][j] != 0 && (dist[i][k] + dist[k][j] < dist[i][j] || dist[i][j] == 0))
                    dist[i][j] = dist[i][k] + dist[k][j];
                if (i==j){
                    dist[i][j]=0;
                }
                
            }
        }
    }
     floydRun=1;
    // Print the shortest distance matrix.
    //printSolution(dist);
}
int ifHasPath(int i,int j){
    if (floydRun != 1){
        floydWarshall();
    }
    if (i==j){
        printf("False");
        return 0;
    }
    else if (dist[i][j]>0){
        printf("True");      
        return 1;
    }
    else{
        printf("False");
        return 0;  
    }
}


void printMatrix() {
    //printf("Enter values to the matrix:");
    //int scanfChar = 0;
    for(int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d",dist[i][j]);
            
        } 
        printf("\n");
    }
    printf("finished");
}

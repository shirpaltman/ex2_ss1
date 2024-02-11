
#include <stdio.h>
#include "my_mat.h"

int dist[10][10];
int matrix[10][10];
int floydRun=0;
int V = 10;


void scanMatrix() {
    floydRun = 0;
    int scanfChar = 0;
    for(int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d\t", &scanfChar);
            matrix[i][j] = scanfChar;
            dist[i][j] = scanfChar;
        } 
    }
    
    
}

void floydWarshall() {
    int  i, j, k;
    for (k = 0; k < V; k++) {
        // Pick all vertices as source one by one.
        for (i = 0; i < V; i++) {
            // Pick all vertices as destination for the above picked source.
            for (j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][k] != 0 && dist[k][j] != 0 && (dist[i][k] + dist[k][j] < dist[i][j] || dist[i][j] == 0)){
                    if (i!=j){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
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


int printLength(int k,int s ){
    if (floydRun != 1){
        floydWarshall();
    }
    if(dist[k][s]){
        return dist[k][s];
    }
    return -1;                         
}
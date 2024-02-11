#include <stdio.h>
#include "my_mat.h"
#include <math.h>
#define bagWeight 20
#define lenArray 5

int weights[lenArray];
int values[lenArray];
int selected_bool[lenArray];
char items[lenArray];

int ffmax(int a, int b){
    if (a>b){
        return a;
    }
    else
        return b;
}

int getInput(){
    for (int i = 0; i < lenArray; i++)
    {
        scanf(" %c", &items[i]);
        scanf(" %d", &values[i]);
        scanf(" %d", &weights[i]);
        
    }
    
   
    for (int j = 0; j < lenArray; j++)
    {
        selected_bool[j]=0;
    }
    
    return 0;
}

int knapSack (int weights[], int values[] , int selected_bool[]){
    int map[lenArray + 1][bagWeight + 1];
 
    for (int j = 0; j <= lenArray; j++) {
        //printf("\n%d%d%d%d%d%d%d%d%d%d%d%d%d\n",j,j,j,j,j,j,j,j,j,j,j,j,j);
        for (int w = 0; w <= bagWeight; w++) {
            if (j == 0 || w == 0)
                map[j][w] = 0;
            else if (weights[j-1] <= w){
                map[j][w] = ffmax(values[j-1] + map[j-1][w - weights[j-1]], map[j-1][w]);
               
            }
            else{
                map[j][w] = map[j-1][w];
            }
           // printf("%d  ",map[j][w]);
        }
    }
    //int result = map[lenArray+1][bagWeight+1];
    int copyBagWeight=bagWeight;
    for (int k = lenArray; k > 0; k--) {
        if (map[k][copyBagWeight] != map[k - 1][copyBagWeight]) {
            selected_bool[k - 1] = 1; // Mark item as selected
            copyBagWeight = copyBagWeight - weights[k - 1];
        }
        else {
            selected_bool[k - 1] = 0; // Mark item as not selected
        }
    }
 
    
    int sumProfit = 0;
    for (int i = 0; i < lenArray; i++) {
        if (selected_bool[i]==1) {
            sumProfit=sumProfit + values[i];
        }
    }
    printf("Maximum profit: %d\n" , sumProfit);
    
    printf("Selected items:");
    for (int i = 0; i < lenArray; i++)
    {
        if (selected_bool[i] == 1){
            printf(" %c", items[i]);
        }
       
    }
    
   
    return 0;
    
} 


int main(){
    
    // Now the arrays are initialized
    getInput();
    knapSack(weights, values, selected_bool );
    return 0;
}
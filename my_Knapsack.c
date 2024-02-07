#include <stdio.h>
#include "my_mat.h"
#include <math.h>

#define bagWeight 20
#define lenArray 5

int weights[lenArray];
int values[lenArray];
int selected_bool[lenArray];
char items[lenArray];



int getInput(){
    for (int i = 0; i < lenArray; i++)
    {
        scanf("%c",&items[i]);
    }
    
    for (int i = 0; i < lenArray; i++)
    {
        scanf("%d",&values[i]);
    }

    for (int i = 0; i < lenArray; i++)
    {
        scanf("%d",&weights[i]);
    }
    
    for (int i = 0; i < lenArray; i++)
    {
        selected_bool[i]=0;
    }
    
    return 0;
}


int knapSack (int weights[], int values[] , int selected_bool[]){
    int map[lenArray + 1][lenArray + 1];
 
    for (int j = 0; j <= lenArray; j++) {
        for (int w = 0; w <= bagWeight; w++) {
            if (j == 0 || w == 0)
                map[j][w] = 0;
            else if (weights[j-1] <= w)
                map[j][w] = fmax(value[j-1] + map[j-1][w - weights[j-1]], map[j-1][w]);
                selected_bool[j-1]=1;
            else
                map[j][w] = map[j-1][w];
        }
    }
    int result = map[lenArray][lenArray];
    
    for (int j = lenArray; j > 0 && result > 0; j--) {
        if (map[j][bagWeight] != map[j - 1][bagWeight]) {
            selected_bool[j - 1] = 1; // Mark item as selected
            result =result - values[j - 1];
            bagWeight = bagWeight - weights[j - 1];
        }
        else {
            selected_bool[j - 1] = 0; // Mark item as not selected
        }
    }
 
    printf("Selected items:\n");
    char itemTaken[lenArray];
    int sumProfit = 0;
    for (int i = 0; i < lenArray; i++) {
        if (selected_bool[i]) {
            sumProfit=sumProfit + values[i];
            itemTaken[i]=items[i];

        }
        else{
           itemTaken[i]=0; 
        }
    }
    printf("Maximum profit: %d" , sumProfit);
    
    printf("Items that give the maximum profit: [");
    for (int i = 0; i < lenArray; i++)
    {
        if (itemTaken[i] == 0){
            printf("%c", itemTaken[i]);

        }
        if(i<lenArray-1){
            printf(", ")
        }
    }
    printf("] \n")
    return 0;
    
} 
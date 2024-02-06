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
    int map[num_items + 1][limit + 1];
 
    for (int j = 0; j <= lenArray; j++) {
        for (int w = 0; w <= bagWeight; w++) {
            if (j == 0 || w == 0)
                map[j][w] = 0;
            else if (weights[j-1] <= w)
                map[j][w] = fmax(value[j-1] + map[j-1][w - weights[j-1]], map[j-1][w]);
            else
                map[j][w] = map[j-1][w];
        }
    }
 
    int result = map[num_items][limit];
    return result;
    
} 
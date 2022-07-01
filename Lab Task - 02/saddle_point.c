#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool findSaddlePoint(int *ptr, int n){
    for(int i= 0; i < n; i++){
        int min_row = *((ptr+i)+0);
        int col_index = 0;
        for(int j = 1; j < n; j++){
            if(min_row > *((ptr+i)+j)){
                min_row = *((ptr+i)+j);
                col_index = j;
            }
        }
        int k;
        for(k = 0; k < n; k++){
            if(min_row < *((ptr+k)+col_index)) break;
        }
        if (k == n){
            printf("Value of Saddle Point: %d", min_row);
            return true;
        } 
    }
    return false;
}

int main(void){
    int n;
    scanf("%d",&n);
    int *ptr = malloc((n*n)*sizeof(int));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",(ptr+i)+j);
        }
    }
    if(findSaddlePoint(ptr,n) == false){
        printf("No Saddle Point");
    }
    return 0;
}
#include<stdio.h>
#include<stdlib.h>

int small_element(int *ptr,int size){
    int min = *(ptr+0);
    for(int i = 0; i < size; i++){
        if(min > *(ptr+i)){
            min = *(ptr+i);
        }
    }
    return min;
}


int largest_element(int *ptr, int size){
    int max = *(ptr+0);
    for(int i = 0; i < size; i++){
        if(max < *(ptr+i)){
            max = *(ptr+i);
        }
    }
    return max;
}

int main(){
    int *ptr;
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    ptr = malloc(n*sizeof(int));
    printf("Enter elements of array: ");
    for(int i = 0; i < n; i++){
        scanf("%d",(ptr+i));
    }
    printf("Smallest Element of pointer array: %d\n", small_element(ptr,n));
    printf("Largest Element of pointer array: %d", largest_element(ptr,n));
    return 0;
}
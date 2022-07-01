// Insertion Sort
#include<stdio.h>
void InsertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main (){
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    printf("Enter elements of array: ");
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Before Sorting Array is: \n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    InsertionSort(arr,n);
    printf("After Sorting Array is: \n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
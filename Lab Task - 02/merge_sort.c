// Merge sort
#include<stdio.h>
void merge(int arr[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int t1[n1], t2[n2];
    for(int i = 0; i < n1; i++){
        t1[i] = arr[l + i];
    }
    for(int i = 0; i < n2; i++){
        t2[i] = arr[m+1+i];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while(i < n1 && j < n2){
        if(t1[i] <= t2[j]){
            arr[k] = t1[i];
            i++;
        }
        else{
            arr[k] = t2[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        arr[k] = t1[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = t2[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int l, int r){
    if(l < r){
        int m = (l + (r - 1))/ 2;
        MergeSort(arr,l,m);
        MergeSort(arr,m+1,r);
        merge(arr,l,m,r);
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
    MergeSort(arr,0,n-1);
    printf("After Sorting Array is: \n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}


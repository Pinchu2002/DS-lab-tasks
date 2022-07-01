// Quick Sort
#include<stdio.h>
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int arr[],int f,int l){
    int pivot = arr[l];
    int pi = f;
    for(int i = f; i < l;i++){
        if(arr[i] <= pivot){ 
            swap(&arr[pi],&arr[i]);
            pi++;
        }
    }
    swap(&arr[pi],&arr[l]);
    return pi;   
}

void QuickSort(int arr[],int f, int l){
    if(f < l){
        int pIndex = Partition(arr,f,l);
        //5
        printf("\n%d\n" ,pIndex);
        QuickSort(arr,f,pIndex-1);
        QuickSort(arr,pIndex+1,l);
    }

}

int main(){
    int n;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements of array: ");
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    int k;
    printf("Enter Kth index: ");
    scanf("%d", &k);
    QuickSort(arr,0,n-1);
    printf("Kth smallest element: %d",arr[k]);
    return 0;
}
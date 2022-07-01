// Searching and Sorting
#include<stdio.h>


/** 
 * Note: Array must be Sorted before Binary Search
 * 
**/
// function to do binary_search()
int binary_search(int arr[], int f, int l, int x){
    int m  = f + (l-f)/2;
    if(l >= f){
        if(arr[m] == x) return m;
        if(arr[m] > x) return binary_search(arr, f, m-1, x);
        return binary_search(arr,m+1,l,x);    
    }
    return -1;
}


// function to do linear_search()
int linear_search(int arr[], int n, int x){
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == x) return i;
    }
    return -1;
}

// function to swap()
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// function to bubblesort()
void bubblesort(int arr[], int n){
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

// function to selectionsort()
void selectionSort(int arr[], int n){
    int min_idx;
    for(int i = 0; i < n-1; i++){
        min_idx = i;
        for(int j = i+1; j < n;j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        swap(&arr[i],&arr[min_idx]);
    }
}

// function to do insertionsort()
void insertionsort(int arr[], int n){
    int key,j;
    for(int i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}


// function to do partition()
int Partition(int arr[],int f, int l){
    int pivot = arr[l];
    int pi = f;
    for(int i = f; i < l; i++){
        if(arr[i] <= pivot) {
            swap(&arr[pi], &arr[i]);
            pi++;
        }
    }
    swap(&arr[l],&arr[pi]);
    return pi;
}

// Function to do QuickSort() -- recursive approach
void QuickSort(int arr[], int f, int l){
    int pi = Partition(arr,f,l);
    QuickSort(arr,f,pi-1);
    QuickSort(arr,pi+1,l);
}

//function  to do merge()
void merge(int arr[], int f, int l, int m){
    int n1 = m - f + 1;
    int n2 = l - m;
    int t1[n1], t2[n2];
    for(int i = 0; i < n1; i++){
        t1[i] = arr[l+i];
    }
    for(int i = 0; i < n2;i++){
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

// function to do mergesort()
void MergeSort(int arr[],int f, int l){
    int m = f + (l-1)/2;
    Mergesort(arr,f,m);
    MergeSort(arr,m+1,l);

    merge(arr,f,l,m);
}

// main code
int main(){
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of array: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    // int x;
    // printf("Enter element to be found: ");
    // scanf("%d", &x);
    // int result = binary_search(arr,0,n-1,x);
    // (result == -1)? printf("Element is not present in array\n") : printf("Element is present at index %d\n",result);
    // int result1 = linear_search(arr,n,x);
    // (result1 == -1)? printf("Element is not present in array") : printf("Element is present at index %d", result1);
    
    bubblesort(arr,n);
    selectionSort(arr,n);
    // QuickSort(arr,0,n-1);
    insertionsort(arr,n);
    // Mergesort(arr,0,n);
    printf("Sorted Array : \n");
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
#include<stdio.h>
int main(){
    int n;
    printf("Enter size of array: ");
    scanf("%d",&n);
    printf("Enter elements of array: ");
    int arr[n];
    for(int i = 0; i< n; i++){
        scanf("%d",&arr[i]);
    }
    printf("Differnce of Last and Second Last Element: %d",(arr[n-1] - arr[n-2]));
    return 0;
}
#include <stdio.h>
void swap(int *i, int *j);
int DNF(int arr[],int n){
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high){
        switch(arr[mid]){
            case 0:
            swap(&arr[mid],&arr[low]);
            low++;
            mid++;
            break;
            case 1:
            mid++;
            break;
            case 2:
            swap(&arr[mid],&arr[high]);
           // mid++;
            high--;
            break;
        }
    }
   // return 0;
    
}
void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}
void printArr(int arr[], int n)  
{  
    int i;  
    for (i = 1; i < n; i++)  {
        printf("%4d",arr[i]); 
    }
 
}  
int main()
{
    int arr[] = { 0,1,0,2,2,1,0,1,0,1,2,2 };  
    int n = sizeof(arr) / sizeof(arr[0]);  
     printf("Before sorting array elements are - ");  
     printArr(arr, n);
     DNF(arr,n);
     printf("\nAfter sorting array elements are - ");    
     printArr(arr, n); 
     return 0;
}


#include <stdio.h>
void swap(int *i, int *j);


int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int start=low;
    int end=high;
        while(start<end){
        while(arr[start]<=pivot){
            start++;
        }
        while(arr[end]>pivot){
            end--;
        }
        if(start<end){
            swap(&arr[start],&arr[end]);
        }
    }
    swap(&arr[low],&arr[end]);
    return end;
}
void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

int quickSort(int arr[], int low, int high) {
  if (low < high) {
    int loc = partition(arr, low, high);
    quickSort(arr, low, loc - 1);
    
    // recursive call on the right of pivot
    quickSort(arr, loc + 1, high);
  }
}
void reverseArr(int arr[],int start,int end)
{
    int temp;
    while(start<end)
    {
        temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}
void printArr(int arr[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  {
        printf("%4d",arr[i]); 
    }
 
}  

int main()  
{  
    int arr[3];  
    printf("Enter the array element\n");
    for(int i = 0; i < 3; ++i) {
     scanf("%d", &arr[i]);
    }
    int n = sizeof(arr) / sizeof(arr[0]);  
    printf("Before sorting array elements are - ");  
    printArr(arr, n);
    quickSort(arr, 0, n - 1);  
    printf("\nAfter sorting array elements are - ");    
    printArr(arr, n);  
   
    printf("\n Maximum= ");
    printf("%d",arr[n-1]);
    printf("\n Manimum= ");
    printf("%d",arr[0]);
    return 0;  
}  






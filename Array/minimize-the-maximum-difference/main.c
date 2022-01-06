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
    for (i = 1; i < n; i++)  {
        printf("%4d",arr[i]); 
    }
 
} 
int minimum(int i,int j);
int Difference(int arr[],int n){
    int k;
    printf("Enter the maximum difference");
    scanf("%d",&k);
    int diff=arr[n-1]-arr[0];
    int min=arr[0]+k;
    int max=arr[n-1]-k;
    for(int i=0;i<n;i++){
        int difference=arr[i]-k;
        int sum=arr[i]+k;
        if(difference>=min || sum <=max)
            continue;
        
        if(max-difference<=sum-min)
            min=difference;
        
        else
            max=sum;
        
    }
    printf("%d",minimum(diff, max - min));;
}
int minimum(int i,int j){
    return (i>j) ? j:i;
}
int main()  
{  
      int k;
    int arr[] = { 24, 9, 29, 14, 19, 27 };  
    int n = sizeof(arr) / sizeof(arr[0]);  
    quickSort(arr, 0, n - 1);
    printf("Array after sorting");
    printArr(arr,n);
    Difference(arr,n);
}  




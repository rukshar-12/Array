#include <stdio.h>
void swap(int *i, int *j);
int neg(int arr[],int n){
    int low=0;
    int temp=0;
    int high=n-1;
    while(temp<=high){
     if(arr[temp]<0){
        
            swap(&arr[temp],&arr[low]);
            low++;
            temp++;
         
     }
           else{
            swap(&arr[temp],&arr[high]);
           // mid++;
            high--;
            
           }
        
            }
            return temp;
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
    for (i = 0; i < n; i++)  {
        printf("%4d",arr[i]); 
    }
 
}  
int main()
{
    int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
     printf("Before sorting array elements are - ");  
     printArr(arr, n);
     neg(arr,n);
     printf("\nAfter sorting array elements are - ");    
     printArr(arr, n); 
     return 0;
}

/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
void reverseArray(int arr[],int start,int end)
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
    void printArray(int arr[],int size)
    {
        for(int i=0;i<size;i++)
        {
            printf("%d",arr[i]);
        }
    }


int main()
{
    int arr[]={1,2,3,4,5,6,7};
    int n= sizeof(arr)/sizeof(arr[0]);
     printArray(arr,n);
     
    reverseArray(arr,0,n-1);
    printf("\nReversed array is -");
     printArray(arr,n);

   // return 0;
}



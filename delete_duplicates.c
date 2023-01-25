/*
program 7: Write an efficicent program to delete all duplicates 
elements from a sorted array
*/

#include<stdio.h>
int remove_duplicates(int arr[], int size)
{
    if(size==0 || size==1)
    {
        return size;
    }
    
    int j=0;
    for(int i=0; i<size-1; i++)
    {
        if(arr[i]!=arr[i+1])
        {
            arr[j]=arr[i];
            j++;
        }
      
    } 
    arr[j]=arr[size-1];
    j++;
    return j;
}

void print_array(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}


void main()
{
   int arr[]={1,1,2,3,3,4,5,6,6,7};
   int size=sizeof(arr)/sizeof(arr[0]);

   printf("Given Array List:  ");
   print_array(arr,size);

   size=remove_duplicates(arr,size);

   printf("Array List without duplicates:  ");
   print_array(arr,size);

}
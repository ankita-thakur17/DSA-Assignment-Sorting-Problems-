/* Program 4 find Kth largest element by partioning the Array

Problem statemet:Given an integer k and an array of size n consisting of unique integers.
Find the kth largest element in this array.

step 1 
take usorted array arr[] of size n
2 5 9 25 13 12 10 3

sort the array using quick sort
2 3 5 9 10 12 13 25

After we have to find the kth largest element
k=1  1st largest element- 25
k=2  2nd largest element- 13
       :
k=5  5th largest element- 9
and so on

return arr[n-k]

In this approach, we will use a concept similar to Quicksort. 
In quicksort, we used a pivot element and a partition function 
to partition the array around the pivot element 
(elements lesser than the pivot come on the left side, and 
elements greater than the pivot come on the right side).
This approach also uses the pivot element and 
a partition function to find out the (n-k)th largest element
And finally, we will return to this element.
*/
#include<stdio.h>

void swap(int *a, int *b)
{
   int temp= *a;
   *a=*b;
   *b=temp;
}
// this function is used to find the pivot point on targeted value i.e n-k
int find_Pivot(int arr[], int l, int r)
{
   int pivot=arr[r];
   int i=l-1;
   for(int j=l;j<r;j++)
   {
      if(arr[j]<=pivot)
      {
      i++;
      swap(&arr[i],&arr[j]);
      }
   }
   swap(&arr[i+1],&arr[r]);
   return (i+1);
}
// finding kth largest element using Kthlargest_Element function
int Kthlargest_Element(int arr[],int k, int size)
{
   //array cotains only one element
   if(size==1)
   {
      return arr[0];
   }

   int left=0;
   int right=size-1;
   int target=size-k;

   while(left<=right)
   {  
   int pivot=find_Pivot(arr,left,right);

   if(pivot<target)
   {
      left=pivot+1;
      
   } 
 
   else if(pivot>target)
   {
      right=pivot-1;
   }
   else
   {
      return arr[pivot];
   }
 }  
 
}
//print fuction
void print_array(int arr[], int size)
{
   for(int i=0; i<size; i++)
   {
      printf("%d ",arr[i]);
   }
}
//driver function
void main()
{
  int arr[]={2,10,1,6,5,3};
  int size=sizeof(arr)/sizeof(arr[0]);
  int k;
  printf("Array Element are: \n");
  print_array(arr,size);
  printf("\nEnter Kth value to be find in an array: ");
  scanf("%d",&k);
  int largest= Kthlargest_Element(arr,k,size);
  printf("\nFind %dth largest element in an array is %d",k,largest );

}
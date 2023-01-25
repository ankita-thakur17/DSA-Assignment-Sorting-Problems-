/*
program 6: To find the length of the longest monotonically increasing 
subsequence from the given array along with index.

subsequence means follows the order

 10, 9, 2, 5, 3, 7, 10, 18,2

 3<7<10<18
 
 
   length=4
*/

#include<stdio.h>

void Calculate_Increasing_Sequence_length(int arr[], int size)
{
  int i, length, MIS=0, index=0;
    for(i=0;i<size;i++)
    {
        //array contain more than one element in an array
        length=1;
        while(i<size && arr[i]<=arr[i+1])
        {
            length++;
            i++;
        }
     
     if(length>MIS)
     {
        MIS=length;
        index=(i+1)-MIS;//starting index of longest subsequence
     }
    }
    printf("\nLongest Length = %d\n",MIS);
    printf("Monotonically Increasing Sub-Sequence (Index,Value):\n ");
    MIS+=index;//last index of longest subsequence
   
    for(i=index;i<MIS;i++)
    {
        printf("(Index: %d, Value: %d)\n",i,arr[i]);
    }
  }

void print_sequence(int arr[], int size)
{
 for(int i=0; i<size; i++)
   {
      printf("%d ",arr[i]);
   }
}
void main()
{
 int arr[]={ 10, 9, 2, 5, 3, 7, 10, 18, 2};
 int size=sizeof(arr)/sizeof(arr[0]);
 printf("Given Array List: ");
 print_sequence(arr,size);
 Calculate_Increasing_Sequence_length(arr,size); 
}
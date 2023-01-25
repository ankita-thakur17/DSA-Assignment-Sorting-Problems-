#include<stdio.h>

// function to swap elements
void swap(int *a, int *b)
 {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// function to find the partition position
int partition(int arr[], int low, int high) 
{
  int pivot = arr[high];  // select the rightmost element as pivot
  int i = low - 1;  // pointer for greater element
  for (int j = low; j < high; j++)
   {
    if (arr[j] <= pivot)
    {   
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quicksort(int arr[], int low,  int high)
{
  
    if(low<high)
    {
    int pi = partition(arr, low, high);
    quicksort(arr, low, pi - 1);
    quicksort(arr, pi + 1, high);
    }
}

//print arrary
void print_array(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d \t",arr[i]);
    }
    printf("\n");
}

//create arrary
int main()
{
  int arr[]={5,8,2,9,1,6,4};
  int size=sizeof(arr)/sizeof(arr[0]);

 printf("Unsorted Array: \n");
 print_array(arr,size);

quicksort(arr,0,size-1);

printf("Sorted Array: \n");
print_array(arr,size);

    return 0;
}
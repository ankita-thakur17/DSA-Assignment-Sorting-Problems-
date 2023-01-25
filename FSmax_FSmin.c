/*
Program 5: find first and second maximum and minimum

using heap /priority 



*/
#include<stdio.h>
void FS_minandmaxelement(int arr[], int size)
{
   int min, smin, max, smax;
   min = smin  = __INT_MAX__;
   max = smax = __WINT_MIN__;
     for(int i = 0; i < size; i++){
        if(arr[i] < min )
        {
            smin = min;
            min = arr[i];
        }
        else if(arr[i] > max)
        {
            smax=max;
            max=arr[i];
        }
        else if(arr[i] > smax && arr[i] < max)
        {
            smax=arr[i];
        }
        
      
    }
    /* Printing Max/Min And Second Max/Min element */
    printf("Minimum Element : %d \nSecond Minimum Element: %d \n\n", min, smin);
    printf("Maximum Element : %d \nSecond Maximum Element: %d \n\n", max, smax);
}


void print_array(int arr[],int size)
{
   for(int i=0;i<size;i++)
   {
    printf("%d ",arr[i]);
   }
   printf("\n");
}
void main()
{
    int arr[]={2,10,1,12,7,3};
    int choice;
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("Given Unsorted Array List: ");
    print_array(arr,size);

    FS_minandmaxelement(arr,size);
}
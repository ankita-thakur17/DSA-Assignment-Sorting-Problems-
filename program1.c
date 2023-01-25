/*
Consider a processor that is to be assigned jobs in order of time (Shortest Job First).
Maintain a priority queue.
Perfom insert & delete operations.
a)  Maintain a FIFO queue.
For deletion, select shortest job (highest priority element),
 delete it and re-arrang the queue by shifting elements.
b)  1.  Use insertion sort to maintain a sorted array.
For insertion, place element at proper position.
For deletion, delete first element and re-arrange the queue by shifting elements.
2.  Maintain queue in reverse order.
Delete last element.
c)  Use heap to maintain priority queue.
For insertion, insert the element in a heap so that heap property is maintained.
For deletion, delete first element. Delete and copy last element to first position,
 and re-heapify to arrange the first element in heap.

*/


#include<stdio.h>
#include<stdlib.h>


//initial value front and rear in queue
int front=-1,rear=-1;

//swap method for swapping
void swap(int *a, int *b)
   {
    int temp = *a;
    *a = *b;
    *b = temp;
  }

//heapify method

 void min_heapify(int p[],int bt[] ,int size, int i)
   {
    // Find smallest among root, left child and right child
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < size && bt[left] < bt[smallest])
      smallest = left;
  
    if (right < size && bt[right] < bt[smallest])
      smallest = right;
  
    // Swap and continue heapifying if root is not largest
    if (smallest != i)
     {
      swap(&bt[i], &bt[smallest]);
      min_heapify(p,bt,size,smallest);
    }
     
  }
//insert node in list ----maintain initial min heap
 void insert_heapnode(int p[],int bt[],int size)
 {
   for (int i = (size-1) / 2 ; i >= 0; i--)
   {
   min_heapify(p,bt, size, i);
   }
   //print sorted array
     print(p,bt,size); 
 }

 //delete method for deleting heap node
 void delete_heapnode(int p[],int bt[],int size)
 {
     for (int i = size-1; i >= 0; i--) 
     {
         swap(&bt[0], &bt[i]);
         swap(&p[0],&p[i]);
        
         min_heapify(p,bt, i, 0);

    print(p,bt,size);
    size=size-1;
     }  
   

   }
  
 //delete method from the front end
 void deletefromfront(int p[],int bt[],int size)
{
   int front=0,rear=size-1;
   if (front == - 1 && front > rear)
   {
      printf("Queue is Empty...\n ");
   }
   else 
   {
    
      printf("Min Process: (P%d %d)\n",p[front],bt[front]);
      for(int i=front;i<size;i++)
      {
         p[i]=p[i+1];
         bt[i]=bt[i+1];
      }
      size=size-1;
   }
   //print sorted array
   print(p,bt,size);
   printf("\n");

}

//ascending insertion sort method
void insertion_sort(int p[],int bt[], int size)
{
   front=0; rear=size;
   int key,j;
   for(int i=1; i<size; i++)
   {
        key=bt[i];
        j=i-1;
        while((j>=0)&&(bt[j]>key))
                                          
           {
            bt[j+1]=bt[j];
            //arranging the process id corresponds to burst time
            int temp=p[j];
            p[j]=p[j+1];
            p[j+1]=temp;    
                   
         j=j-1;
            
           }       
        bt[j+1]=key;
      
   }

     //print sorted array
     print(p,bt,size);
    for(int i=front;i<rear;i++)
    {

    printf("Delete the highest priority process waiting in queue:\n ");
    deletefromfront(p,bt,size);
    size=size-1;
    }

}

//delete method from rear end 
void deletefromrear(int p[],int bt[],int size)
{
  front=0, rear=size-1;
  if (front == - 1 && front > rear)
   {
      printf("Queue is Empty...\n ");
   }
   else
   {
    printf("Min Process: (P%d %d)\n",p[rear],bt[rear]);
      for(int i=rear;i>0;i--)
      {
       rear= bt[i];
       rear--;
      }
      size=size-1;
   }
   //print sorted array
   print(p,bt,size);
     printf("\n");
   }

   
//descending insertion sort method
void desc_insertsort(int p[], int bt[], int size)
{
   front=0; rear=size;
   int key,j;
   for(int i=2; i<size; i++)
   {
        key=bt[i];
        j=i-1;
        while((j>=0)&&(key>bt[j]))
                                          
           {
            bt[j+1]=bt[j];
            int temp=p[j];
            p[j]=p[j+1];
            p[j+1]=temp; 
            j=j-1;
           }       
        bt[j+1]=key;
   }
     //print sorted array
     print(p,bt,size);
      for(int i=front;i<rear;i++)
    {

    printf("Delete the highest priority process waiting in queue:\n ");
    deletefromrear(p,bt,size);
    size=size-1;
    } 
}

//sorting the elements using selection method
void sort(int p[],int bt[],int size)
{
   int min,temp=0;
   front=0; rear=size;
 
   //find highest priority job present in the process
   printf("\nArrange or sort process in ascending order\n");
   //selection sort
   for(int i=0; i<size; i++)
   {
   min=i;
    for(int j=i+1;j<size;j++) 
    {
      if(bt[j]<bt[min])
      {
       min=j;
      }
    }
      temp=bt[i];
      bt[i]=bt[min];
      bt[min]=temp;
  
      temp=p[i];
      p[i]=p[min];
      p[min]=temp;
 
   }
   //print sorted array
   print(p,bt,size);

    for(int i=front;i<rear;i++)
    {

    printf("Delete the highest priority process waiting in queue:\n ");
    deletefromfront(p,bt,size);
    size=size-1;
    }
   }

//Insert the element at the rear end
void insertatend(int p[], int bt[],int size)
{
  
   if(rear==size)
   {
      printf("Queue is full....\n");
   }
   else
   {
   printf("Insert at End position of queue:\n ");
   printf("\nJob id\t\t Burst Time\n");
   for(int i=0;i<size;i++)
    {
      rear=rear+1;
      bt[rear]=bt[i];
      printf("P%d\t\t %d\n",p[i], bt[rear]);          
    }
     
   }

}

//print array
void print(int p[], int bt[],int size)
{
 printf("\nJob id\t\t Burst Time\n");
     for(int i=0;i<size;i++)
     {
      printf("P%d\t\t %d\n",p[i], bt[i]); 
     }
} 


//driver code
void main()
{ 
   int bt[]={8,4,2,6,1},p[]={1,2,3,4,5},size;
   size=sizeof(bt)/sizeof(bt[0]);
   int choice;
   char again;
   do
   {
     printf("\nPerform operations i.e. Insertion , Deletion & Sorting \nwith different approaches on given Inputs\n\n");
     printf("1. Maintain Priority Queue using FIFO\n");
     printf("2. Maintain Priority Queue using Insert Sort\n");
     printf("3. Maintain Priority Queue using Insert Sort in reverse order\n");
     printf("4. Maintain Priority Queue using Heap Sort\n\n");
   
     printf("Enter your choice: ");
     scanf("%d",&choice);
     switch(choice)
     {

        case 1: 
                {
                  printf("first way\n");
                  insertatend(p,bt,size);
                  sort(p,bt,size);
                  break;
                }
       case 2: 
                {
                  printf("Second way\n");
                  insertatend(p,bt,size);
                  insertion_sort(p,bt,size);
                  break;
                }
      case 3: 
                {
                  printf("Third way\n");
                  insertatend(p,bt,size);
                  desc_insertsort(p,bt,size);
                  break;
                }
      case 4: 
                {
                  printf("Fourth way\n");
                  insert_heapnode(p,bt,size);
                  delete_heapnode(p,bt,size);
                  break;
                }
        default:
                {
                 printf("\nYou pressed wrong key..choose a number again between 1 to 3\n");
                 break;
                }
       }

      printf("If you want to continue, press 'y'...\n");     
      printf("If you want to end, press any other key ");
      scanf("%s",&again);

   }while(again == 'y' || again =='Y');
}

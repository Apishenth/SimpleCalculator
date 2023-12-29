#include <stdio.h>
#include <stdlib.h>

void WriteFile (FILE *file,int data);

typedef struct Node{
  int data;
  struct Node* next;
}Node;

typedef struct {
  Node* head;
}LinkedList;


void insertFront(LinkedList *list,int n)
{
   Node* newNode;
   newNode =(Node*)malloc(sizeof(Node));

   (*newNode).data=n;
   (*newNode).next = (*list).head;
   (*list).head = newNode;


}

void display(Node *h)
{
 Node* current = h;

 printf("Data : %d \n", (*current).data);

}

int listLength(Node* h)
{
  int length=0;

  if(h != NULL)
  {
    length = 1+ listLength((*h).next);
  }

  return length;
}


void displayList(Node* h)
{
  Node* current = h;

 while(current !=NULL)
 {
   display(current);
   current = (*current).next;
 }

}


Node* SearchList(Node* h, int key)
{
  Node* current = h;

  while(current != NULL)
  {
    if ( (*current).data == key)
    {
      return current;
    }

    current = (*current).next;
  }

  return NULL;

}



void freeLinkedList(LinkedList *list, FILE *file)
{
  Node *current, *nextNode;
  int data;
  current = (*list).head;
  
  
  

  while( current != NULL)
  {
    nextNode = (*current).next;
    printf("Deleting Node : %d \n", (*current).data);
    data = (*current).data;
    WriteFile(file,data);
    free(current);
    current = nextNode; 
  }

  printf("Deleteing LinkedList \n");
  free(list);
}




int main(void) {

  
  LinkedList* list;
  Node* result ;
  int n, i, key;
  FILE *file = fopen("output.txt","w");
  list = (LinkedList*)malloc(sizeof(LinkedList));
  (*list).head = NULL;

  

  for(i=1; i<=3; i++)
  {
    
   printf("Input data : ");
   scanf("%d", &n);

   insertFront(list, n);
   
  }

 
  displayList((*list).head);

 
  printf("Length of List : %d \n", listLength((*list).head));

 
  printf("Input key to search : ");
  scanf("%d", &key);
  result = SearchList((*list).head, key);

  if(result != NULL)
  {
   printf("Found the key \n");
  }
  else
  {
   printf("Key NOT found \n");
  }

    freeLinkedList(list,file);
	
    fclose(file);
    return 0;
}

void WriteFile (FILE *file,int data)
{
    if (file == NULL)
        {
            perror("Unable to open file");
        }
        else
        {
            fprintf(file,"%d, ",data);
        }

}
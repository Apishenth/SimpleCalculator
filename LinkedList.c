#include <stdio.h>
#include <stdlib.h>
#include "writeFile.h"

typedef struct Node{
  int data;
  struct Node* next;
}Node;

typedef struct {
  Node* head;
}LinkedList;
static int count;

void insertFront(LinkedList *list,int n)
{
   Node* newNode;
   newNode =(Node*)malloc(sizeof(Node));

   (*newNode).data=n;
   (*newNode).next = (*list).head;
   (*list).head = newNode;
   count++;

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
  int output,count=0;
  current = (*list).head;

  while( current != NULL)
  {
    nextNode = (*current).next;
    printf("Deleting Node : %d \n", (*current).data);
    output = (*current).data;
    WriteFile(file,output,count);
    count++;
    free(current);
    current = nextNode; 
  }
  
  printf("Deleteing LinkedList \n");
  free(list);
}
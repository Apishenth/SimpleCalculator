#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node{
  int data;
  struct Node* next;
}Node;

typedef struct {
  Node* head;
}LinkedList;

typedef struct _IO_FILE FILE;

void insertFront(LinkedList *list,int n);
void freeLinkedList(LinkedList *list, FILE* file);


#endif
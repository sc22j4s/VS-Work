
#include "linkedList.h"
#include "traverse.h"
#include "create.h"
#include "add.h"

/*
 * insert a node - check for head node
 */

Node *insertNode( Node *head, Node *location, Node *newNode ) {

  if( location == head )
    head = addNodeAtHead( head, newNode );
  else
    insertNodeAfter( location, newNode );

  return head;
}

/*
 * add a node to the list at the head
 */

Node *addNodeAtHead( Node *head, Node *newNode ) {

  newNode->next = head;

  return newNode;
}

/*
 * insert a node after a given location
 */

void insertNodeAfter( Node *location, Node *new ) {

  new->next = location->next;
  location->next = new;

  return;
}

/*
 * add a node to the list at the tail
 */

void addNodeAtTail( Node *head, Node *newNode ) {

  Node *tail = findTail( head ); // find the tail by traversal
  insertNodeAfter( tail, newNode ); // add node at tail

  return;
}

/*
 * delete a node from the list
 */

Node *deleteNode( Node *head, Node *location ) {

  if( location == head )
     head = deleteFirstNode( head );
  else
    deleteNextNode( location );

  return head;
}

/*
 * delete a node from within the list
 */

void deleteNextNode( Node *location ) {

  Node *toBeRemoved = location->next;
  location->next = toBeRemoved->next;  // unlink from the list
  freeNode( toBeRemoved );

  return;
}

/*
 * delete the node at the head of the list
 */

Node *deleteFirstNode( Node *head ) {

  Node *toBeRemoved = head;
  head = toBeRemoved->next;  // unlink from the list
  freeNode( toBeRemoved );

  return head;
}



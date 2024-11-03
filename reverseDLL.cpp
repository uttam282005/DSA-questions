#include <bits/stdc++.h>
using namespace std;

// a node of the doubly linked list
class DLLNode {
public:
  int data;
  DLLNode *next;
  DLLNode *prev;

  DLLNode(int val) {
    data = val;
    this->next = NULL;
    this->prev = NULL;
  }
};

// Function to insert a node at the end
// of the Doubly Linked List
void push(DLLNode **tailRef, int new_data) {
  // allocate node
  DLLNode *newNode = new DLLNode(new_data);

  // since we are adding at the end,
  // next is NULL
  newNode->next = NULL;

  newNode->prev = (*tailRef);

  // change next of tail node to new node
  if ((*tailRef) != NULL)
    (*tailRef)->next = newNode;

  (*tailRef) = newNode;
}

// Function to print nodes in a given doubly linked list
void printList(DLLNode *head) {
  // if list is empty
  if (head == NULL)
    return;

  while (head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }
}

// } Driver Code Ends
/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
DLLNode *reverseDLL(DLLNode *head) {
  // Your code here
  while (head) {
    DLLNode *temp = head;
    head->next = temp->prev;
    head->prev = temp->next;
    head = temp->next;
  }
  head->next = head->prev;
  head->prev = NULL;
  return head;
}

DLLNode *vectorToDLL(vector<int> v) {
  DLLNode *head = new DLLNode(v[0]);
  DLLNode *tail = head;
  for (int i = 1; i < v.size(); i++) {
    DLLNode *newNode = new DLLNode(v[i]);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }
  return head;
}
// } Driver Code Ends
int main() {
  vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  DLLNode *head = vectorToDLL(v);
  reverseDLL(head);
  printList(head);
  return 0;
}

/*
Author: Uttam Raj
Date: 2024-10-26
Problem: Problem Name/URL
*/

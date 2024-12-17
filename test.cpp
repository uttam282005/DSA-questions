#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *next;

  Node(int data1) {
    data = data1;
    next = nullptr;
  };

  Node(int data1, Node *next1) {
    data = data1;
    next = next1;
  };
};

Node *insertNodeAtEnd(Node *head, int data) {
  Node *temp = head;
  while (temp->next) {
    temp = temp->next;
  }
  temp->next = new Node(data);
  return head;
}

void displayList(Node *head) {
  Node *temp = head;
  while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

int main() {
  Node *node1 = new Node(1);
  Node *node2 = new Node(24);
  node1 = insertNodeAtEnd(node1, 50);
  node2 = insertNodeAtEnd(
      node1,
      100); // node1 = insertNodeAtEnd(head, int data) displayList(node1);
  displayList(node1);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

void freeList(Node *head) {
  while (head) {
    Node *tmp = head;
    head = head->next;
    free(tmp);
  }
}

int main() {
  Node *head = NULL, *tail = NULL;

  int x;
  while (scanf("%d", &x), x != 0) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = x;
    newNode->next = NULL;

    if (!head) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  Node *prev = NULL, *curr = head;
  while (curr) {
    Node *next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  head = prev;

  for (Node *p = head; p != NULL; p = p->next) {
    printf("%d ", p->value);
  }
  printf("\n");

  freeList(head);
  return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
void push(struct ListNode** head_ref, int new_data);
void printList(struct ListNode* head); 
int power(int num1, int num2);
void append(struct ListNode** head_ref, int new_data);

struct ListNode {
      int val;
      struct ListNode *next;
};

int main() {

    struct ListNode* l1 = NULL;
    struct ListNode* l2 = NULL;

    push(&l1, 9); 
    // push(&l1, 4); 
    // push(&l1, 2); 

    push(&l2, 9); 
    push(&l2, 9);
    push(&l2, 9);
    push(&l2, 9);
    push(&l2, 9);
    push(&l2, 9);
    push(&l2, 9);
    push(&l2, 9);
    push(&l2, 9);
    push(&l2, 1); 

    struct ListNode* result = NULL;

    result = addTwoNumbers(l1, l2);

    printList(result);

    return 0;
}

int power(int num1, int num2) {
    int power = 1;

    if (num2 == 0) {
        return power;
    }

    for(int i = 0; i < num2; i++) {
        power = power * num1; 
    }

    return power;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    
    struct ListNode *curNode1 = l1;
    struct ListNode *curNode2 = l2;
    struct ListNode *result = NULL;
    int carry = 0;


    while(curNode1 != NULL || curNode2 != NULL) {
        int num1 = 0;
        int num2 = 0;
        int total = 0;

        if (curNode1 != NULL) {
            num1 = curNode1->val;
            curNode1 = curNode1->next;
        }

        if (curNode2 != NULL) {
            num2 = curNode2->val;
            curNode2 = curNode2->next;
        }

        total = num1 + num2 + carry;

        carry = 0;

        if (total > 9) {
            carry = 1;
        } 

        total = total % 10;

        append(&result, total);        
    }

    if (carry == 1) {
        append(&result, carry);
    }

    return result;
}

void push(struct ListNode** head_ref, int new_data) 
{ 
  // allocate node 
  struct ListNode* new_node = (struct ListNode*) malloc(sizeof(struct ListNode)); 
   
  // put in the data  
  new_node->val  = new_data; 
   
  // link the old list off the new node 
  new_node->next = (*head_ref); 
   
  // move the head to point to the new node 
  (*head_ref) = new_node; 
} 

void append(struct ListNode** head, int new_data) { 
 
    struct ListNode* new_node = (struct ListNode*) malloc(sizeof(struct ListNode)); 
   
    new_node->val = new_data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct ListNode* curNode = *head;

        while(curNode->next != NULL) {
             curNode = curNode->next;
        }
        
        curNode->next = new_node;
    }
}  

void printList(struct ListNode* head) { 
  
  //recursive way
  if (head == NULL) {
      return;
  }
  
  printList(head->next);
  
  printf("%d ", head->val);
  
} 
//This version converts the numbers from a linked list to a int but doesnt work because the numbers get too big.

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

    push(&l2, 1); 
    push(&l2, 9);
    push(&l2, 9);
    push(&l2, 9);
    push(&l2, 9);
    push(&l2, 9);
    push(&l2, 9);
    push(&l2, 9);
    push(&l2, 9);
    push(&l2, 9); 

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
    int digCnt1 = 0;
    int digCnt2 = 0;
    int num1 = 0;
    int num2 = 0;

    while(curNode1 != NULL) {
        int mult = power(10, digCnt1);
        int add = curNode1->val * mult;
        num1 += add;
        digCnt1++;
        curNode1 = curNode1->next;
    }

    while(curNode2 != NULL) {
        int mult = power(10, digCnt2);
        int add = curNode2->val * mult;
        num2 += add;
        digCnt2++;
        curNode2 = curNode2->next;
    }

    printf("%d\n", num1);
    printf("%d\n", num2);

    int total = num1 + num2;

    printf("%d\n", total);

    int digit = 0;

    if (total == 0) {
        append(&result, 0);
    } else {
        while (total != 0) {
            digit = total % 10;
            total = total - digit;
            total = total / 10;
            append(&result, digit); 
        }
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
  (*head_ref)    = new_node; 
} 

void append(struct ListNode** head_ref, int new_data) 
{ 
  // allocate node 
  struct ListNode* new_node = (struct ListNode*) malloc(sizeof(struct ListNode)); 
   
  // put in the data  
  new_node->val  = new_data;

  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }

    struct ListNode* curNode = *head_ref;

  //traverse to end of list 
    while(curNode->next != NULL) {
        curNode = curNode->next;
    }

  curNode->next = new_node; 

} 

void printList(struct ListNode* head) 
{ 
  
  //recursive way
  if (head == NULL) {
      return;
  }
  
  printList(head->next);
  
  printf("%d ", head->val);
  
} 


// l1 =
// [9]
// l2 =
// [1,9,9,9,9,9,9,9,9,9]

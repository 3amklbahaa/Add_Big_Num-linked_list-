#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    unsigned short digit;
    struct node* next;
}node;
node* Add_Big_Num(node* N1, node* N2){
    node* N3 = NULL, *current_1 = N1, *current_2 = N2;
    node* temp = NULL;
    int sum1 = 0, sum2 = 0;
    while(current_1!=NULL){
        sum1 = sum1 * 10 + current_1->digit;
        current_1 = current_1->next;
    }
    while(current_2!=NULL){
        sum2 = sum2 * 10 + current_2->digit;
        current_2 = current_2->next;
    }
    int sum = sum1 + sum2;
    while(sum>0){
        temp = (node*)malloc(sizeof(node));
        if(temp==NULL){
            return NULL;
        }
        temp->digit = sum%10;
        temp->next = N3;
        N3 = temp;
        sum = sum / 10;
    }
    node* prev = NULL;
    node* current = N3;
    node* next = NULL;
    while(current!=NULL){
        next = current->next;
        current->next=prev;
        prev = current;
        current = next;
    }
    N3 = prev;
    return N3;
}

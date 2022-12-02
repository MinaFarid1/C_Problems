#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}node;
int insert(int index, int data, node **head);
int delete(int index, node **head);
void printLinkedList(node *head);
int size = 1;
void main(){
    node *head;
    node *one;
    one = malloc(sizeof(node));
    one->data=3;
    one->next=NULL;
    head = one;
    insert(0, 20, &head);
    insert(2, 30, &head);
    printLinkedList(head);
    delete(1, &head);
    printLinkedList(head);
}
int insert(int index, int data, node **head){
    if(index > size){
        printf("Invalid index\n");
        return size;
    }
    node *curr_node = *head;
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if(index != 0){ // Index isn't head node != 0
        index--; // To get the node before insertion index
        while(index != 0){
            curr_node = curr_node->next; // Current node is the node before the insertion index
            index--;
        }
        new_node->next = curr_node->next;
        curr_node->next = new_node; 
    } else { // Index is head node == 0
        new_node->next = *head;
        *head = new_node;
    }
    size++; 
    return size;
}
int delete(int index, node **head){
    if(index >= size){
        printf("Invalid index\n");
        return size;
    }
    node *curr_node = *head, *next, *temp;
    // Remove head
    if (index == 0) {
        *head = curr_node->next;   // Change head
        free(curr_node);   
        size--;
        return size;
    }
    // Traverse to node before the node being deleted
    for (int i = 0; curr_node != NULL && i < index - 1; i++)
        curr_node = curr_node->next;
    temp = curr_node->next; // Set temp to node being deleted
    next = curr_node->next->next; // Set next to be the node after the deleted node
    free(temp); // Delete the node
    temp = curr_node; // Set temp to previous node
    temp->next = next; // Set temp's next node to next
    size--;
    return size;
}
void printLinkedList(node *head){
    node *curr_node = head;
    while(curr_node != NULL){
        if(curr_node->next != NULL)
            printf("%d->", curr_node->data);
        else
            printf("%d", curr_node->data);
        curr_node = curr_node->next;
    }
    printf("\n");
}
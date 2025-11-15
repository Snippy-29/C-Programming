# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *create(int data);
void add(struct node **head, int data);
void display(struct node *head);

struct node *create(int data){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if(p==NULL){
        printf("Memory Allocation Failed");
        exit(1);
    }

    p->data = data;
    p->next = NULL;

    return p;
}

void add(struct node **head,int data){
    struct node *p = create(data);
    if(*head == NULL){
        *head = NULL;
    }
    else{
        struct node *temp = *head;
        while(temp -> next != NULL){
            temp = temp->next;
        }
        temp->next = p;
    }
}

void display(struct node *head){
    struct node *temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
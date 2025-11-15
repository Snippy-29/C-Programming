# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *create(int data){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if(p == NULL){
        printf("Memory Allocation Failed!");
        exit(1);
    }
    p->data = data;
    p->next = NULL;

    return p;
}

void front(struct node **head, int data){
    struct node *new= create(data);
    struct node *p = *head;
    if(p == NULL){
        *head = new;
        return;
    }
    new->next = *head;
    *head = new;
}

void add(struct node **head, int data){
    struct node *p = create(data);
    if(*head == NULL){
        *head = p;
    }
    else{
        struct node *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = p;
    }
}

void add_num(struct node *head, struct node *head1, struct node **head2){
    struct node *p = head;
    struct node *q = head1;
    int carry = 0,sum;
    while(p != NULL || q != NULL){
        sum = carry;
        if(p!=NULL){
            sum = sum + p->data;
            p = p ->next;
        }
        if(q!=NULL){
            sum = sum + q->data;
            q = q->next;
        }
        add(head2,sum%10);
        carry = sum/10;
    }
    if(carry>0){
        add(head2,carry);
    }
}

void display(struct node *head){
    struct node *p = head;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main(){
    struct node *head = NULL;
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    int x,y,n,n1;

    printf("Enter the 1st Number limit : ");
    scanf("%d",&n);
    printf("Enter the 1st Number Value : ");
    for(int i = 0; i < n; i ++){
        scanf("%d",&x);
        front(&head,x);
    }

    printf("\n");

    printf("Enter the 2nd Number limit : ");
    scanf("%d",&n1);
    printf("Enter the 2nd Number Value : ");
    for(int i = 0; i < n1; i ++){
        scanf("%d",&y);
        front(&head1,y);
    }

    add_num(head,head1,&head2);
    display(head2);

    return 0;
}
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
        return 0;
    }
    p->data = data;
    p->next = NULL;

    return p;
}

void add(struct node **head,int data){
    struct node *p = create(data);
    if(*head == NULL){
        *head = p;
    }
    else{
        struct node *temp = *head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = p;
    }
}

void display(struct node *head){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void delete(struct node **head, int spec){
    struct node *p = *head;
    if(p == NULL){
        printf("No NODE present!");
        return;
    }
    else{
        while(p->next!=NULL){
            if(spec == p->data){
                struct node *temp = p;
                p->next = p->next->next;
                free(temp);
                break;
            }
            p = p->next;
        }
    }
    display(*head);
}

int main(){
    struct node *head = NULL;
    int n,x;
    printf("Enter the Limit : ");
    scanf("%d",&n);

    for(int i = 0; i < n; i ++){
        printf("Enter the Number : ");
        scanf("%d",&x);
        add(&head,x);
    }

    printf("Enter the Value to be deleted : ");
    scanf("%d",&x);

    delete(&head,x);

    return 0;
}
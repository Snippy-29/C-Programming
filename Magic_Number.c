# include <stdio.h>

void main()
{
    int a;
    int t;
    printf("Enter the Number : ");
    scanf("%d",&a);//5500

    do{
        t = 0; // 0,
        while(a > 0)
        {
            t = t + (a % 10); //0,0,5,10
            a = a / 10;
        }
        a = t;
    }while(t >= 10);

    if (t == 1){
        printf("Magic Number Successful!");
    }
    else{
        printf("Magic Number not Successful!");
    }
}


// void display(struct node *root){
//     if(root == NULL){
//         printf("No tree present");
//         return;
//     }
//     else{
//         if(root->left == NULL && root->right == NULL)
//     }
// }
# include <stdio.h>
main()
{
    int x,y;
    printf("Enter the Value : ");
    scanf("%d",&x);
    // printf("Enter the Value : ");
    // scanf("%d",&y);
    // float a;
    // a = x + y;
    // printf("%f",a);
    y = x;
    int a;
    while (x > 0)
    {
        int b = x % 10;
        a = a*10 + b;
        x = x / 10;
    }
    if (y == a)
    {
        printf("This is a Palindrome Number ! ");
    }
    else
    {
        printf("This is not a Palindrome Number ! ");
    }
}
# include <stdio.h>

int rec(int k);

main()
{
    int res = rec(10);
    printf("%d",res);
}

int rec(int k)
{
    if (k > 0)
    {
        return k * rec(k-1);
    }
    else{
        return 1;
    }
}
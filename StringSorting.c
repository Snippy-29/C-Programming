# include <stdio.h>
// # define n 30

void main()
{
    char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char b[] = "abcdefghijklmnopqrstuvwxyz";
    char i[] = "soumyajit";

    int s = sizeof(i)/sizeof(i[1]);
    int s1 = sizeof(b)/sizeof(b[1]);
    int t = 0;
    

    for(int k = 0; k<s ; k ++ )
    {
        for(int j = 0; j < s1; j ++)
        {
            if (i[k]==b[j])
            {
                i[k] = a[j];
            }
        }
    }
    puts(i);
}
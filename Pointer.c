// # include <stdio.h>
// # include <stdlib.h>

// int main(int argc, char const *argv[])
// {
//     int n=8,a[n];
//     int *p=(int *)malloc(n*sizeof(int));
//     int *c=(int *)calloc(n,sizeof(int));
//     for(int i=0;i<8;i++)
//     {
//         printf("%p ",(void *)(c+i));
//     }
//     printf("\n");
//     for(int i=0;i<8;i++)
//     {
//         printf("%p ",(void *)(p+i));
//     }
//     free(p);
//     free(c);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n = 8;

    int *p = (int *)malloc(n * sizeof(int));
    int *c = (int *)calloc(n, sizeof(int));

    if (p == NULL || c == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Addresses from calloc:\n");
    for (int i = 0; i < n; i++) {
        printf("%p ", (void *)(c + i));
    }
    printf("\n");

    printf("Addresses from malloc:\n");
    for (int i = 0; i < n; i++) {
        printf("%p ", (void *)(p + i));
    }
    printf("\n");

    free(p);
    free(c);
    return 0;
}

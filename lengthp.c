# include <stdio.h>

main(){
    int a[]={10,20,30,40,100,200,101,201,300,301};
    int *p=a;
    int s=sizeof(a)/sizeof(*p);
    printf("%d\n",s);
}
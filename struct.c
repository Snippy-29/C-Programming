// # include <stdio.h>
// # include <stdlib.h>

// struct Details
// {
//     char id[3];
//     char Name[10];
//     char City[10];
// };


// main()
// {
//     int n;
//     printf("Enter the limit : ");
//     scanf("%d",&n);
//     struct Details S1[n];
    
//     for(int i=0;i<n;i++){
//         printf("Enter the ID, Name, City : \n");
//         scanf("%s %s %s",&S1[i].id,&S1[i].Name,&S1[i].City);
//     }

//     for(int i=0;i<n;i++){
//         if(S1[i].City=="Nab" || S1[i].City=="Kol"){
//             printf("%s\n",S1[i].Name);
//         }
//     }
// }

#include<stdio.h>
#include<stdlib.h>

void main()
{
	int i;
	struct details
	{
		int id;
		char name[50];
		char city[50];
	};

	struct details s1[5];
	for( i=0;i<2;i++)
		{
			printf("enter id :");
			scanf("%d",&s1[i].id);
			printf("enter name:");
			scanf("%s",&s1[i].name);
			printf("enter city:");
			scanf("%s",&s1[i].city);
		}
	for(i=0;i<2;i++)
	{
		printf("%d %s %s",s1[i].id,s1[i].name,s1[i].city);
		printf("\n");
	}
}
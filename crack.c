
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "md5.h"




char ss[]="14928501";
char pass[4];	// 4 character password
int *pass_pointer, *temp;
int n, result, *temp;
MD5_CTX mdContext;

main (int argc, char *argv[])
{
	FILE *f;
	int length=62;
	char dict[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};	
	int i,j,k,l;
	f=fopen("hashes.txt","r");
	char st[8];
	int brute=0;
	for (i=0; i<length;i++)
	{
		for (j=0; j<length; j++)
		{
			for (k=0; k<length; k++)
			{
				for (l=0; l<length; l++)
				{
					printf ("Brute:%d\n",++brute);
					fscanf (f, "%s\n", st);

					if (strcmp(ss,st)==0)
					{			
						printf ("i,j,k,l:%d %d %d %d\n", i, j, k, l);				
						printf ("I found the match:%c%c%c%c\n", dict[i], dict[j], dict[k], dict[l]);
						printf ("dict[i]:%c\n", dict[i]);
						printf ("dict[j]:%c\n", dict[j]);
						printf ("dict[k]:%c\n", dict[k]);
						printf ("dict[l]:%c\n", dict[l]);
						exit (0);
						
					}
					
				}
			}
		}
	}
	fclose (f);


};
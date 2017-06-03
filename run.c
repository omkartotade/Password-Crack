#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "md5.h"




char ss[]="97e75d32";
char pass[4];	// 4 character password
int *pass_pointer, *temp;
int n, result, *temp;
MD5_CTX mdContext;



main (int argc, char *argv[])
{
	FILE *f;
	int length=62;
	
	int count=0;
	char dict[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};	
	int i,j,k,l;
	f=fopen("hashes.txt","w");
	for (i=0; i<length;i++)
	{
		for (j=0; j<length; j++)
		{
			for (k=0; k<length; k++)
			{
				for (l=0; l<length; l++)
				{
				printf ("Count:%d\n",++count);					
					pass_pointer = (int *) pass; // get an int pointer to the password store
   					
   					*pass_pointer = 0;
   					
   					pass_pointer = (int *) pass; // get an int pointer to the password store
   					
   					pass[0]=dict[i];
   					pass[1]=dict[j];
   					pass[2]=dict[k];
   					pass[3]=dict[l];

   					MD5Init(&mdContext);  // compute MD5 of password   					
   					MD5Update(&mdContext, pass_pointer, 4);   					
   					MD5Final(&mdContext);
   					
   					temp = (int *) &mdContext.digest[12];    					
   					result= *temp;  					

   					fprintf (f, "%x\n", result);
   					
				}
			}
		}
	}

	fclose(f);
};
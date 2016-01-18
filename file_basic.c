#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
int main()
{
	FILE *f;

	f=fopen("file.txt","r+");
	
	/*
	USING FGETS
	*/
	
	char *arr;
	arr=(char*)malloc(sizeof(char)*15);
	fgets(arr,10,f);
	printf("%s\n",arr);
	
	/*
	USING FPUTS
	*/
	fputs("hello\n",f);

	/*
	USING GETLINE
	*/
	size_t ch,num=32;
	char *buf;
	buf=(char*)(malloc(sizeof(char)*20));
	ch=getline(&buf,&num,f);
	printf("%s\n",buf);
	

	/*
	Writing to a specified position*/

	size_t pos=1,pos1=7;
	fseek(f,10,SEEK_SET);

	printf("%ld",ftell(f));
	char buf1[20]="How are you Rohit";
	pos1=strlen(buf1);

	fwrite((void*)buf1,pos,pos1,f);

	fclose(f);
return 0;
}
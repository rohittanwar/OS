/*
Basic Fork Program
*/
#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int i=10;
	pid_t a;
	a=fork();
	if(a==0)
	{
	while(i--)
	printf("%s\n","Child Process");
	}
	else
	{
	
	//usleep(10);
	int status;
	waitpid(a,&status,0);
	printf("%s\n","Parent Process");
	}
return 0;

}

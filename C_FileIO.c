#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<sys/wait.h>

#define	SH_PATH_FIN	"/home/jiyoon/Desktop/Git/study1/Shell_Exam/IP_test.sh"
#define	SH_PATH	"/home/jiyoon/Desktop/Git/study1/Shell+C/IP_test.sh"
// enp0s3"

int main(void)
{
	int rtn = 0;
	char cmd[256] = {0,};
	char InterName[256] = {0,};
	
	int PathLen = 0;
	
	printf("Interface Name : ");
	scanf("%s", InterName);
	
	PathLen = strlen(SH_PATH) + strlen(InterName);

	printf("SH_PATH : %ld\n", strlen(SH_PATH));
	printf("InterName : %ld\n", strlen(InterName));	
	printf("PathLen : %d\n", PathLen);
	
	
	memcpy(cmd, SH_PATH, sizeof(cmd));
	strcat(cmd, " ");
	
	strcat(cmd, InterName);
		
	printf("%s\n", cmd);
	
	system(cmd);
	
	FILE *fp = NULL;

	int line = 0;
	int c;
	char fname[256] = "ipPrint.txt";
	
	// shell -> txt -> file read
	if((fp = fopen(fname, "r")) == NULL)
	{
		fprintf(stderr, "%s open Fail! \n", fname);
		return 0;
	} 
	
	while((c = fgetc(fp)) != EOF)
	{
		putchar(c);
	}
		
	fclose(fp); //pointer close
	
	return 0;

}

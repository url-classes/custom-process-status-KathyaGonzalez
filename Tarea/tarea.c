#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
int main()
{
	//Kathya Gonzalez - 1599019
	printf("\n			BIENVENIDO\n\n");
	printf("Process type		PID	PPID	Time\n");
	char formato[20];
	char *estructura = "%d/%m/%Y %H:%M:%S";
	int fork_result;
	fork_result = fork();
	fork_result = fork();
	fork_result = fork();
	if( fork_result >=1)
	{
		wait(NULL);
		time_t t = time(NULL);
		struct tm fechahora = *localtime(&t);
		int conformato = strftime(formato, sizeof formato, estructura, &fechahora);
		printf("System process		%d	%d	", getpid(), getppid());
		printf("%s\n", formato);
	}else if (fork_result == 0){
		time_t t = time(NULL);
		struct tm fechahora = *localtime(&t);
		int conformato = strftime(formato, sizeof formato, estructura, &fechahora);
		printf("System process		%d	%d	", getpid(), getppid());
		printf("%s\n", formato);
		exit(EXIT_SUCCESS);
	}else {
		printf("ERROR\n");
	}
	return 0;
}

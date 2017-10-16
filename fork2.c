#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(int argc, char const *argv[])
{
	pid_t pid1,pid2;
	printf("Hola\n");
	if(pid1=fork()==-1){
		exit(-1);
	}
	if (pid1==0){
		pid2=fork();
		if (pid2==0)		{
			printf("Hola soy el nieto. Mi padre es: %d\n",getppid());
			printf("Hola soy el nieto. Mi PID es: %d\n",getpid());

		}
		else{
			printf("Hola soy el hijo. Mi padre es: %d\n",getppid());
			printf("Hola soy el hijo. Mi PID es: %d\n",getpid());
			//printf("Hola soy el hijo. Mi hijo es: %d\n",pid2);
			printf("el proceso %d termino\n",wait(NULL));
		}
		
	}
	else{
		//printf("Hola soy el padre. Mi padre es: %d\n",getppid());
		printf("Hola soy el padre. Mi PID es: %d\n",getpid());
		//printf("Hola soy el padre. Mi hijo es: %d\n",pid1);
		printf("el proceso %d termino\n",wait(NULL));
	}
	
	return 0;
}
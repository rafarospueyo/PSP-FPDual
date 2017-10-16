#include <stdio.h>
#include <unistd.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char const *argv[])
{
	pid_t pid1,pid2;
	printf("Hola\n");
	pid1=fork();
	if (pid1==0)	{
		printf("Hola soy el 1º hijo. Mi padre es: %d\n",getppid());
	}
	else{
		pid2=fork();
		if(pid2==0){
			printf("Hola soy el 2º hijo. Mi padre es: %d\n",getppid());
		}
		else{
			printf("Hola soy el padre. Mi pid es: %d\n",getpid());
			printf("He creado un proceso hijo cuyo pid es: %d\n",pid1);
			printf("He creado un proceso hijo cuyo pid es: %d\n",pid2);	

			printf("el proceso %d termino\n",wait(NULL));
			printf("el proceso %d termino\n",wait(NULL));

		}
	}
	sleep(1);
	return 0;
}
#include <stdio.h>
#include <unistd.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{

	int tub[2];
	if(pipe(tub)==-1){
		fprintf(stderr, "Error en el pipe\n");
		exit(-1);
	}
	pid_t pid1,pid2,pid3;
	pid1=fork();
	if (pid1==0)	{
		// HIJO 1

		write(tub[1],&pid1,sizeof(pid_t));
	}
	else{
		pid2=fork();
		if(pid2==0){
			//HIJO 2
			write(tub[1],&pid2,sizeof(pid_t));

		}
		else{
			pid3=fork();
			if(pid3==0){
				//HIJO 3
				write(tub[1],&pid3,sizeof(pid_t));

			}
			else{
				for (int i = 0; i < 3; ++i){
					wait(NULL);
				pid_t hijo;
				read(tub[0],&hijo,sizeof(pid_t));
				fprintf(stdout, "El hijo %d ha acabado\n",hijo );
				}
				
			}
		}
	}
	close(tub[0]);
	close(tub[1]);
	return 0;
}
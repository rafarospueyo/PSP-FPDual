#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
	printf("%d\n",getpid() );
	printf("%d\n",getppid() );
	return 0;
}
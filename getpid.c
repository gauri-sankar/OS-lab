#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
void main()
{
 int n=fork();
 pid_t processid;
 processid=getpid();
 if(n==0)
 printf("The id for current process is %d"getpid());
 return 0;
}

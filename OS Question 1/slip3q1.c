#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
pid_t child_pid;
child_pid=fork();

if(child_pid<0)
{
perror("fork failed");
exit(1);
}
if(child_pid==0)
{
printf("child process : my pid is :%d\n",getpid());
printf("child process :executing 'ls' command \n");
execlp("ls","ls",(char*)NULL);
perror("execlp");
}
else
{
printf("parrent process : my pid is :%d\n",getpid());
printf("parrent process : waiting for the child to finish....\n");
wait(NULL);
printf("parrent  process : has finish \n");
}
return 0;
}

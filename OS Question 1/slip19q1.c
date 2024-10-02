// same as slip 7 and 9 and 15
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
printf("parrent process : (pid is :%d) going to sleep .\n",getpid());
sleep(5);
printf("parrent process : woke up....\n");

}
return 0;
} 

//same as slip 2
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{

pid_t pid=fork();
if(pid<0)
{
perror("fork failed");
return 1;
}
else if(pid==1)
{
printf("child process id:%d\n",getpid());
printf("hello world \n");
}
else
{
printf("parent process id:%d\n",getpid());
wait(NULL);
printf("hiii \n");
}
return 0;
}


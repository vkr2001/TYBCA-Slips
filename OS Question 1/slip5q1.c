// slip 1 q1 is same for slip5 q1
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
pid_t pid=fork();
if(pid==0)
{
printf("child pid:%d\n",getpid());
nice(5);
printf("child priority increased.\n");
sleep(2);
}
else if(pid>0)
{
wait(NULL);
printf("child finished execution\n");
}
else 
{
perror("fork failed");
}
return 0;
}

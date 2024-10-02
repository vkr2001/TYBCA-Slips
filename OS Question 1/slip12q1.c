//same as slip10 
// same as slip 4

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
pid_t pid=fork();

if(pid<0)
{
perror("fork failed");
exit(1);
}
else if(pid==0)
{
sleep(5);
printf("child process(pid:%d) has become orphan(parrent pid:%d).\n",getpid(),getpid());
}
else 
{
printf("parent process(pid:%d)is terminating.\n",getpid());
exit(0);
}
return 0 ;
}

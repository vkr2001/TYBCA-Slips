// same as slip 6 and 14 
#include<stdio.h>
#include<time.h>

int main()
{
clock_t start,end;
double cpu_time_used;
int i,sum=0;

start=clock();

for(i=0;i<10000000;i++)
{
//sum+=i;
}
end=clock();

cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;

printf("cpu time used %f secound \n" ,cpu_time_used);
return 0;
}

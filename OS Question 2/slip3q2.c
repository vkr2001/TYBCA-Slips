/*Write the simulation program using FCFS. The arrival time and first CPU bursts of different
jobs should be input to the system. Assume the fixed I/O waiting time (2 units). The next CPU burst
should be generated using random function. The output should give the Gantt chart,Turnaround
Time and Waiting time for each process and average times */


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct process{

int id;
int arrival_time;
int initial_cpu_burst;
int remaining_cpu_burst;
int turnaround_time;
int waiting_time;
};

// function to sort processes by arrival time 
void sort_by_arrival_time(struct process processes[] ,int n)
{
int i, j;
for(i=0; i<n; i++)
{
  for(j=i+1; j<n; j++)  {
   if(processes[i].arrival_time > processes[j].arrival_time)
    {
      struct process temp=processes[i];
       processes[i]=processes[j];
        processes[j]=temp;
        }
      }
     }
   }   
    
 int main()
 {
 srand(time(NULL));
 
 int n,i;
 printf("Enter the Number of processes ");
 scanf("%d",&n);
 
 struct process processes[n];
 for(i=0; i<n; i++)
 {
  processes[i].id = i;
  printf("Enter the Arrival time of process P%d :",i);
  scanf("%d", &processes[i].arrival_time);
  printf("Enter the Initial burst for process P%d:" ,i);
  scanf("%d", &processes[i].initial_cpu_burst);
  processes[i].remaining_cpu_burst = processes[i].initial_cpu_burst;
  }
 sort_by_arrival_time(processes,n);
 
 int current_time = 0;
 int total_turnaround_time = 0;
 int total_waiting_time = 0;
 
 printf("\n gantt chart : \n");
 printf("0");
 
 for(i=0; i<n; i++)
 {
   if(processes[i].arrival_time > current_time)
   { 
   current_time = processes[i].arrival_time;
 }
   printf("|P%d", processes[i].id);
   processes[i].waiting_time = current_time - processes[i].arrival_time;
   total_waiting_time += processes[i].waiting_time;
   current_time += processes[i].remaining_cpu_burst;
   
   processes[i].turnaround_time = current_time-processes[i].arrival_time;
   total_turnaround_time += processes[i].turnaround_time;
   }
   
   printf("|\n");
   
   printf("\n processes \t Turnaround Time \t waiting Time \n");
   for (i=0; i<n; i++); 
   {
     printf("P%d\t%d\t\t%d\n",i,processes[i].turnaround_time,processes[i].waiting_time);
   }
   
   float avg_turnaroud_time=(float)total_turnaround_time /n;
   float avg_waiting_time = (float)total_waiting_time /n;
   
   printf("Average waiting time :%.2f\n",avg_waiting_time);
   return 0;
   }
   
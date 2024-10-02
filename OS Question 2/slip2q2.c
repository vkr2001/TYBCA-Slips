// NON-Premptive SJF

#include<stdio.h>
#include<stdlib.h>

struct job{
	int atime; //arraival time.
	int btime; //brust time.
	int ft; //finish time.
	int tat; //Trun around time.
	int wt; // waiting time.
}p[10];

int arr[10],brust[10],n,rq[10],no_rq=0,time=0;

void main(){
	
	int i,j;
	printf("Enter the job number:");
	scanf("%d",&n);
	printf("\n");
	
	for(i = 0;i<n;i++){
		printf("Enter the arrival time p%d:",i);
		scanf("%d",&p[i].atime); //Assigning the arrival time.
		arr[i] = p[i].atime;
	}
	printf("\n");
	
	for(i = 0;i<n;i++){
	printf("Enter the arrival time p%d:",i);
	printf("%d\n",p[i].atime); //Printing the arrival time.
	arr[i] = p[i].atime;
	}
	printf("\n");
	
	for(i = 0;i<n;i++){
	printf("Enter the brust time p%d:",i);
	scanf("%d",&p[i].btime); //Assigning the brust time.
	brust[i] = p[i].btime;
	}
	printf("\n");
	
	for(i = 0;i<n;i++){
	printf("Enter the brust time p%d:",i);
	printf("%d\n",p[i].btime); //Printing the brust time.
	brust[i] = p[i].btime;
	}
	printf("\n");
	
	addrq();  //Adding the process.
	// Process start now.
	printf("Gnatt Chart is:");
	while(1){
	j = selectionjob(); //sercah the process now.
		
		if(j == -1){
			printf("CPU is ideal");
			time++;
			addrq();			
		}else{
			while(brust[j]!=0){
				printf("\t j %d",j);
				brust[j]--;
				time++;
				addrq();
			}
			p[j].ft = time;
		}
		if(fsahll() == 1)
		break;
	}
	int Tat = 0,Twt =0;
	
	printf("\n");
	printf("\nJob \t FT \t TAT \t WT");
	for(i=0;i<n;i++){
		p[i].tat = p[i].ft-p[i].atime;
		p[i].wt = p[i].tat-p[i].btime;
		
		printf("\n JOb %d \t %d \t %d \t %d",i,p[i].ft,p[i].tat,p[i].wt);
		Tat += p[i].tat;
		Twt += p[i].wt;
	}
	
	float avgtat = Tat /n;
	float avgwt = Twt /n;
	
	printf("\nAverage of trun around time is:%f",avgtat);
	printf("\nAverage of wait time is:%f",avgwt);
	printf("\n");
}

int addrq(){
	int i;
	for(i=0;i<n;i++){
		if(arr[i] == time){
			rq[no_rq] = i;
			no_rq++;
		}
	}
}

int selectionjob(){
	int i,j;
	if(no_rq == 0)
		return 1;
		j = rq[0];
		
		for(i=1;i<no_rq;i++)
		if(brust[j]>brust[rq[i]])
		j = rq[i];
		
		deleteq(j);
		return j;
}

int deleteq(int j){
	int i;
	for(i=0;i<no_rq;i++)
		
		if(rq[i] == j)
			break;
		
		for(i= i+1;i<no_rq;i++)
		rq[i-1] = rq[i];
		no_rq--;
}

int fsahll(){
	int i;
	for(i=0;i<n;i++)
	if(brust[i]!=0)
	return -1;
	return 1; 
}


/*
Output:-
Enter the job number:3

Enter the arrival time p0:1
Enter the arrival time p1:2
Enter the arrival time p2:0

Enter the arrival time p0:1
Enter the arrival time p1:2
Enter the arrival time p2:0

Enter the brust time p0:3
Enter the brust time p1:2
Enter the brust time p2:5

Enter the brust time p0:3
Enter the brust time p1:2
Enter the brust time p2:5

Gnatt Chart is:  j 2     j 2     j 2     j 2     j 2     j 1     j 1     j 0     j 0     j 0
Job      FT      TAT     WT
 JOb 0   10      9       6
 JOb 1   7       5       3
 JOb 2   5       5       0
Average of trun around time is:6.000000
Average of wait time is:3.000000

Sanket Nalage
*/



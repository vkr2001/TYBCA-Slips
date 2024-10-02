#include<stdio.h>

int main() 
{
int page_reference_string[] = {3,4,5,6,3,4,7,3,4,7,3,4,5,6,7,2,4,6};
int n,i;

printf(" Enter the number of memory frames : ");
scanf("%d",&n);

int memory_frames[n];
int page_queue[n];
int page_faults =0;

for(i = 0; i<=n; i++) {
memory_frames[i] = -1;
page_queue[i] = -1;
}

for (i=0; i<sizeof(page_reference_string)/sizeof(page_reference_string[0]);i++) {

int page = page_reference_string[i];
int found =0;
int j;

for(j=0; j<n; j++) {
if(memory_frames[i] ==page)
{
found=1;
break;
}
}
if(!found)
{
page_faults++;
if(page_queue[0]!=-1)
{

int replaced_page = page_queue[0];

for(j=0; j<n; j++) {
if(memory_frames[j] == replaced_page) {
memory_frames[j]=page;
break;
}
}

for(j=0;j<n-1;j++) {
page_queue[j] = page_queue[j+1];
}
}
else {
for(j=0;j<n-1;j++) {
if(memory_frames[j]== -1) {
   memory_frames[j] = page;
 break;
}
}
}
int j;
for(j=0; j<n-1; j++) {
page_queue[j] = page_queue[j + 1];
}
page_queue[n-1]=page;
}

printf("Page Reference : %d\n", page);
printf("Memory Frames :");
for(j=0; j<n; j++) {
printf("%d", memory_frames[j]);
}

printf("\n\n");
}
printf("Total Page Faults : %d\n",page_faults);
return 0;
}
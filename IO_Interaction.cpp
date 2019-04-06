#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

struct Process
{
	int pid;
	int arr[10];
};

void main()
{

struct Process P[10];
int n;
printf("Enter the no. of processes: ");
scanf("%d",&n);
for(int i=0;i<n;i++)
{	int io;
	printf("\nEnter Process Id for Process %d: ",i+1);
	scanf("%d",&P[i].pid);
	printf("Enter the no. of times this process uses I/O terminal: ");
	scanf("%d",&io);
	printf("Enter the timings of I/O interaction: \n");
	for(int j=0;j<io;j++)
	{
		scanf("%d",&P[i].arr[j]);
	}
}
}

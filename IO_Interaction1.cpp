#include<unistd.h>
#include<stdio.h>

struct Process
{
	int pid;
	int interact;
};

void main()
{
	struct Process P[50],higher[50],lower[50];
	int h=0,l=0;
	int np;
	printf("Enter the no. of processes: ");
	scanf("%d",&np);
	for(int i=0;i<np;i++)
	{	int io;
		printf("\nEnter Process Id for Process %d: ",i+1);
		scanf("%d",&P[i].pid);
		printf("Enter the timing of I/O interaction: ");
		scanf("%d",&P[i].interact);
		//printf("\n");
	}
	for(int t=0,k=0;t<10,k<np;t+=1,k++)
	{	
		sleep(1);		
		if(P[k].interact!=t)
		{	
			lower[l]=P[k];
			l+=1;
		}
		else
		{
			higher[h]=P[k];
			h++;
		}
			
	}

	printf("\nProcesses in Lower Priority Queue:\n");
	for(int y=0;y<l;y++)
	{
	printf("Process Id: %d\n",lower[y].pid);
	}

	printf("\nProcesses in Higher Priority Queue:\n");
	for(int y=0;y<h;y++)
	{
	printf("Process Id: %d\n",higher[y].pid);
	}
}














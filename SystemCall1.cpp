//Q7
#include <stdio.h>
#include <time.h>
#include<pthread.h>
#include<unistd.h>
void func();
void *Nsleep()
{	int i=0;

	while(i<1)
	{
	   struct timespec tim, tim2;
	   tim.tv_sec = 0;
	   tim.tv_nsec = 699999999;

	   if(nanosleep(&tim , &tim2) < 0 )   
	   {
	      printf("Output failed \n");
	   }
	   if(i==-6)
		   func();

	   printf("Outputting on screen \n");
	   i--;
	}
}

void func()
{
	printf("\nAgain executing main Process");
	for(int i=100;i<200;i+=10)
	{
	printf("\n		%d\n",i);
	}
}

void *Program()
{	
	printf("\nExecuting main Process");
	for(int i=0;i<100;i+=10)
	{
	printf("\n		%d\n",i);
	}
}


int main()
{
	pthread_t t1,t2;
	pthread_create(&t1,NULL,Nsleep,NULL);
	pthread_create(&t2,NULL,Program,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
}


#include <stdio.h>
#include <time.h>
#include<pthread.h>
#include<unistd.h>

void *Nsleep()
{

	while(1)
	{
	   struct timespec tim, tim2;
	   tim.tv_sec = 1;
	   tim.tv_nsec = 5000000;

	   if(nanosleep(&tim , &tim2) < 0 )   
	   {
	      printf("Nano sleep system call failed \n");
	   }

	   printf("Nano sleep successfull \n");
	}
}

void *Program()
{
	for(int i=0;i<100;i+=10)
	{
	printf("\n		%d\n",i);
	}
}


void main()
{
	pthread_t t1,t2;
	pthread_create(&t1,NULL,Nsleep,NULL);
	pthread_create(&t2,NULL,Program,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
}




















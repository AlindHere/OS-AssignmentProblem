//Q20
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<semaphore.h>
#include<pthread.h>
int pen=4,quespaper=4,paper=4;		//infinite supply means (supply > requirement)
sem_t s;
void *Student1()
	{
	int pen=1;
	sem_wait(&s);
	printf("\nStudent 1 using his pen, and question paper, paper provided by the teacher\n\n");
	quespaper-=1;
	paper-=1;
	sem_post(&s);
	}
void *Student2()
	{	
	int quespaper=1;
	sem_wait(&s);
	printf("\nStudent 2 using his Question paper, and pen, paper provided by the teacher\n\n");
	pen-=1;
	paper-=1;
	sem_post(&s);
	}
void *Student3()
	{
	int paper=1;
	sem_wait(&s);
	printf("\nStudent 3 using his paper, and question paper, pen provided by the teacher\n\n");
	pen-=1;
	quespaper-=1;
	sem_post(&s);
	}

void main()
{	printf("\nSupplies with teacher before the students start doing their assignments are:\nPens: %d\nQuestion Papers: %d\nPapers: %d\n",pen,quespaper,paper);
	pthread_t t1,t2,t3;
	sem_init(&s,0,3);
	pthread_create(&t1,NULL,Student1,NULL);
	pthread_create(&t2,NULL,Student2,NULL);
	pthread_create(&t3,NULL,Student3,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	printf("\nSupplies left with teacher after all the students have completed the assignment are:\nPens: %d\nQuestion Papers: %d\nPapers: %d\n\n\n",pen,quespaper,paper);
}

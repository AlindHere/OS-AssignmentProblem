//Q20
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<semaphore.h>
#include<pthread.h>
int pen=1,quespaper=1,paper=1;
sem_t s;


void main()
{

sem_init(&s,0,3);

}

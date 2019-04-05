#include <stdio.h>
#include <time.h>

int main()
{
//for(int i=0;i<10;i+=1)
while(1)
{
   struct timespec tim, tim2;
   tim.tv_sec = 1;
   tim.tv_nsec = 500000000;

   if(nanosleep(&tim , &tim2) < 0 )   
   {
      printf("Nano sleep system call failed \n");
   }

   printf("Nano sleep successfull \n");
}
}

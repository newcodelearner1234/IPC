// Program to demonstrate semaphore

#include <stdio.h>
#include <pthread.h>         //required header file for thread programming
#include <semaphore.h>       //required header file for semaphore
#include <unistd.h>

sem_t mutex;                 // declaring variable of semaphore type

void* thread(void* arg) 
{ 
			     //function acting as a thread
   sem_wait(&mutex);         //wait state

   printf("\n Entered into the Critical Section..\n");
   sleep(3);             //critical section
   
   printf("\n Completed...\n");  //comming out from Critical section
   sem_post(&mutex);
}
main() {
   sem_init(&mutex, 0, 1);        //initialising semaphore
   pthread_t th1,th2;             // declaring threads

   //creating threads
   pthread_create(&th1,NULL,thread,NULL);
   sleep(2);
   pthread_create(&th2,NULL,thread,NULL);

   //Join threads with the main thread
   pthread_join(th1,NULL);
   pthread_join(th2,NULL);

   sem_destroy(&mutex);            //destroying the threads
}

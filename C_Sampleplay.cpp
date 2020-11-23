/*
 ============================================================================
 Name        : C_Play.c
 Author      : Ahmed Elghamry
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "ChocolateyInstaller.h"

#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

#define NUM_OF_THREADS 2
  
pthread_t thread_id[NUM_OF_THREADS];
  
void* shared_function_between_two_threads(void *arg) ;
void *functioncalledbythread(void *arg) ;

  
int main() {

	printf("\n========= Main ============\n" );

	//ChocolateyInstaller chocolateyInstaller;
	//chocolateyInstaller.installAPPs();
	//chocolateyInstaller.init();
/////////////////////////////////////////////////////////////////////
	
    int retval;
    pthread_t threadId;
    int pass_this_val = 5;
  
	 int i = 1;
        int err;
	
	
    printf("Creating simple thread\n");
    if((retval = pthread_create(&threadId, NULL, &functioncalledbythread, (void *)&pass_this_val))) {
        printf("Thread creation failed: %d\n", retval);
    }
  

	
/////////////////////////////////////////////////////////////////////

  
        for (i=0; i<NUM_OF_THREADS; i++) {
                err = pthread_create(&(thread_id[i]), NULL, &shared_function_between_two_threads, NULL);
                if (err != 0)
                        printf("Thread creation failed :[%s]", strerror(err));
                else
                        printf("Thread %ld created successfully\n", thread_id[i]);
        }
  
	
////////////////////////////////////////////////////////////////////
    printf("Waiting in main for thread to finish\n");
    /* Wait till threads are complete before main continues.*/
    pthread_join(threadId, NULL);
  
    printf("Thread execution finished, exiting from main program\n");	
////////////////////////////////////////////////////////////////////
        printf("Waiting in main for thread to finish\n");
        for (i=0; i<NUM_OF_THREADS; i++) {
                pthread_join(thread_id[i], NULL);
        }
  
        printf("Thread execution finished, exiting from main program\n");
/////////////////////////////////////////////////////////////////////
    return 0; 
}


void *functioncalledbythread(void *arg) {
    int count = 0, i;
    int *passed_value = (int*)arg;
    printf("Value passed to thread from main : %d \n", *passed_value);
  
    for(i=0; i<10; i++) {
        count++;
        sleep(1);
    }
    return NULL; 
}

void* shared_function_between_two_threads(void *arg) {
        //unsigned long i = 0;
        pthread_t id = pthread_self();
  
        if(pthread_equal(id, thread_id[0]))
                printf("\n First thread processing\n");
        else
                printf("\n Second thread processing\n");
        return NULL;
}

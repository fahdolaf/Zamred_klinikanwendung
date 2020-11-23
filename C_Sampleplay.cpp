/*
 ============================================================================
 Name        : C_Play.c
 Author      : Ahmed Elghamry
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

//#include "ChocolateyInstaller.h"

#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
  
#define NUM_OF_THREADS 2
  
pthread_t thread_id[NUM_OF_THREADS];
  
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
  
  
int main() {

	printf("\n========= Main ============\n" );

	//ChocolateyInstaller chocolateyInstaller;
	//chocolateyInstaller.installAPPs();
	//chocolateyInstaller.init();
    int retval;
    pthread_t threadId;
    int pass_this_val = 5;
  
    printf("Creating simple thread\n");
    if((retval = pthread_create(&threadId, NULL, &functioncalledbythread, (void *)&pass_this_val))) {
        printf("Thread creation failed: %d\n", retval);
    }
  
    printf("Waiting in main for thread to finish\n");
    /* Wait till threads are complete before main continues.*/
    pthread_join(threadId, NULL);
  
    printf("Thread execution finished, exiting from main program\n");
    return 0; 
}




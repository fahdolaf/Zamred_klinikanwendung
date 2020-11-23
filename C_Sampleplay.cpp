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
  
void* shared_function_between_two_threads(void *arg) {
        unsigned long i = 0;
        pthread_t id = pthread_self();
  
        if(pthread_equal(id, thread_id[0]))
                printf("\n First thread processing\n");
        else
                printf("\n Second thread processing\n");
        return NULL;
}
  
int main() {

	printf("\n========= Main ============\n" );

	//ChocolateyInstaller chocolateyInstaller;
	//chocolateyInstaller.installAPPs();
	//chocolateyInstaller.init();
        int i = 1;
        int err;
  
        for (i=0; i<NUM_OF_THREADS; i++) {
                err = pthread_create(&(thread_id[i]), NULL, &shared_function_between_two_threads, NULL);
                if (err != 0)
                        printf("Thread creation failed :[%s]", strerror(err));
                else
                        printf("Thread %ld created successfully\n", thread_id[i]);
        }
  
        printf("Waiting in main for thread to finish\n");
        for (i=0; i<NUM_OF_THREADS; i++) {
                pthread_join(thread_id[i], NULL);
        }
  
        printf("Thread execution finished, exiting from main program\n");
        return 0;
}




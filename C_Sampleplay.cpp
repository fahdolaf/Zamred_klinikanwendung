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

#include <stdio.h> 
#include <stdlib.h> 
#include <pthreads.h>

void* calls(void* ptr) 
{ 
    // using pthread_self() get current thread id 
    printf("In function \nthread id = %d\n", pthread_self()); 
    pthread_exit(NULL); 
    return NULL; 
} 

int main() {

	printf("\n========= Main ============\n" );

	//ChocolateyInstaller chocolateyInstaller;
	//chocolateyInstaller.installAPPs();
	//chocolateyInstaller.init();
	pthread_t thread; // declare thread 
	pthread_create(&thread, NULL, calls, NULL); 
	printf("In main \nthread id = %d\n", thread);  
	pthread_join(thread, NULL);  
	
	return 0;
}




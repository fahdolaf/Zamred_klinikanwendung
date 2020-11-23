/*
 ============================================================================
 Name        : C_Play.c
 Author      : Ahmed Elghamry
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <windows.h>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

DWORD WINAPI ThreadFunc(void* data) {
  // Do stuff.  This will be the first function called on the new thread.
  // When this function returns, the thread goes away.  See MSDN for more details.
 printf("\n First thread processing\n");
  return 0;
}

int main() {
 	printf("\n========= Main ============\n" );

  HANDLE thread = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);
  if (thread) {
    // Optionally do stuff, such as wait on the thread.
   printf("Thread creation Done \n");
  }
}

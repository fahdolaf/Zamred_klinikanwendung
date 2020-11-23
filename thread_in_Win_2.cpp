#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>

DWORD WINAPI MyThreadFunction(LPVOID lpParam){
printf("The parameter: %lu.\n", *(DWORD*)lpParam);
return 0;
}


DWORD WINAPI myThread(LPVOID lpParameter)
{
	unsigned int& myCounter = *((unsigned int*)lpParameter);
	while(myCounter < 0xFFFFFFFF) ++myCounter;
	return 0;
}

int main(int argc, char* argv[])
{
DWORD dwThreadId, dwThrdParam = 1;
HANDLE hThread;
hThread = CreateThread(
NULL, // default security attributes
0, // use default stack size
MyThreadFunction, // thread function
&dwThrdParam, // argument to thread function
0, // use default creation flags
&dwThreadId); // returns the thread identifier

printf("The thread ID: %ld.\n", dwThreadId);

// Check the return value for success. If something wrong...
if (hThread == NULL)
printf("CreateThread() failed, error: %ld.\n", GetLastError());
//else, gives some prompt...
else
printf("It seems the CreateThread() is OK lol!\n");

if (CloseHandle(hThread) != 0)
printf("Handle to thread closed successfully.\n");
/////////////////////////////////////////////////////////////////
 
 	using namespace std;

	unsigned int myCounter = 0;
	DWORD myThreadID;
	HANDLE myHandle = CreateThread(0, 0, myThread, &myCounter, 0, &myThreadID);
	char myChar = ' ';
	while(myChar != 'q') {
		cout << myCounter << endl;
		myChar = getchar();
	}
	
	CloseHandle(myHandle);
 
 
return 0;
}

 

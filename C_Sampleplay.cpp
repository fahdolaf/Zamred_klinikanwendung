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
#include<stdlib.h>
#include<unistd.h>


  
int main() {

	printf("\n========= Main ============\n" );

	ChocolateyInstaller chocolateyInstaller;
	//chocolateyInstaller.installAPPs();
	chocolateyInstaller.init();

    return 0; 
}

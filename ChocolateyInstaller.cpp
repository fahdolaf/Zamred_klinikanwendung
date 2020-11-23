#include "ChocolateyInstaller.h"



void ChocolateyInstaller::installAPPs(){


    char *appsList[] = { "firefox", "vlc", "7zip" , "putty","winscp", "notepadplusplus","javaruntime"};
	int loop;

	for(loop=0; loop<7; loop++)
	{
		install_Single_APP( appsList[loop]);
	}



}

void ChocolateyInstaller::install_Single_APP(char *appName)
{

	char program[100] = {"choco install "};
	//printf("%s %s\n",program, appName);
	strcat(program, appName);
	strcat(program, " -y");

	printf("%s\n",program );

    system(program);


}

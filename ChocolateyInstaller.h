#ifndef CHOCOLATEYINSTALLER_H_
#define CHOCOLATEYINSTALLER_H_


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <list>
#include <iostream>

using namespace std;

class ChocolateyInstaller {
  private:
    int counter_;
    char *appsList[] = { "firefox", "vlc", "7zip" , "putty","winscp", "notepadplusplus","javaruntime"};
  
  public:
    ChocolateyInstaller() : counter_(0) {}
      int Incr();
      int value();
      void installAPPs();
      void install_Single_APP(char *appName);

};

#endif /* CHOCOLATEYINSTALLER_H_ */


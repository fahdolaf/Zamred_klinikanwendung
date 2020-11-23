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
  
  public:
    ChocolateyInstaller() : counter_(0) {}
      void init();
      void installAPPs();
      void install_Single_APP(char *appName);

};

#endif /* CHOCOLATEYINSTALLER_H_ */


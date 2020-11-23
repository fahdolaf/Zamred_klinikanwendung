# Zamred_klinikanwendung


pwd

#### WIN ####

path C:\MinGW\bin;%path%

rm -rf play_c_3.exe src/play_c_3.d src/ChocolateyInstaller.d src/ChocolateyInstaller.o src/play_c_3.o

g++ -O0 -g3 -Wall -c -fmessage-length=0 -o "src\\C_Sampleplay.o" "src\\C_Sampleplay.cpp"

g++ -O0 -g3 -Wall -c -fmessage-length=0 -o "src\\ChocolateyInstaller.o" "src\\ChocolateyInstaller.cpp"

g++ -o C_Sampleplay.exe "src\\ChocolateyInstaller.o" "src\\C_Sampleplay.o"

C_Sampleplay.exe



#### Linux #####

tree

rm -rf play_c_3.exe src/play_c_3.d src/ChocolateyInstaller.d src/ChocolateyInstaller.o src/play_c_3.o

g++ -O0 -g3 -Wall -c -fmessage-length=0 -o "src/C_Sampleplay.o" "src/C_Sampleplay.cpp"

g++ -O0 -g3 -Wall -c -fmessage-length=0 -o "src/ChocolateyInstaller.o" "src/ChocolateyInstaller.cpp"

g++ -o C_Sampleplay.exe "src/ChocolateyInstaller.o" "src/C_Sampleplay.o"

./C_Sampleplay.exe



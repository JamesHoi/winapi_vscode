del *.o
SET PATH=%PATH%;%1
gcc -c wave.cpp -Wno-write-strings 
g++ *.o -O0 -o %2 -s -lgdi32 -luser32 -lkernel32  -lcomdlg32 -lwinspool -lwinmm  -lcomctl32 -mwindows
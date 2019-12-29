#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <deque>
#include <mutex>

using namespace std;

struct files {
  mutex m;
  deque<string> filenames;
};

struct counts {
  mutex m;
  deque<int> counts;
  deque<thread::id> who;
};

void map(files* fq, counts* cq, const string& needle);
void reduce(counts* cq);
void read_file(string filename, files* fq);

#include "Functions.cpp" 
// If this line is missing, preLaunchTask is determined with exit code 1 on g++.exe | Visual Studio Code
// In order to debug, I have to include this .cpp file :(
// But I see on this website https://stackoverflow.com/questions/3002110/include-in-h-or-c-cpp 
// and this website https://stackoverflow.com/questions/19547091/including-cpp-files
// it seems including cpp files is legal but may cause that duplication problem
// so it's deprecated (maybe?) or not recommend to use? (I just wondering)
// if I am lucky enough to get an answer, please contact me through hikarika021@gmail.com
#endif
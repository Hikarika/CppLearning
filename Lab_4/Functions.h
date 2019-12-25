#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <fstream>
#include <iostream>
#include <string>
#include <deque>
#include <mutex>
#include <thread>

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
#endif
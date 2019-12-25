//============================================================================
// Name        : myMapReduce.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <fstream>
#include <iostream>
#include <string>
#include "Functions.h"
#define MAPPERS_NUM 4
#define REDUCERS_NUM 4
#define INPUT_FILE "Lab_4\\files.dat"

using namespace std;

int main(int argc, char *argv[])
{

  string needle = "the"; //default search word

  if (argc == 2) // assume the user is passing the target string in the execution call
    needle = argv[1];

  files fq;
  counts cq;

  //setup some sample files for the threads to read...
  //(to give it "enough" data, files are processed multiple times :)
  for(int i = 0; i < 10; i++)
  {
    // fq.filenames.push_back("Lab_4\\modest-proposal.txt");
    // fq.filenames.push_back("Lab_4\\flatland.txt");
    read_file(INPUT_FILE, &fq);
  }

 
  thread mappers[MAPPERS_NUM];
  for(int i = 0; i < MAPPERS_NUM; i++)
  {
    mappers[i] = thread(map, &fq, &cq, needle);
  }

  //make sure all threads have finished work and join main before continuing
  for(auto& m : mappers)
  {
    m.join();
  }

  //all counting has completed, proceed to analyze individual counts
  auto whoit = cq.who.begin();
  for(auto& i : cq.counts)
  {
    cout << *whoit << " " << i << endl;
    whoit++;
  }

  thread reducers[REDUCERS_NUM];
  for(int i = 0; i < REDUCERS_NUM; i++)
  {
    reducers[i] = thread(reduce, &cq);
  }

  for(auto& r : reducers)
  {
    r.join();
  }

  cout << "Final count: " << endl;
  for(auto& i : cq.counts)
  {
    cout << i << endl;
  }

  system("pause");
  return 0;
}
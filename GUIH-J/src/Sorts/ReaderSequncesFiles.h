//
// Created by pda on 22.06.19.
//

#ifndef H_J_READERSEQUNCESFILES_H
#define H_J_READERSEQUNCESFILES_H

#include <string.h>
#include <fstream>
#include <iostream>
#include <string>

#include <stdlib.h>

using namespace std;

class FilesDTO {
 private:
  int length;
  int *vector;
  string name;

 public:
  void set_length(int);

  void set_vector(int *);

  int get_length();

  int *get_vector();

  void add_name(string name);

  string get_name();
};

class ReaderSequncesFiles {
 public:
  FilesDTO *readfile(string filepath);
};

enum errors { ERRORFILENAME = 1, ERRORSIZE, NOEXISTS, NEGATIVEVALUE };

class ChekerSequncesFiles {
 public:
  int check_file(string filepath);
};

#endif  // H_J_READERSEQUNCESFILES_H

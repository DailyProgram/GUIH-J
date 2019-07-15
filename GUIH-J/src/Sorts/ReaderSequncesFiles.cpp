//
// Created by pda on 22.06.19.
//

#include "ReaderSequncesFiles.h"

//функция отделения  имени файла от пути
string delete_path(string filePath) {
  string resultstring = "";
  int pos_last_slash = 0;
  int len_str = filePath.length();

  for (int i = 0; i < len_str; i++) {
    if (filePath[i] == '/') {
      pos_last_slash = i;
    }
  }

  for (int i = pos_last_slash + 1; i < len_str; i++) {
    resultstring = resultstring + filePath[i];
  }
  return resultstring;
}

//функция проверки существования файла
bool FileIsExists(string filePath) {
  bool isExist = false;
  ifstream fin(filePath.c_str());

  if (fin.is_open()) isExist = true;

  fin.close();
  return isExist;
}

int ChekerSequncesFiles::check_file(string filepath) {
  const int MIN_LEN = 24;
  const int TEXT_LEN = 17;
  const int EXP_LEN = 4;

  string filename = delete_path(filepath);

  int flag = 0;
  string copyfilename = filename;
  int len_cpy = copyfilename.length();

  if (len_cpy < MIN_LEN) {
    return ERRORFILENAME;
  }

  int num = 0;
  string strnum = "";
  int i = 0;
  while (copyfilename[i] != '_' && i < len_cpy) {
    strnum = strnum + copyfilename[i];
    i++;
  }
  num = atoi(strnum.c_str());

  if (num <= 0) {
    return ERRORFILENAME;
  }

  string output = "";
  for (int j = 0; j < TEXT_LEN; j++) {
    output = output + copyfilename[i];
    i++;
  }

  if (output != "_Output_sequnces_") {
    return ERRORFILENAME;
  }

  int size = 0;
  string strsize = "";

  while (copyfilename[i] != '.' && i < len_cpy) {
    strsize = strsize + copyfilename[i];
    i++;
  }
  size = atoi(strsize.c_str());
  if (size <= 0) {
    return !flag;
  }

  string expansion = "";

  for (int j = 0; j < EXP_LEN; j++) {
    expansion = expansion + copyfilename[i];
    i++;
  }

  if (expansion != ".sqc") {
    return ERRORFILENAME;
  }

  int type_sqc = 0;
  string strtype_sqc = "";
  strtype_sqc = copyfilename[i];

  type_sqc = atoi(strtype_sqc.c_str());

  if (type_sqc < 0 || type_sqc > 9) {
    return ERRORFILENAME;
  }

  if (FileIsExists(filepath)) {
    ifstream infile;
    infile.open(filepath);

    int sizefile;
    infile >> sizefile;

    if (size != sizefile) {
      return ERRORSIZE;
    }

    int count = 0;

    while (!infile.eof()) {
      int simple = -1;
      infile >> simple;
      if (simple != -1) {
        if (simple < 0) {
          return NEGATIVEVALUE;
        }
        count++;
      }
    }

    if (count != size || count != sizefile) {
      infile.close();
      return ERRORSIZE;
    }

    infile.close();

  } else {
    return NOEXISTS;
  }

  return 0;
}

FilesDTO *ReaderSequncesFiles::readfile(string filepath) {
  ifstream infile;
  infile.open(filepath);

  int sizefile;

  infile >> sizefile;

  int *resulvector = new int[sizefile];

  int i = 0;
  while (!infile.eof()) {
    int simple = -1;
    infile >> simple;
    if (simple != -1) {
      resulvector[i] = simple;
      i++;
    }
  }
  infile.close();

  FilesDTO *filesDto = new FilesDTO;
  filesDto->set_length(sizefile);
  filesDto->set_vector(resulvector);
  filesDto->add_name(delete_path(filepath));
  return filesDto;
}

void FilesDTO::set_length(int len) { length = len; }

void FilesDTO::set_vector(int *data) {
  vector = new int[length];

  for (int i = 0; i < length; i++) {
    vector[i] = data[i];
  }
}

int FilesDTO::get_length() { return length; }

int *FilesDTO::get_vector() {
  int *resultvector = new int[length];
  for (int i = 0; i < length; i++) {
    resultvector[i] = vector[i];
  }
  return resultvector;
}

void FilesDTO::add_name(string myname) { this->name = myname; }

string FilesDTO::get_name() { return name; }

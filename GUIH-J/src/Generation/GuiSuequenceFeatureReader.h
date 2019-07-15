#ifndef H_J_GUISUEQUENCEFEATUREREADER_H
#define H_J_GUISUEQUENCEFEATUREREADER_H

const int L = 8;  //число последовательностей

// enum errors {
//  NOSQNS = 1,
//  NOSQN1,
//  NOSQN2,
//  NOSQN3,
//  NOSQN4,
//  NOSQN5,
//  NOSQN6,
//  NOSQN7,
//  NOSQN8,
//  NOCSM,
//  NOSWP,
//  NORPT
//};

class ReadDTO;

class GuiSuequenceFeatureReader {
 public:
  ReadDTO *read();
};

class CheckerGUIdataGeneration {
 public:
  bool checksqns(bool *sqns);
  bool checkswp(int swp);
  bool checkrpt(int rpt);
  bool checkcsm(int csm);
};

class ReadDTO {
 private:
  bool sequences[L];  //последовательности
  int lengths[L];     //длины последовательностей
  //доп.данные
  int csm;
  int swp;
  int rpt;

 public:
  void set_sequence(bool num[L]);

  void set_lengths(int len[L]);

  void set_scm(int);

  void set_swp(int);

  void set_rpt(int);

  bool *get_sequences();

  int *get_lenghts();

  int get_csm();

  int get_swp();

  int get_rpt();
};

#endif  // H_J_GUISUEQUENCEFEATUREREADER_H

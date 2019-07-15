//
// Created by pda on 09.06.19.
//

#include "Generator.h"
#include <fstream>
#include <iostream>

ResultData *Generator::generate(ReadDTO &data) {
  vector<InterfaceSequences *> collectionGeneratorsSequences;
  collectionGeneratorsSequences.push_back(new Sequences1);
  collectionGeneratorsSequences.push_back(new Sequences2);
  collectionGeneratorsSequences.push_back(new Sequences3);
  collectionGeneratorsSequences.push_back(new Sequences4);
  collectionGeneratorsSequences.push_back(new Sequences5);
  collectionGeneratorsSequences.push_back(new Sequences6);
  collectionGeneratorsSequences.push_back(new Sequences7);
  collectionGeneratorsSequences.push_back(new Sequences8);

  ResultData *resultData = new ResultData;
  resultData->set_lengths(data.get_lenghts());

  int **resultsqcs = new int *[L];

  for (int i = 0; i < L; i++) {
    if (data.get_sequences()[i] == true) {
      int subdata = 0;

      switch (i) {
        case 4:
          subdata = data.get_csm();
          break;
        case 5:
          subdata = data.get_swp();
          break;
        case 6:
          subdata = data.get_rpt();
          break;
      }

      resultsqcs[i] = collectionGeneratorsSequences.at(i)->get_vector(
          data.get_lenghts()[i], subdata);

    } else {
      resultsqcs[i] = NULL;
    }
  }

  resultData->set_sequences(resultsqcs);

  return resultData;
}

void ResultData::set_lengths(int *lens) {
  for (int i = 0; i < L; i++) {
    lengths[i] = lens[i];
  }
}

void ResultData::set_sequences(int **sqcs) {
  sequences = new int *[L];
  for (int i = 0; i < L; i++) {
    sequences[i] = sqcs[i];
  }
}

int **ResultData::get_sequences() { return sequences; }

int *ResultData::get_lengths() { return lengths; }

void ResultData::print() {
  for (int i = 0; i < L; i++) {
    if (sequences[i] != nullptr) {
      // cout << "Sqs#" << i + 1 << "=";
      for (int k = 0; k < lengths[i]; k++) {
        // cout << sequences[i][k] << " ";
      }
      // cout << endl;
    } else { /*cout << "Sqs#" << i + 1 << "No" << endl; */
    }
  }
}

//функция проверки существования файла
bool FileIsExist(std::string filePath) {
  bool isExist = false;
  ifstream fin(filePath.c_str());

  if (fin.is_open()) isExist = true;

  fin.close();
  return isExist;
}

//перевод числа в char*
char *inttostr(int num) {
  int buf = num;
  int kol = 0;
  while (buf != 0) {
    buf = buf / 10;
    kol++;
  }
  char *result = new char[kol + 1];
  buf = num;
  for (int i = 0; i < kol; i++) {
    result[kol - 1 - i] = buf % 10 + '0';
    buf = buf / 10;
  }
  result[kol] = '\0';
  return result;
}

//создание свободного имени файла
string createName(int num, int numfile, int len) {
  string resstring;
  char *numchar = inttostr(num);
  char *numfilechar = inttostr(numfile);
  char *lenchar = inttostr(len);

  resstring = numfilechar;
  resstring = resstring + "_Output_sequnces_" + lenchar;
  resstring = resstring + ".sqc" + numchar;

  return resstring;
}

void Writer::write(ResultData &data) {
  int num_file = 1;
  string namefile;
  for (int i = 0; i < L; i++) {
    int lennowsqs = data.get_lengths()[i];

    if (data.get_sequences()[i] != NULL) {
      namefile = createName(i + 1, num_file, lennowsqs);
      while (FileIsExist(namefile)) {
        num_file++;
        namefile = createName(i + 1, num_file, lennowsqs);
      }
      num_file++;
      cout << namefile << endl;

      //вывод содержимого в файл
      ofstream fout;
      fout.open(namefile);
      // fout << data.get_massive_type() << endl;
      fout << lennowsqs << " ";

      for (int j = 0; j < lennowsqs; j++) {
        if (j == lennowsqs - 1) {
          fout << data.get_sequences()[i][j];
        } else {
          fout << data.get_sequences()[i][j] << " ";
        }
      }
    }
    namefile = "";
  }
}

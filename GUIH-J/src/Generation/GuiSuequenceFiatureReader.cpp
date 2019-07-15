#include <string.h>
#include "GuiSuequenceFeatureReader.h"

void ReadDTO::set_sequence(bool sqs[L]) {
  for (int i = 0; i < L; i++) {
    sequences[i] = sqs[i];
  }
}

void ReadDTO::set_lengths(int len[L]) {
  for (int i = 0; i < L; i++) {
    lengths[i] = len[i];
  }
}

void ReadDTO::set_scm(int c) { csm = c; }

void ReadDTO::set_rpt(int r) { rpt = r; }

void ReadDTO::set_swp(int s) { swp = s; }

bool *ReadDTO::get_sequences() { return sequences; }

int *ReadDTO::get_lenghts() {
  int *result = new int[L];
  for (int i = 0; i < L; i++) {
    result[i] = lengths[i];
  }
  return result;
}

int ReadDTO::get_rpt() { return rpt; }

int ReadDTO::get_swp() { return swp; }

int ReadDTO::get_csm() { return csm; }

bool CheckerGUIdataGeneration::checksqns(bool *sqns) {
  bool flag = false;
  for (int i = 0; i < L; i++) {
    if (sqns[i] == true) {
      flag = true;
    }
  }
  return flag;
}

bool CheckerGUIdataGeneration::checkcsm(int csm) {
  const int max_csm = 500000;
  if (csm <= 0 || csm > max_csm) {
    return false;
  }
  return true;
}

bool CheckerGUIdataGeneration::checkswp(int swp) {
  const int max_swp = 500000;
  if (swp <= 0 || swp > max_swp) {
    return false;
  }
  return true;
}

bool CheckerGUIdataGeneration::checkrpt(int rpt) {
  const int max_rpt = 90;
  const int min_rpt = 10;
  if (rpt <= min_rpt || rpt > max_rpt) {
    return false;
  }
  return true;
}

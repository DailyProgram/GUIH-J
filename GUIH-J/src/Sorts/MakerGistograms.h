//
// Created by pda on 22.06.19.
//
#ifndef H_J_MAKERGISTOGRAMS_H
#define H_J_MAKERGISTOGRAMS_H

#include <string>
#include <vector>
#include "ReaderSequncesFiles.h"
#include "Sort.h"

#include "gistograms.h"

class MakerGistograms {
 private:
  vector<FilesDTO *> sequnces;

  vector<string> get_names();

 public:
  void add_seq(FilesDTO *data);

  bool is_empty();

  bool make_gistograms();
};

#endif  // H_J_MAKERGISTOGRAMS_H

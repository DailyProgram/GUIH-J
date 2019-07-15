//
// Created by pda on 22.06.19.
//

#include "MakerGistograms.h"
#include <QFont>
void MakerGistograms::add_seq(FilesDTO *data) { sequnces.push_back(data); }

//среденее float значение
double culc_mid_valuef(double *data, int size) {
  double result = 0;
  for (int i = 0; i < size; i++) {
    result = result + data[i];
  }
  result = result - data[0] - data[size - 1];
  result = result / size;
  return result;
}

//сренее int значение
int culc_mid_value(int *data, int size) {
  float result = 0;
  for (int i = 0; i < size; i++) {
    result = result + data[i];
  }
  result = result - data[0] - data[size - 1];
  result = result / size;
  return result;
}

std::vector<std::string> MakerGistograms::get_names() {
  int mysize = sequnces.size();
  std::vector<std::string> result;
  for (int i = 0; i < mysize; i++) {
    result.push_back(sequnces.at(i)->get_name());
  }
  return result;
}

bool MakerGistograms::make_gistograms() {
  const int num_rpt = 10;  //число тестовых запусков

  if (sequnces.empty()) {
    return true;
  }

  Heapsort heapsort;
  Jsort jsort;

  int num_sqs =
      sequnces.size();  //кол-во файлов со считанными последовательностями

  //данные для построения гистограммы
  double ResultTimesHeapsort[num_sqs];
  int ResultSwpsHeapsort[num_sqs];
  int ResultEqlsHeapsort[num_sqs];

  double ResultTimesJsort[num_sqs];
  int ResultSwpsJsort[num_sqs];
  int ResultEqlsJsort[num_sqs];

  //данные для вычисления средних значений
  double *alltimeheapsort = new double[num_rpt];
  int *allswpheapsort = new int[num_rpt];
  int *alleqlheapsort = new int[num_rpt];

  double *alltimejsort = new double[num_rpt];
  int *allswpjsort = new int[num_rpt];
  int *alleqljsort = new int[num_rpt];

  for (int i = 0; i < num_sqs; i++) {
    for (int j = 0; j < num_rpt; j++) {
      Resultdata *nowdatasortingheapsort;
      Resultdata *nowdatasortingjsort;

      nowdatasortingheapsort = heapsort.sorting(sequnces.at(i)->get_vector(),
                                                sequnces.at(i)->get_length());
      nowdatasortingjsort = jsort.sorting(sequnces.at(i)->get_vector(),
                                          sequnces.at(i)->get_length());

      alltimeheapsort[j] = nowdatasortingheapsort->get_time();
      allswpheapsort[j] = nowdatasortingheapsort->get_swp();
      alleqlheapsort[j] = nowdatasortingheapsort->get_eql();

      alltimejsort[j] = nowdatasortingjsort->get_time();
      allswpjsort[j] = nowdatasortingjsort->get_swp();
      alleqljsort[j] = nowdatasortingjsort->get_eql();
    }
    //считаем средние значения
    int num_middle_elems = num_rpt - 2;
    ResultTimesHeapsort[i] = culc_mid_valuef(alltimeheapsort, num_middle_elems);
    ResultSwpsHeapsort[i] = culc_mid_value(allswpheapsort, num_middle_elems);
    ResultEqlsHeapsort[i] = culc_mid_value(alleqlheapsort, num_middle_elems);

    ResultTimesJsort[i] = culc_mid_valuef(alltimejsort, num_middle_elems);
    ResultSwpsJsort[i] = culc_mid_value(allswpjsort, num_middle_elems);
    ResultEqlsJsort[i] = culc_mid_value(alleqljsort, num_middle_elems);
  }
  //строим гистрограммы
  Gistograms *gistoramsform = new Gistograms();
  // float *ResultTimesHeapsort,float *ResultTimesJsort,string *Names,int sizev
  vector<string> mynames = this->get_names();

  gistoramsform->set_gisttime(ResultTimesHeapsort, ResultTimesJsort, mynames,
                              num_sqs);
  gistoramsform->set_gisteqwl(ResultEqlsHeapsort, ResultEqlsJsort, mynames,
                              num_sqs);
  gistoramsform->set_gistswp(ResultSwpsHeapsort, ResultSwpsJsort, mynames,
                             num_sqs);

  gistoramsform->setModal(true);
  gistoramsform->exec();

  return true;
}

bool MakerGistograms::is_empty() { return sequnces.empty(); }

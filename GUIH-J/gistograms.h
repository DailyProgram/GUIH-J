#ifndef GISTOGRAMS_H
#define GISTOGRAMS_H

#include <QDialog>
#include <string>
#include <vector>

namespace Ui {
class Gistograms;
}
#include "experimentform.h"
class Gistograms : public QDialog {
  Q_OBJECT
 public:
  void set_gisttime(double *ResultTimesHeapsort, double *ResultTimesJsort,
                    std::vector<std::string> &mynames, int sizev);

  void set_gistswp(int *ResultSwpHeapsort, int *ResultSwpJsort,
                   std::vector<std::string> &mynames, int sizev);

  void set_gisteqwl(int *ResultEqlHeapsort, int *ResultEqlJsort,
                    std::vector<std::string> &mynames, int sizev);

  explicit Gistograms(QWidget *parent = nullptr);
  ~Gistograms();

 private slots:
  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

  void on_pushButton_3_clicked();

 private:
  Ui::Gistograms *ui;
};

#endif  // GISTOGRAMS_H

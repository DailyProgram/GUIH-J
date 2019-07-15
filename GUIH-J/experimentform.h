#ifndef EXPERIMENTFORM_H
#define EXPERIMENTFORM_H

#include <QFileDialog>
#include <string>
#include <vector>
#include "QListWidget"

namespace Ui {
class ExperimentForm;
}

class ExperimentForm : public QDialog {
  Q_OBJECT
  QStringList filepaths;

 public:
  explicit ExperimentForm(QWidget *parent = nullptr);
  ~ExperimentForm();

 private slots:
  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

 private:
  Ui::ExperimentForm *ui;
};

#endif  // EXPERIMENTFORM_H

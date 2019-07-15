#ifndef GENERATIONFORM_H
#define GENERATIONFORM_H

#include <QDialog>

namespace Ui {
class GenerationForm;
}

class GenerationForm : public QDialog {
  Q_OBJECT

 public:
  explicit GenerationForm(QWidget *parent = nullptr);
  ~GenerationForm();

 private slots:
  void on_pushButton_clicked();

  void on_checkBox_stateChanged(int arg1);

  void on_checkBox_2_stateChanged(int arg1);

  void on_checkBox_3_stateChanged(int arg1);

  void on_checkBox_4_stateChanged(int arg1);

  void on_checkBox_5_stateChanged(int arg1);

  void on_checkBox_6_stateChanged(int arg1);

  void on_checkBox_7_stateChanged(int arg1);

  void on_checkBox_8_stateChanged(int arg1);

 private:
  Ui::GenerationForm *ui;
};

#endif  // GENERATIONFORM_H

#include "experimentform.h"
#include <QMessageBox>
#include <iostream>
#include <string>
#include "ui_experimentform.h"

#include "gistograms.h"
#include "src/Sorts/MakerGistograms.h"
#include "src/Sorts/ReaderSequncesFiles.h"
#include "src/Sorts/Sort.h"

ExperimentForm::ExperimentForm(QWidget *parent)
    : QDialog(parent), ui(new Ui::ExperimentForm) {
  ui->setupUi(this);
}

ExperimentForm::~ExperimentForm() { delete ui; }

void ExperimentForm::on_pushButton_clicked() {
  QFileDialog filedialog;

  filepaths = filedialog.getOpenFileNames(
      this, "Выбирите файлы с последовательностями", "",
      "All sqcs(*sqc1 *sqc2 *sqc3 *sqc4 *sqc5 *sqc6 *sqc7 *sqc8);;*.sqc1;; "
      "*.sqc2;; *.sqc3;; *.sqc5;; *.sqc5;; *.sqc6;; *.sqc7;; *.sqc8;;");

  if (filepaths.isEmpty()) {
    ui->listWidget->clear();
  } else {
    ui->listWidget->clear();
    for (int i = 0; i < filepaths.size(); i++) {
      ui->listWidget->addItem(filepaths.at(i));

      std::string nowfilepath = filepaths.at(i).toStdString();
    }
  }
}

void ExperimentForm::on_pushButton_2_clicked() {
  if (filepaths.isEmpty()) {
    QMessageBox::warning(this, "Ошибка",
                         "Нельзя построить гистограммы! Не выбраны файлы!");
  } else {
    ChekerSequncesFiles chekerSequncesFiles;
    ReaderSequncesFiles readerSequncesFiles;
    MakerGistograms makerGistograms;
    int i = 0;
    for (i = 0; i < filepaths.size(); i++) {
      string filepath = filepaths.at(i).toStdString();

      int type_error = chekerSequncesFiles.check_file(filepath);
      if (type_error == 0) {
        makerGistograms.add_seq(readerSequncesFiles.readfile(filepath));
      } else {
        //"errors";
        switch (type_error) {
          case 1:
            QMessageBox::warning(this, "Ошибка",
                                 "Нельзя создать график по данному файлу " +
                                     filepaths.at(i) +
                                     ".Некорректное имя файла или расширение!");
            break;
          case 2:
            QMessageBox::warning(
                this, "Ошибка",
                "Нельзя создать график по данному файлу " + filepaths.at(i) +
                    ".Число элементов последовательности в файле не "
                    "совпадает с указанным в имени файла");
            break;
          case 4:
            QMessageBox::warning(this, "Ошибка",
                                 "Нельзя создать график по данному файлу " +
                                     filepaths.at(i) +
                                     ".Последовательность содержит "
                                     "отрицательные или некорректные числа");
            break;
        }
      }
    }
    if (makerGistograms.is_empty()) {
      QMessageBox::warning(
          this, "Ошибка", "Нельзя создать график. Выбранные файлы некорректны");
    }
    makerGistograms.make_gistograms();
  }
}

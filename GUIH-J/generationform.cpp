#include "generationform.h"
#include <QMessageBox>
#include <iostream>
#include "src/Generation/Generator.h"
#include "src/Generation/GuiSuequenceFeatureReader.h"
#include "ui_generationform.h"

GenerationForm::GenerationForm(QWidget *parent)
    : QDialog(parent), ui(new Ui::GenerationForm) {
  ui->setupUi(this);
}

GenerationForm::~GenerationForm() { delete ui; }

void GenerationForm::on_pushButton_clicked() {
  GuiSuequenceFeatureReader guireader;
  Writer writer;
  Generator generator;

  CheckerGUIdataGeneration checkerGuidata;

  ReadDTO readDto;

  int *lens = new int[L];
  bool *sqns = new bool[L];
  int csm, swp, rpt;
  bool have_error = 0;

  for (int i = 0; i < L; i++) {
    sqns[i] = false;
    lens[i] = 0;
  }

  if (ui->checkBox->isChecked() == true) {
    sqns[0] = true;
    lens[0] = ui->lineEdit_5->text().toInt();
    if (lens[0] <= 0) {
      QMessageBox::warning(
          this, "Ошибка",
          "Не задана или задана некорректно длина Возрастающей "
          "последовательности");
      have_error = true;
    }
  }
  if (ui->checkBox_2->isChecked() == true) {
    sqns[1] = true;
    lens[1] = ui->lineEdit_6->text().toInt();
    if (lens[1] <= 0) {
      QMessageBox::warning(this, "Ошибка",
                           "Не задана или задана некорректно длина Убывающей "
                           "последовательности");
      have_error = true;
    }
  }
  if (ui->checkBox_3->isChecked() == true) {
    sqns[2] = true;
    lens[2] = ui->lineEdit_7->text().toInt();
    if (lens[2] <= 0) {
      QMessageBox::warning(this, "Ошибка",
                           "Не задана или задана некорректно длина Случайной "
                           "последовательности");
      have_error = true;
    }
  }
  if (ui->checkBox_4->isChecked() == true) {
    sqns[3] = true;
    lens[3] = ui->lineEdit_8->text().toInt();
    if (lens[3] <= 0) {
      QMessageBox::warning(this, "Ошибка",
                           "Не задана или задана некорректно длина "
                           "частично-упорядоченной последовательности");
      have_error = true;
    }
  }
  if (ui->checkBox_5->isChecked() == true) {
    sqns[4] = true;
    lens[4] = ui->lineEdit_9->text().toInt();

    if (lens[4] <= 0) {
      QMessageBox::warning(this, "Ошибка",
                           "Не задана или задана некорректно длина "
                           "последовательности с подпоследовательностями");
      have_error = true;
    }
    csm = 0;
    csm = ui->lineEdit->text().toInt();
    if (!checkerGuidata.checkcsm(csm)) {
      QMessageBox::warning(
          this, "Ошибка",
          "Не задано или задано некорректно число подпоследовательностей");
      have_error = true;
    } else {
      if (csm >= lens[4] / 2) {
        QMessageBox::warning(
            this, "Ошибка",
            "Число подпоследовательностей не может быть "
            "больше или равно половине размерности последовательности");
        have_error = true;
      } else {
        readDto.set_scm(csm);
      }
    }
  }

  if (ui->checkBox_6->isChecked() == true) {
    sqns[5] = true;
    lens[5] = ui->lineEdit_10->text().toInt();
    if (lens[5] <= 0) {
      QMessageBox::warning(
          this, "Ошибка",
          "Не задана или задана некорректно длина последовательности с "
          "заданным числом случайных обменов");
      have_error = true;
    }
    swp = 0;
    swp = ui->lineEdit_2->text().toInt();
    if (!checkerGuidata.checkswp(swp)) {
      QMessageBox::warning(
          this, "Ошибка",
          "Не задано или задано некорректно число случайный обменов");
      have_error = true;
    } else {
      if (swp >= lens[5] / 2) {
        QMessageBox::warning(
            this, "Ошибка",
            "Число случайных обменов не может быть "
            "больше или равно половине размерности последовательности");
        have_error = true;
      } else {
        readDto.set_swp(swp);
      }
    }
  }

  if (ui->checkBox_7->isChecked() == true) {
    sqns[6] = true;
    lens[6] = ui->lineEdit_11->text().toInt();
    if (lens[6] <= 0) {
      QMessageBox::warning(
          this, "Ошибка",
          "Не задана или задана некорректно длина последовательности с большим "
          "повторением одного числа");
      have_error = true;
    }
    rpt = 0;
    rpt = ui->lineEdit_3->text().toInt();
    if (!checkerGuidata.checkrpt(rpt)) {
      QMessageBox::warning(this, "Ошибка",
                           "Не задано или задано некорректно число повторений "
                           "одного элемента(от 10 до 90)");
      have_error = true;
    } else {
      readDto.set_rpt(rpt);
    }
  }

  if (ui->checkBox_8->isChecked() == true) {
    sqns[7] = true;
    lens[7] = ui->lineEdit_12->text().toInt();
    if (lens[7] <= 0) {
      QMessageBox::warning(
          this, "Ошибка",
          "Не задана или задана некорректно длина последовательности Мигалка");
      have_error = true;
    }
  }

  if (!checkerGuidata.checksqns(sqns)) {
    have_error = true;
    QMessageBox::warning(this, "Ошибка",
                         "Не задана ни одна последовательность!");
  }

  if (have_error == 0) {
    readDto.set_lengths(lens);
    readDto.set_sequence(sqns);

    generator.generate(readDto)->print();
    writer.write(*generator.generate(readDto));
    QMessageBox::warning(this, "", "Успешно сгенерировано!");
  }
}

void GenerationForm::on_checkBox_stateChanged(int arg1) {
  ui->lineEdit_5->setEnabled(!ui->lineEdit_5->isEnabled());
  ui->lineEdit_5->clear();
}

void GenerationForm::on_checkBox_2_stateChanged(int arg1) {
  ui->lineEdit_6->setEnabled(!ui->lineEdit_6->isEnabled());
  ui->lineEdit_6->clear();
}

void GenerationForm::on_checkBox_3_stateChanged(int arg1) {
  ui->lineEdit_7->setEnabled(!ui->lineEdit_7->isEnabled());
  ui->lineEdit_7->clear();
}

void GenerationForm::on_checkBox_4_stateChanged(int arg1) {
  ui->lineEdit_8->setEnabled(!ui->lineEdit_8->isEnabled());
  ui->lineEdit_8->clear();
}

void GenerationForm::on_checkBox_5_stateChanged(int arg1) {
  ui->lineEdit_9->setEnabled(!ui->lineEdit_9->isEnabled());
  ui->lineEdit_9->clear();
  ui->lineEdit->setEnabled(!ui->lineEdit->isEnabled());
  ui->lineEdit->clear();
}

void GenerationForm::on_checkBox_6_stateChanged(int arg1) {
  ui->lineEdit_10->setEnabled(!ui->lineEdit_10->isEnabled());
  ui->lineEdit_10->clear();
  ui->lineEdit_2->setEnabled(!ui->lineEdit_2->isEnabled());
  ui->lineEdit_2->clear();
}

void GenerationForm::on_checkBox_7_stateChanged(int arg1) {
  ui->lineEdit_11->setEnabled(!ui->lineEdit_11->isEnabled());
  ui->lineEdit_11->clear();
  ui->lineEdit_3->setEnabled(!ui->lineEdit_3->isEnabled());
  ui->lineEdit_3->clear();
}

void GenerationForm::on_checkBox_8_stateChanged(int arg1) {
  ui->lineEdit_12->setEnabled(!ui->lineEdit_12->isEnabled());
  ui->lineEdit_12->clear();
}

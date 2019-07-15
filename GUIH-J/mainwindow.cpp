#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "generationform.h"
#include "experimentform.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
  GenerationForm generationwindow;
  generationwindow.setModal(true);
  generationwindow.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
   ExperimentForm experimentform;
   experimentform.setModal(true);
   experimentform.exec();
}

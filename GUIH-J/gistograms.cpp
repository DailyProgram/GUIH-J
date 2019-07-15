#include "gistograms.h"
#include "ui_gistograms.h"

Gistograms::Gistograms(QWidget *parent)
    : QDialog(parent), ui(new Ui::Gistograms) {
  ui->setupUi(this);
}

Gistograms::~Gistograms() { delete ui; }

void Gistograms::set_gisttime(double *ResultTimesHeapsort,
                              double *ResultTimesJsort,
                              std::vector<std::string> &mynames, int sizev) {
  // set dark background gradient:
  QLinearGradient gradient(0, 0, 0, 400);
  gradient.setColorAt(0, QColor(90, 90, 90));
  gradient.setColorAt(0.38, QColor(105, 105, 105));
  gradient.setColorAt(1, QColor(70, 70, 70));
  ui->widget->setBackground(QBrush(gradient));

  // create empty bar chart objects:

  QCPBarsGroup *group = new QCPBarsGroup(ui->widget);
  QCPBars *Heapsort = new QCPBars(ui->widget->xAxis, ui->widget->yAxis);
  QCPBars *Jsort = new QCPBars(ui->widget->xAxis, ui->widget->yAxis);

  Heapsort->setAntialiased(false);  // gives more crisp, pixel aligned bar
  // borders
  Jsort->setAntialiased(false);

  Heapsort->setStackingGap(1);
  Jsort->setStackingGap(1);

  Heapsort->setBarsGroup(group);
  Jsort->setBarsGroup(group);
  // set names and colors:

  Jsort->setName("Jsort");
  Jsort->setPen(QPen(QColor(250, 170, 20).lighter(150)));
  Jsort->setBrush(QColor(250, 170, 20));
  Jsort->setWidth(0.4);
  Heapsort->setName("Heapsort");
  Heapsort->setPen(QPen(QColor(0, 168, 140).lighter(130)));
  Heapsort->setBrush(QColor(0, 168, 140));
  Heapsort->setWidth(0.4);
  // stack bars on top of each other:

  // prepare x axis with country labels:
  QVector<double> ticks;
  QVector<QString> labels;

  for (int i = 0; i < sizev; i++) {
    ticks << i * 2 + 1;
    labels << mynames.at(i).c_str();
  }

  QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
  textTicker->addTicks(ticks, labels);
  ui->widget->xAxis->setTicker(textTicker);
  ui->widget->xAxis->setTickLabelRotation(60);
  ui->widget->xAxis->setSubTicks(false);
  ui->widget->xAxis->setTickLength(0, 4);
  ui->widget->xAxis->setRange(0, 8);
  ui->widget->xAxis->setBasePen(QPen(Qt::white));
  ui->widget->xAxis->setTickPen(QPen(Qt::white));
  ui->widget->xAxis->grid()->setVisible(true);
  ui->widget->xAxis->grid()->setPen(
      QPen(QColor(130, 130, 130), 0, Qt::DotLine));
  ui->widget->xAxis->setTickLabelColor(Qt::white);
  ui->widget->xAxis->setLabelColor(Qt::white);

  // prepare y axis:
  //определяем наибольшие результативные данные чтобы построить длину ординаты
  double max_y = ResultTimesHeapsort[0];
  for (int i = 0; i < sizev; i++) {
    if (ResultTimesHeapsort[i] > max_y) {
      max_y = ResultTimesJsort[i];
    }
    if (ResultTimesJsort[i] > max_y) {
      max_y = ResultTimesJsort[i];
    }
  }

  ui->widget->yAxis->setRange(0, max_y);  // 10 минут в миллисекундах
  ui->widget->yAxis->setPadding(1);  // a bit more space to the left
                                     // border
  ui->widget->yAxis->setLabel("Время в мс");
  ui->widget->yAxis->setBasePen(QPen(Qt::white));
  ui->widget->yAxis->setTickPen(QPen(Qt::white));
  ui->widget->yAxis->setSubTickPen(QPen(Qt::white));
  ui->widget->yAxis->grid()->setSubGridVisible(true);
  ui->widget->yAxis->setTickLabelColor(Qt::white);
  ui->widget->yAxis->setLabelColor(Qt::white);
  ui->widget->yAxis->grid()->setPen(
      QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
  ui->widget->yAxis->grid()->setSubGridPen(
      QPen(QColor(130, 130, 130), 0, Qt::DotLine));

  // Add data:
  QVector<double> HeapsortData, JsortData;
  for (int i = 0; i < sizev; i++) {
    HeapsortData << ResultTimesHeapsort[i];
    JsortData << ResultTimesJsort[i];
  }

  Jsort->setData(ticks, JsortData);
  Heapsort->setData(ticks, HeapsortData);
  // setup legend:
  ui->widget->legend->setVisible(true);
  ui->widget->axisRect()->insetLayout()->setInsetAlignment(
      0, Qt::AlignTop | Qt::AlignHCenter);
  ui->widget->legend->setBrush(QColor(255, 255, 255, 100));
  ui->widget->legend->setBorderPen(Qt::NoPen);
  QFont legendFont = font();
  legendFont.setPointSize(10);
  ui->widget->legend->setFont(legendFont);
  ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
};
///////////////////////////////////////////////////////////////////////////////////////
void Gistograms::set_gisteqwl(int *ResultEqlHeapsort, int *ResultEqlJsort,
                              std::vector<std::string> &mynames, int sizev) {
  // set dark background gradient:
  QLinearGradient gradient(0, 0, 0, 400);
  gradient.setColorAt(0, QColor(90, 90, 90));
  gradient.setColorAt(0.38, QColor(105, 105, 105));
  gradient.setColorAt(1, QColor(70, 70, 70));
  ui->widgetone->setBackground(QBrush(gradient));

  // create empty bar chart objects:

  QCPBarsGroup *group = new QCPBarsGroup(ui->widgetone);
  QCPBars *Heapsort = new QCPBars(ui->widgetone->xAxis, ui->widgetone->yAxis);
  QCPBars *Jsort = new QCPBars(ui->widgetone->xAxis, ui->widgetone->yAxis);

  Heapsort->setAntialiased(false);  // gives more crisp, pixel aligned bar
  // borders
  Jsort->setAntialiased(false);

  Heapsort->setStackingGap(1);
  Jsort->setStackingGap(1);

  Heapsort->setBarsGroup(group);
  Jsort->setBarsGroup(group);
  // set names and colors:

  Jsort->setName("Jsort");
  Jsort->setPen(QPen(QColor(250, 170, 20).lighter(150)));
  Jsort->setBrush(QColor(250, 170, 20));
  Jsort->setWidth(0.4);
  Heapsort->setName("Heapsort");
  Heapsort->setPen(QPen(QColor(0, 168, 140).lighter(130)));
  Heapsort->setBrush(QColor(0, 168, 140));
  Heapsort->setWidth(0.4);
  // stack bars on top of each other:

  // prepare x axis with country labels:
  QVector<double> ticks;
  QVector<QString> labels;

  for (int i = 0; i < sizev; i++) {
    ticks << i * 2 + 1;
    labels << mynames.at(i).c_str();
  }

  QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
  textTicker->addTicks(ticks, labels);
  ui->widgetone->xAxis->setTicker(textTicker);
  ui->widgetone->xAxis->setTickLabelRotation(60);
  ui->widgetone->xAxis->setSubTicks(false);
  ui->widgetone->xAxis->setTickLength(0, 4);
  ui->widgetone->xAxis->setRange(0, 8);
  ui->widgetone->xAxis->setBasePen(QPen(Qt::white));
  ui->widgetone->xAxis->setTickPen(QPen(Qt::white));
  ui->widgetone->xAxis->grid()->setVisible(true);
  ui->widgetone->xAxis->grid()->setPen(
      QPen(QColor(130, 130, 130), 0, Qt::DotLine));
  ui->widgetone->xAxis->setTickLabelColor(Qt::white);
  ui->widgetone->xAxis->setLabelColor(Qt::white);

  // prepare y axis:
  //определяем наибольшие результативные данные чтобы построить длину ординаты
  int max_y = ResultEqlHeapsort[0];
  for (int i = 0; i < sizev; i++) {
    if (ResultEqlHeapsort[i] > max_y) {
      max_y = ResultEqlJsort[i];
    }
    if (ResultEqlJsort[i] > max_y) {
      max_y = ResultEqlJsort[i];
    }
  }

  ui->widgetone->yAxis->setRange(0, max_y);  // 10 минут в миллисекундах
  ui->widgetone->yAxis->setPadding(1);  // a bit more space to the left
                                        // border
  ui->widgetone->yAxis->setLabel("Сравнения");
  ui->widgetone->yAxis->setBasePen(QPen(Qt::white));
  ui->widgetone->yAxis->setTickPen(QPen(Qt::white));
  ui->widgetone->yAxis->setSubTickPen(QPen(Qt::white));
  ui->widgetone->yAxis->grid()->setSubGridVisible(true);
  ui->widgetone->yAxis->setTickLabelColor(Qt::white);
  ui->widgetone->yAxis->setLabelColor(Qt::white);
  ui->widgetone->yAxis->grid()->setPen(
      QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
  ui->widgetone->yAxis->grid()->setSubGridPen(
      QPen(QColor(130, 130, 130), 0, Qt::DotLine));

  // Add data:
  QVector<double> HeapsortData, JsortData;
  for (int i = 0; i < sizev; i++) {
    HeapsortData << ResultEqlHeapsort[i];
    JsortData << ResultEqlJsort[i];
  }

  Jsort->setData(ticks, JsortData);
  Heapsort->setData(ticks, HeapsortData);
  // setup legend:
  ui->widgetone->legend->setVisible(true);
  ui->widgetone->axisRect()->insetLayout()->setInsetAlignment(
      0, Qt::AlignTop | Qt::AlignHCenter);
  ui->widgetone->legend->setBrush(QColor(255, 255, 255, 100));
  ui->widgetone->legend->setBorderPen(Qt::NoPen);
  QFont legendFont = font();
  legendFont.setPointSize(10);
  ui->widgetone->legend->setFont(legendFont);
  ui->widgetone->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
};

void Gistograms::set_gistswp(int *ResultSwpHeapsort, int *ResultSwpJsort,
                             std::vector<std::string> &mynames, int sizev) {
  // set dark background gradient:
  QLinearGradient gradient(0, 0, 0, 400);
  gradient.setColorAt(0, QColor(90, 90, 90));
  gradient.setColorAt(0.38, QColor(105, 105, 105));
  gradient.setColorAt(1, QColor(70, 70, 70));
  ui->widgettwo->setBackground(QBrush(gradient));

  // create empty bar chart objects:

  QCPBarsGroup *group = new QCPBarsGroup(ui->widgettwo);
  QCPBars *Heapsort = new QCPBars(ui->widgettwo->xAxis, ui->widgettwo->yAxis);
  QCPBars *Jsort = new QCPBars(ui->widgettwo->xAxis, ui->widgettwo->yAxis);

  Heapsort->setAntialiased(false);  // gives more crisp, pixel aligned bar
  // borders
  Jsort->setAntialiased(false);

  Heapsort->setStackingGap(1);
  Jsort->setStackingGap(1);

  Heapsort->setBarsGroup(group);
  Jsort->setBarsGroup(group);
  // set names and colors:

  Jsort->setName("Jsort");
  Jsort->setPen(QPen(QColor(250, 170, 20).lighter(150)));
  Jsort->setBrush(QColor(250, 170, 20));
  Jsort->setWidth(0.4);
  Heapsort->setName("Heapsort");
  Heapsort->setPen(QPen(QColor(0, 168, 140).lighter(130)));
  Heapsort->setBrush(QColor(0, 168, 140));
  Heapsort->setWidth(0.4);
  // stack bars on top of each other:

  // prepare x axis with country labels:
  QVector<double> ticks;
  QVector<QString> labels;

  for (int i = 0; i < sizev; i++) {
    ticks << i * 2 + 1;
    labels << mynames.at(i).c_str();
  }

  QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
  textTicker->addTicks(ticks, labels);
  ui->widgettwo->xAxis->setTicker(textTicker);
  ui->widgettwo->xAxis->setTickLabelRotation(60);
  ui->widgettwo->xAxis->setSubTicks(false);
  ui->widgettwo->xAxis->setTickLength(0, 4);
  ui->widgettwo->xAxis->setRange(0, 8);
  ui->widgettwo->xAxis->setBasePen(QPen(Qt::white));
  ui->widgettwo->xAxis->setTickPen(QPen(Qt::white));
  ui->widgettwo->xAxis->grid()->setVisible(true);
  ui->widgettwo->xAxis->grid()->setPen(
      QPen(QColor(130, 130, 130), 0, Qt::DotLine));
  ui->widgettwo->xAxis->setTickLabelColor(Qt::white);
  ui->widgettwo->xAxis->setLabelColor(Qt::white);

  // prepare y axis:
  //определяем наибольшие результативные данные чтобы построить длину ординаты
  double max_y = ResultSwpHeapsort[0];
  for (int i = 0; i < sizev; i++) {
    if (ResultSwpHeapsort[i] > max_y) {
      max_y = ResultSwpJsort[i];
    }
    if (ResultSwpJsort[i] > max_y) {
      max_y = ResultSwpJsort[i];
    }
  }

  ui->widgettwo->yAxis->setRange(0, max_y);  // 10 минут в миллисекундах
  ui->widgettwo->yAxis->setPadding(1);  // a bit more space to the left
                                        // border
  ui->widgettwo->yAxis->setLabel("Обмены");
  ui->widgettwo->yAxis->setBasePen(QPen(Qt::white));
  ui->widgettwo->yAxis->setTickPen(QPen(Qt::white));
  ui->widgettwo->yAxis->setSubTickPen(QPen(Qt::white));
  ui->widgettwo->yAxis->grid()->setSubGridVisible(true);
  ui->widgettwo->yAxis->setTickLabelColor(Qt::white);
  ui->widgettwo->yAxis->setLabelColor(Qt::white);
  ui->widgettwo->yAxis->grid()->setPen(
      QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
  ui->widgettwo->yAxis->grid()->setSubGridPen(
      QPen(QColor(130, 130, 130), 0, Qt::DotLine));

  // Add data:
  QVector<double> HeapsortData, JsortData;
  for (int i = 0; i < sizev; i++) {
    HeapsortData << ResultSwpHeapsort[i];
    JsortData << ResultSwpJsort[i];
  }

  Jsort->setData(ticks, JsortData);
  Heapsort->setData(ticks, HeapsortData);
  // setup legend:
  ui->widgettwo->legend->setVisible(true);
  ui->widgettwo->axisRect()->insetLayout()->setInsetAlignment(
      0, Qt::AlignTop | Qt::AlignHCenter);
  ui->widgettwo->legend->setBrush(QColor(255, 255, 255, 100));
  ui->widgettwo->legend->setBorderPen(Qt::NoPen);
  QFont legendFont = font();
  legendFont.setPointSize(10);
  ui->widgettwo->legend->setFont(legendFont);
  ui->widgettwo->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
};

void Gistograms::on_pushButton_clicked() {
  ui->widget->show();
  ui->widgetone->hide();
  ui->widgettwo->hide();
}

void Gistograms::on_pushButton_2_clicked() {
  ui->widgetone->show();
  ui->widget->hide();
  ui->widgettwo->hide();
}

void Gistograms::on_pushButton_3_clicked() {
  ui->widgettwo->show();
  ui->widgetone->hide();
  ui->widget->hide();
}

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "stopwatch.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    stopwatch = new StopWatch(this);
    ui->setupUi(this);

    ui->pb_startStop->setCheckable(true);
    ui->pb_startStop->setText("CTAPT");
    ui->pb_circle->setText("КРУГ");
    ui->pb_clear->setText("ОЧИСТИТЬ");
    ui->pb_circle->setEnabled(false);

    connect(stopwatch, &StopWatch::sig_updateTime, this, &MainWindow::rcv_updateTime);
    connect(this, &MainWindow::sig_circleTime, stopwatch, &StopWatch::rcv_circleTime);
    connect(this, &MainWindow::sig_clearTime, stopwatch, &StopWatch::rcv_clearTime);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::rcv_updateTime(QString text)
{
    ui->l_time->setText(text);
}

void MainWindow::on_pb_startStop_clicked()
{
    if(ui->pb_startStop->isChecked()) {

        stopwatch->startTimer();
        ui->pb_startStop->setText("CTOП");
        ui->pb_circle->setEnabled(true);
    }
    else
    {
        stopwatch->stopTimer();
        ui->pb_startStop->setText("CTAPT");
        ui->pb_circle->setEnabled(false);
    }
}

void MainWindow::on_pb_circle_clicked()
{
    emit sig_circleTime();
    QString text = stopwatch->strCircleTime;
    ui->tB_cirkles->append(text);
}

void MainWindow::on_pb_clear_clicked()
{
    ui->l_time->setText("00:00.0");
    emit sig_clearTime();
}

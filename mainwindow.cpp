#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "worker.h"
#include <QTime>
#include <QThread>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startFlag = 0;
    lapCounter = 0;
    Worker *lobWorker = new Worker;
    lobWorker->moveToThread(&workerThread);
    connect(lobWorker,SIGNAL(resultReady(QString)),this,SLOT(workerFinish(QString)));
    connect(this,SIGNAL(startChrono()),lobWorker,SLOT(launchChrono()));
    connect(this, SIGNAL(resetChrono()), lobWorker, SLOT(resetChrono()));
    connect(&workerThread, SIGNAL (finished()), &workerThread, SLOT (deleteLater()));
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    workerThread.start();
    this->statusBar()->showMessage(tr("www.gtronick.com"));
}

MainWindow::~MainWindow()
{
    workerThread.quit();
    workerThread.wait();
    delete ui;
}

void MainWindow::on_startButton_clicked()
{

    if(startFlag == 0){
        ui->startButton->setIcon(QIcon(":/img/img/Stop.png"));
        ui->startButton->setText("Stop");
        emit(startChrono());
        startFlag = 1;
        stopFlag = 1;
    }else{
        ui->startButton->setIcon(QIcon(":/img/img/Go.png"));
        ui->startButton->setText("Start");
        startFlag = 0;
        stopFlag = 0;
    }
}

void MainWindow::on_resetButton_clicked()
{
    ui->gobLCD->setText("00:00:00");
    emit(resetChrono());
}

void MainWindow::on_flagButton_clicked()
{
    lapCounter ++;
    ui->gobLapTextArea->appendPlainText(QString("%1) %2 ").arg(lapCounter).arg(ui->gobLCD->text()));
}

void MainWindow::workerFinish(QString data)
{
    ui->gobLCD->setText(data);
    if(startFlag == 1)emit(startChrono());
}

void MainWindow::on_clearLapsButton_clicked()
{
    ui->gobLapTextArea->clear();
    lapCounter = 0;
}

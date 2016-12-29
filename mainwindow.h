#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QThread workerThread;
public:
    bool eventFilter(QObject *obj, QEvent *event);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_startButton_clicked();

    void on_resetButton_clicked();

    void on_flagButton_clicked();

    void workerFinish(QString data);

    void on_clearLapsButton_clicked();

    void on_closeWindowButton_clicked();

    void on_restoreWindowButton_clicked();

    void on_restoreWindowButton_2_clicked();

signals:
    void startChrono();
    void resetChrono();
    void killChronoThread();

private:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
    Ui::MainWindow *ui;
    int startFlag;
    int stopFlag;
    int lapCounter;
};

#endif // MAINWINDOW_H

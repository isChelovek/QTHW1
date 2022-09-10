#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
   void setKoef(float newValue1, float newValue2, float newValue3);

private slots:
    void on_getReesult_clicked();
    void getResult(int r, float r1, float r2);


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

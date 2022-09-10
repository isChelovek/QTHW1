#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "quadratic_equation.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    quadratic_equation *qua = new quadratic_equation();
    ui->setupUi(this);
    connect(this, &MainWindow::setKoef,            qua,  &quadratic_equation::setKoef);
    connect(qua,  &quadratic_equation::sendAnswer, this, &MainWindow::getResult);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_getReesult_clicked()
{
    emit setKoef(ui->koefA->text().toFloat(), ui->koefB->text().toFloat(), ui->koefC->text().toFloat());
}

void MainWindow::getResult(int numRoots, float root1, float root2)
{
    switch(numRoots)
    {
    case 0:
        ui->answer->setText("У уровнения нет корней");
        break;
    case 1:
        ui->answer->setText("Уровнение имеет один корень: X = " +  QString::number(root1));
        break;
    case 2:
        ui->answer->setText("Уровнение имеет два корня: \n X1 = " +  QString::number(root1)
                            + "\n X2 = " + QString::number(root2));
        break;
    default:
        break;
    }
}

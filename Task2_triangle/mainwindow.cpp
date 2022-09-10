#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>
#include <QIntValidator>
#include <QRegExpValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->side1->setAlignment(Qt::AlignRight);
    ui->side2->setAlignment(Qt::AlignRight);
    ui->answe->setAlignment(Qt::AlignCenter);
    ui->corner->setAlignment(Qt::AlignRight);
    ui->side1->setValidator(new QRegExpValidator(QRegExp("[0-9.]*")));
    ui->side2->setValidator(new QRegExpValidator(QRegExp("[0-9.]*")));
    ui->corner->setValidator(new QRegExpValidator(QRegExp("[0-9.]*")));
    ui->radioButton_degrees->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    float corner;

    if (ui->radioButton_radians->isChecked()){
        corner = qDegreesToRadians(ui->corner->text().toFloat());
    }
    else{
        corner = ui->corner->text().toFloat();
    }

    float side1 = ui->side1->text().toFloat();
    float side2 = ui->side1->text().toFloat();
    float a = qSqrt(qPow(side1, 2) + qPow(side1, 2) - 2 * side1 * side2 * qCos(corner));
    ui->answe->setText(QString::number(a));
}


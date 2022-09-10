#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_copyText1toText2_clicked()
{
    ui->plainTextEdit_2->setPlainText(ui->plainTextEdit->toPlainText());
}


void MainWindow::on_copyText2toText1_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit_2->toPlainText());
}


void MainWindow::on_addHTML_clicked()
{
    ui->plainTextEdit->clear();
    ui->plainTextEdit->appendHtml(QString("<font color='red'>Hello</font>"));
}


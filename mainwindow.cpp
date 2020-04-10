#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*Подключение к кнопка индивидуальных слотов*/
    connect(ui->btn_1,SIGNAL(clicked()),this,SLOT(slotButton1()));
    connect(ui->btn_2,SIGNAL(clicked()),this,SLOT(slotButton2()));
    connect(ui->btn_3,SIGNAL(clicked()),this,SLOT(slotButton3()));
    /*Подключение передачи номера к слоту вывода сообщения*/
    connect(this,&MainWindow::signalFromButton,this,&MainWindow::slotMessage);
}

MainWindow::~MainWindow()
{
    delete ui;
}
	/*Обработка слотов*/
void MainWindow::slotButton1()
{
    emit signalFromButton(1);
}

void MainWindow::slotButton2()
{
    emit signalFromButton(2);
}

void MainWindow::slotButton3()
{
    emit signalFromButton(3);
}

void MainWindow::slotMessage(int buttonId)
{
    QMessageBox::information(this,"Уведомление о нажатой кнопке","Нажатая кнопка под номером : " + QString::number(buttonId));
}

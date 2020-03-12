#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QThread>

#include <QFuture>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    index = 0;
    m_pBtn = new QPushButton("Click me",this);
    m_pBtn->setGeometry(100,100,220,70);
    connect(m_pBtn,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onBtnClicked()
{
#if 1
    //调用外部函数
    QFuture<void> f1 =QtConcurrent::run(func,QString(index++));
    //调用类成员函数
    QFuture<void> f2 =QtConcurrent::run(this,&MainWindow::myFunc,QString("aaa"));
#else  //使用Lambda函数实现
    QFuture < void > future =  QtConcurrent::run([=](){
        qDebug() << __FUNCTION__  << QThread::currentThreadId() << QThread::currentThread();
    });
    QFuture < void > future2 = QtConcurrent::run([=](){
        qDebug() << __FUNCTION__  << QThread::currentThreadId() << QThread::currentThread();
    });
#endif

}


void MainWindow::myFunc(const QString & str)
{
    qDebug() << __FUNCTION__ << str << QThread::currentThreadId() << QThread::currentThread();
}

void func(QString str)
{
    qDebug() << __FUNCTION__ << str << QThread::currentThreadId() << QThread::currentThread();
}



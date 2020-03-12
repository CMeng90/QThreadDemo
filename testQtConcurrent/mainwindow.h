#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QtConcurrent>
QT_BEGIN_NAMESPACE

extern void func(QString str);
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void onBtnClicked();
    void myFunc(const QString & str);

private:
    Ui::MainWindow *ui;
    QPushButton *m_pBtn;
    int index;
};
#endif // MAINWINDOW_H

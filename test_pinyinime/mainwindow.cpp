#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <pinyinime.h>
#include <QFileInfo>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFileInfo info("./dict_pinyin.dat");
    qDebug() << info.size();

    if (!ime_pinyin::im_open_decoder("./dict_pinyin.dat",
                                     "./user_dict.dat")) {
        qDebug("%s[%d] open pinyin dictionary failed", __func__, __LINE__);
        return;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    size_t qty = ime_pinyin::im_search(arg1.toUtf8().data(), arg1.size());
    ime_pinyin::char16 buf[256] = {0};
    QString msg;
    for (size_t i = 0; i < 100; ++i) {
        ime_pinyin::im_get_candidate(i, buf, 255);
        msg.append(QString::fromUtf16(buf)+" ");
    }
    ui->textBrowser->setText(msg);
}

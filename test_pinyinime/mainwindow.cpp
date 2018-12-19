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

    ime_pinyin::im_set_max_lens(1, 36);
    size_t qty = ime_pinyin::im_search("zgr", 3);
    ime_pinyin::char16 buf[256] = {0};

    qDebug("%s[%d] qty(%d)", __func__, __LINE__, qty);
    for (int i = 0; i < qty; ++i) {
        ime_pinyin::im_get_candidate(i, buf, 255);

        qDebug() << QString::fromUtf16(buf);
    }

    qDebug() << buf;

}

MainWindow::~MainWindow()
{
    delete ui;
}

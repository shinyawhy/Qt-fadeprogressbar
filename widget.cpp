#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QVBoxLayout * vb = new QVBoxLayout(this);
        myProgressBar * bar = new myProgressBar(this);
        QSlider * slider = new QSlider(Qt::Horizontal,this);
        slider->setRange(0,100);
        bar->setRange(0,100);
        vb->setContentsMargins(20,20,20,20);
        vb->addWidget(bar);
        vb->addStretch();
        vb->addWidget(slider);
        connect(slider,&QSlider::valueChanged,bar,&QProgressBar::setValue);

}

Widget::~Widget()
{
    delete ui;
}


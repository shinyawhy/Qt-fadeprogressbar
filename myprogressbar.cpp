#include "myprogressbar.h"
#include <QPainter>
#include <QStyleOptionProgressBar>
#include <QStylePainter>
#include <QPaintEvent>

myProgressBar::myProgressBar(QWidget *parent):QProgressBar(parent)
{
    setMinimumSize(180, 150);
    setAlignment(Qt::AlignCenter);
}

void myProgressBar::paintEvent(QPaintEvent *event)
{
    QStylePainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QStyleOptionProgressBar option;

    initStyleOption(&option);

    QStyleOptionProgressBar opt1 =option;
    opt1.rect = this->style()->subElementRect(QStyle::SE_ProgressBarContents, &opt1, this);

    QStyleOptionProgressBar opt2 = option;

    QRect rect = QRect(opt1.rect.topLeft().x(),
                       opt1.rect.topLeft().y(),
                       opt1.rect.width() * opt1.progress / opt1.maximum,
                       opt1.rect.height());

   auto eventRect = event->rect();
   QLinearGradient linearGradient(eventRect.topLeft(), eventRect.topRight());
   linearGradient.setColorAt(0.0, Qt::red);
   linearGradient.setColorAt(0.3, Qt::cyan);
   linearGradient.setColorAt(0.7, Qt::green);
   linearGradient.setColorAt(1.0, Qt::blue);

   painter.fillRect(rect, linearGradient);

   if(option.textVisible)
   {
       opt2.rect = this->style()->subElementRect(QStyle::SE_ProgressBarLabel, &opt2, this);
       painter.setPen(Qt::red);
       painter.drawControl(QStyle::CE_ProgressBarLabel, opt2);
   }

}

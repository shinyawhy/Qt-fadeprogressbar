#ifndef MYPROGRESSBAR_H
#define MYPROGRESSBAR_H

#include <QProgressBar>

class myProgressBar : public QProgressBar
{
public:
    myProgressBar(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // MYPROGRESSBAR_H

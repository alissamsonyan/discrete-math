#include "mainwindow.h"


MainWindow::MainWindow(int n, int m)
{
    wid = new QWidget();
    this->n = n;
    this->m = m;
}

MainWindow::~MainWindow()
{
}

void MainWindow::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);
    QPainter qp(this);
    graphh(&qp);
}

void MainWindow::graphh(QPainter *qp) const
{
    int l = 0, z;
    bool t = false;
    if(m%2==0&&n%2==0) t=true;

    for (int i = 0; i < n; i++)
    {

        z = 50;

        for (int j = 0; j < m; j++)
        {

            QPen pen(Qt::black);
            qp->setPen(pen);
            qp->drawEllipse(100 + z, 100 + l, 20, 20);

            if (j < (m - 1))
            {
                QPen pen;
                if ((j == m - 2 || i == n - 1) && t == true) {
                     pen.setColor(Qt::blue);
                }
                else {
                    pen.setColor(Qt::red);
                   }
                qp->setPen(pen);
                qp->drawLine(130 + z, 110 + l, 140 + z, 110 + l);
            }

            if (i < (n - 1))
            {
                QPen pen;
                if ((j == m - 1 || i == n - 2) && t == true)
                {
                    if (i == n - 2 && j == m - 2)
                    {
                       pen.setColor(Qt::blue);
                    }
                    else
                    {
                       pen.setColor(Qt::blue);
                    }
                }
                else
                {
                    pen.setColor(Qt::green);
                }
                qp->setPen(pen);
                qp->drawLine(110 + z, 130 + l, 110 + z, 140 + l);
            }
            z += 50;
        }
        l += 50;
    }
}

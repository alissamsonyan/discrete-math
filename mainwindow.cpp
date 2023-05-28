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
    int i, l = 0, z, o = 11, v = 5, b;
    bool t = false;

    for (i = 0; i < n; i++)
    {

        z = 0;
        b = 1;

        for (int j = 0; j < m; j++)
        {
            if (i == n - 1 && j == m - 2) o--;
            if (j % 2 == 0) b++;

            QPen pen(Qt::black);
            qp->setPen(pen);
            qp->drawEllipse(100 + z, 100 + l, 20, 20);

            if (j < (m - 1))
            {
                QPen pen;
                if ((j == m - 2 || i == n - 1) && t == true) {
                     pen.setColor(Qt::green);
                } else {
                    pen.setColor(Qt::red);
                   }
                qp->setPen(pen);
                qp->drawLine(120 + z, 100 + l, 130 + z, 100 + l);
            }

            if (i < (n - 1))
            {
                QPen pen;
                if ((j == m - 1 || i == n - 2) && t == true)
                {
                    if (i == n - 2 && j == m - 2)
                    {
                       pen.setColor(Qt::red);
                    }
                    else
                    {
                       pen.setColor(Qt::green);
                    }
                }
                else
                {
                    pen.setColor(Qt::green);
                }
                qp->setPen(pen);
                qp->drawLine(100 + z, 120 + l, 100 + z, 130 + l);
            }
            z += 50;

        }
        l += 50;
    }
}

#include "mainwindow.h"
#include <QPainter>
MainWindow::MainWindow(int n, int m)
{
    wid=new QWidget();
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
    QPen pen(Qt::SolidLine);
    qp->setPen(pen);
    int i, l = 0, z, o = 11, v = 5, b; bool t = false;

    if (n % 2 == 0 && m % 2 == 0) { t = true; }
    for (i = 0; i < n; i++)
    {
        if (i == n - 2) o = o + m - 2;
        if (i == n - 1) o = o + m;
        if (i % 2 == 0) v++;
        z = 0; b = 1;
        for (int j = 0; j < m; j++)
        {
            if (i == n - 1 && j == m - 2) o--;
            if (j % 2 == 0) b++;
            pen.setColor(QColor(0, 0, 0));
            qp->drawEllipse(100 + z, 100 + l, 20,20);
            if (j < (m - 1))
            {
                if ((j == m - 2 || i == n - 1) && t == true) pen.setColor(QColor(120, 0, 0));
                else
                    pen.setColor(QColor(121, 0, 0));
                qp->drawLine(120 + z, 100 + l, 130 + z, 100 + l);
            }
            if (i < (n - 1))
            {
                if ((j == m - 1 || i == n - 2) && t == true)
                    if (i == n - 2 && j == m - 2) { o--; pen.setColor(QColor(122, 0, 0)); o += 2; }
                    else
                        pen.setColor(QColor(122, 0, 0));
                else pen.setColor(QColor(120, 0, 0));
                qp->drawLine(100 + z, 120 + l, 100 + z, 130 + l);
            }
            z += 50;
            if (i >= n - 2) o--;
        }
        l += 50; o--;
    }
}



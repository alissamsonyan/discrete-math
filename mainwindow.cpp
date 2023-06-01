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
    int l = 80, z;
    bool t = false;

    double v=0.0;

    if (m % 2 == 0 && n % 2 == 0)
        t = true;

    for (int i = 0; i < n; i++)
    {
        double k = 0.0;
        z = 80;

        for (int j = 0; j < m; j++)
        {
            QPen pen(Qt::black);
            qp->setPen(pen);
            qp->drawEllipse(z, l, 20, 20);

            // Horizontal lines
            if (j < (m - 1))
            {
                QPen pen;
                // zuygg
                if ((j == m - 2 || i == n - 1) && t == true) {
                    if (static_cast<int>(k) % 2 == 0.0)
                        pen.setColor(Qt::black);
                    else
                        pen.setColor(Qt::black);
                }
                // kent
                else {
                    if ((static_cast<int>(k) % 2 == 0.0 ) )

                            pen.setColor(Qt::red);
                    else if ((static_cast<int>(k) % 2 != 0.0 ) )

                        pen.setColor(Qt::cyan);
                }
                qp->setPen(pen);
                qp->drawLine(30 + z, 10 + l, 40 + z, 10 + l);
            }

            // Vertical lines
            if (i < (n - 1))
            {
                QPen pen;
                //zuyg
                if ((j == m - 1 || i == n - 2) && t == true)
                    if (static_cast<int>(v) % 2 == 0)   pen.setColor(Qt::black);
                    else pen.setColor(Qt::black);
                //kent
                else
                {
                    if (static_cast<int>(v) % 2 == 0)
                        pen.setColor(Qt::green);
                    else pen.setColor(Qt::magenta);

                }
                qp->setPen(pen);
                qp->drawLine(10 + z, 30 + l, 10 + z, 40 + l);
            }

            z += 50;
            k += 0.5;

        }

        v+=0.5;
        l += 50;
    }

}

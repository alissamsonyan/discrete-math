#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    int m, n;
  bool ok;
 m = QInputDialog::getInt(nullptr, "Enter Value", "Enter the value of m:", 1, 1, 100, 1, &ok);
  if (!ok) return 0;
 n = QInputDialog::getInt(nullptr, "Enter Value", "Enter the value of n:", 1, 1, 100, 1, &ok);
  if (!ok) return 0;
    if ((n % 2 == 0 && m % 2 != 0) || (n % 2 != 0 && m % 2 == 0) || (n == 1 && m == 1) || n <= 0 || m <= 0)
    {
        QMessageBox::critical(nullptr, "Error", "Can't cover");
        return 0;
    }
    else
    {
        MainWindow w(m, n);
        w.show();
        return a.exec();
    }

    return 0;
}

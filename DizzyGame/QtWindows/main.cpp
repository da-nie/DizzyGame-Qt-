#include "cmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
 //��� ������ ��� ������������� Qt ��������� ����� �������������
 QStringList paths=QCoreApplication::libraryPaths();
 paths.append(".");
 paths.append("platforms");

 QApplication a(argc,argv);
 CMainWindow w;
 w.show();
 return(a.exec());
}

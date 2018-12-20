#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include <QFile>
#include <QDataStream>


void save(QString path, QList<int> list) {

    QFile file(path);
    if(!file.open(QIODevice::WriteOnly)) {
        qFatal("Could not write to the file!");
    }

    QDataStream stream(&file);
    stream << list;
    file.close();
}

QList<int> load(QString path) {
    QList<int> list;

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)) {
        qFatal("Could not write to the file!");
    }

    QDataStream stream(&file);
    stream >> list;
    file.close();

    return list;

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path = "test.txt";
    QList<int> list;
    list << 1 << 2 << 3 << 4;

    save(path,list);

    QList<int> data = load(path);
    qInfo() << data;

    return a.exec();
}

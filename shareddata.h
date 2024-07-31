#ifndef SHAREDDATA_H
#define SHAREDDATA_H

#include <QObject>

class SharedData
{
public:
    static QVector<QString> Split(QString str, QString splitBy, int splitCount = -1);
};

#endif // SHAREDDATA_H

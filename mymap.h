#ifndef MYMAP_H
#define MYMAP_H

#include <map>
#include <QString>

class MyMap
{
public:
    MyMap();

    // Métodos para agregar y consultar elementos
    void insert(const QString &key, const QString &value);
    QString getValue(const QString &key) const;

private:
    std::map<QString, QString> dataMap;
};

#endif // MYMAP_H



#include "MyMap.h"
#include <QString>
MyMap::MyMap()
{
    // Constructor, si es necesario
}

void MyMap::insert(const QString &key, const QString &value)
{
    // Insertar un par clave-valor en el mapa
    dataMap[key] = value;
}

QString MyMap::getValue(const QString &key) const
{
    // Obtener el valor asociado con la clave
    auto it = dataMap.find(key);
    if (it != dataMap.end()) {
        return it->second;
    } else {
        // Devolver una cadena vacía si la clave no está presente
        return QString();
    }
}


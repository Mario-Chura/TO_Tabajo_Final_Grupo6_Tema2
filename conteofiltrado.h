#ifndef CONTEO_FILTRADO_H
#define CONTEO_FILTRADO_H

#include <map>
#include <iostream>
#include <vector>
#include "PacienteData.h"
#include <QTextDocument>
#include <QPdfWriter>
#include <QFile>
#include <QTextStream>
#include <QPainter>
#include <QMessageBox>


class ConteoFiltrado {
public:
    static void realizarConteo(const std::vector<PacienteData>& dataVector);
};

#endif // CONTEO_FILTRADO_H

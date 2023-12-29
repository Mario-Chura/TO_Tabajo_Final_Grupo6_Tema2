// DataHolder.h
#ifndef DATAHOLDER_H
#define DATAHOLDER_H

#include "AVLTree.h"
#include <vector>
#include "Registro.h"
#include <QString>


class DataHolder {
public:
    static DataHolder& instance() {
        static DataHolder instance;
        return instance;
    }

    AVLTree* getTree() const {
        return tree;
    }

    void setTree(AVLTree* newTree) {
        tree = newTree;
    }

    // Agregar getter y setter para DEPARTAMENTO_MUESTRAS
    const std::vector<std::vector<Registro*>>& getDepartamentoMuestras() const {
        return DEPARTAMENTO_MUESTRAS;
    }

    void setDepartamentoMuestras(const std::vector<std::vector<Registro*>>& newDepartamentoMuestras) {
        DEPARTAMENTO_MUESTRAS = newDepartamentoMuestras;
    }

    // Agregar getter y setter para TIPO_MUESTRAS
    const std::vector<std::vector<Registro*>>& getTipoMuestras() const {
        return TIPO_MUESTRAS;
    }

    void setTipoMuestras(const std::vector<std::vector<Registro*>>& newTipoMuestras) {
        TIPO_MUESTRAS = newTipoMuestras;
    }

    // Agregar getter y setter para resultados
    const std::vector<std::vector<Registro*>>& getresultados() const {
        return resultados;
    }

    void setresultados(const std::vector<std::vector<Registro*>>& newresultados) {
        resultados = newresultados;
    }

    const QString& getNombreArchivo() const {
        return nombreArchivo;
    }

    void setNombreArchivo(const QString& newNombreArchivo) {
        nombreArchivo = newNombreArchivo;
    }

private:
    DataHolder() {}
    AVLTree* tree = nullptr;
    std::vector<std::vector<Registro*>> DEPARTAMENTO_MUESTRAS;
    std::vector<std::vector<Registro*>> TIPO_MUESTRAS;
    std::vector<std::vector<Registro*>> resultados;
    QString nombreArchivo;
};

#endif // DATAHOLDER_H


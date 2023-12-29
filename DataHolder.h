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

    // Agregar getter y setter para FECHAS_CORTE
    const std::vector<std::vector<Registro*>>& getFechaCorte() const {
        return FECHAS_CORTE;
    }

    void setFechaCorte(const std::vector<std::vector<Registro*>>& newFechaCorte) {
        FECHAS_CORTE = newFechaCorte;
    }


    // Agregar getter y setter para FECHAS_MUESTRAS
    const std::vector<std::vector<Registro*>>& getFechaMuestras() const {
        return FECHAS_MUESTRAS;
    }

    void setFechaMuestras(const std::vector<std::vector<Registro*>>& newFechaMuestras) {
        FECHAS_MUESTRAS = newFechaMuestras;
    }

    // Agregar getter y setter para Edades
    const std::vector<std::vector<Registro*>>& getEdades() const {
        return Edades;
    }

    void setEdades(const std::vector<std::vector<Registro*>>& newEdades) {
        Edades = newEdades;
    }

    // Agregar getter y setter para Sexos
    const std::vector<std::vector<Registro*>>& getSexos() const {
        return Sexos;
    }

    void setSexos(const std::vector<std::vector<Registro*>>& newSexos) {
        Sexos = newSexos;
    }

    // Agregar getter y setter para instituciones
    const std::vector<std::vector<Registro*>>& getinstituciones() const {
        return instituciones;
    }

    void setinstituciones(const std::vector<std::vector<Registro*>>& newinstituciones) {
        instituciones = newinstituciones;
    }


    // Agregar getter y setter para UBIGEO_PACIENTES
    const std::vector<std::vector<Registro*>>& getUBIGEO_PACIENTES() const {
        return UBIGEO_PACIENTES;
    }

    void setUBIGEO_PACIENTES(const std::vector<std::vector<Registro*>>& newUBIGEO_PACIENTES) {
        UBIGEO_PACIENTES = newUBIGEO_PACIENTES;
    }


    // Agregar getter y setter para DEPARTAMENTO_PACIENTES
    const std::vector<std::vector<Registro*>>& getDEPARTAMENTO_PACIENTES() const {
        return DEPARTAMENTO_PACIENTES;
    }

    void setDEPARTAMENTO_PACIENTES(const std::vector<std::vector<Registro*>>& newDEPARTAMENTO_PACIENTES) {
        DEPARTAMENTO_PACIENTES = newDEPARTAMENTO_PACIENTES;
    }


    // Agregar getter y setter para PROVINCIA_PACIENTES
    const std::vector<std::vector<Registro*>>& getPROVINCIA_PACIENTES() const {
        return PROVINCIA_PACIENTES;
    }

    void setPROVINCIA_PACIENTES(const std::vector<std::vector<Registro*>>& newPROVINCIA_PACIENTES) {
        PROVINCIA_PACIENTES = newPROVINCIA_PACIENTES;
    }


    // Agregar getter y setter para DISTRITO_PACIENTES
    const std::vector<std::vector<Registro*>>& getDISTRITO_PACIENTES() const {
        return DISTRITO_PACIENTES;
    }

    void setDISTRITO_PACIENTES(const std::vector<std::vector<Registro*>>& newDISTRITO_PACIENTES) {
        DISTRITO_PACIENTES = newDISTRITO_PACIENTES;
    }



    // Agregar getter y setter para DEPARTAMENTO_MUESTRAS
    const std::vector<std::vector<Registro*>>& getDepartamentoMuestras() const {
        return DEPARTAMENTO_MUESTRAS;
    }

    void setDepartamentoMuestras(const std::vector<std::vector<Registro*>>& newDepartamentoMuestras) {
        DEPARTAMENTO_MUESTRAS = newDepartamentoMuestras;
    }

    // Agregar getter y setter para PROVINCIA_MUESTRAS
    const std::vector<std::vector<Registro*>>& getProvinciaMuestras() const {
        return PROVINCIA_MUESTRAS;
    }

    void setProvinciaMuestras(const std::vector<std::vector<Registro*>>& newProvinciaMuestras) {
        DEPARTAMENTO_MUESTRAS = newProvinciaMuestras;
    }

    // Agregar getter y setter para DISTRITO_MUESTRAS
    const std::vector<std::vector<Registro*>>& getDistritoMuestras() const {
        return DISTRITO_MUESTRAS;
    }

    void setDistritoMuestras(const std::vector<std::vector<Registro*>>& newDistritoMuestras) {
        DISTRITO_MUESTRAS = newDistritoMuestras;
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
    std::vector<std::vector<Registro*>> FECHAS_CORTE;
    std::vector<std::vector<Registro*>> FECHAS_MUESTRAS;
    std::vector<std::vector<Registro*>> Edades;
    std::vector<std::vector<Registro*>> Sexos;
    std::vector<std::vector<Registro*>> instituciones;
    std::vector<std::vector<Registro*>> UBIGEO_PACIENTES;
    std::vector<std::vector<Registro*>> DEPARTAMENTO_PACIENTES;
    std::vector<std::vector<Registro*>> PROVINCIA_PACIENTES;
    std::vector<std::vector<Registro*>> DISTRITO_PACIENTES;
    std::vector<std::vector<Registro*>> DEPARTAMENTO_MUESTRAS;
    std::vector<std::vector<Registro*>> PROVINCIA_MUESTRAS;
    std::vector<std::vector<Registro*>> DISTRITO_MUESTRAS;
    std::vector<std::vector<Registro*>> TIPO_MUESTRAS;
    std::vector<std::vector<Registro*>> resultados;
    QString nombreArchivo;
};

#endif // DATAHOLDER_H


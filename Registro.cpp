#include "Registro.h"
#include <sstream>

Registro::Registro(std::string fecha_corte, int uuid, std::string fecha_muestra, int edad, std::string sexo, std::string institucion, std::string ubigeo_paciente, std::string departamento_paciente, std::string provincia_paciente, std::string distrito_paciente, std::string departamento_muestra, std::string provincia_muestra, std::string distrito_muestra, std::string tipo_muestra, std::string resultado)
    : fecha_corte(fecha_corte), uuid(uuid), fecha_muestra(fecha_muestra), edad(edad), sexo(sexo), institucion(institucion), ubigeo_paciente(ubigeo_paciente), departamento_paciente(departamento_paciente), provincia_paciente(provincia_paciente), distrito_paciente(distrito_paciente), departamento_muestra(departamento_muestra), provincia_muestra(provincia_muestra), distrito_muestra(distrito_muestra), tipo_muestra(tipo_muestra), resultado(resultado) {}

std::string Registro::getFechaCorte() {
    return fecha_corte;
}

int Registro::getUuid() {
    return uuid;
}

std::string Registro::getFechaMuestra() {
    return fecha_muestra;
}

int Registro::getEdad() {
    return edad;
}

std::string Registro::getSexo() {
    return sexo;
}

std::string Registro::getInstitucion() {
    return institucion;
}

std::string Registro::getUbigeoPaciente() {
    return ubigeo_paciente;
}

std::string Registro::getDepartamentoPaciente() {
    return departamento_paciente;
}

std::string Registro::getProvinciaPaciente() {
    return provincia_paciente;
}

std::string Registro::getDistritoPaciente() {
    return distrito_paciente;
}

std::string Registro::getDepartamentoMuestra() {
    return departamento_muestra;
}

std::string Registro::getProvinciaMuestra() {
    return provincia_muestra;
}

std::string Registro::getDistritoMuestra() {
    return distrito_muestra;
}

std::string Registro::getTipoMuestra() {
    return tipo_muestra;
}

std::string Registro::getResultado() {
    return resultado;
}

std::string Registro::toString() {
    std::ostringstream oss;
    oss << "Fecha de corte: " << fecha_corte << "\n"
        << "UUID: " << uuid << "\n"
        << "Fecha de muestra: " << fecha_muestra << "\n"
        << "Edad: " << edad << "\n"
        << "Sexo: " << sexo << "\n"
        << "Institución: " << institucion << "\n"
        << "Ubigeo del paciente: " << ubigeo_paciente << "\n"
        << "Departamento del paciente: " << departamento_paciente << "\n"
        << "Provincia del paciente: " << provincia_paciente << "\n"
        << "Distrito del paciente: " << distrito_paciente << "\n"
        << "Departamento de la muestra: " << departamento_muestra << "\n"
        << "Provincia de la muestra: " << provincia_muestra << "\n"
        << "Distrito de la muestra: " << distrito_muestra << "\n"
        << "Tipo de muestra: " << tipo_muestra << "\n"
        << "Resultado: " << resultado;
    return oss.str();
}



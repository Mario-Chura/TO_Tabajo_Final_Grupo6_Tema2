#ifndef REGISTRO_H
#define REGISTRO_H

#include <string>

class Registro {
private:
    std::string fecha_corte;
    int uuid;
    std::string fecha_muestra;
    int edad;
    std::string sexo;
    std::string institucion;
    std::string ubigeo_paciente;
    std::string departamento_paciente;
    std::string provincia_paciente;
    std::string distrito_paciente;
    std::string departamento_muestra;
    std::string provincia_muestra;
    std::string distrito_muestra;
    std::string tipo_muestra;
    std::string resultado;

public:
    Registro( std::string fecha_corte, int uuid, std::string fecha_muestra, int edad, std::string sexo, std::string institucion, std::string ubigeo_paciente, std::string departamento_paciente, std::string provincia_paciente, std::string distrito_paciente, std::string departamento_muestra, std::string provincia_muestra, std::string distrito_muestra, std::string tipo_muestra, std::string resultado);
    std::string getFechaCorte();
    int getUuid();
    std::string getFechaMuestra();
    int getEdad();
    std::string getSexo();
    std::string getInstitucion();
    std::string getUbigeoPaciente();
    std::string getDepartamentoPaciente();
    std::string getProvinciaPaciente();
    std::string getDistritoPaciente();
    std::string getDepartamentoMuestra();
    std::string getProvinciaMuestra();
    std::string getDistritoMuestra();
    std::string getTipoMuestra();
    std::string getResultado();
    std::string toString();
};

#endif // REGISTRO_H



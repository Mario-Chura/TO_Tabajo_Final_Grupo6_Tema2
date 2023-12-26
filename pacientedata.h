#ifndef PACIENTE_DATA_H
#define PACIENTE_DATA_H

#include <string>

class PacienteData {
public:
    std::string fechaCorte;
    std::string uuid;
    std::string fechaMuestra;
    int edad;
    std::string sexo;
    std::string institucion;
    std::string ubigeoPaciente;
    std::string departamentoPaciente;
    std::string provinciaPaciente;
    std::string distritoPaciente;
    std::string departamentoMuestra;
    std::string provinciaMuestra;
    std::string distritoMuestra;
    std::string tipoMuestra;
    std::string resultado;
};

#endif // PACIENTE_DATA_H

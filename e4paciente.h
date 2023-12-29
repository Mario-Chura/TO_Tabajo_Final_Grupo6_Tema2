#ifndef E4PACIENTE_H
#define E4PACIENTE_H

#include <string>

class e4paciente {
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

#endif // E4PACIENTE_H

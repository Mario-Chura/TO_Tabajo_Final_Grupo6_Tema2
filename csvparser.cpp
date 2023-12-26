#include "CsvParser.h"

std::vector<PacienteData> CsvParser::parseCsv(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<PacienteData> dataVector;

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        PacienteData paciente;

        std::getline(iss, paciente.fechaCorte, ';');
        std::getline(iss, paciente.uuid, ';');
        std::getline(iss, paciente.fechaMuestra, ';');
        iss >> paciente.edad;
        iss.ignore();
        std::getline(iss, paciente.sexo, ';');
        std::getline(iss, paciente.institucion, ';');
        std::getline(iss, paciente.ubigeoPaciente, ';');
        std::getline(iss, paciente.departamentoPaciente, ';');
        std::getline(iss, paciente.provinciaPaciente, ';');
        std::getline(iss, paciente.distritoPaciente, ';');
        std::getline(iss, paciente.departamentoMuestra, ';');
        std::getline(iss, paciente.provinciaMuestra, ';');
        std::getline(iss, paciente.distritoMuestra, ';');
        std::getline(iss, paciente.tipoMuestra, ';');
        std::getline(iss, paciente.resultado, ';');

        dataVector.push_back(paciente);
    }

    return dataVector;
}

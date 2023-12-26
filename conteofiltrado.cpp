// ConteoFiltrado.cpp
#include "ConteoFiltrado.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

void ConteoFiltrado::realizarConteo(const std::vector<PacienteData>& dataVector) {
    // Crear un archivo CSV
    QFile file("ConteoFiltrado.csv");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);

        // Escribir encabezados en el archivo CSV
        stream << "Departamento,Provincia,Sexo,Tipo Muestra,Resultado,Cantidad\n";

        std::map<std::string, std::map<std::string, std::map<std::string, std::map<std::string, std::map<std::string, int>>>>> conteoFiltrado;

        for (const auto &paciente : dataVector) {
            std::string departamento = paciente.departamentoPaciente;
            std::string provincia = paciente.provinciaPaciente;
            std::string sexo = paciente.sexo;
            std::string tipoMuestra = paciente.tipoMuestra;
            std::string resultado = paciente.resultado;

            conteoFiltrado[departamento][provincia][sexo][tipoMuestra][resultado]++;
        }

        for (const auto &depEntry : conteoFiltrado) {
            const auto &departamento = depEntry.first;
            const auto &provinciaMap = depEntry.second;

            for (const auto &provEntry : provinciaMap) {
                const auto &provincia = provEntry.first;
                const auto &sexoMap = provEntry.second;

                for (const auto &sexoEntry : sexoMap) {
                    const auto &sexo = sexoEntry.first;
                    const auto &tipoMuestraMap = sexoEntry.second;

                    for (const auto &tipoMuestraEntry : tipoMuestraMap) {
                        const auto &tipoMuestra = tipoMuestraEntry.first;
                        const auto &resultadoMap = tipoMuestraEntry.second;

                        for (const auto &resultadoEntry : resultadoMap) {
                            const auto &resultado = resultadoEntry.first;
                            int cantidad = resultadoEntry.second;

                            // Escribir datos en el archivo CSV
                            stream << QString::fromStdString(departamento) << ","
                                   << QString::fromStdString(provincia) << ","
                                   << QString::fromStdString(sexo) << ","
                                   << QString::fromStdString(tipoMuestra) << ","
                                   << QString::fromStdString(resultado) << ","
                                   << QString::number(cantidad) << "\n";
                        }
                    }
                }
            }
        }

        // Cerrar el archivo CSV
        file.close();

        QMessageBox::information(nullptr, "Generación de CSV", "El CSV se ha generado exitosamente.");
    } else {
        QMessageBox::critical(nullptr, "Error", "No se pudo abrir el archivo para escribir el CSV.");
    }
}

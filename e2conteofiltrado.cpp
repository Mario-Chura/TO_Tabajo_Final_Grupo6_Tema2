#include "e2conteofiltrado.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

std::vector<QStringList> e2conteofiltrado::realizarConteo(const std::vector<e2paciente>& dataVector) {

        std::vector<QStringList> result;  // Almacenará los datos para la tabla

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

                            // Agregar datos al resultado
                            QStringList rowData;
                            rowData << QString::fromStdString(departamento)
                                    << QString::fromStdString(provincia)
                                    << QString::fromStdString(sexo)
                                    << QString::fromStdString(tipoMuestra)
                                    << QString::fromStdString(resultado)
                                    << QString::number(cantidad);
                            result.push_back(rowData);
                        }
                    }
                }
            }
        }
        QMessageBox::information(nullptr, "Generación de CSV", "Los datos se han procesado exitosamente.");

        return result;
    }

#include "mainpage.h"
#include "ui_mainpage.h"
#include <QFileDialog>
#include "principal.h"

#include <QFileDialog>
#include "AVLTree.h"
#include "Registro.h"
#include <iostream>
#include "DataHolder.h"
#include <QDebug>
MainPage::MainPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);

}

MainPage::~MainPage()
{
    delete ui;
}

void MainPage::on_carga_clicked()
{
    QString nombreArchivo = QFileDialog::getOpenFileName(this, tr("Seleccionar archivo CSV"), "", tr("Archivos CSV (*.csv);;Todos los archivos (*.*)"));
    DataHolder::instance().setNombreArchivo(nombreArchivo);
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




    if (!nombreArchivo.isEmpty()) {
        AVLTree* tree = new AVLTree(); // Crea el árbol AVL
        DataHolder::instance().setTree(tree);


        QFile file(nombreArchivo);
        if (!file.open(QIODevice::ReadOnly)) {
            qDebug() << file.errorString();
            return;
        }

        file.readLine(); // Saltar la línea de encabezado

        int id = 1;
        while (!file.atEnd()) {
            QByteArray line = file.readLine();
            QStringList fields = QString(line).split(";");

            int uuid = (fields[1].compare("NULL", Qt::CaseInsensitive) == 0) ? -id : fields[1].toInt();
            Registro* registro = new Registro(fields[0].toStdString(), uuid, fields[2].toStdString(), fields[3].toInt(), fields[4].toStdString(), fields[5].toStdString(), fields[6].toStdString(), fields[7].toStdString(), fields[8].toStdString(), fields[9].toStdString(), fields[10].toStdString(), fields[11].toStdString(), fields[12].toStdString(), fields[13].toStdString(), fields[14].toStdString());

            tree->insert(registro);

            //====================== FECHAS_CORTE ===========================================
            // Buscar la institución en el vector de vectores
            bool FECHAS_CORTEEncontrada = false;
            for (auto& vec : FECHAS_CORTE) {
                if (!vec.empty() && vec[0]->getFechaCorte() == registro->getFechaCorte()) {
                    vec.push_back(registro);
                    FECHAS_CORTEEncontrada = true;
                    break;
                }
            }

            // Si FECHAS_CORTE no existe, crear un nuevo vector
            if (!FECHAS_CORTEEncontrada) {
                FECHAS_CORTE.push_back({registro});
            }


            //====================== FECHAS_MUESTRAS ===========================================
            // Buscar FECHAS_MUESTRAS en el vector de vectores
            bool FECHAS_MUESTRASEncontrada = false;
            for (auto& vec : FECHAS_MUESTRAS) {
                if (!vec.empty() && vec[0]->getFechaMuestra() == registro->getFechaMuestra()) {
                    vec.push_back(registro);
                    FECHAS_MUESTRASEncontrada = true;
                    break;
                }
            }

            // Si FECHAS_MUESTRAS no existe, crear un nuevo vector
            if (!FECHAS_MUESTRASEncontrada) {
                FECHAS_MUESTRAS.push_back({registro});
            }


            //====================== Edades ===========================================
            // Buscar la Edades en el vector de vectores
            bool EdadesEncontrada = false;
            for (auto& vec : Edades) {
                if (!vec.empty() && vec[0]->getEdad() == registro->getEdad()) {
                    vec.push_back(registro);
                    EdadesEncontrada = true;
                    break;
                }
            }

            // Si la Edades no existe, crear un nuevo vector
            if (!EdadesEncontrada) {
                Edades.push_back({registro});
            }


            //====================== Sexos ===========================================
            // Buscar Sexos en el vector de vectores
            bool SexosEncontrada = false;
            for (auto& vec : Sexos) {
                if (!vec.empty() && vec[0]->getSexo() == registro->getSexo()) {
                    vec.push_back(registro);
                    SexosEncontrada = true;
                    break;
                }
            }

            // Si Sexos no existe, crear un nuevo vector
            if (!SexosEncontrada) {
                Sexos.push_back({registro});
            }


            //====================== Instituciones ===========================================
            // Buscar la institución en el vector de vectores
            bool institucionEncontrada = false;
            for (auto& vec : instituciones) {
                if (!vec.empty() && vec[0]->getInstitucion() == registro->getInstitucion()) {
                    vec.push_back(registro);
                    institucionEncontrada = true;
                    break;
                }
            }

            // Si la institución no existe, crear un nuevo vector
            if (!institucionEncontrada) {
                instituciones.push_back({registro});
            }


            //====================== UBIGEO_PACIENTES ===========================================
            // Buscar UBIGEO_PACIENTES en el vector de vectores
            bool UBIGEO_PACIENTESEncontrada = false;
            for (auto& vec : UBIGEO_PACIENTES) {
                if (!vec.empty() && vec[0]->getUbigeoPaciente() == registro->getUbigeoPaciente()) {
                    vec.push_back(registro);
                    UBIGEO_PACIENTESEncontrada = true;
                    break;
                }
            }

            // Si UBIGEO_PACIENTES no existe, crear un nuevo vector
            if (!UBIGEO_PACIENTESEncontrada) {
                UBIGEO_PACIENTES.push_back({registro});
            }


            //====================== DEPARTAMENTO_PACIENTES ===========================================
            // Buscar PDEPARTAMENTO_PACIENTES en el vector de vectores
            bool DEPARTAMENTO_PACIENTESEncontrada = false;
            for (auto& vec : DEPARTAMENTO_PACIENTES) {
                if (!vec.empty() && vec[0]->getDepartamentoPaciente() == registro->getDepartamentoPaciente()) {
                    vec.push_back(registro);
                    DEPARTAMENTO_PACIENTESEncontrada = true;
                    break;
                }
            }

            // Si DEPARTAMENTO_PACIENTES no existe, crear un nuevo vector
            if (!DEPARTAMENTO_PACIENTESEncontrada) {
                DEPARTAMENTO_PACIENTES.push_back({registro});
            }

            //====================== PROVINCIA_PACIENTES ===========================================
            // Buscar PROVINCIA_PACIENTES en el vector de vectores
            bool PROVINCIA_PACIENTESEncontrada = false;
            for (auto& vec : PROVINCIA_PACIENTES) {
                if (!vec.empty() && vec[0]->getProvinciaPaciente() == registro->getProvinciaPaciente()) {
                    vec.push_back(registro);
                    PROVINCIA_PACIENTESEncontrada = true;
                    break;
                }
            }

            // Si PROVINCIA_PACIENTES no existe, crear un nuevo vector
            if (!PROVINCIA_PACIENTESEncontrada) {
                PROVINCIA_PACIENTES.push_back({registro});
            }


            //====================== DISTRITO_PACIENTES ===========================================
            // Buscar DISTRITO_PACIENTES en el vector de vectores
            bool DISTRITO_PACIENTESEncontrada = false;
            for (auto& vec : DISTRITO_PACIENTES) {
                if (!vec.empty() && vec[0]->getDistritoPaciente() == registro->getDistritoPaciente()) {
                    vec.push_back(registro);
                    DISTRITO_PACIENTESEncontrada = true;
                    break;
                }
            }

            // Si DISTRITO_PACIENTES no existe, crear un nuevo vector
            if (!DISTRITO_PACIENTESEncontrada) {
                DISTRITO_PACIENTES.push_back({registro});
            }


            //====================== DEPARTAMENTO_MUESTRAS ===========================================
            // Buscar DEPARTAMENTO_MUESTRAS en el vector de vectores
            bool DEPARTAMENTO_MUESTRASEncontrada = false;
            for (auto& vec : DEPARTAMENTO_MUESTRAS) {
                if (!vec.empty() && vec[0]->getDepartamentoMuestra() == registro->getDepartamentoMuestra()) {
                    vec.push_back(registro);
                    DEPARTAMENTO_MUESTRASEncontrada = true;
                    break;
                }
            }

            // Si DEPARTAMENTO_MUESTRAS no existe, crear un nuevo vector
            if (!DEPARTAMENTO_MUESTRASEncontrada) {
                DEPARTAMENTO_MUESTRAS.push_back({registro});
            }


            //====================== PROVINCIA_MUESTRAS ===========================================
            // Buscar PROVINCIA_MUESTRAS en el vector de vectores
            bool PROVINCIA_MUESTRASEncontrada = false;
            for (auto& vec : PROVINCIA_MUESTRAS) {
                if (!vec.empty() && vec[0]->getProvinciaMuestra() == registro->getProvinciaMuestra()) {
                    vec.push_back(registro);
                    PROVINCIA_MUESTRASEncontrada = true;
                    break;
                }
            }

            // Si PROVINCIA_MUESTRAS no existe, crear un nuevo vector
            if (!PROVINCIA_MUESTRASEncontrada) {
                PROVINCIA_MUESTRAS.push_back({registro});
            }


            //====================== DISTRITO_MUESTRAS ===========================================
            // Buscar DISTRITO_MUESTRAS en el vector de vectores
            bool DISTRITO_MUESTRASEncontrada = false;
            for (auto& vec : DISTRITO_MUESTRAS) {
                if (!vec.empty() && vec[0]->getDistritoMuestra() == registro->getDistritoMuestra()) {
                    vec.push_back(registro);
                    DISTRITO_MUESTRASEncontrada = true;
                    break;
                }
            }

            // Si DISTRITO_MUESTRAS no existe, crear un nuevo vector
            if (!DISTRITO_MUESTRASEncontrada) {
                DISTRITO_MUESTRAS.push_back({registro});
            }


            //====================== TIPO_MUESTRAS ===========================================
            // Buscar TIPO_MUESTRAS en el vector de vectores
            bool TIPO_MUESTRASEncontrada = false;
            for (auto& vec : TIPO_MUESTRAS) {
                if (!vec.empty() && vec[0]->getTipoMuestra() == registro->getTipoMuestra()) {
                    vec.push_back(registro);
                    TIPO_MUESTRASEncontrada = true;
                    break;
                }
            }

            // Si TIPO_MUESTRAS no existe, crear un nuevo vector
            if (! TIPO_MUESTRASEncontrada) {
                TIPO_MUESTRAS.push_back({registro});
            }

            //====================== Resultados ===========================================
            // Buscar resultados en el vector de vectores
            bool resultadoEncontrada = false;
            for (auto& vec : resultados) {
                if (!vec.empty() && vec[0]->getResultado() == registro->getResultado()) {
                    vec.push_back(registro);
                    resultadoEncontrada = true;
                    break;
                }
            }


            // Si la resultado no existe, crear un nuevo vector
            if (!resultadoEncontrada) {
                resultados.push_back({registro});
            }


            if (fields[1].compare("NULL", Qt::CaseInsensitive) == 0) {
                id++;
            }
        }

        ui->confirmacion->setText(" Carga exitosa... !!!!" );

        DataHolder::instance().setDepartamentoMuestras(DEPARTAMENTO_MUESTRAS);
        DataHolder::instance().setTipoMuestras(TIPO_MUESTRAS);
        DataHolder::instance().setresultados(resultados);

        // Verificacion =============================================================================================



        // Imprimir los nombres de FECHAS_CORTE en el vector principal
        std::cout << "Nombres de FECHAS_CORTE en el Vector Principal:" << std::endl;
        for (const auto& vec : FECHAS_CORTE) {
            std::cout << vec[0]->getFechaCorte() << std::endl;
        }


        std::cout << " " << std::endl;

        // Imprimir los nombres de FECHAS_MUESTRAS en el vector principal
        std::cout << "Nombres de FECHAS_MUESTRAS en el Vector Principal:" << std::endl;
        for (const auto& vec : FECHAS_MUESTRAS) {
            std::cout << vec[0]->getFechaMuestra() << std::endl;
        }


        std::cout << " " << std::endl;

        // Imprimir los nombres de Edades en el vector principal
        std::cout << "Nombres de Edades en el Vector Principal:" << std::endl;
        for (const auto& vec : Edades) {
            std::cout << vec[0]->getEdad() << std::endl;
        }


        std::cout << " " << std::endl;

        // Imprimir los nombres de Sexos en el vector principal
        std::cout << "Nombres de Sexos en el Vector Principal:" << std::endl;
        for (const auto& vec : Sexos) {
            std::cout << vec[0]->getSexo() << std::endl;
        }


        std::cout << " " << std::endl;


        // Imprimir los nombres de las instituciones en el vector principal
        std::cout << "Nombres de Instituciones en el Vector Principal:" << std::endl;
        for (const auto& vec : instituciones) {
            std::cout << vec[0]->getInstitucion() << std::endl;
        }

        std::cout << " " << std::endl;


        // Imprimir los nombres de UBIGEO_PACIENTES en el vector principal
        std::cout << "Nombres de UBIGEO_PACIENTES en el Vector Principal:" << std::endl;
        for (const auto& vec : UBIGEO_PACIENTES) {
            std::cout << vec[0]->getUbigeoPaciente() << std::endl;
        }


        std::cout << " " << std::endl;

        // Imprimir los nombres de DEPARTAMENTO_PACIENTES en el vector principal
        std::cout << "Nombres de DEPARTAMENTO_PACIENTES en el Vector Principal:" << std::endl;
        for (const auto& vec : DEPARTAMENTO_PACIENTES) {
            std::cout << vec[0]->getDepartamentoPaciente() << std::endl;
        }


        std::cout << " " << std::endl;

        // Imprimir los nombres de PROVINCIA_PACIENTES en el vector principal
        std::cout << "Nombres de PROVINCIA_PACIENTES en el Vector Principal:" << std::endl;
        for (const auto& vec : PROVINCIA_PACIENTES) {
            std::cout << vec[0]->getProvinciaPaciente() << std::endl;
        }


        std::cout << " " << std::endl;

        // Imprimir los nombres DISTRITO_PACIENTES en el vector principal
        std::cout << "Nombres de DISTRITO_PACIENTES en el Vector Principal:" << std::endl;
        for (const auto& vec : DISTRITO_PACIENTES) {
            std::cout << vec[0]->getDistritoPaciente() << std::endl;
        }


        std::cout << " " << std::endl;

        // Imprimir los nombres DEPARTAMENTO_MUESTRAS en el vector principal
        std::cout << "Nombres de DEPARTAMENTO_MUESTRAS en el Vector Principal:" << std::endl;
        for (const auto& vec : DEPARTAMENTO_MUESTRAS) {
            std::cout << vec[0]->getDepartamentoMuestra() << std::endl;
        }


        std::cout << " " << std::endl;

        // Imprimir los nombres de PROVINCIA_MUESTRAS en el vector principal
        std::cout << "Nombres de PROVINCIA_MUESTRAS en el Vector Principal:" << std::endl;
        for (const auto& vec : PROVINCIA_MUESTRAS) {
            std::cout << vec[0]->getProvinciaMuestra() << std::endl;
        }

        std::cout << " " << std::endl;

        // Imprimir los nombres DISTRITO_MUESTRAS en el vector principal
        std::cout << "Nombres de DISTRITO_MUESTRAS en el Vector Principal:" << std::endl;
        for (const auto& vec : DISTRITO_MUESTRAS) {
            std::cout << vec[0]->getDistritoMuestra() << std::endl;
        }

        std::cout << " " << std::endl;

        // Imprimir los nombres de TIPO_MUESTRAS en el vector principal
        std::cout << "Nombres de TIPO_MUESTRAS en el Vector Principal:" << std::endl;
        for (const auto& vec : TIPO_MUESTRAS) {
            std::cout << vec[0]->getTipoMuestra() << std::endl;
        }

        std::cout << " " << std::endl;

        // Imprimir los nombres de los resultados en el vector principal
        std::cout << "Nombres de resultados en el Vector Principal:" << std::endl;
        for (const auto& vec : resultados) {
            std::cout << vec[0]->getResultado() << std::endl;
        }

        int uuidBusqueda = -1; // Cambia esto por el UUID que quieras buscar
        Registro* registroBuscado = tree->search(uuidBusqueda);
        if (registroBuscado != nullptr) {
            // Imprimir la representación en texto del registro buscado
            std::cout << "Registro con UUID " << uuidBusqueda << ":\n" << registroBuscado->toString() << std::endl;
            std::cout << registroBuscado->getResultado() << std::endl;
        } else {
            qDebug() << "No se encontró un registro con el UUID" << uuidBusqueda;
        }

        std::cout << " " << std::endl;


    }


}


void MainPage::on_siguiente_clicked()
{
    // Oculta la ventana actual (MainPage)
    this->hide();

    // Crea o obtén la instancia de la ventana llamada "principal"
    Principal *principal = new Principal(DataHolder::instance().getTree());  // Asegúrate de que la clase se llama "Principal"

    // Muestra la ventana "principal"
    principal->show();
}


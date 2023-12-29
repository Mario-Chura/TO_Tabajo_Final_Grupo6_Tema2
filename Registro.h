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

    // Setters
    void setFechaCorte(const std::string& fecha);
    void setUuid(int newUuid);
    void setFechaMuestra(const std::string& fecha);
    void setEdad(int newEdad);
    void setSexo(const std::string& newSexo);
    void setInstitucion(const std::string& newInstitucion);
    void setUbigeoPaciente(const std::string& newUbigeo);
    void setDepartamentoPaciente(const std::string& newDepartamento);
    void setProvinciaPaciente(const std::string& newProvincia);
    void setDistritoPaciente(const std::string& newDistrito);
    void setDepartamentoMuestra(const std::string& newDepartamento);
    void setProvinciaMuestra(const std::string& newProvincia);
    void setDistritoMuestra(const std::string& newDistrito);
    void setTipoMuestra(const std::string& newTipoMuestra);
    void setResultado(const std::string& newResultado);
};

#endif // REGISTRO_H



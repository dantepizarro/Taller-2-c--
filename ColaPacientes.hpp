#pragma once
#include "NodoCola.hpp"

class ColaPacientes {
private:
    NodoCola* frente;
    NodoCola* final;
    int tamano;

public:
    ColaPacientes();
    ~ColaPacientes();

    void encolar(Paciente* p);
    Paciente* desencolar();
    bool estaVacia();
    int getTamano();
    void mostrar();
    bool existeID(string id);
    
};
#pragma once
#include "NodoHistorial.hpp"
#include <string>

class PilaHistorial {
private: 
    NodoHistorial* tope;
    int tamano;

public: 
    PilaHistorial();
    ~PilaHistorial();

    void apilar(string evento);
    void mostrarHistorial();
    bool estaVacia();
    int getTamano();
};
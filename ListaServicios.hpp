#pragma once
#include "NodoServicio.hpp"
#include <string>

class ListaServicios {
private:
    NodoServicio* frente;
    NodoServicio* final;
    int tamaño;
public:
    ListaServicios();
    ~ListaServicios();

    void insertar(string nombre, Paciente* paciente);
    NodoServicio* buscarServicio(string nombre);
    bool estaVacia();
    int getTamano();
    void mostrar();
    void mostrarHistorial();
};
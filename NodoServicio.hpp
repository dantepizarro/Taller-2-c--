#pragma once
#include "ColaPacientes.hpp"

struct NodoServicio {
    string nombre;
    ColaPacientes pacientes;
    NodoServicio* siguiente;

    NodoServicio(string nombre) : nombre(nombre), siguiente(nullptr) {}
};

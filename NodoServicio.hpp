#pragma once
#include "ArbolAVL.hpp"


struct NodoServicio {
    string nombre;
    ArbolAVL pacientes;
    NodoServicio* siguiente;

    NodoServicio(string nombre) : nombre(nombre), siguiente(nullptr) {}
};

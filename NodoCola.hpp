#pragma once
#include "Paciente.hpp"

struct NodoCola {
    Paciente* paciente;
    NodoCola* siguiente;

    NodoCola(Paciente* p) : paciente(p), siguiente(nullptr) {}
};

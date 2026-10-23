#pragma once
#include <string>
#include "NodoDecision.hpp"
#include "Paciente.hpp"

class ArbolDecision {
private:
    NodoDecision* raiz;

    bool responder(int pregunta, const Paciente& p);
    void ImprimirNodo(NodoDecision* nodo, int nivel);
    void RecorrerPreorden(NodoDecision* nodo, int nivel);
    void RecorrerInorden(NodoDecision* nodo, int nivel);
    void RecorrerPostOrden(NodoDecision* nodo, int nivel);

public:
    ArbolDecision();
    ~ArbolDecision();

    void construir();

    string evaluar(const Paciente& p, string& ruta);

    void mostrarPreorden();
    void mostrarInOrden();
    void mostrarPostOrden();
};
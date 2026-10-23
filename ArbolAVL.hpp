#pragma once
#include <string>
#include "NodoAVL.hpp"

class ArbolAVL {
private:
    NodoAVL* raiz;

    int getAltura(NodoAVL* nodo);
    int getBalance(NodoAVL* nodo);
    void actualizarAltura(NodoAVL* nodo);
    void destruirArbol(NodoAVL* nodo);

    NodoAVL* Derecha(NodoAVL* y);
    NodoAVL* Izquierda(NodoAVL* x);

    NodoAVL* insertar(NodoAVL* nodo, Paciente* paciente);
    
    void PreOrden(NodoAVL* nodo);
    void InOrden(NodoAVL* nodo);
    void PostOrden(NodoAVL* nodo);


public :    
    ArbolAVL();
    ~ArbolAVL();
    void insertar(Paciente* paciente);
    Paciente* buscar(std::string id);

    void mostrarPreOrden();
    void mostrarInOrden();
    void mostrarPostOrden();
    bool estaVacio();

};
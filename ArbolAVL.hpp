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
    void mostrarBalance(NodoAVL* nodo);
    NodoAVL* Derecha(NodoAVL* y);
    NodoAVL* Izquierda(NodoAVL* x);

    NodoAVL* insertar(NodoAVL* nodo, Paciente* paciente);
    Paciente* buscarPorNombre(NodoAVL* nodo, std::string nombre);
    void PreOrden(NodoAVL* nodo);
    void InOrden(NodoAVL* nodo);
    void PostOrden(NodoAVL* nodo);
    void listarResumen(NodoAVL* nodo, bool& primero);


public :    
    ArbolAVL();
    ~ArbolAVL();
    void insertar(Paciente* paciente);
    Paciente* buscarPorID(std::string id,std::string& ruta);
    Paciente* buscarPorNombre(const std::string& nombre);
    void mostrarPreOrden();
    void mostrarInOrden();
    void mostrarPostOrden();
    bool estaVacio();
    void mostrarAltura();
    void mostrarFactorBalance();
    void mostrarResumen();

};
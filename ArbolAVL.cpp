#include "ArbolAVL.hpp"


using namespace std;

ArbolAVL::ArbolAVL() : raiz(nullptr) {}
ArbolAVL::~ArbolAVL() {
    destruirArbol(raiz);
}



void ArbolAVL::destruirArbol(NodoAVL* nodo) {
    if (nodo != nullptr) {
        destruirArbol(nodo->izquierdo);
        destruirArbol(nodo->derecho);
        delete nodo;
    }
}

int ArbolAVL::getAltura(NodoAVL* nodo) {
    if (nodo == nullptr) {
    return 0;
} else {
    return nodo->altura;
}
}

int ArbolAVL::getBalance(NodoAVL* nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    return getAltura(nodo->izquierdo) - getAltura(nodo->derecho);
}

void ArbolAVL::actualizarAltura(NodoAVL* nodo) {
    if (nodo != nullptr) {
        nodo->altura = 1 + max(getAltura(nodo->izquierdo), getAltura(nodo->derecho));
    }
}


NodoAVL* ArbolAVL::Derecha(NodoAVL* y) {
    NodoAVL* x = y->izquierdo;
    NodoAVL* T2 = x->derecho;

    x->derecho = y;
    y->izquierdo = T2;

    y->altura = max(getAltura(y->izquierdo), getAltura(y->derecho)) + 1;
    x->altura = max(getAltura(x->izquierdo), getAltura(x->derecho)) + 1;

    return x;
}


NodoAVL* ArbolAVL::Izquierda(NodoAVL* x) {
    NodoAVL* y = x->derecho;
    NodoAVL* T2 = y->izquierdo;

    y->izquierdo = x;
    x->derecho = T2;

    x->altura = max(getAltura(x->izquierdo), getAltura(x->derecho)) + 1;
    y->altura = max(getAltura(y->izquierdo), getAltura(y->derecho)) + 1;

    return y;
}
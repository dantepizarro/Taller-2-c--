#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "ColaPacientes.hpp"
#include "ListaServicios.hpp"
#include "PilaHistorial.hpp"

using namespace std;

void lectura(ColaPacientes &cola) {
    ifstream archivo("pacientes.txt", ios::in);
    
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo pacientes.txt desde la carpeta de ejecucion." << endl;
        return;
    }
    
    string linea;
    while (getline(archivo, linea)) {
        if (linea.empty()) continue;

        if (!linea.empty() && linea.back() == '\r') {
            linea.pop_back();
        }

        stringstream ss(linea);
        string token;
        
        string id, nombre, tipoDolor;
        int edad = 0, presionArterial = 0, dolor = 0, diasHospitalizacion = 0;
        float temperatura = 0.0f;
        int traumaInt = 0, sintomasInt = 0, cirugiaInt = 0;
        
        bool lineaValida = true;
        int columna = 0;

        while (getline(ss, token, ';')) {
            try {
                switch (columna) {
                    case 0: id = token; break;
                    case 1: nombre = token; break;
                    case 2: edad = stoi(token); break;
                    case 3: temperatura = stof(token); break;
                    case 4: presionArterial = stoi(token); break;
                    case 5: dolor = stoi(token); break;
                    case 6: tipoDolor = token; break;
                    case 7: traumaInt = stoi(token); break;
                    case 8: sintomasInt = stoi(token); break;
                    case 9: cirugiaInt = stoi(token); break;
                    case 10: diasHospitalizacion = stoi(token); break;
                    default: break;
                }
            } catch (const invalid_argument&) {
                lineaValida = false;
                break;
            } catch (const out_of_range&) {
                lineaValida = false;
                break;
            }
            columna++;
        }

        if (!lineaValida || columna < 11) {
            cout << "Advertencia: Linea invalida u omitida por formato/datos incompletos." << endl;
            continue;
        }

        if (edad < 0 || dolor < 0 || dolor > 10 || temperatura < 30.0f) {
            cout << "Advertencia: Datos fuera de rango para el paciente " << id << ". Se omite la linea." << endl;
            continue;
        }

        if (cola.existeID(id)) {
            cout << "Advertencia: ID duplicado (" << id << "), se omite la linea." << endl;
            continue;
        }

        Paciente* nuevoPaciente = new Paciente(
            id, nombre, edad, temperatura, presionArterial, dolor, tipoDolor,
            traumaInt != 0, sintomasInt != 0, cirugiaInt != 0, diasHospitalizacion
        );

        cola.encolar(nuevoPaciente);
    }

    archivo.close();
    cout << "Carga de pacientes realizada con exito." << endl;
}

void mostrarDepartamentos(ListaServicios& listaServicios, int opcion) {
    NodoServicio* actual = nullptr;
    switch (opcion) {
        case 1: actual = listaServicios.buscarServicio("Urgencias"); break;
        case 2: actual = listaServicios.buscarServicio("Medicina General"); break;
        case 3: actual = listaServicios.buscarServicio("Cardiologia"); break;
        case 4: actual = listaServicios.buscarServicio("Neurologia"); break;
        case 5: actual = listaServicios.buscarServicio("Traumatologia"); break;
        case 6: actual = listaServicios.buscarServicio("Cirugia"); break;
        case 7: actual = listaServicios.buscarServicio("Pediatria"); break;
        case 8: actual = listaServicios.buscarServicio("Hospitalizacion"); break;
        default: break;
    }
    
    if (actual != nullptr) {
        cout << "Departamento: " << actual->nombre << endl;
        actual->pacientes.mostrar();
    } else {
        cout << "No se encontro el departamento seleccionado." << endl;
    }
}

int main() {
    ColaPacientes cola;  
    ListaServicios listaServicios; 
    PilaHistorial historial;

    lectura(cola);        


    int opcion = 0;
    while (opcion != 4) {
        cout << "\n=== HOSPITAL MARMAJA ===" << endl;
        cout << "1. Atender pacientes" << endl;
        cout << "2. Ver departamentos" << endl;
        cout << "3. Revisar historial de pacientes" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccionar opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cola.mostrar();
                int cantidad;
                cout << "Indique la cantidad de pacientes a atender: ";
                cin >> cantidad;

                for (int i = 0; i < cantidad; i++) {
                    Paciente* pacienteAtendido = cola.desencolar();
                    if (pacienteAtendido != nullptr) {
                        pacienteAtendido->mostrar();
                        cout << "Paciente enviado a: " + pacienteAtendido->getServicio() << endl;
                        listaServicios.insertar(pacienteAtendido->getServicio(), pacienteAtendido);
                        
                        string evento = "ID: " + pacienteAtendido->getId() +
                                       " | Nombre: " + pacienteAtendido->getNombre() + 
                                       " | Edad: " + to_string(pacienteAtendido->getEdad()) + 
                                       " | Departamento: " + pacienteAtendido->getServicio(); 
                        historial.apilar(evento);
                    } else {  
                        cout << "No hay mas pacientes para atender." << endl;
                        break;
                    }
                }
                break;
            }
            case 2: {
                int opcionDepartamento = 0;
                cout << "\n==== DEPARTAMENTOS Y SERVICIOS ===" << endl;
                cout << "1. Urgencias" << endl;
                cout << "2. Medicina General" << endl;
                cout << "3. Cardiologia" << endl;
                cout << "4. Neurologia" << endl;
                cout << "5. Traumatologia" << endl;
                cout << "6. Cirugia" << endl;
                cout << "7. Pediatria" << endl;
                cout << "8. Hospitalizacion" << endl;
                cout << "Seleccione un departamento (1-8): ";
                cin >> opcionDepartamento;

                mostrarDepartamentos(listaServicios, opcionDepartamento);
                break;
            }
            case 3: {
                cout << "\n=== HISTORIAL DE ULTIMAS ATENCIONES DEL HOSPITAL ===" << endl;
                historial.mostrarHistorial();
                break;
            }
            case 4: {
                cout << "Saliendo del sistema..." << endl;
                break;
            }
            default: {
                cout << "Opcion fuera de rango (1-4)." << endl;
                break;
            }
        }
    }
    
    return 0;
}
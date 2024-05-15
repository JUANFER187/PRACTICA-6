#include <iostream>
#include "Cola.h"

enum OpcionesMenu {
    OPT_SALIR,
    OPT_ALTA_SOLICITUD,
    OPT_ELABORAR_CONSTANCIA,
    OPT_BUSCAR_SOLICITUD

};

int main() {
    setlocale(LC_ALL, "spanish");

    Cola solicitudes;
    persona x;
    int opc;
    do {
        std::cout << "\t\tMENU" << std::endl;
        std::cout << OPT_ALTA_SOLICITUD << ") Alta de solicitud." << std::endl;
        std::cout << OPT_ELABORAR_CONSTANCIA << ") Elaborar constancia." << std::endl;
        std::cout << OPT_BUSCAR_SOLICITUD << ") Buscar solicitud." << std::endl;
        std::cout << OPT_SALIR << ") Salir." << std::endl;
        std::cout << "Seleccione una opción: ";
        std::cin >> opc;

        switch (opc) {
            case OPT_ALTA_SOLICITUD: {
                std::cin >> x;
                solicitudes.enqueue(x);
                std::cout << "Solicitud de constancia agregada." << std::endl;
                break;
            }
            case OPT_ELABORAR_CONSTANCIA: {
                if (!solicitudes.vacia()) {
                    std::cout << "Constancia elaborada para: " << solicitudes.dequeue();
                } else {
                    std::cout << "No hay solicitudes pendientes." << std::endl;
                }
                break;
            }
            case OPT_BUSCAR_SOLICITUD: {
                if (!solicitudes.vacia()) {
                    std::string nombreBuscar;
                    std::cout << "\nIngrese el nombre de la persona a buscar: ";
                    std::cin >> nombreBuscar;
                    int posicion = solicitudes.busquedaLineal(nombreBuscar);
                    if (posicion != -1) {
                        std::cout << "La solicitud se encuentra en la posición: " << (solicitudes.ultimo() - posicion) + 1 << " de " << solicitudes.ultimo() + 1 << std::endl;
                    } else {
                        std::cout << "La solicitud no se encuentra en la cola." << std::endl;
                    }
                } else {
                    std::cout << "No hay solicitudes pendientes." << std::endl;
                }
                break;
            }
            case OPT_SALIR: {
                std::cout << "Saliendo..." << std::endl;
                break;
            }
            default: {
                std::cout << "Opción no válida." << std::endl;
                break;
            }
        }
    } while (opc != OPT_SALIR);

    return 0;
}

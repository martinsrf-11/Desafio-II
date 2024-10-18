#include "menu.h"
#include <iostream>

Menu::Menu(RedEstaciones* redEstaciones) : redEstaciones(redEstaciones) {}

void Menu::mostrarMenu() {
    int OpcionMenuPrincipal;
    do {
        std::cout << "\n--- Menu Principal ---\n";
        std::cout << "1. Gestionar Red de Estaciones\n";
        std::cout << "2. Gestionar Estacion\n";
        std::cout << "3. Verificar Fugas\n";
        std::cout << "4. Simular Ventas\n"; // Nueva opción
        std::cout << "5. Salir\n"; // Aumenta la opción para salir
        std::cout << "Seleccione una opcion: ";
        std::cin >> OpcionMenuPrincipal;
        switch (OpcionMenuPrincipal) {
            case 1:
                gestionarRedEstaciones();
                break;
            case 2:
                gestionarEstacion();
                break;
            case 3:
                verificarFugas();
                break;
            case 4:
                simularVentas();
                break;
            case 5:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opción invalida, intente de nuevo.\n";
                break;
        }
    } while (OpcionMenuPrincipal != 5);
}

void Menu::gestionarRedEstaciones() {
    mostrarOpcionesRed();
    int OpcionGestionRed;
    std::cin >> OpcionGestionRed;
    do {
        switch (OpcionGestionRed) {
        case 1:
            agregarEstacion();
            break;
        case 2:
            eliminarEstacion();
            break;
        case 3: 
            redEstaciones->mostrarEstaciones();
        case 4:
            mostrarMenu();
        default:
            std::cout << "Opcion inválida, intente nuevamente.\n";
            mostrarOpcionesRed();
            std::cin >> OpcionGestionRed;
            break;
        }
    } while (OpcionGestionRed !=5 );
}

void Menu::gestionarEstacion() {
    mostrarOpcionesEstacion();
    int OpcionGestionEstacion;
    std::cin >> OpcionGestionEstacion;

    switch (OpcionGestionEstacion) {
    case 1:
        agregarSurtidor();
        break;
    case 2:
        eliminarSurtidor();
        break;
    case 3:
        mostrarMenu();
        break;
    default:
        std::cout << "Opcion invalida.\n";
        break;
    }
}

void Menu::agregarEstacion() {
    std::string nombre, codigo, gerente, region, ubicacion;

    std::cout << "Ingrese el nombre de la estacion: ";
    std::getline(std::cin >> std::ws, nombre);  // Captura nombre completo con espacios

    std::cout << "Ingrese el codigo de la estacion: ";
    std::getline(std::cin >> std::ws, codigo);

    std::cout << "Ingrese el nombre del gerente: ";
    std::getline(std::cin >> std::ws, gerente);

    // Validar la región
    bool regionValida = false;
    do {
        std::cout << "Ingrese la region (Norte, Sur, Centro): ";
        std::getline(std::cin >> std::ws, region);
        if (region == "Norte" || region == "Sur" || region == "Centro") {
            regionValida = true;
        } else {
            std::cout << "Región incorrecta, ingrese una de las regiones indicadas respetando sus mayúsculas y minúsculas." << std::endl;
        }
    } while (!regionValida);

    std::cout << "Ingrese la ubicacion: ";
    std::getline(std::cin >> std::ws, ubicacion);

    // Crear una nueva estación con los datos ingresados
    EstacionDeServicio* nuevaEstacion = new EstacionDeServicio(nombre, codigo, gerente, region, ubicacion);

    // Agregar la estación a la red
    redEstaciones->agregarEstacion(nuevaEstacion);

    mostrarMenu();
}


void Menu::agregarSurtidor() {
    std::string codigo, modelo;
    std::cout << "Ingrese el codigo del surtidor: ";
    std::cin >> codigo;
    std::cout << "Ingrese el modelo del surtidor: ";
    std::cin >> modelo;

    std::string codigoEstacion;
    std::cout << "Ingrese el codigo de la estacion a la que se agregara el surtidor: ";
    std::cin >> codigoEstacion;

    EstacionDeServicio* estacion = redEstaciones->buscarEstacion(codigoEstacion);
    if (estacion) {
        Surtidor* nuevoSurtidor = new Surtidor(codigo, modelo);
        estacion->agregarSurtidor(nuevoSurtidor);
        std::cout << "Surtidor agregado correctamente.\n";
    } else {
        std::cout << "Estacion no encontrada.\n";
    }
}

void Menu::eliminarEstacion() {
    std::string codigo;
    std::cout << "Ingrese el codigo de la estacion a eliminar: ";
    std::cin >> codigo;
    redEstaciones->eliminarEstacion(codigo);
    mostrarMenu();
}

void Menu::eliminarSurtidor() {
    std::string codigoSurtidor;
    std::cout << "Ingrese el codigo del surtidor a eliminar: ";
    std::cin >> codigoSurtidor;

    std::string codigoEstacion;
    std::cout << "Ingrese el codigo de la estacion que contiene el surtidor: ";
    std::cin >> codigoEstacion;

    EstacionDeServicio* estacion = redEstaciones->buscarEstacion(codigoEstacion);
    if (estacion) {
        estacion->eliminarSurtidor(codigoSurtidor);
        std::cout << "Surtidor eliminado correctamente.\n";
    } else {
        std::cout << "Estacion no encontrada.\n";
    }
}

void Menu::consultarHistorico() {
    std::string codigo;
    std::cout << "Ingrese el codigo del surtidor: ";
    std::cin >> codigo;
    Surtidor* surtidor = redEstaciones->buscarSurtidor(codigo);
    if (surtidor) {
        surtidor->consultarHistorico();
    } else {
        std::cout << "Surtidor no encontrado.\n";
    }
}

void Menu::verificarFugas() {
    std::string codigo;
    std::cout << "Ingrese el codigo de la estacion para verificar fugas: ";
    std::cin >> codigo;
    EstacionDeServicio* estacion = redEstaciones->buscarEstacion(codigo);
    if (estacion) {
        if (estacion->verificarFugas()) {
            std::cout << "Fugas detectadas en la estacion.\n";
        } else {
            std::cout << "No se detectaron fugas.\n";
        }
    } else {
        std::cout << "Estacion no encontrada.\n";
    }
}

void Menu::mostrarOpcionesRed() {
    std::cout << "\n--- Gestionar Red de Estaciones ---\n";
    std::cout << "1. Agregar Estacion\n";
    std::cout << "2. Eliminar Estacion\n";
    std::cout << "3. Ver Estaciones De La Red\n";
    std::cout << "4. Volver al menú principal\n";
    std::cout << "Seleccione una opcion: ";
}

void Menu::mostrarOpcionesEstacion() {
    std::cout << "\n--- Gestionar Estacion ---\n";
    std::cout << "1. Agregar Surtidor\n";
    std::cout << "2. Eliminar Surtidor\n";
    std::cout << "3. Volver al menú principal\n";
    std::cout << "Seleccione una opcion: ";
}
void Menu::simularVentas() {
    std::string codigoEstacion;
    std::cout << "Ingrese el código de la estación para simular ventas: ";
    std::cin >> codigoEstacion;

    EstacionDeServicio* estacion = redEstaciones->buscarEstacion(codigoEstacion);
    if (estacion) {
        float cantidad;
        int categoria;
        int metodoPago;
        std::string documentoCliente;

        std::cout << "Ingrese la cantidad de litros a vender: ";
        std::cin >> cantidad;

        std::cout << "Ingrese la categoría de combustible (0: Regular, 1: Premium, 2: EcoExtra): ";
        std::cin >> categoria;

        std::cout << "Ingrese el método de pago (0: Efectivo, 1: TDebito, 2: TCredito): ";
        std::cin >> metodoPago;

        std::cout << "Ingrese el número de documento del cliente: ";
        std::cin >> documentoCliente;

    } else {
        std::cout << "Estación no encontrada.\n";
    }
}

#include "EstacionDeServicio.h"
#include <iostream>

EstacionDeServicio::EstacionDeServicio(const std::string& nombre, const std::string& codigo, const std::string& gerente, const std::string& region, const std::string& ubicacion)
    : nombre(nombre), codigo(codigo), gerente(gerente), region(region), ubicacion(ubicacion), numSurtidores(0) {
    surtidores = new Surtidor*[12];  // 12 surtidores por estación
}

EstacionDeServicio::~EstacionDeServicio() {
    for (int i = 0; i < numSurtidores; ++i) {
        delete surtidores[i];
    }
    delete[] surtidores;
}

void EstacionDeServicio::agregarSurtidor(Surtidor* surtidor) {
    if (numSurtidores < 12) {
        surtidores[numSurtidores++] = surtidor;
    } else {
        std::cout << "No se pueden agregar más surtidores.\n";
    }
}

void EstacionDeServicio::eliminarSurtidor(const std::string& codigo) {
    for (int i = 0; i < numSurtidores; ++i) {
        if (surtidores[i]->getCodigo() == codigo) {
            delete surtidores[i]; // Liberar la memoria del surtidor
            for (int j = i; j < numSurtidores - 1; ++j) {
                surtidores[j] = surtidores[j + 1]; // Desplazar los elementos
            }
            --numSurtidores; // Reducir el conteo
            std::cout << "Surtidor eliminado.\n";
            return;
        }
    }
    std::cout << "Surtidor no encontrado.\n";
}

void EstacionDeServicio::consultarHistorico() {
    for (int i = 0; i < numSurtidores; ++i) {
        surtidores[i]->consultarHistorico();
    }
}

bool EstacionDeServicio::verificarFugas() {
    for (int i = 0; i < numSurtidores; ++i) {
        if (surtidores[i]->verificarFugas()) { 
            return true;
        }
    }
    return false;
}

std::string EstacionDeServicio::getCodigo() const {
    return codigo;
}

Surtidor* EstacionDeServicio::buscarSurtidor(const std::string& codigo) {
    for (int i = 0; i < numSurtidores; ++i) {
        if (surtidores[i]->getCodigo() == codigo) {
            return surtidores[i];
        }
    }
    return nullptr;
}
void EstacionDeServicio::registrarVenta(double litros, const std::string& tipoCombustible) {
    if (tipoCombustible == "Regular") {
        ventasRegular += litros;
    } else if (tipoCombustible == "Premium") {
        ventasPremium += litros;
    } else if (tipoCombustible == "EcoExtra") {
        ventasEcoExtra += litros;
    } else {
        std::cout << "Tipo de combustible no válido.\n";
    }
}

void EstacionDeServicio::calcularVentasPorTipoCombustible() {
    double totalRegular = 0.0;
    double totalPremium = 0.0;
    double totalEcoExtra = 0.0;

    for (int i = 0; i < numSurtidores; ++i) {
        totalRegular += surtidores[i]->getVentasPorCombustible(0);
        totalPremium += surtidores[i]->getVentasPorCombustible(1);
        totalEcoExtra += surtidores[i]->getVentasPorCombustible(2);
    }

    std::cout << "Ventas totales en la estación " << nombre << ":\n";
    std::cout << "Gasolina Regular: $" << totalRegular << "\n";
    std::cout << "Gasolina Premium: $" << totalPremium << "\n";
    std::cout << "EcoExtra: $" << totalEcoExtra << "\n";
}

void EstacionDeServicio::fijarPreciosCombustible(double precioRegular, double precioPremium, double precioEcoExtra) {
    for (int i = 0; i < numSurtidores; ++i) {
        surtidores[i]->setPrecio(0, precioRegular);
        surtidores[i]->setPrecio(1, precioPremium);
        surtidores[i]->setPrecio(2, precioEcoExtra);
    }
}

double EstacionDeServicio::getVentasTotales() const {
    return ventasTotales;
}
std::string EstacionDeServicio::getNombre() const {
    return nombre;
}
std::string EstacionDeServicio::getRegion() const {
    return region;
}    
std::string EstacionDeServicio::getUbicacion() const {
    return ubicacion;
}
std::string EstacionDeServicio::getGerente() const {
    return gerente;
}
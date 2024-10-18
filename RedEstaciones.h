#ifndef REDESTACIONES_H
#define REDESTACIONES_H

#include "EstacionDeServicio.h"
#include <string>

class RedEstaciones {
private:
    EstacionDeServicio** estaciones; // Array dinámico de punteros a EstacionDeServicio
    int numEstaciones;
    int maxEstaciones;
public:
    RedEstaciones();
    ~RedEstaciones();

    void agregarEstacion(EstacionDeServicio* nuevaEstacion);
    void eliminarEstacion(const std::string& codigo);
    EstacionDeServicio* buscarEstacion(const std::string& codigo);
    Surtidor* buscarSurtidor(const std::string& codigo); // Nueva función para buscar un surtidor
    void calcularVentasTotalesPorTipoCombustible();
    void mostrarEstaciones() const;
};

#endif // REDESTACIONES_H

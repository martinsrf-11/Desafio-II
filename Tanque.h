#ifndef TANQUE_H
#define TANQUE_H

#include <string>

class Tanque {
private:
    double capacidadTotal;
    double capacidadDisponible;
    std::string categoriaCombustible;

public:
    Tanque(double capacidadTotal, double capacidadDisponible, std::string categoriaCombustible);
    void actualizarCapacidad(double cantidad);
    bool verificarFugas();
};

#endif // TANQUE_H


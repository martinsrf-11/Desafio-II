#ifndef MENU_H
#define MENU_H

#include "RedEstaciones.h"

class Menu {
private:
    RedEstaciones* redEstaciones;

public:
    Menu(RedEstaciones* redEstaciones);
    void mostrarMenu();
    void gestionarRedEstaciones();
    void gestionarEstacion();
    void agregarEstacion();
    void agregarSurtidor();
    void eliminarEstacion();
    void eliminarSurtidor();
    void consultarHistorico();
    void verificarFugas();
    void mostrarOpcionesRed();
    void mostrarOpcionesEstacion();
    void simularVentas();
};

#endif // MENU_H

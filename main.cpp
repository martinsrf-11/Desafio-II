#include <iostream>
#include "menu.h"
#include "RedEstaciones.h"

int main() {
    RedEstaciones* redEstaciones = new RedEstaciones();
    Menu menu(redEstaciones);
    menu.mostrarMenu();
    delete redEstaciones; // Liberar memoria al final
    return 0;
}



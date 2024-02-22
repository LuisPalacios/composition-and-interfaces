#include "DelegadoVisibilidad.h"
#include <iostream>

void Invisible::dibuja() {
    // No hace nada, el objeto es invisible.
}

void Visible::dibuja() {
    std::cout << "Dibujando un objeto en la pantalla." << std::endl;
}

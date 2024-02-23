#include "DelegadoVisibilidad.h"
#include <iostream>

void Invisible::dibuja()
{
    // No dibujar nada.
}

void Visible::dibuja()
{
    std::cout << "D";
    //std::cout << "Dibujando objeto." << std::endl;
}

#include "DelegadoActualizacion.h"
#include <iostream>

void Inamovible::actualiza() {
    // No se realiza ninguna acción, el objeto es inamovible.
}

void Movible::actualiza() {
    std::cout << "Actualizando la posición del objeto." << std::endl;
    // Aquí se añadiría el código para cambiar la posición del objeto.
}

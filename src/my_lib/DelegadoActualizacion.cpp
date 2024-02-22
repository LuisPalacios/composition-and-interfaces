#include "DelegadoActualizacion.h"
#include <iostream>
#include <algorithm>

void Inamovible::actualiza() {
    // No realizar ninguna acción.
}

Movible::Movible(Posicion& pos, Direccion& dir, Tamanio tamanio, int anchoPantalla, int altoPantalla)
    : _pos(pos), _dir(dir), _tamanio(tamanio), _anchoPantalla(anchoPantalla), _altoPantalla(altoPantalla) {}

void Movible::actualiza() {
    _pos.x += _dir.deltaX;
    _pos.y += _dir.deltaY;
    std::cout << "A";
    // std::cout << "Actualizando la posición del objeto." << std::endl;
    // Aquí se añadiría el código para cambiar la posición del objeto.
}

#include "DelegadoColision.h"
#include "Objeto.h" // Asegúrate de que esta clase está definida correctamente.
#include <iostream>

void Gaseoso::colision(Objeto objetos[]) {
    // Implementación de la colisión para un objeto gaseoso.
    // En este ejemplo, no se hace nada.
}

void Liquido::colision(Objeto objetos[]) {
    std::cout << "Comprobando colisión con objetos líquidos." << std::endl;
    // Aquí iría el código para gestionar colisiones de objetos líquidos.
}

void Solido::colision(Objeto objetos[]) {
    std::cout << "Comprobando colisión con objetos sólidos." << std::endl;
    // Aquí iría el código para gestionar colisiones de objetos sólidos.
}

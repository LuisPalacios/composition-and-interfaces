#include "DelegadoColision.h"
#include "Objeto.h"
#include <iostream>

bool DelegadoColision::colisionan( Objeto* obj1,  Objeto* obj2) {
    if (!obj1 || !obj2) return false;

    auto& pos1 = obj1->getPosicion();
    auto& tam1 = obj1->getTamanio();
    auto& pos2 = obj2->getPosicion();
    auto& tam2 = obj2->getTamanio();

    // Comprobar si hay superposición en el eje X
    bool colisionX = pos1.x < pos2.x + tam2.ancho && pos1.x + tam1.ancho > pos2.x;

    // Comprobar si hay superposición en el eje Y
    bool colisionY = pos1.y < pos2.y + tam2.alto && pos1.y + tam1.alto > pos2.y;

    // Si hay superposición en ambos ejes, los objetos han colisionado
    return colisionX && colisionY;
}

void Gaseoso::colision(Objeto* objeto, Objeto* otros[], int numOtros) {
    // Ejemplo: Gaseoso no reacciona a colisiones
}

void Liquido::colision(Objeto* objeto, Objeto* otros[], int numOtros) {
    for (int i = 0; i < numOtros; ++i) {
        if (colisionan(objeto, otros[i])) {
            std::cout << "Liquido colisionando con otro objeto." << std::endl;
            // Lógica específica de colisión para líquidos
        }
    }
}

void Solido::colision(Objeto* objeto, Objeto* otros[], int numOtros) {
    for (int i = 0; i < numOtros; ++i) {
        if (colisionan(objeto, otros[i])) {
            std::cout << "Solido colisionando con otro objeto." << std::endl;
            // Lógica específica de colisión para sólidos
        }
    }
}

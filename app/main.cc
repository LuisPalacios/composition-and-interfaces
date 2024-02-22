// Estándares
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Librerías externas
#include <spdlog/spdlog.h>

// Mis variables estáticas e includes
#include "config.hpp"
#include "Objeto.h"

const int SCREEN_WIDTH = 3840;
const int SCREEN_HEIGHT = 2160;


struct Posicion {
    int x, y;
};

struct Tamanio {
    int ancho, alto;
};

struct Direccion {
    int deltaX, deltaY;
};

// Aquí se añade lógica para mover el objeto rebotando en la pantalla
void moveObject(Objecto& obj, Posicion& pos, Direccion& dir, const Tamanio& tamanio, const int anchoPantalla, const int altoPantalla) {
    // Mover el objeto en su dirección actual
    pos.x += dir.deltaX;
    pos.y += dir.deltaY;

    // Comprobar colisiones con los bordes de la pantalla y rebotar si es necesario
    if (pos.x < 0 || pos.x + tamanio.ancho > anchoPantalla) {
        dir.deltaX = -dir.deltaX; // Invertir dirección en el eje X
        pos.x = std::max(0, std::min(pos.x, anchoPantalla - tamanio.ancho)); // Ajustar posición
    }
    if (pos.y < 0 || pos.y + tamanio.alto > altoPantalla) {
        dir.deltaY = -dir.deltaY; // Invertir dirección en el eje Y
        pos.y = std::max(0, std::min(pos.y, altoPantalla - tamanio.alto)); // Ajustar posición
    }

    // Actualizar el objeto (si es necesario)
    obj.actualiza();
}

bool colisionan(const Posicion& pos1, const Tamanio& tam1, const Posicion& pos2, const Tamanio& tam2) {
    // Comprobar si hay superposición en el eje X
    bool colisionX = pos1.x < pos2.x + tam2.ancho && pos1.x + tam1.ancho > pos2.x;

    // Comprobar si hay superposición en el eje Y
    bool colisionY = pos1.y < pos2.y + tam2.alto && pos1.y + tam1.alto > pos2.y;

    // Si hay superposición en ambos ejes, los objetos han colisionado
    return colisionX && colisionY;
}

/**
 * Punto de entrada principal
*/
int main(int argc, char **argv)
{
    // Mensaje de log de bienvenida
    const auto welcome_message =
        fmt::format("Bienvenido al programa {} v{}\n", project_name, project_version);
    spdlog::info(welcome_message);

    srand(static_cast<unsigned int>(time(0))); // Inicializar semilla aleatoria

    // Crear objetos
    Jugador jugador(30, 30); // Asumiendo que el constructor acepta tamaño
    Coche coche(40, 40);
    Humo humo(100, 100);
    Charco charco(200, 20);

    Posicion posJugador = {0, 0};
    Posicion posCoche = {100, 100};
    Posicion posHumo = {200, 200};
    Posicion posCharco = {300, 300};

    Tamanio tamanioJugador = {30, 30};
    Tamanio tamanioCoche = {40, 40};
    Tamanio tamanioHumo = {100, 100};
    Tamanio tamanioCharco = {200, 20};

    Direccion dirJugador = {1, 1}; // Por ejemplo, movimiento inicial diagonal
    Direccion dirCoche = {-1, 1};  // Otro ejemplo de movimiento inicial
    Direccion dirHumo = {1, 1}; // Por ejemplo, movimiento inicial diagonal

    const int anchoPantalla = 3840;
    const int altoPantalla = 2160;

    while (true) {
        moveObject(jugador, posJugador, dirJugador, tamanioJugador, anchoPantalla, altoPantalla);
        moveObject(coche, posCoche, dirCoche, tamanioCoche, anchoPantalla, altoPantalla);
        moveObject(humo, posHumo, dirHumo, tamanioHumo, anchoPantalla, altoPantalla);

        // Comprobar colisiones
        if (colisionan(posJugador, tamanioJugador, posCoche, tamanioCoche)) {
            std::cout << "\nJugador ha colisionado con Coche" << std::endl;
        }
        if (colisionan(posJugador, tamanioJugador, posHumo, tamanioHumo)) {
            std::cout << "\nJugador ha colisionado con Humo" << std::endl;
        }
        // ... [Agregar comprobaciones adicionales para otras colisiones] ...

        // Pausa breve para que el bucle no se ejecute demasiado rápido
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << ". ";
    }

    return 0;
}

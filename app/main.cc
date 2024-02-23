// Estándares
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>
#include <vector>

// Librerías externas
#include <spdlog/spdlog.h>

// Mis variables estáticas e includes
#include "Objeto.h"
#include "config.hpp"

/**
 * Punto de entrada principal
*/
int main(int argc, char **argv)
{
    // Mensaje de log de bienvenida
    const auto welcome_message = fmt::format("Bienvenido al programa {} v{}\n",
                                             project_name,
                                             project_version);
    spdlog::info(welcome_message);

    // Definir las dimensiones de la pantalla
    const int anchoPantalla = 3840;
    const int altoPantalla = 2160;

    // Inicializar posiciones y direcciones
    Posicion posJugador = {100, 100};
    Posicion posCoche = {300, 300};
    Posicion posHumo = {500, 500};
    Posicion posCharco = {700, 200};

    Direccion dirJugador = {1, 1};
    Direccion dirCoche = {-1, 1};
    Direccion dirHumo = {1, -1};
    Direccion dirCharco = {0, 0}; // Inamovible

    // Tamaños de los objetos
    Tamanio tamJugador = {30, 30};
    Tamanio tamCoche = {40, 40};
    Tamanio tamHumo = {100, 100};
    Tamanio tamCharco = {200, 20};

    // Crear delegados y objetos
    Objeto jugador(new Visible(),
                   new Movible(posJugador,
                               dirJugador,
                               tamJugador,
                               anchoPantalla,
                               altoPantalla),
                   new Solido(),
                   posJugador,
                   dirJugador);
    Objeto coche(
        new Visible(),
        new Movible(posCoche, dirCoche, tamCoche, anchoPantalla, altoPantalla),
        new Solido(),
        posCoche,
        dirCoche);
    Objeto humo(
        new Visible(),
        new Movible(posHumo, dirHumo, tamHumo, anchoPantalla, altoPantalla),
        new Gaseoso(),
        posHumo,
        dirHumo);
    Objeto charco(new Visible(),
                  new Inamovible(),
                  new Liquido(),
                  posCharco,
                  dirCharco);

    std::vector<Objeto *> objetos = {&jugador, &coche, &humo, &charco};

    // while (true) {
    //     for (auto& obj : objetos) {
    //         obj->actualiza();
    //         obj->dibuja();

    //         // Comprobar colisiones con otros objetos
    //         for (auto& otroObj : objetos) {
    //             if (obj != otroObj) {
    //                 // Aquí iría la lógica de detección de colisiones
    //                 std::cout << "." << std::flush;
    //             }
    //         }
    //     }

    //     // Pausa breve para hacer la simulación visible y no sobrecargar la CPU
    //     std::this_thread::sleep_for(std::chrono::milliseconds(100));
    // }
    while (true)
    {
        for (auto &obj : objetos)
        {
            obj->actualiza();
            obj->dibuja();
            obj->colisiona(objetos.data(), objetos.size());
        }
        std::cout << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}

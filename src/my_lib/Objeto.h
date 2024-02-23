#pragma once

#include "DelegadoActualizacion.h"
#include "DelegadoColision.h"
#include "DelegadoVisibilidad.h"

/**
 * @brief Clase base para objetos en el juego.
 */
class Objeto
{
    DelegadoVisibilidad *_v;
    DelegadoActualizacion *_a;
    DelegadoColision *_c;
    Posicion _pos;
    Direccion _dir;
    Tamanio _tamanio; // Añadir tamaño del objeto

public:
    Objeto(DelegadoVisibilidad *v,
           DelegadoActualizacion *a,
           DelegadoColision *c,
           Posicion pos,
           Direccion dir);
    ~Objeto();

    void actualiza();
    void dibuja();
    void colisiona(Objeto *objetos[], int numObjetos);

    // Métodos de acceso
    Posicion &getPosicion();
    Direccion &getDireccion();
    Tamanio &getTamanio();
};

// ... [Definiciones de Jugador, Coche, etc., si es necesario] ...

class Jugador : public Objeto
{
public:
    Jugador();
};

class Coche : public Objeto
{
public:
    Coche();
};

class Humo : public Objeto
{
public:
    Humo();
};

class Charco : public Objeto
{
public:
    Charco();
};

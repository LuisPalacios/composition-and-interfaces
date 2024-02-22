#pragma once

#include "DelegadoVisibilidad.h"
#include "DelegadoActualizacion.h"
#include "DelegadoColision.h"

/**
 * @brief Clase base para objetos en el juego.
 */
class Objeto {
    DelegadoVisibilidad*   _v;
    DelegadoActualizacion* _u;
    DelegadoColision*      _c;

public:
    Objeto(DelegadoVisibilidad* v, DelegadoActualizacion* u, DelegadoColision* c);
    void actualiza();
    void dibuja();
    void colisiona(Objeto objectos[]);
};

class Jugador : public Objeto {
public:
    Jugador();
};

class Coche : public Objeto {
public:
    Coche();
};

class Humo : public Objeto {
public:
    Humo();
};

class Charco : public Objeto {
public:
    Charco();
};

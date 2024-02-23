#pragma once

struct Posicion
{
    int x, y;
};

struct Direccion
{
    int deltaX, deltaY;
};

struct Tamanio
{
    int ancho, alto;
};

/**
 * @brief Clase base abstracta para actualizar estados de objetos.
 */
class DelegadoActualizacion
{
public:
    virtual ~DelegadoActualizacion()
    {
    } // Destructor virtual

    virtual void actualiza() = 0;
};

class Inamovible : public DelegadoActualizacion
{
public:
    void actualiza() override;
};

class Movible : public DelegadoActualizacion
{
    Posicion &_pos;
    Direccion &_dir;
    Tamanio _tamanio;
    int _anchoPantalla;
    int _altoPantalla;

public:
    Movible(Posicion &pos,
            Direccion &dir,
            Tamanio tamanio,
            int anchoPantalla,
            int altoPantalla);
    void actualiza() override;
};

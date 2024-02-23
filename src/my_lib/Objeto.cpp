#include "Objeto.h"

Objeto::Objeto(DelegadoVisibilidad *v,
               DelegadoActualizacion *a,
               DelegadoColision *c,
               Posicion pos,
               Direccion dir)
    : _v(v), _a(a), _c(c), _pos(pos), _dir(dir)
{
}

Objeto::~Objeto()
{
    delete _v;
    delete _a;
    delete _c;
}

void Objeto::actualiza()
{
    _a->actualiza();
}

void Objeto::dibuja()
{
    _v->dibuja();
}

void Objeto::colisiona(Objeto *objetos[], int numObjetos)
{
    _c->colision(this, objetos, numObjetos);
}

Posicion &Objeto::getPosicion()
{
    return _pos;
}

Direccion &Objeto::getDireccion()
{
    return _dir;
}

Tamanio &Objeto::getTamanio()
{
    return _tamanio;
}

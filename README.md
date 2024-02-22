# Composición e interfaces

![C++](https://img.shields.io/badge/C%2B%2B-11%2F14%2F17%2F20%2F23-blue)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
![Linux Build](https://github.com/franneck94/CppProjectTemplate/workflows/Ubuntu%20CI%20Test/badge.svg)
[![codecov](https://codecov.io/gh/franneck94/CppProjectTemplate/branch/master/graph/badge.svg)](https://codecov.io/gh/franneck94/CppProjectTemplate)

<br/>

## Introducción

En C++ es importante entender la recomendación de favorecer la 'composición de objetos' frente a la 'herencia de clases'. Este repositorio contiene el ejemplo de la sección **Composition and interfaces** del artículo de la [Wikipedia Composition over inheritance](https://en.wikipedia.org/wiki/Composition_over_inheritance).

Los ejemplos de C++ de esta sección demuestran el principio de utilizar la composición y las interfaces para lograr la reutilización del código y el polimorfismo. Debido a que el lenguaje C++ no tiene una palabra clave dedicada para declarar interfaces, vamos a usar la **herencia de una clase base abstracta pura**, que es **funcionalmente equivalente a las interfaces** proporcionadas en otros lenguajes, como Java.

Creamos las siguientes clases:

- Clase abstracta **DelegadoVisibilidad**, con las subclases **Invisible** y **Visible**, que simulan una forma de indicar cuando mostrar o no un objeto (instancia de **Objeto**) en pantalla .
- Clase abstracta **DelegadoActualizacion**, con las subclases **Inamovible** y **Movible**, que ofrecen una forma de mover el objeto en pantalla.
- Clase abstracta **DelegadoColision**, con las subclases **Solido**, **Liquido** y **Gaseoso**, que ofrecen una forma de identificar cómo colisionarán entre sí dos objetos.
- Clase **Objeto** con miembros para controlar su visibilidad (usando un *DelegadoVisibilidad*), movilidad (usando un *DelegadoActualizacion*), y colision (usando un DelegadoColision). Esta clase tiene métodos que delegan en sus miembros, por ejemplo, *actualiza()* simplemente llama a un método del *DelegadoActualizacion*. 
- Un par de subclases concretas **Jugador** y **Humo** que heradan de *Objeto*

<br/>

---

```c++
class DelegadoVisibilidad
{
public:
    virtual void dibuja() = 0;
};

class Invisible : public DelegadoVisibilidad
{
public:
    virtual void dibuja() override {
        // no-op
    }
};

class Visible : public DelegadoVisibilidad
{
public:
    virtual void dibuja() override {
        // código para dibujar un modelo en la posición del objeto. 
    }
};

class DelegadoActualizacion
{
public:
    virtual void actualiza() = 0;
};

class Inamovible : public DelegadoActualizacion
{
public:
    virtual void actualiza() override {
        // no-op
    }
};

class Movible : public DelegadoActualizacion
{
public:
    virtual void actualiza() override {
        // código para actualizar la posición en pantalla del objeto
    }
};

class DelegadoColision
{
public:
    virtual void colision(Objecto objectos[]) = 0;
};

class Gaseoso : public DelegadoColision
{
public:
    virtual void colision(Objecto objectos[]) override {
        // no-op
    }
};

class Liquido : public DelegadoColision
{
public:
    virtual void colision(Objecto objectos[]) override {
        // código comprueba y reaciona a la colisión con otro objeto
    }
};

class Solido : public DelegadoColision
{
public:
    virtual void colision(Objecto objectos[]) override {
        // código comprueba y reaciona a la colisión con otro objeto
    }
};


class Objecto
{
    DelegadoVisibilidad*   _v;
    DelegadoActualizacion* _u;
    DelegadoColision*      _c;

public:
    Object(DelegadoVisibilidad* v, DelegadoActualizacion* u, DelegadoColision* c)
        : _v(v)
        , _u(u)
        , _c(c)
    {}

    void actualiza() {
        _u->actualiza();
    }

    void dibuja() {
        _v->dibuja();
    }

    void colisiona(Objecto objectos[]) {
        _c->colisiona(objectos);
    }
};

class Jugador : public Objecto
{
public:
    Jugador()
        : Objecto(new Visible(), new Movible(), new Solido())
    {}

    // ...
};

class Humo : public Objecto
{
public:
    Humo()
        : Object(new Visible(), new Movible(), new Gaseoso())
    {}

    // ...
};
```



<br/>

## Referencias

Repositorio creado desde el template [CppPlantilla](https://github.com/LuisPalacios/CppPlantilla).
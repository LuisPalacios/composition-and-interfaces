#pragma once

class Objeto; // Declaración adelantada

/**
 * @brief Clase base abstracta para manejar colisiones de objetos.
 */
class DelegadoColision
{
public:
    /**
     * @brief Destructor virtual para asegurar una correcta limpieza en clases derivadas.
     */
    virtual ~DelegadoColision()
    {
    }

    /**
     * @brief Método abstracto para manejar colisiones.
     *
     * Este método debe ser implementado por las clases derivadas para definir
     * cómo manejan las colisiones.
     *
     * @param objetos Array de punteros a los objetos con los que puede colisionar.
     * @param numObjetos Número de elementos en el array de objetos.
     */
    //virtual void colision(Objeto* objetos[], int numObjetos) = 0;
    virtual void colision(Objeto *objeto, Objeto *otros[], int numOtros) = 0;

    // Método estático para comprobar si dos objetos colisionan
    static bool colisionan(Objeto *obj1, Objeto *obj2);
    //    static bool colisionan(objeto->getPosicion(), objeto->getTamanio(), otros[i]->getPosicion(), otros[i]->getTamanio())) {
};

/**
 * @brief Clase que representa un comportamiento de colisión para objetos gaseosos.
 */
class Gaseoso : public DelegadoColision
{
public:
    //void colision(Objeto* objetos[], int numObjetos) override;
    void colision(Objeto *objeto, Objeto *otros[], int numOtros) override;
};

/**
 * @brief Clase que representa un comportamiento de colisión para objetos líquidos.
 */
class Liquido : public DelegadoColision
{
public:
    //void colision(Objeto* objetos[], int numObjetos) override;
    void colision(Objeto *objeto, Objeto *otros[], int numOtros) override;
};

/**
 * @brief Clase que representa un comportamiento de colisión para objetos sólidos.
 */
class Solido : public DelegadoColision
{
public:
    //void colision(Objeto* objetos[], int numObjetos) override;
    void colision(Objeto *objeto, Objeto *otros[], int numOtros) override;
};

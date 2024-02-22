#pragma once

class Objeto; // Declaración adelantada

/**
 * @brief Clase base abstracta para manejar colisiones.
 */
class DelegadoColision {
public:
    virtual void colision(Objeto objetos[]) = 0;
};

class Gaseoso : public DelegadoColision {
public:
    void colision(Objeto objetos[]) override;
};

class Liquido : public DelegadoColision {
public:
    void colision(Objeto objetos[]) override;
};

class Solido : public DelegadoColision {
public:
    void colision(Objeto objetos[]) override;
};

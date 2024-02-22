#pragma once

/**
 * @brief Clase base abstracta para actualizar estados de objetos.
 */
class DelegadoActualizacion {
public:
    virtual void actualiza() = 0;
};

class Inamovible : public DelegadoActualizacion {
public:
    void actualiza() override;
};

class Movible : public DelegadoActualizacion {
public:
    void actualiza() override;
};

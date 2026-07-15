#ifndef CARTABONUS_H
#define CARTABONUS_H

#include "carta.h"

class CartaBonus : public Carta
{
public:
    CartaBonus(int valor, float volumeEfeitos, bool mutar);
    void AoCombinar(Jogo *jogo) override;

private:
    const float PONTOS_EXTRAS = 2.5; // ganha três pontos
};

#endif // CARTABONUS_H

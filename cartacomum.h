#ifndef CARTACOMUM_H
#define CARTACOMUM_H

#include "carta.h"

class CartaComum : public Carta
{
public:
    CartaComum(int valor, float volumeEfeitos, bool mutar);
    void AoCombinar(Jogo *jogo) override;

private:
    const float PONTO = 0.5;
};

#endif // CARTACOMUM_H

#ifndef CARTAARMADILHA_H
#define CARTAARMADILHA_H

#include "carta.h"

class CartaArmadilha : public Carta
{
public:
    CartaArmadilha(int valor, float volumeEfeitos, bool mutar);
    void AoCombinar(Jogo *jogo) override;

private:
    const float PENALIDADE = 2.5; // perde dois pontos
};

#endif // CARTAARMADILHA_H

#ifndef FUNCOES_H
#define FUNCOES_H

#include <string>
#include "settings.h"

using namespace std;

void lerArquivo(string nomeArquivo, Settings &settings);
void salvarArquivo(string nomeArquivo, Settings &settings);

#endif // FUNCOES_H

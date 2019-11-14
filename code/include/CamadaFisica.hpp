// "Copyright [2018] <Copyright Owner>"  [legal/copyright]

#ifndef CAMADAFISICA_HPP_
#define CAMADAFISICA_HPP_

#include <iostream>
#include <string>

# include <bitset>
# include <cstring>

# include "gtest/gtest.h"

#include <math.h>

using namespace std;

#define BITS 8
#define CODIFICACAO 1

void AplicacaoTransmissora(void);
void CamadaDeAplicacaoTransmissora(string mensagem);
void CamadaFisicaTransmissora(int quadro[]);
int* CamadaFisicaTransmissoraCodificacaoBinaria(int quadro[]);
int* CamadaFisicaTransmissoraCodificacaoManchester(int* quadro);
int* CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(int quadro[]);
void MeioDeComunicacao(int fluxoBrutoDeBits[]);
void CamadaFisicaReceptora(int quadro[]);
int* CamadaFisicaReceptoraDecodificacaoBinaria(int quadro[]);
int* CamadaFisicaReceptoraDecodificacaoManchester(int quadro[]);
int* CamadaFisicaReceptoraDecodificacaoManchesterDiferencial(int quadro[]);
void CamadaDeAplicacaoReceptora(int quadro[]);
void AplicacaoReceptora(string mensagem);

#endif  // CAMADAFISICA_HPP_

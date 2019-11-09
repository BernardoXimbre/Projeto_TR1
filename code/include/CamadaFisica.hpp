// "Copyright [2018] <Copyright Owner>"  [legal/copyright]

#ifndef CAMADAFISICA_HPP_
#define CAMADAFISICA_HPP_

#include <iostream>
using namespace std;

#define TAMANHO_QUADRO 8

int* CamadaFisicaTransmissoraCodificacaoBinaria(int quadro[]);
int* CamadaFisicaReceptoraCodificacaoBinaria(int quadro[]);

int* CamadaFisicaTransmissoraCodificacaoManchester(int quadro[]);
int* CamadaFisicaReceptoraCodificacaoManchester(int quadro[]);

int* CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(int quadro[]);
int* CamadaFisicaReceptoraCodificacaoManchesterDiferencial(int quadro[]);

#endif  // CAMADAFISICA_HPP_

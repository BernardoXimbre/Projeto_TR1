// Copyright [2019] <Copyright Owner>

#ifndef CAMADAFISICA_HPP_
#define CAMADAFISICA_HPP_

# include <iostream>
using namespace std;
#include <string>

void AplicacaoTransmissora(void);
// fim do metodo AplicacaoTransmissora

void CamadaDeAplicacaoTransmissora(string mensagem);
// fim do metodo CamadaDeAplicacaoTransmissora

void CamadaFisicaTransmissora(int quadro[]);
// fim do metodo CamadaFisicaTransmissora

int* CamadaFisicaTransmissoraCodificacaoBinaria(int quadro[]);
// fim do metodo CamadaFisicaTransmissoraCodificacaoBinaria

int* CamadaFisicaTransmissoraCodificacaoManchester(int quadro[]);
// fim do metodo CamadaFisicaTransmissoraCodificacaoManchester

int* CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(int quadro[]);
// fim do CamadaFisicaTransmissoraCodificacaoManchesterDiferencial
/* Este metodo simula a transmissao da informacao no meio de
* comunicacao, passando de um pontoA (transmissor) para um
* ponto B (receptor)
*/

void MeioDeComunicacao(int fluxoBrutoDeBits[]);
// fim do metodo MeioDeTransmissao

void CamadaFisicaReceptora(int quadro[]);
// fim do metodo CamadaFisicaTransmissora

int* CamadaFisicaReceptoraCodificacaoBinaria(int quadro[]);
// fim do metodo CamadaFisicaReceptoraDecodificacaoBinaria

int* CamadaFisicaReceptoraCodificacaoManchester(int quadro[]);
// fim do metodo CamadaFisicaReceptoraDecodificacaoManchester

int* CamadaFisicaReceptoraCodificacaoManchesterDiferencial(int quadro[]);
// fim do CamadaFisicaReceptoraDecodificacaoManchesterDiferencial

void CamadaDeAplicacaoReceptora(int quadro[]);
// fim do metodo CamadaDeAplicacaoReceptora

void AplicacaoReceptora(string mensagem);
// fim do metodo AplicacaoReceptora

#endif  // CAMADAFISICA_HPP_

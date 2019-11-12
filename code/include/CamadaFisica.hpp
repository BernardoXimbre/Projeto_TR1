// "Copyright [2018] <Copyright Owner>"  [legal/copyright]

#ifndef CAMADAFISICA_HPP_
#define CAMADAFISICA_HPP_

#include <iostream>
#include <string>

using std::string;

#define TAMANHO_QUADRO 8

void AplicacaoTransmissora(void);
void CamadaDeAplicacaoTransmissora(string mensagem);
void CamadaFisicaTransmissora(int quadro[]);
int* CamadaFisicaTransmissoraCodificacaoBinaria(int quadro[]);
int* CamadaFisicaTransmissoraCodificacaoManchester(int quadro[]);
int* CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(int quadro[]);
void MeioDeComunicacao(int fluxoBrutoDeBits[]);
void CamadaFisicaReceptora(int quadro[]);
int* CamadaFisicaReceptoraDecodificacaoBinaria(int quadro[]);
int* CamadaFisicaReceptoraDecodificacaoManchester(int quadro[]);
int* CamadaFisicaReceptoraDecodificacaoManchesterDiferencial(int quadro[]);
void CamadaDeAplicacaoReceptora(int quadro[]);
void AplicacaoReceptora(string mensagem);

#endif  // CAMADAFISICA_HPP_

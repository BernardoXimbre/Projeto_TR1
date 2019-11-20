// "Copyright [2019] <Copyright Owner>"  [legal/copyright]

#ifndef CAMADAFISICA_HPP_
#define CAMADAFISICA_HPP_

# include <iostream>
# include <string>
# include <bitset>
# include <cstring>
# include <cmath>
# include <ctime>

#define BITS 8
#define PORCENTAGEM_ERRO 100
#define CODIFICACAO 1
//  0 - Binaria
//  1 - Manchester
//  2 - ManchesterDiferencial


using namespace std;

void AplicacaoTransmissora(void);
void CamadaDeAplicacaoTransmissora(string mensagem);
void CamadaFisicaTransmissora(int quadro[], int *tamanho);
int* CamadaFisicaTransmissoraCodificacaoBinaria(int quadro[], int *tamanho);
int* CamadaFisicaTransmissoraCodificacaoManchester(int quadro[], int *tamanho);
int* CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(int quadro[], int *tamanho);
void MeioDeComunicacao(int fluxoBrutoDeBits[], int *tamanho);
void CamadaFisicaReceptora(int quadro[], int *tamanho);
int* CamadaFisicaReceptoraDecodificacaoBinaria(int quadro[], int *tamanho);
int* CamadaFisicaReceptoraDecodificacaoManchester(int quadro[], int *tamanho);
int* CamadaFisicaReceptoraDecodificacaoManchesterDiferencial(int quadro[], int *tamanho);
void CamadaDeAplicacaoReceptora(int quadro[], int *tamanho);
void AplicacaoReceptora(string mensagem);

#endif  // CAMADAFISICA_HPP_

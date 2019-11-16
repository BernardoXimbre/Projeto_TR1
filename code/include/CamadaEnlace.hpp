// "Copyright [2019] <Copyright Owner>"  [legal/copyright]

#ifndef CAMADAENLACE_HPP_
#define CAMADAENLACE_HPP_

using namespace std;

void CamadaEnlaceTransmissora(int quadro[], int *tamanho);
void CamadaEnlaceTransmissoraEnquadramento(int quadro[], int *tamanho);
int* CamadaEnlaceTransmissoraEnquadramentoContagemDeCaracteres(int quadro[], int *tamanho);
int* CamadaEnlaceTransmissoraEnquadramentoInsercaoDeBytes(int quadro[], int *tamanho);
int* CamadaEnlaceTransmissoraEnquadramentoInsercaoDeBits(int quadro[], int *tamanho);
int* CamadaEnlaceTransmissoraEnquadramentoViolacaoDaCamadaFisica(int quadro[], int *tamanho);

void CamadaEnlaceReceptora(int quadro[], int *tamanho);
void CamadaEnlaceReceptoraEnquadramento(int quadro[], int *tamanho);
int* CamadaEnlaceReceptoraEnquadramentoContagemDeCaracteres(int quadro[], int *tamanho);
int* CamadaEnlaceReceptoraEnquadramentoInsercaoDeBytes(int quadro[], int *tamanho);
int* CamadaEnlaceReceptoraEnquadramentoInsercaoDeBits(int quadro[], int *tamanho);
int* CamadaEnlaceReceptoraEnquadramentoViolacaoDaCamadaFisica(int quadro[], int *tamanho);

void CamadaEnlaceTransmissoraControleDeErro(int quadro[], int *tamanho);
void CamadaEnlaceTransmissoraControleDeErroBitParidadePar(int quadro[], int *tamanho);
void CamadaEnlaceTransmissoraControleDeErroBitParidadeImpar(int quadro[], int *tamanho);
void CamadaEnlaceTransmissoraControleDeErroCRC(int quadro[], int *tamanho);
void CamadaEnlaceTransmissoraControleDeErroCodigoDeHamming(int quadro[], int *tamanho);

void CamadaEnlaceReceptoraControleDeErro(int quadro[], int *tamanho);
void CamadaEnlaceReceptoraControleDeErroBitDeParidadePar(int quadro[], int *tamanho);
void CamadaEnlaceReceptoraControleDeErroBitDeParidadeImpar(int quadro[], int *tamanho);
void CamadaEnlaceReceptoraControleDeErroCRC(int quadro[], int *tamanho);
void CamadaEnlaceReceptoraControleDeErroCodigoDeHamming(int quadro[], int *tamanho);

void CamadaEnlaceTransmissoraControleDeFluxo(int quadro[], int *tamanho);
void CamadaEnlaceReceptoraControleDeFluxo(int quadro[], int *tamanho);

#endif  // CAMADAENLACE_HPP_

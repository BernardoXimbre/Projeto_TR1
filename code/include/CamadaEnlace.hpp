// "Copyright [2019] <Copyright Owner>"  [legal/copyright]

#ifndef CAMADAENLACE_HPP_
#define CAMADAENLACE_HPP_

using namespace std;

#define ENQUADRAMENTO 0
#define CONTROLE_ERRO 1

void CamadaEnlaceTransmissora(int quadro[], int *tamanho);
void CamadaEnlaceTransmissoraEnquadramento(int quadro[], int *tamanho);
int* CamadaEnlaceTransmissoraEnquadramentoContagemDeCaracteres(int quadro[], int *tamanho);
int* CamadaEnlaceTransmissoraEnquadramentoInsercaoDeBytes(int quadro[], int *tamanho);
int* CamadaEnlaceTransmissoraEnquadramentoInsercaoDeBits(int quadro[], int *tamanho);
int* CamadaEnlaceTransmissoraEnquadramentoViolacaoDaCamadaFisica(int quadro[], int *tamanho);

void CamadaEnlaceTransmissoraControleDeErro(int quadro[], int *tamanho);
int* CamadaEnlaceTransmissoraControleDeErroBitParidadePar(int quadro[], int *tamanho);
int* CamadaEnlaceTransmissoraControleDeErroBitParidadeImpar(int quadro[], int *tamanho);
int* CamadaEnlaceTransmissoraControleDeErroCRC(int quadro[], int *tamanho);
int* CamadaEnlaceTransmissoraControleDeErroCodigoDeHamming(int quadro[], int *tamanho);


void CamadaEnlaceReceptora(int quadro[], int *tamanho);
void CamadaEnlaceReceptoraEnquadramento(int quadro[], int *tamanho);
int* CamadaEnlaceReceptoraEnquadramentoContagemDeCaracteres(int quadro[], int *tamanho);
int* CamadaEnlaceReceptoraEnquadramentoInsercaoDeBytes(int quadro[], int *tamanho);
int* CamadaEnlaceReceptoraEnquadramentoInsercaoDeBits(int quadro[], int *tamanho);
int* CamadaEnlaceReceptoraEnquadramentoViolacaoDaCamadaFisica(int quadro[], int *tamanho);

void CamadaEnlaceReceptoraControleDeErro(int quadro[], int *tamanho);
int* CamadaEnlaceReceptoraControleDeErroBitDeParidadePar(int quadro[], int *tamanho, bool *verificador);
int* CamadaEnlaceReceptoraControleDeErroBitDeParidadeImpar(int quadro[], int *tamanho, bool *verificador);
int* CamadaEnlaceReceptoraControleDeErroCRC(int quadro[], int *tamanho, bool *verificador);
int* CamadaEnlaceReceptoraControleDeErroCodigoDeHamming(int quadro[], int *tamanho, bool *verificador);

void CamadaEnlaceTransmissoraControleDeFluxo(int quadro[], int *tamanho);
void CamadaEnlaceReceptoraControleDeFluxo(int quadro[], int *tamanho);

#endif  // CAMADAENLACE_HPP_

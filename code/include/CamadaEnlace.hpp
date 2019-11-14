// "Copyright [2019] <Copyright Owner>"  [legal/copyright]

#ifndef CAMADAENLACE_HPP_
#define CAMADAENLACE_HPP_


void CamadaEnlaceTransmissora(int quadro[]);
void CamadaEnlaceTransmissoraEnquadramento(int quadro[]);
int* CamadaEnlaceTransmissoraEnquadramentoContagemDeCaracteres(int quadro[]);
int* CamadaEnlaceTransmissoraEnquadramentoInsercaoDeBytes(int quadro[]);
int* CamadaEnlaceTransmissoraEnquadramentoInsercaoDeBits(int quadro[]);
int* CamadaEnlaceTransmissoraEnquadramentoViolacaoDaCamadaFisica(int quadro[]);

void CamadaEnlaceReceptora(int quadro[]);
void CamadaEnlaceReceptoraEnquadramento(int quadro[]);
int* CamadaEnlaceReceptoraEnquadramentoContagemDeCaracteres(int quadro[]);
int* CamadaEnlaceReceptoraEnquadramentoInsercaoDeBytes(int quadro[]);
int* CamadaEnlaceReceptoraEnquadramentoInsercaoDeBits(int quadro[]);
int* CamadaEnlaceReceptoraEnquadramentoViolacaoDaCamadaFisica(int quadro[]);

void CamadaEnlaceTransmissoraControleDeErro(int quadro[]);
void CamadaEnlaceTransmissoraControleDeErroBitParidadePar(int quadro[]);
void CamadaEnlaceTransmissoraControleDeErroBitParidadeImpar(int quadro[]);
void CamadaEnlaceTransmissoraControleDeErroCRC(int quadro[]);
void CamadaEnlaceTransmissoraControleDeErroCodigoDeHamming(int quadro[]);

void CamadaEnlaceReceptoraControleDeErro(int quadro[]);
void CamadaEnlaceReceptoraControleDeErroBitDeParidadePar(int quadro[]);
void CamadaEnlaceReceptoraControleDeErroBitDeParidadeImpar(int quadro[]);
void CamadaEnlaceReceptoraControleDeErroCRC(int quadro[]);
void CamadaEnlaceReceptoraControleDeErroCodigoDeHamming(int quadro[]);

void CamadaEnlaceTransmissoraControleDeFluxo(int quadro[]);
void CamadaEnlaceReceptoraControleDeFluxo(int quadro[]);

#endif  // CAMADAENLACE_HPP_

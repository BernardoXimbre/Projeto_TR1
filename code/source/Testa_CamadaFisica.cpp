// "Copyright [2018] <Copyright Owner>"  [legal/copyright]

#include "gtest/gtest.h"
#include "CamadaFisica.hpp"

int main(int argc, char **argv) {
::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
TEST(ABERTURA_ARQUIVO, arquivo_inexistente) {
    int quadro[]= {1};
    ASSERT_EQ(1, (CamadaFisicaTransmissoraCodificacaoBinaria(quadro))[0]);
}
/*
TEST(QUANTIDADE_DE_LINHAS, sem_linhas_e_comentarios) {
    char name[]="sem_linhas_e_comentarios.c";
    ASSERT_EQ(0, Nline(name));
}
*/

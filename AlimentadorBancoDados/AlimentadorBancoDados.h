#ifndef _ALIMENTADOR_BANCO_DADOS
#define _ALIMENTADOR_BANCO_DADOS

#include <vector>
#include "../Logistica/Logistica.h"
#include "../ListaVeiculos/ListaVeiculos.h"

using namespace std;

/**
 * \brief Alimenta o banco de dados, atualmente só suporta arquivos em formato CSV.
*/
class AlimentadorBancoDados
{
    public:
        /**
         * \brief Lê uma linha de um arquivo CSV, considerando possíveis strings abertas.
         * \param linha A linha a ser lida.
         * \param string_aberta Uma referência a uma variável boolena que indica se uma string está aberta.
         * \return Um vetor contendo os campos da linha.
         */
        static vector<string> lerLinha(string linha, bool& string_aberta);

        /**
         * \brief Alimenta um sistema de logística com dados de um arquivo CSV.
         * \param path O caminho para o arquivo CSV.
         * \param logistica Um ponteiro para o objeto de logística a ser alimentado.
         * \param veiculos Um ponteiro para a lista de veículos, que pode ser NULL.
         * \param maximo_de_linhas O número máximo de linhas a serem lidas do arquivo (padrão é ler todas as linhas).
         */
        static void alimentarComCSV(string path, Logistica* logistica, ListaVeiculos* veiculos = NULL, uint64_t maximo_de_linhas = UINT64_MAX);

};

#endif
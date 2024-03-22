#include <iostream>
#include <string.h>
#include "Veiculos.h"

using namespace std;

Veiculo::Veiculo()
{
    memset(this->ano, '\0', 21);
    this->capacidade = 0;
    memset(this->chassi, '\0', 21);
    memset(this->localização, '\0', 41);
    memset(this->modelo, '\0', 21);
    memset(this->tipo, '\0', 21);
}

char* Veiculo::getTipo()
{
    return this->tipo;
}
void Veiculo::setTipo(const char* tipo)
{
    if(strlen(tipo) > 20){
        cout << "Erro: máximo de caracteres é 20" << endl;
        return;
    }

    strcpy(this->tipo, tipo);
}

int Veiculo::getCapacidade()
{
    return this->capacidade;
}
void Veiculo::setCapacidade(int capacidade)
{
    this->capacidade = capacidade;
}

char* Veiculo::getAno()
{
    return this->ano;
}
void Veiculo::setAno(const char* ano)
{
    if(strlen(ano) > 4){
        cout << "Erro: máximo de caracteres é 4" << endl;
        return;
    }

    strcpy(this->ano, ano);
}

char* Veiculo::getChassi()
{
    return this->chassi;
}
void Veiculo::setChassi(const char* chassi)
{
    if(strlen(chassi) > 20){
        cout << "Erro: máximo de caracteres é 20" << endl;
        return;
    }
    
    strcpy(this->chassi, chassi);
}

char* Veiculo::getModelo()
{
    return this->modelo;
}
void Veiculo::setModelo(const char* modelo)
{
    if(strlen(modelo) > 20){
        cout << "Erro: máximo de caracteres é 20" << endl;
        return;
    }

    strcpy(this->modelo, modelo);
}

char* Veiculo::getLocalização()
{
    return this->localização;
}
void Veiculo::setLocalização(const char* localização)
{
    if(strlen(localização) > 20){
        cout << "Erro: máximo de caracteres é 40" << endl;
        return;
    }
    
    strcpy(this->localização, localização);
}
#include <iostream>
#include <string.h>
#include "Clientes.h"

using namespace std;

Cliente::Cliente()
{
    memset(this->id, '\0', 10);
    memset(this->nome ,'\0', 30);
    memset(this->rg, '\0', 11);
    memset(this->cpf, '\0', 15);
    this->idade = 0;
}

char* Cliente::getId()
{
    return this->id;
}
void  Cliente::setId(const char* id)
{
    if(strlen(id) > 9){
        cout << "Erro: o máximo de caracteres é 9" << endl;
        return;
    }

    strcpy(this->id, id);
}

char* Cliente::getNome()
{
    return this->nome;
}
void Cliente::setNome(const char* nome)
{
    if(strlen(nome) > 29){
        cout << "Erro: o máximo de caracteres é 29" << endl;
        return;
    }

    strcpy(this->nome, nome);
}

char* Cliente::getRg()
{
    return this->rg;
}
void Cliente::setRg(const char* rg)
{
    if(strlen(rg) > 10){
        cout << "Erro: o máximo de caracteres é 10" << endl;
        return;
    }

    strcpy(this->rg, rg);
}

char* Cliente::getCpf()
{
    return this->cpf;
}
void Cliente::setCpf(const char* cpf)
{
    if(strlen(cpf) > 14){
        cout << "Erro: o máximo de caracteres é 14" << endl;
        return;
    }

    strcpy(this->cpf, cpf);
}

int Cliente::getIdade()
{
    return this->idade;
}
void Cliente::setIdade(int idade)
{
    if(idade < 18){
        cout << "É necessário ser maior de idade" << endl;
        return;
    }

    this->idade = idade;
}
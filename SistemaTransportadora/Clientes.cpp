#include <iostream>
#include <string>
#include "Clientes.h"

using namespace std;

Cliente::Cliente()
{
    this->id = "\0";
    this->nome = "\0";
    this->rg = "\0";
    this->cpf = "\0";
    this->idade = 0;
}

Cliente::~Cliente()
{
    cout << "limpando memória.." << endl;
}

string Cliente::getId()
{
    return this->id;
}
int Cliente::setId(const string id)
{
    if(id.length() != 10){
        cout << "Id deve ter 10 caracteres" << endl;
        return 0;
    }

    this->id = id;

    return 1;
}

string Cliente::getNome()
{
    return this->nome;
}
int Cliente::setNome(const string nome)
{
    if(nome.length() > 50){
        cout << "Nome deve ter no máximo 50 caracteres" << endl;
        return 0;
    }

    this->nome = nome;

    return 1;
}

string Cliente::getRg()
{
    return this->rg;
}
int Cliente::setRg(const string rg)
{
    if(rg.length() != 10){
        cout << "RG deve ter 10 caracteres" << endl;
        return 0;
    }

    this->rg = rg;

    return 1;
}

string Cliente::getCpf()
{
    return this->cpf;
}
int Cliente::setCpf(const string cpf)
{
    if(cpf.length() != 14){
        cout << "Cpf deve ter 14 caracteres" << endl;
        return 0;
    }

    if(cpf[3] != '.' || cpf[7] != '.' || cpf[11] != '-'){
        cout << "Cpf deve seguir o seguinte formato: ";
        cout << "xxx.xxx.xxx-xx" << endl;
        return 0;
    }

    this->cpf = cpf;

    return 1;
}

int Cliente::getIdade()
{
    return this->idade;
}
int Cliente::setIdade(int idade)
{
    if(idade < 0){
        cout << "Idade negativa não permitida" << endl;
        return 0;
    }

    this->idade = idade;

    return 1;
}
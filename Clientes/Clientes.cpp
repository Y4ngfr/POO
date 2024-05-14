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

Cliente::Cliente(
    string id,
    string nome,
    string rg,
    string cpf,
    int idade
)
{
    this->id = id;
    this->nome = nome;
    this->rg = rg;
    this->cpf = cpf;
    this->idade = idade;
}

Cliente::~Cliente()
{
    clog << "Limpando memória..." << endl;
}

string Cliente::getId()
{
    return this->id;
}
int Cliente::setId(const string id)
{
    if(id.length() != 10){
        cerr << "Id deve ter 10 caracteres" << endl;
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
        cerr << "Nome deve ter no máximo 50 caracteres" << endl;
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
        cerr << "RG deve ter 10 caracteres" << endl;
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
        cerr << "Cpf deve ter 14 caracteres" << endl;
        return 0;
    }

    if(cpf[3] != '.' || cpf[7] != '.' || cpf[11] != '-'){
        cerr << "Cpf deve seguir o seguinte formato: ";
        cerr << "xxx.xxx.xxx-xx" << endl;
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
        cerr << "Idade negativa não permitida" << endl;
        return 0;
    }

    this->idade = idade;

    return 1;
}

ostream& operator<<(ostream& ostr, const Cliente& cliente)
{
    ostr << "Cpf: " << cliente.cpf << endl;
    ostr << "Id: " << cliente.id << endl;
    ostr << "Idade: " << cliente.idade << endl;
    ostr << "Nome: " << cliente.nome << endl;
    ostr << "Rg: " << cliente.rg << endl;
    ostr << endl;


    return ostr;
}

bool operator==(const Cliente& este, const Cliente& outro)
{
    if(
        este.cpf == outro.cpf &&
        este.id == outro.id &&
        este.idade == outro.idade &&
        este.nome == outro.nome &&
        este.rg == outro.rg
    ){
        return true;
    }

    return false;
}
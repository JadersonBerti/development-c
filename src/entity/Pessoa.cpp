#include "Pessoa.h";
#include <string.h>

using namespace std;

Pessoa::Pessoa(){
	id = 0;
	nome = "";
	sobrenome = "";
}

int Pessoa::getId(){
	return id;
}

void Pessoa::setId(int id){
	this->id = id;
}

string Pessoa::getNome(){
	return nome;
}

void Pessoa::setNome(string nome){
	this->nome = nome;
}

string Pessoa::getSobrenome(){
	return sobrenome;
}

void Pessoa::setSobrenome(string sobrenome){
	this->sobrenome = sobrenome;
}

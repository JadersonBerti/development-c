#include "Pessoa.h"

#include <sstream>
#include <string>

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
	return this->sobrenome;
}

void Pessoa::setSobrenome(string sobrenome){
	this->sobrenome = sobrenome;
}

bool Pessoa::isEmpty(){
	return this->nome == "" && this->sobrenome == "";
}

bool Pessoa::equals(int id){
	return this->id == id;
}

string Pessoa::toString(){
	stringstream conversor;
	conversor << this->id;
	return "id:" + conversor.str() +  ";nome:" + this->nome + ";sobrenome:" + this->sobrenome;
}

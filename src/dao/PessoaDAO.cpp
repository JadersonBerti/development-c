#include "PessoaDAO.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

bool PessoaDAO::insert(Pessoa pessoa){
	try{
		bool hasFolder = mkdir("db-object");
		hasFolder ? cout << "Pasta Existente" : cout << "Pasta Criada";

		ofstream ofs("db-object/pessoa.txt", fstream::app);
		ofs << pessoa;
		ofs.close();
		return true;
	}catch (const exception& e) {
		printf(e.what());
		return false;
	}
}

bool PessoaDAO::update(Pessoa pessoa){
	vector<Pessoa> pessoas = findAll();
	int size = pessoas.size();
	for(int i = 0;i < size;i++){
		if(pessoas[i].getId() == pessoa.getId()){
			pessoas[i] = pessoa;
		}
	}

	if(remove("db-object/pessoa.txt") != 0){
		cout << "Erro: " << strerror(errno) << endl;
	}else{
		cout << "Arquivo excluído com sucesso" << endl;
	}

	for(int i = 0;i < size;i++){
		insert(pessoas[i]);
	}

	return true;
}

bool PessoaDAO::removee(int pessoaId){
	vector<Pessoa> pessoas = findAll();
	vector<Pessoa> pessoasAtaulizadas;

	int size = pessoas.size();
	for(int i = 0;i < size;i++){
		if(pessoas[i].getId() != pessoaId){
			pessoasAtaulizadas.push_back(pessoas[i]);
		}
	}

	if(remove("db-object/pessoa.txt") != 0){
		cout << "Erro: " << strerror(errno) << endl;
	}else{
		cout << "Arquivo excluído com sucesso" << endl;
	}

	size = pessoasAtaulizadas.size();
	for(int i = 0;i < size;i++){
		insert(pessoasAtaulizadas[i]);
	}

	return true;
}

Pessoa PessoaDAO::findById(int pessoaId){
	Pessoa pessoa = Pessoa();

	try{
		ifstream findObject;
		string linha;

		findObject.open("db-object/pessoa.txt");
		while(!findObject.eof()){
			getline(findObject, linha);
			vector<string> dados = parseValueToPessoa(linha);

			cout << dados[0] << endl;

			if(!dados[0].empty()){
				if(atoi(dados[0].c_str()) == pessoaId){
					pessoa.setId(atoi(dados[0].c_str()));
					pessoa.setNome(dados[1]);
					pessoa.setSobrenome(dados[2]);
				}
			}

		}
		findObject.close();

		return pessoa;
	}catch (const exception& e) {
		printf(e.what());
		return pessoa;
	}
}

vector<Pessoa> PessoaDAO::findAll(){
	vector<Pessoa> pessoas;
	try{
		ifstream findObject;
		string linha;

		findObject.open("db-object/pessoa.txt");
		while(!findObject.eof()){
			getline(findObject, linha);
			vector<string> dados = parseValueToPessoa(linha);

			if(!dados[0].empty()){
				Pessoa pessoa = Pessoa();
				pessoa.setId(atoi(dados[0].c_str()));
				pessoa.setNome(dados[1]);
				pessoa.setSobrenome(dados[2]);

				pessoas.push_back(pessoa);
			}
		}
		findObject.close();

		return pessoas;
	}catch (const exception& e) {
		printf(e.what());
		return pessoas;
	}
}

vector<string> PessoaDAO::parseValueToPessoa(string linha){
	size_t pos = 0;
	string token;
	string delimiter = "&";//string::npos
	vector<string> dados;

	while ((pos = linha.find(delimiter)) != string::npos) {
		token = linha.substr(0, pos);
		//cout << token << endl;
		dados.push_back(token);
		linha.erase(0, pos + delimiter.length());
	}
	//cout << linha << endl;
	dados.push_back(linha);

	return dados;
}

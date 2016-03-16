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

Pessoa PessoaDAO::findById(int pessoaId){
	int maxValueArray = 999;
	Pessoa pessoa = Pessoa();

	try{
		ifstream findObject;
		string dados[maxValueArray];
		string linha;

		findObject.open("db-object/pessoa.txt");
		while(!findObject.eof()){
			getline(findObject, linha);
			parseValueToPessoa(linha, dados);
		}
		findObject.close();

		int i;
		for (i = 0; i < maxValueArray; ++i) {
			cout << dados[i];
		}

		return pessoa;
	}catch (const exception& e) {
		printf(e.what());
		return pessoa;
	}
}

void PessoaDAO::parseValueToPessoa(string linha, string dados[]){
	int i = 0;
	size_t pos = 0;
	string token;
	string delimiter = "&";//string::npos

	cout << "INCIANDO LEITURA" << endl;
	while ((pos = linha.find(delimiter)) != string::npos) {
		token = linha.substr(0, pos);
		cout << token << endl;
		dados[i++] = token;
		linha.erase(0, pos + delimiter.length());
	}
	cout << linha << endl;
	dados[i++] = linha;
}

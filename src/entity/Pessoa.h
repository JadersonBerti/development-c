#ifndef PESSOA_H_
#define PESSOA_H_
#include <string.h>
#include <iostream>

using namespace std;

class Pessoa {
	private:
		int id;
		string nome;
		string sobrenome;
	public:
		Pessoa();
		int getId();
		void setId(int id);
		string getNome();
		void setNome(string nome);
		string getSobrenome();
		void setSobrenome(string nome);
		string toString();
		bool equals(int id);
		bool isEmpty();

		friend ostream& operator<<(ostream& os, const Pessoa& p){
			os << p.id << "&" << p.nome << "&" << p.sobrenome << "\n";
			return os;
		}

};

#endif /* PESSOA_H_ */

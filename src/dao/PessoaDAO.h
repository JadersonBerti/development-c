#ifndef PESSOADAO_H_
#define PESSOADAO_H_
#include "C:\\Users\\JadersonBerti\\Desktop\\workspace-c++\\desenvolvimento-c++\\src\\entity\\Pessoa.h"

class PessoaDAO {
	public:
	 bool insert(Pessoa pessoa);
	 void update(Pessoa pessoa);
	 void remove(int pessoaId);
	 Pessoa findById(int pessoaId);
	 void parseValueToPessoa(string linha, string dados[]);
};

#endif /* PESSOADAO_H_ */

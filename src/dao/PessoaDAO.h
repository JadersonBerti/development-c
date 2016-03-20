#ifndef PESSOADAO_H_
#define PESSOADAO_H_
#include "C:\\Users\\JadersonBerti\\Desktop\\workspace-c++\\desenvolvimento-c++\\src\\entity\\Pessoa.h"
#include <vector>

class PessoaDAO {
	public:
	 bool insert(Pessoa pessoa);
	 bool update(Pessoa pessoa);
	 bool removee(int pessoaId);
	 Pessoa findById(int pessoaId);
	 vector<Pessoa> findAll();
	 vector<string> parseValueToPessoa(string linha);
};

#endif /* PESSOADAO_H_ */

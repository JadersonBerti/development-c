#include <iostream>
#include "C:\\Users\\JadersonBerti\\Desktop\\workspace-c++\\desenvolvimento-c++\\src\\entity\\Pessoa.h"
#include "C:\\Users\\JadersonBerti\\Desktop\\workspace-c++\\desenvolvimento-c++\\src\\dao\\PessoaDAO.h"
//#include "C:\\Users\\JadersonBerti\\Desktop\\workspace-c++\\desenvolvimento-c++\\src\\include\\libpq-fe.h"
//#include "C:\\Program Files (x86)\\PostgreSQL\\9.2\include\\libpq-fe.h"
//#include "Pessoa.h"

using namespace std;

const int EXITE_PROGRAM = 0;

int main (void){
	PessoaDAO dao = PessoaDAO();

	cout << "========= PESSOAS ==========" << endl;
	vector<Pessoa> pessoas = dao.findAll();
	int size = pessoas.size();
	for(int i = 0;i< size;i++){
		cout << pessoas[i].toString() << endl;
	}

//	Pessoa pessoa = Pessoa();
//	pessoa.setId(4);
//	pessoa.setNome("barnabe");
//	pessoa.setSobrenome("cardoso");

//	bool sucess	= dao.insert(pessoa);
//  bool sucess	= dao.update(pessoa);
//	if(sucess){
//		cout << "Cadastrado/Auterado com sucesso" << endl;
//	}else{
//		cout << "Nao possivel cadastrar/atualizar";
//	}

//  bool sucess	= dao.removee(pessoa.getId());
//	if(sucess){
//		cout << "Pessoa removida com sucesso" << endl;
//	}else{
//		cout << "Nao possivel remover";
//	}

//	Pessoa pessoa = dao.findById(1);
//	if(!pessoa.isEmpty()){
//		cout << pessoa.toString();
//	}else{
//		cout << "Objeto não encontrado";
//	}

	return 0;
}

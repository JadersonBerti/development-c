#include <iostream>
#include "C:\\Users\\JadersonBerti\\Desktop\\workspace-c++\\desenvolvimento-c++\\src\\entity\\Pessoa.h"
#include "C:\\Users\\JadersonBerti\\Desktop\\workspace-c++\\desenvolvimento-c++\\src\\dao\\PessoaDAO.h"
//#include "C:\\Users\\JadersonBerti\\Desktop\\workspace-c++\\desenvolvimento-c++\\src\\include\\libpq-fe.h"
//#include "C:\\Program Files (x86)\\PostgreSQL\\9.2\include\\libpq-fe.h"
//#include "Pessoa.h"

using namespace std;

int main (void){
	Pessoa pessoa = Pessoa();
	pessoa.setId(0);
	pessoa.setNome("jaderson");
	pessoa.setSobrenome("berti");

	PessoaDAO dao = PessoaDAO();
	dao.findById(0);
//	bool sucess	= dao.insert(pessoa);
//
//	if(sucess){
//		cout << pessoa.getId() << endl;
//		cout << pessoa.getNome() << endl;
//		cout << pessoa.getSobrenome() << endl;
//	}else{
//		cout << "Nao possivel salvar";
//	}

	return 0;
}

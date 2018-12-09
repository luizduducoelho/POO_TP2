#include "Biblioteca.h"

int Emprestimo::proximoNumero = 0;

Biblioteca::Biblioteca(){	
}

void Biblioteca::insere_usuario(Usuario user){
	lista_usuarios.push_back(user);
}

void Biblioteca::insere_emprestimo(Emprestimo emp){
	lista_emprestimos.push_back(emp);
}

void Biblioteca::insere_item_emprestimo(Emprestimo emp, ItemEmprestimo item_emp){	
	for(int i = 0; i < lista_emprestimos.size(); i++){
		if(lista_emprestimos[i].get_numero() == emp.get_numero())
			lista_emprestimos[i].adiciona_itememprestimo(item_emp);
			return;
	}
}

void Biblioteca::exclui_usuario(Usuario user){
	for(int i = 0; i < lista_emprestimos.size(); i++){
		if(lista_emprestimos[i].get_user() == user)
			return; // THROW!!! Usuario com emprestimo
	}
	for(int j = 0; j < lista_usuarios.size(); j++){
		if(lista_usuarios[j] == user){
			lista_usuarios.erase(lista_usuarios.begin() + j);
			return;
		}
	}						
}

/*
void Biblioteca::exclui_publicacao(Publicacao publi){
	if(publi.teste()){
		
		
	}
	for(int i = 0; i < lista_publicacoes.size(); i++){
		if(lista_publicacoes[i].get_codPub() == publi.get_codPub()){
				if(lista_publicacoes[i].teste() == true){
					for(int j = 0; j < lista_emprestimos.size(); j++){
					//	for(int k = 0; k < lista_emprestimos[j].get_sizeitens(); k++){
							//lista_emprestimos[j];
					//	}
					}
				}
			lista_publicacoes.erase(lista_publicacoes.begin() + i);
			return;
		}
	}	
}
*/

void Biblioteca::exclui_emprestimo(Emprestimo emp){
	if(emp.get_sizeitens() != 0)
		return; // !!! LAN�AR THROW, tem itens no empr�stimo
	else{
		for(int i = 0; i < lista_emprestimos.size(); i++){
			if(lista_emprestimos[i] == emp){
				lista_emprestimos.erase(lista_emprestimos.begin() + i);
				return;
			}
		}	
	}
}

/*
void Biblioteca::exclui_item_emprestimo(Emprestimo emp, ItemEmprestimo item_emp){
	for(int i = 0; i < lista_emprestimos.size(); i++){
		if(lista_emprestimos[i] == emp){
			for(int j = 0; j < lista_emprestimos[i].get_sizeitens(); j++){
				if(item_emp.get_Livro() == lista_emprestimos[i].get_codPub(j)){	
					Livro l = item_emp.get_Livro();
					lista_emprestimos[i].exclui_livro(l);
					return;
				}
			}
		}
	}
}*/

/*
void Biblioteca::devolve_item(Emprestimo emp, Livro livro){
	for(int i = 0; i < lista_emprestimos.size(); i++){
		if(lista_emprestimos[i].get_numero() == emp.get_numero()){
			for(int j = 0; j < lista_emprestimos[i].get_sizeitens(); j++){
				if(livro.get_codPub() == lista_emprestimos[i].get_codPub(j)){
					lista_emprestimos[i].devolve_livro(livro);
				}
			}
		}
	}
}*/
		
				



#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char Agenda[100][20+1];
char Nome[100],End[20+1],Tel[20+1],Info[100+1];

int geraIndex(char Nome[100]){
	int index = 0;
	index = (Nome[0] + 'K') + (Nome[1] - 'C') + (Nome[0] - 'D');
	index = index%100;
	return index;	
}

void gravaAgenda(char Nome[100], char Tel[20+1], char End[20+1]){
	int index = geraIndex(Nome);
	strcpy(Info,Tel);
	strcpy(Info,"|");
	strcpy(Info,End);
	strcpy(Agenda[index],Info);
}

void consultaAgenda(char Nome[100], char* Info){
	
	int index = geraIndex(Nome);
	strcpy(Info, Agenda[index]);
}

void chamarCadastro(){
	printf("\nDigite um Nome: ");
	scanf("%s", Nome);
	printf("\nDigite um Telefone: ");
	scanf("%s", Tel);
	printf("\nDigite um Endereco: ");
	scanf("%s", End);
	gravaAgenda(Nome, Tel, End);
}

int menu(){
	int m;
	printf("\n1)Para realizar um novo cadastro\n2)Para Realizar uma pesquisa\n3)Para sair: ");
	scanf("%d", &m);
	return m;	
}

int main(){
	int x = 0;
	int m = 0;
	while(x != 3){
		m = menu();
		switch(m){
			case 1 :
				chamarCadastro();
			break;

			case 2 :
		        	qualquer merda printf("Digite um Nome: ");
				scanf("%s", Nome);
				consultaAgenda(Nome, Info);
				char *i;
				i = strsep(Info,'|');
				printf("\nDados da busca:\nO nome e: %s\nO Telefone e: %s\nO End e: %s\n", Nome, i[0],i[1]);
			break;

			case 3 :
				x=3;
			break;

		}
	}
	return 0;
}

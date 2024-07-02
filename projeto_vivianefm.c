#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro(){ //fun��o respons�vel por cadastrar os usu�rios no sistema

	//inicio da cria��o de vari�veis/string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char arquivo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se as strings
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	printf("\n");
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta(){
	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("\nCPF inv�lido, tente novamente!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("\nEssas s�o as informa��es do usu�rio:\n\n");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar(){
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	
	if(file == NULL){
		printf("\nCPF n�o encontrado no sistema!\n\n");
		system("pause");
		
	}
	
}

int main()
{
	int opcao=0; //definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;){
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		
		printf("#### Cart�rio da EBAC ####\n\n"); //in�cio do menu
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\tDigite [1] para registrar nomes.\n");
		printf("\tDigite [2] para consultar nomes.\n");
		printf("\tDigite [3] para deletar nomes.\n");
		printf("\tDigite [4] para sair do sistema.\n\n");
		printf("Op��o: "); //fim do menu
		
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
		
		system("cls"); //comando de limpar a tela
		
		switch(opcao){ //in�cio da sele��o do menu
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar nosso sistema!\n");
			return 0;
			break;
			
			default:
			printf("Op��o inv�lida! Por favor, tente novamente.\n\n");
			system("pause");
			break;	
		} //fim da sele��o
		
	
	}

}

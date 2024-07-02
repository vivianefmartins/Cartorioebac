#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro(){ //função responsável por cadastrar os usuários no sistema

	//inicio da criação de variáveis/string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char arquivo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se as strings
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variável
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
		printf("\nCPF inválido, tente novamente!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("\nEssas são as informações do usuário:\n\n");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar(){
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	
	if(file == NULL){
		printf("\nCPF não encontrado no sistema!\n\n");
		system("pause");
		
	}
	
}

int main()
{
	int opcao=0; //definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;){
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		
		printf("#### Cartório da EBAC ####\n\n"); //início do menu
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\tDigite [1] para registrar nomes.\n");
		printf("\tDigite [2] para consultar nomes.\n");
		printf("\tDigite [3] para deletar nomes.\n");
		printf("\tDigite [4] para sair do sistema.\n\n");
		printf("Opção: "); //fim do menu
		
		scanf("%d", &opcao); //armazenando a escolha do usuário
		
		system("cls"); //comando de limpar a tela
		
		switch(opcao){ //início da seleção do menu
			case 1:
			registro(); //chamada de funções
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
			printf("Opção inválida! Por favor, tente novamente.\n\n");
			system("pause");
			break;	
		} //fim da seleção
		
	
	}

}

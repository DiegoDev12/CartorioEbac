#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço
#include <locale.h> //biblioteca de alocação de testo por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()
{
	    setlocale(LC_ALL, "Portuguese");
		
		char arquivo[40];  //criação de strings
        char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		  
		printf("Digite o CPF a ser cadastrado:");
		scanf("%s", cpf); 
		
		strcpy(arquivo, cpf); //responsavél por copiar os valores da strings
		
		FILE *file ; //cria o arquivo
		file = fopen(arquivo, "w"); //cria o arquivo
		fprintf(file,cpf); //salvo o valor da variável
		fclose(file); //fecho o arquivo
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf("Digite o nome a ser cadastrado:");
		scanf("%s", nome);
		
		file = fopen(arquivo, "a");
		fprintf(file, nome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf("Digite o sobrenome a ser cadastrado:");
		scanf("%s", sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf(file, sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf("cargo:");
		scanf("%s", cargo);
		
		file = fopen(arquivo, "a");
		fprintf(file, cargo);
		fclose(file);
		system("pause");	
}

int consulta()
{
        setlocale(LC_ALL, "Portuguese");
		
		char cpf[40];
        char conteudo[200];
        
        printf("Digite o cpf a ser consultado: ");
        scanf("%s", cpf);
        
        FILE *file;
        file = fopen(cpf, "r");
        
        if (file == NULL)
        {
        	printf("CPF não está na base de dados! \n");
		}
		
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas são as informações do usuário:");
			printf("%s", conteudo);
			printf("\n");
		}
		
		system("pause");	
}

int deletar()
{
	    char cpf[40];
	    
	    printf("digite o CPF do usuário a ser deletado:");
	    scanf("%s", cpf);
	    
	    
	    FILE *file;
	    file = fopen(cpf, "r");
	    fclose(file);
	    
	    if (file != NULL)
	    {
	    	remove(cpf);
			printf("Usuário deletado com sucesso!\n");
	    	system("pause");
		}
		else
		{
		printf("Usuário não está no sistema!\n");
		system("pause");
		}
}
        

int main()  //função principal
{ 
	int opcao=0; //definindo variavéis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("     Cartório da EBAC     \n\n");
	printf("Login de administrador!\n\nDigite a sua senha:");
	scanf("%s", senhadigitada);
	comparacao = strcmp(senhadigitada, "admin");

	
	if(comparacao==0)
	{
		
	
	 for(laco=1;laco=1;)
 	 {
    	
    	system("cls");

		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("     Cartório da EBAC     \n\n");
		printf("Escolha a opção desejada do menu:\n\n"); //inicio do menu
		printf("\t1 - registrar nomes\n");
		printf("\t2 - consultar nomes\n");
		printf("\t3 - apagar nomes\n");
		printf("\t4 - sair do programa\n\n\n");
		printf("digite a opção desejada:"); //final do menu

    	scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls");
	
	
			switch(opcao) //selecionamento de opções
			{
				case 1:
				registro();
				break;
			
				case 2:
				consulta();
				break;
			
				case 3:
				deletar();
				break;
			
				case 4:
				printf("Obrigado por usar o sistema");
				return(0);
				break;
		
				default:
				printf("Essa opção não existe!\n\n"); //final das opções
				system("pause");
				break;
			
			}
	
	
		}
	}
	
	else
		printf("senha incorreta!");
		
}

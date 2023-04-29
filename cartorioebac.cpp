#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //fub��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o das vari�veis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da cria��o de vari�veis/string
    
    printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //responsavel por copiar os valores das string
    
    FILE *file; // Cria o arquivo
    file = fopen(arquivo,"w"); // Cria o arquivo
    fprintf(file,cpf); //salva o valor da variavel
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
    
    
}

int consulta()
{
	setlocale (LC_ALL, "portuguese"); //Definindo a liguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consutado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o loclizado!\n");
	}

    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("\nEssas s�o as informa��es do usu�rio: ");
    	printf("%s", conteudo);
    	printf("\n\n");
    }
        
        system("pause");
        
   	}
    
int deletar()
{
    char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado:  ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
		
	if(file == NULL);
	{
		printf("O usu�rio n�o se encontra cadastrado no sistema!\n");
		system("pause");
	}
	
    else
    
	    printf("O Usu�rio foi deletado com sucesso!\n");
	    system("pause");
	
	

}

int main ()
{
	int opcao=0; //definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls");
	    
    	setlocale (LC_ALL, "portuguese"); //Definido liguagem
	
    	printf ("### Cart�rio da EBAC ###\n\n"); //inicio do menu
    	printf ("\tSelecione a op��o desejada\n\n");
    	printf ("\t1 - Registrar nomes\n");
        printf ("\t2 - Consultar nomes\n");
    	printf ("\t3 - Deletar nomes\n\n");
    	printf ("Op��o: "); //fim do menu
    	
    	scanf("%d", &opcao); //Armazenando escolha do usu�rio
    	
    	system("cls");
    	
    	switch(opcao) //Inicio da sele��o
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
	
			default:
			printf("Essa op��o n�o est� disponivel!\n\n");
			system("pause");
			break;
		}
    }
}

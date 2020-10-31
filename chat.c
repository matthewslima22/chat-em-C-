#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>


int Cadastrar_Usuario(int ContCadastro);
void Remover_Usuario();
char Conversar();
/*Essas duas abaixo devem ficar dentro da função conversar*/
char Enviar_Mensagem();
char Receber_Mensagem();
void Listar_Usuarios();

typedef struct
{
    char IP[17];
    char Nome[50];
} tUsuario;
tUsuario Usuario[100];

int main()
{
	int Opcao, ContCadastro=0;
	printf("Bem-vindo. Eh um prazer ter voce usando este programa\n");
	do
	{
	printf("Digite:\n\n1 - Conversar com usuario cadastrado\n2 - Cadastrar usuario a sua lista\n3 - Remover usuario da sua lista\n4 - Exibir lista de amigos\n5 - Sair\n");
	scanf("%i", &Opcao);
	getchar();

	if(Opcao == 1)
		Conversar();
	if(Opcao == 2)
		{
        ContCadastro = Cadastrar_Usuario(ContCadastro);
        printf("%s", (Usuario[ContCadastro].Nome));
        printf("%s", (Usuario[ContCadastro].IP));
		}
	if(Opcao == 3)
		Remover_Usuario();
	if(Opcao == 4)
		Listar_Usuarios();
	}
	while(Opcao!=5);

	return 0;

}

char Conversar()
{
	/*Enviar_Mensagem();
	Receber_Mensagem();*/
    printf("Conversando... \n");
    return 'a';
}

int Cadastrar_Usuario(int ContCadastro)
{

    printf("Digite o nome do usuario a ser cadastrado: ");
    fgets(Usuario[ContCadastro].Nome, 50, stdin);
    printf("\nDigite o IP do usuario a ser cadastrado: ");
    fgets(Usuario[ContCadastro].IP, 17, stdin);
    ContCadastro++;
    return ContCadastro;
}


void Remover_Usuario()
{
    int i;
    char Nome[30];
    printf("Os nomes dos usuarios sao: \n");

	for(i=0;i<100;i++)
	{
        printf("%s", Usuario[i].Nome);
	}

	printf("Para remover usuario, digite nome exato : \n");
	fgets(Nome, 30, stdin);

	for(i=0;i<100;i++)
	{
        if(strcmp(Usuario[i].Nome, Nome)==0){
            Usuario[i].Nome[0]='\0';
        }
	}


}


void Listar_Usuarios()
{
printf("Os usuarios cadastrados são : \n");
int i;

for (i = 0; i <100; i++)
{
	if(Usuario[i].Nome[0]!='\0')
    {
		printf("\n%s", Usuario[i].Nome);
	}


}
}



/*char Enviar_Mensagem()
{
}

}

char Receber_Mensagem()
{
}*/


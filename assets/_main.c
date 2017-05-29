#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


		
		// estruturas 
		typedef struct agenda {
				int codigo;
				char nome[150];
				char dtnascimento[10];
				char email[100];
				char telefone[100];
		}agenda;

		//Variáveis Globais
		FILE *arq_agenda;
		agenda contato;
	
char menu_da_agenda()
{
    system("cls");
    printf("\t\t Agenda de Contatos\n");
    printf("\n");
    printf("[1] - Incluir\n");
    printf("[2] - Alterar\n");
    printf("[3] - Excluir\n");
    printf("[4] - Consultar\n"); //Procurar contato pelo Nome
    printf("[5] - listar\n");
    printf("[0] - Sair\n");
    printf("\n");
    printf("> ");
    return (toupper(getche()));
}


/*Funcao que serve para verificar se no arquivo "banco.bin", já existe telefone do contato, retornando 1*/
int verifica_cod(int cod)
{
    fread(&contato,sizeof(agenda),1,arq_agenda);
    while(!feof(arq_agenda))
    {
        if (contato.codigo == cod)
        {
            fseek(arq_agenda,-sizeof(agenda),SEEK_CUR);
            return 1;
        }
        fread(&contato,sizeof(agenda),1,arq_agenda);
    }
    return 0;
}

/*Funcao que serve para verificar se no arquivo "banco.bin", já existe nome do contato, retornando 1*/
int verifica_nome(char nome[])
{
    fread(&contato,sizeof(agenda),1,arq_agenda);
    while(!feof(arq_agenda))
    {
        if (strcmp(contato.nome,nome) == 0)

        {
            fseek(arq_agenda,-sizeof(agenda),SEEK_CUR);
            return 1;
        }
        fread(&contato,sizeof(agenda),1,arq_agenda);
    }

    return 0;
}




/*Funcao que serve para verificar se no arquivo "banco.bin", já existe datanascimento, retornando 1*/
int verifica_data_nasc(char nasc[])
{
    fread(&contato,sizeof(agenda),1,arq_agenda);
    while(!feof(arq_agenda))
    {
        if (strcmp(contato.dtnascimento,nasc) == 0)

        {
            fseek(arq_agenda,-sizeof(agenda),SEEK_CUR);
            return 1;
        }
        fread(&contato,sizeof(agenda),1,arq_agenda);
    }

    return 0;
}



/*Funcao que serve para verificar se no arquivo "banco.bin", já existe um email, retornando 1*/
int verifica_e_mail(char mail[])
{
    fread(&contato,sizeof(agenda),1,arq_agenda);
    while(!feof(arq_agenda))
    {
        if (strcmp(contato.email,mail) == 0)

        {
            fseek(arq_agenda,-sizeof(agenda),SEEK_CUR);
            return 1;
        }
        fread(&contato,sizeof(agenda),1,arq_agenda);
    }

    return 0;
}

/*
/*Funcao que serve para verificar se no arquivo "banco.bin", já existe telefone, retornando 1
*/


int verifica_telef(char tel[])
{
    fread(&contato,sizeof(agenda),1,arq_agenda);
    while(!feof(arq_agenda))
    {
        if (strcmp(contato.telefone,tel) == 0)

        {
            fseek(arq_agenda,-sizeof(agenda),SEEK_CUR);
            return 1;
        }
        fread(&contato,sizeof(agenda),1,arq_agenda);
    }

    return 0;
}


/*
*****
/* Funcao para adicionar contatos na agenda
*****
*/

void incluir(struct agenda *dadosAgenda)
{
    char nome[20];

    arq = fopen("banco.bin","a+b");
    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    printf("\n\n");
    printf("Digite o nome: ");
    fflush(stdin);
    gets(nome);

    if (verifica(nome) == 1)
    {
        printf("\nNome ja existe.\n");
    }
    else
    {
        strcpy(contato.nome,nome);
        printf("Digite o telefone: ");
        scanf("%d", &contato.telefone);
        fwrite(&contato,sizeof(agenda),1,arq);
    }
    fclose(arq);
}




int main(int argc, char *argv[]) {

return 0;
}

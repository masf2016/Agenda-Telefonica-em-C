#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

typedef struct Agenda
{
        int codigo;
		char nome[150];
        char dtnascimento[10];
        char email[100];
		char telefone[17];
        
}T_agenda;

// prototipos
void incluir(T_agenda *a);
void Listar(T_agenda *a);
void quick_struct(int);
void qs_struct(int,int);
void ordenar(void);
void pesquisar(T_agenda *a);
char Validaresp();

static int qtd = 0;

T_agenda Tab[100];
FILE *fp;


/*=================================================================
* ======INCLUIR DADOS NO ARQUIVO ==================================
* ======Fun��o Recebe um vetor de estrutura do tipo T_agenda  e ===
* ======armazenda o registro no arquivo============================
*/ 


void incluir(T_agenda *a){
     int total = 0, retorno;
     char op = 's';

     if ((fp = fopen("agenda.db", "a")) == NULL)			//Abre um arquivo texto para grava��o. Os dados ser�o adicionados no fim do arquivo ("append") 
     {														//se ele j� existir, ou um novo arquivo ser� criado, no caso de arquivo n�o existente anteriormente.
     
        printf ("O arquivo da lista n�o pode ser aberto!\n");
        printf ("Insira dados!\n");
        getch();
        exit(1);
        
     }
     while ((total < 100) && (op == 's'))					//Enquanto o vetor n�o atingir o limite de 100 posi��es ou o 'S' n�o for teclado
     {
           printf ("Digite o cod: ");
           scanf("%d",a[total].codigo);
           fflush(stdin);
		   printf ("Digite o nome: ");
           gets(a[total].nome);
           printf ("Digite a data de nascimento");
           gets(a[total].dtnascimento);
           printf ("Digite o E-mail: ");
           gets(a[total].email);
           printf ("Digite o numero de telefone: ");
           gets(a[total].telefone);


           retorno = fwrite (&a[total], sizeof(struct Agenda) ,1,fp); 	/* fwrite() recebe como parametro a posi��o da memoria onde ser� escrito os elementos,
           																*  tamanho em bytes de cada elemento a ser escrito (obtido aqui com a fun�ao sizeof()),
           																*  n�mero de elementos, cada um com um tamanho de tamanho byte e
           																*  o ponteiro para o objeto FILE (variavel fp) que receber� o fluxo de sa�da.
		   																*  Variavel 'retorno' recebe 1 caso a opera��o de escrita em fwrite for bem sucedida
		   																*/
           if (retorno == 1) {
               printf(" \nGravacao ok ! ");
           }
           total++;
           op = Validaresp();
           qtd++;
     }
     fclose (fp);
}


void alterar (T_agenda *a, int cod){
	int total = 0; // variavel para marcar inicio do arquivo
	int posicao = 0; 
	int sucesso=0; // variavel para confirmar grava��o dos dados no arquivo
	
	fseek(fp, posicao, SEEK_SET); //posiciona o ponteiro no in�cio do arquivo.
	
	
	do {
			  if (fread(&a,sizeof(struct Agenda),1,fp) == 0)
			    break;
			  if (a[posicao].codigo == cod) 
			   { 
			    system("cls");
			    printf("<<<< Registro Antigo >>>\n\n");
			    printf("Codigo..............: %d\n",a[posicao].codigo);
			    printf("Nome ...............: %s\n",a[posicao].nome);
			    printf("Data de Nascimento..: %s\n",a[posicao].dtnascimento);
			    printf("E-mail..............: %d\n\n",a[posicao].email);			    
				printf("Telefone............: %s\n",a[posicao].telefone);

			    printf("<<<  Digite o Registro novo >>\n\n");
			    printf("C�digo..............: ");
				scanf("%d", &a[posicao].codigo);
				fflush(stdin);
			    printf("Nome ...............: ");
			    gets(a[posicao].nome);
			    printf("Data de Nascimento..: ");
			    gets(a[posicao].dtnascimento);
			    printf("E-mail..............: ");
			    gets(a[posicao].email);
			    printf("Telefone............: "); 				 
			    gets(a[posicao].telefone);

			    // quando voc� le o arquivo o ponteiro se desloca.
			    // � necessario voltar para a posicao anterior a 
			    // da leitura que � onde o registro come�a
			
			    fseek(fp, posicao, SEEK_SET);
			
			    // agora sim, podemos gravar
			    // e � melhor o sucesso estar condicionado a 
			    // correta gravacao do registro (abaixo)

			    sucesso= fwrite(&a,sizeof(struct Agenda),1,fp) == sizeof(struct Agenda);
			    break;
			  }

			
			  posicao = posicao + sizeof(struct Agenda); // ajustar posicao em rela��o ao inicio do arquivo

		}while(posicao < 100);
	
		if (!sucesso) {
			printf("Jogo n�o encontrado no arquivo\n");
		}
  
}


/*=================================================================
* ======VALIDAR RESPOSTAS =========================================
* ======Fun��o usada na alimenta��o de dados na agenda ============
* ======armazenda o registro no arquivo============================
*/ 

char Validaresp() {
   char op;
   do {
      printf(" \nDeseja inserir novos dados? [S ou N] ? " );
      op = getch();
      printf("\n" );
   } while (op != 's' && op != 'n'); 		// enquanto o 's' ou 'n' n�o for digitado o la�o continua a execu��o
   return op;
}




/*=================================================================
* ======ORDENAR ELEMENTOS =========================================
* ======Organizar em ordem alfabetica os elementos da agenda=======
*/

void ordenar(void){
       
     T_agenda vet;
     int aux,i,j,k,retorno;
     char *str, *str2, *straux; // Ponteiros que receber�o a posi��o de memoria do elementos da estrutura Agenda e intercalaram entre si os elementos em ordem
    

         aux = qtd; // aux recebe a quantidade de contatos inscritos
         for ( i = 0 ; i < aux ; i++ ){
               str = Tab[i].nome;              
               for ( j = i+1 ; j < aux ; j++ ){
                   str2 = Tab[j].nome;
                   if ( strcmp ( str, str2 ) > 0 ){			// | A fun��o strcmp() pode retornar um valor nulo (zero), positivo ou negativo.
                        vet = Tab[i];						// | Quando as palavras comparadas s�o iguais, a fun��o retorna 0.
                        Tab[i] = Tab[j];					// | Quando as palavras comparadas s�o diferentes e a primeira � maior, a fun��o retorna um valor 
                        Tab[j] = vet;						// | positivo, caso contr�rio, a fun��o retorna negativo, sendo que no alfabeto a �menor� letra � �a�,
                   }										// | e a maior, �z�.
               }											
         }
    
     remove("agenda.db"); 									// Apaga o arquivo de dados antigo 
     if ((fp = fopen("agenda.db", "w+")) == NULL){ 			// | Cria um arquivo texto para leitura e grava��o. Se o arquivo existir, o conte�do anterior ser� destru�do. 
        printf ("ERRO!\n");						   			// | Se n�o existir, ser� criado.
        getch();								   			//
        exit(1);
     }
     for ( k = 0 ; k < aux ; k++ ){
           retorno = fwrite (&Tab[k], sizeof(struct Agenda) ,1,fp); //grava os dados agora ordenodos no novo arquivo
           if (retorno != 1) {
               printf(" \nERRO ! ");
           }
     }
     fclose(fp);
     printf("\nLista Ordenada! \n");
     getch();
}

//=======PESQUISA NOME =================================================
// ======Pesquisar contato pelo nome ===================================
  
void pesquisar(T_agenda *a, int codigo){  // parei aqui 29/05/17 01:07
     int indice = 0, retorno = 1, cont = 0;
     char nome[80],op;

     if ((fp = fopen("agenda.db", "r")) == NULL){  // abre o arquivo em modo de leitura
     printf ("O arquivo da lista n�o pode ser aberto!\n");
     printf ("Insira dados!\n");
     getch();
     exit(1);
     }
     printf ("Digite o nome: ");
     gets(nome);

     retorno = fread(&Tab[indice], sizeof(struct Agenda), 1, fp); // retorna o n�mero de unidades no arquivo efetivamente lidas

        while (retorno == 1){
            if (strcmp(nome, Tab[indice].nome) == 0 ){
            printf ("\nNome ..: %s\nFone ..: %s\nE-mail ..: %s\n", nome, Tab[indice].fone, Tab[indice].email);
            cont++;
            }
            indice++;
            retorno = fread(&Tab[indice], sizeof(struct Agenda), 1, fp);
        }
        if(cont == 0){
                     printf("Nao ha contatos com este nome!\n");
                     }
        getch();
        fclose(fp);
   }

//======================================================================
// ======Lista os contatos cadastrados =================================

void Listar(T_agenda *a){
int i = 0, retorno;

    if ((fp = fopen("agenda.db", "r")) == NULL)
    {
    printf ("O arquivo da lista n�o pode ser aberto!\n");
    printf ("Insira dados!\n");
    getch();
    exit(1);
    }

    retorno = fread(&Tab[i], sizeof(struct Agenda), 1, fp);
   // fread retorna a quantidade de itens ...

   while ( retorno == 1) {
      printf("\n Nome ..: %s",   Tab[i].nome);
      printf("\n Fone ..: %s",   Tab[i].fone);
      printf("\n E-mail ..: %s\n",   Tab[i].email); 
      i++;
      retorno = fread(&Tab[i], sizeof(struct Agenda), 1, fp);  
      }
      printf(" \n\n %d Contatos salvos!\n", i);
      getch();
      fclose(fp);
}

//======================================================================
// ======Menu ==========================================================

void menu(void){
char op;
int teste;

if ((fp = fopen("agenda.db", "r")) != NULL){
        qtd = 0;       
        do {
             teste = fread(&Tab, sizeof(struct Agenda), 1, fp);
             qtd++;
        }while ( teste == 1 );
        qtd--;
}

do{
system("cls");
printf("\n(1)Incluir\n(2)Listar\n(3)Ordenar por nome\n(4)Pesquisar por nome\n");
printf("(5)Pesquisar por fone\n(6)Pesquisar por E-mail\n(7)Qualquer outra tecla para sair\n\n");
op = getch();
switch(op){
case '1':
     inclusao(Tab);
break;
case '2':
     Listar(Tab);
break;
case '3':
     ordenar();
break;
case '4':
     pesquisar(Tab);
break;
case '5':
     pesquisarfone();
break;
case '6':
     pesquisaremail();
break;
default:
exit(1);
}
}while (op < '7');
}

int main (){
    int var;

    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("                  .::AGENDA ELETRONICA:.  \n\n");
    printf("  Veja todas as funcoes disponiveis no menu   \n");
    printf("  use os numeros para selecionar a opcao desejada  \n");
    printf("  pressione qualquer tecla para continuar ou ESC para sair do programa agora.");
    var=getch();
    if(var == 27){ exit(1);}
menu();
system("pause");
}


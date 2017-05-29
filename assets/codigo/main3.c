#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

typedef struct Agenda
{
        char nome[50];
        char fone[17];
        char email[80];
}T_agenda;

// prototipos
void inclusao(T_agenda *a);
void Listar(T_agenda *a);
void quick_struct(int);
void qs_struct(int,int);
void ordenar(T_agenda *a);
void pesquisar(T_agenda *a);
char Validaresp();

static int qtd = 0;

T_agenda a[100];
FILE *fp;


// =================================================================
// ======Incluir dados no arquivo ==================================

void inclusao(T_agenda *a){
     int total = 0, retorno;
     char op = 's';

     if ((fp = fopen("agenda.db", "a")) == NULL)
     {
        printf ("O arquivo da lista não pode ser aberto!\n");
        printf ("Insira dados!\n");
        getch();
        exit(1);
     }
     while ((total < 10) && (op == 's'))
     {
           printf ("Digite o nome: ");
           gets(a[total].nome);
           printf ("Digite o numero: ");
           gets(a[total].fone);
           printf ("Digite o E-mail: ");
           gets(a[total].email);

           retorno = fwrite (&a[total], sizeof(struct Agenda) ,1,fp);

           if (retorno == 1) {
               printf(" \nGravacao ok ! ");
           }
           total++;
           op = Validaresp();
           qtd++;
     }
     fclose (fp);
}

//======================================================================
// ======Valida resposta ===============================================

char Validaresp() {
   char op;
   do {
      printf(" \nDeseja inserir novos dados? [S ou N] ? " );
      op = getch();
      printf("\n" );
   } while (op != 's' && op != 'n');
   return op;
}

//======================================================================
// ======Organizar em ordem alfabetica =================================

void ordenar(T_agenda *a){
       
     T_agenda vet;
     int aux,i,j,k,retorno;
     char *str, *str2, *straux;
    

         aux = qtd; // aux recebe a quantidade de contatos inscritos
         for ( i = 0 ; i < aux ; i++ ){
               str = a[i].nome;              
               for ( j = i+1 ; j < aux ; j++ ){
                   str2 = a[j].nome;
                   if ( strcmp ( str, str2 ) > 0 ){
                        vet = a[i];
                        a[i] = a[j];
                        a[j] = vet;
                   }
               }
         }
    
     remove("agenda.db");
     if ((fp = fopen("agenda.db", "w+")) == NULL){
        printf ("ERRO!\n");
        getch();
        exit(1);
     }
     for ( k = 0 ; k < aux ; k++ ){
           retorno = fwrite (&a[k], sizeof(struct Agenda) ,1,fp);
           if (retorno != 1) {
               printf(" \nERRO ! ");
           }
     }
     fclose(fp);
     printf("\nLista Ordenada! \n");
     getch();
}

//======================================================================
// ======Pesquisar contato pelo nome ===================================

void pesquisar(T_agenda *a){
     int indice = 0, retorno = 1, cont = 0;
     char nome[80],op;

     if ((fp = fopen("agenda.db", "r")) == NULL){
     printf ("O arquivo da lista não pode ser aberto!\n");
     printf ("Insira dados!\n");
     getch();
     exit(1);
     }
     printf ("Digite o nome: ");
     gets(nome);

     retorno = fread(&a[indice], sizeof(struct Agenda), 1, fp);

        while (retorno == 1){
            if (strcmp(nome, a[indice].nome) == 0 ){
            printf ("\nNome ..: %s\nFone ..: %s\nE-mail ..: %s\n", nome, a[indice].fone, a[indice].email);
            cont++;
            }
            indice++;
            retorno = fread(&a[indice], sizeof(struct Agenda), 1, fp);
        }
        if(cont == 0){
                     printf("Nao ha contatos com este nome!\n");
                     }
        getch();
        fclose(fp);
   }
  
//======================================================================
// ======Pesquisar Telefone ============================================

void pesquisarfone(T_agenda *a){
     int indice = 0, retorno = 1, cont = 0;
     char fone[80],op;

     if ((fp = fopen("agenda.db", "r")) == NULL){
     printf ("O arquivo da lista não pode ser aberto!\n");
     printf ("Insira dados!\n");
     getch();
     exit(1);
     }
     printf ("Digite o telefone: ");
     gets(fone);

     retorno = fread(&a[indice], sizeof(struct Agenda), 1, fp);

        while (retorno == 1){
            if (strcmp(fone, a[indice].fone)==0){
            printf ("\nNome ..: %s\nFone ..: %s\nE-mail ..: %s\n", a[indice].nome, a[indice].fone, a[indice].email);
            cont++;
            }
            indice ++;
            retorno = fread(&a[indice], sizeof(struct Agenda), 1, fp);
        }
        if(cont == 0){
                     printf("Nao ha contatos com este Telefone!\n");
                     }
        getch();
        fclose(fp);
   }
  
//======================================================================
// ======Pesquisar contato por Email ===================================

void pesquisaremail(void){
     int indice = 0, retorno = 1, cont =0;
     char email[80],op;

     if ((fp = fopen("agenda.db", "r")) == NULL){
     printf ("O arquivo da lista não pode ser aberto!\n");
     printf ("Insira dados!\n");
     getch();
     exit(1);
     }
     printf ("Digite o E-mail: ");
     gets(email);

     retorno = fread(&a[indice], sizeof(struct Agenda), 1, fp);

        while (retorno == 1){
            if (strcmp(email, a[indice].email)==0){
            printf ("\nNome ..: %s\nFone ..: %s\nE-mail ..: %s\n", a[indice].nome, a[indice].fone, a[indice].email);
            cont++;
            }
            indice ++;
            retorno = fread(&a[indice], sizeof(struct Agenda), 1, fp);
        }
        if(cont == 0){
                     printf("Nao ha contatos com este Email!\n");
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
    printf ("O arquivo da lista não pode ser aberto!\n");
    printf ("Insira dados!\n");
    getch();
    exit(1);
    }

    retorno = fread(&a[i], sizeof(struct Agenda), 1, fp);
   // fread retorna a quantidade de itens ...

   while ( retorno == 1) {
      printf("\n Nome ..: %s",   a[i].nome);
      printf("\n Fone ..: %s",   a[i].fone);
      printf("\n E-mail ..: %s\n",   a[i].email); 
      i++;
      retorno = fread(&a[i], sizeof(struct Agenda), 1, fp);  
      }
      printf(" \n\n %d Contatos salvos!\n", i);
      getch();
      fclose(fp);
}

//======================================================================
// ======Menu ==========================================================

void menu(void){
T_agenda *b;	
char op;
int teste;

if ((fp = fopen("agenda.db", "r")) != NULL){
        qtd = 0;       
        do {
             teste = fread(&b, sizeof(struct Agenda), 1, fp);
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
     inclusao(b);
break;
case '2':
     Listar(b);
break;
case '3':
     ordenar(b);
break;
case '4':
     pesquisar(b);
break;
case '5':
     pesquisarfone(b);
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



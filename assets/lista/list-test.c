					
	//**************************************
	// Naome: Agenda Telefonica
	// Descri��o: Usado como agenda simples de contatos armazenados em um arquivo de dados
	// autor(a): Rafaella Costa
	//**************************************
	
	/*---------------------*/
	 /* AGENDA TELEF�NICA */
	 /*---------------------*/
	# include <stdio.h>
	# include <conio.h>
	# include <string.h>
	# include <stdlib.h>
	
	/*  Campos da Estrutura
			int codigo;
			char nome[150];
			char dtnascimento[10];
			char email[100];
			char telefone[100];
	*/
	
	/*
		1. incluir = receber cada um dos campos do registro como parametro e incluir um novo registro num vetor de registros.
		2. alterar = receber cada um dos campos do registro e alterar os valores cujo registro contenha o código recebido pela função.
		3. excluir = receber o código do registro e excluir o registro do vetor.
		4. consultar = eceber o código do registro e exibir na tela os campos do registro correspondente.
		5. listar = exibir na tela todos os registros do vetor.
		6. sair
	*/
	
	struct agenda {
		int codigo;
		char nome[150], dtnascimento[10], email[100], telefone[100];
		struct agenda *proximo;
	};
	typedef struct agenda contato;
	contato *inicio, *temporario;
	FILE *fp;
	
	int menu(); // menu principal
	void incluir(); //adicionar um contato a lista
	void consultar(); //procurar um contato na lista
	void alterar(); //editar um contato na lista
	void excluir(); //apagar um contato na lista
	void listar(); //listar todos o contatos
	
	int menu()
	{
	int dch;

		printf("\n\t\t AGENDA TELEFONICA ");
 		printf("\n\t\t  =================== ");
		printf("\n\t\t Escolha uma acao");
		printf("\n\t\t  1. incluir ");
		printf("\n\t\t  2. consultar ");
		printf("\n\t\t  3. alterar ");
		printf("\n\t\t  4. excluir ");
		printf("\n\t\t  5. listar ");
		printf("\n\t\t  6. SAIR ");
		printf("\n\t\t  Entre com um valor (1-6):");

		scanf("%d", &dch);
		return dch;
	}
	
	//##################################################
	//##################################################
	
	void incluir()
	{
		contato *dptr,*dprev;
		int retorno;
		
		if ((fp = fopen("agenda.db", "a")) == NULL)				//Abre um arquivo texto para gravação. Os dados serão adicionados no fim do arquivo ("append") 
        {														//se ele já existir, ou um novo arquivo será criado, no caso de arquivo não existente anteriormente.
     
        printf ("O arquivo da lista nao pode ser aberto!\n");
        printf ("Insira dados!\n");
        getch();
        exit(1);
        } else {
		
		
		temporario=(contato *)malloc(sizeof(contato));
		
		temporario->codigo = temporario->codigo + 1;
		printf("Nome: ");
		scanf("%s", temporario->nome);
		printf("Data Nasc:");
		scanf("%s", temporario->dtnascimento);
		printf("E-mail: ");
		scanf("%s", temporario->email);
		printf("Telefone: ");
		scanf("%s", temporario->telefone);
		
		temporario->proximo=NULL;
		
	}
		
		if(inicio==NULL)
		{
			inicio=temporario;
		} 
			
	 	dprev=dptr=inicio;
	 	while((temporario->codigo) > (dptr->codigo)){
	 		dprev=dptr;
	 		dptr= dptr->proximo;
		if (dptr == NULL) break;
	 	}
			if(dptr==dprev) {
				temporario->proximo=inicio;
				inicio=temporario;
			}
			else if(dptr==NULL)
				dprev->proximo=temporario;
			else {
				temporario->proximo=dptr;
				dprev->proximo=temporario;
			}

		retorno = fwrite (&temporario, sizeof(struct agenda) ,1,fp);
		fclose (fp);
		
		    if (retorno == 1) {
               printf(" \nGravacao ok ! ");
           }
			 getch();
	}
	
	//##################################################
	//##################################################
		
	void consultar()
	 {
		contato *dptr;
		int dstr,retorno;
		
		
		if ((fp = fopen("agenda.db", "a")) == NULL)				//Abre um arquivo texto para gravação. Os dados serão adicionados no fim do arquivo ("append") 
        {														//se ele já existir, ou um novo arquivo será criado, no caso de arquivo não existente anteriormente.
			printf ("O arquivo da lista nao pode ser aberto!\n");
			printf ("Insira dados!\n");
			getch();
			exit(1);
        }
		
		if(inicio==NULL) {
			printf("\n\t\t\tAgenda est� vazia....\n");
			getch();
			return;
		}
		printf("Entre com o c�digo do contato : ");
		scanf("%d",dstr);
		dptr=inicio;
		
		retorno = fread(&dptr, sizeof(struct agenda), 1, fp); // retorna o número de unidades no arquivo efetivamente lidas
		
		 while(dptr->codigo != dstr || retorno == 1)
		 {
			dptr= dptr->proximo;
			
			if (dptr == NULL) 
			{
				break;
			}
		 }
		if(dptr!=NULL) {
			
			printf("Codigo : %d\n",dptr->codigo);
			printf("Nome : %s\n",dptr->nome);
			printf("Data Nasc : %s\n",dptr->dtnascimento);
			printf("E-mail : %s\n",dptr->email);
			printf("Telefone : %s\n",dptr->telefone);
		}
		else {
			printf("Nenhum registro encontrado .......\n");
		}
		
		   if (retorno == 1) {
               printf(" \nGravacao ok ! ");
           }
		fclose(fp);
	 getch();
	       
	 
	}
	
	//##################################################
	//##################################################
	
	void alterar()
	{
		contato *dptr;
		int dstr, retorno, sucesso;
		
		if ((fp = fopen("agenda.db", "a")) == NULL)				//Abre um arquivo texto para gravação. Os dados serão adicionados no fim do arquivo ("append") 
        {														//se ele já existir, ou um novo arquivo será criado, no caso de arquivo não existente anteriormente.
			printf ("O arquivo da lista nao pode ser aberto!\n");
			printf ("Insira dados!\n");
			getch();
			exit(1);
        }
		
		if(inicio==NULL) {
			printf("\n\t\t\tAgenda est� vazia....\n");
		getch();
			return;
		}
		printf("Entre com o c�digo do contato : ");
		scanf("%d",dstr);
		dptr=inicio;
		
		retorno = fread(&dptr, sizeof(struct agenda), 1, fp); // retorna o número de unidades no arquivo efetivamente lidas
		
	 while(dptr->codigo != dstr)
	 {
	 	dptr= dptr->proximo;
		if (dptr == NULL) 
		{
			break;
		}
	 }
		if(dptr!=NULL) {
			
			printf("\n\t\t Nome : %s", dptr->nome);

			scanf("%s", dptr->nome);
			printf("\n\t\t Data Nasc : %s", dptr->dtnascimento);

			scanf("%s", dptr->dtnascimento);
			printf("\n\t\t E-mail : %s", dptr->email);

			scanf("%s", dptr->email);
			printf("\n\t\t Telefone : %s", dptr->telefone);

			scanf("%s", dptr->telefone);
		}
		else {
			printf("Nenhum registro encontrado .......\n");
		}
		
//			fseek(fp, dptr->proximo, SEEK_SET); 	// volta para a posicao anterior a da leitura onde o registro começa
			
			sucesso= fwrite(&dptr,sizeof(struct agenda),1,fp) == sizeof(struct agenda);
			

            printf(" \nGravacao ok ! ");
        
		
		if (!sucesso) {
			printf("arquivo nao encontrado no arquivo\n");
		}
		fclose(fp); 
	 getch();
	 
	 
	}
	
	//##################################################
	//##################################################	
	void excluir()
	 {
		contato *dptr,*dprev,*temporario;
		int dstr, retorno;
		char dyn='n';
		
		if ((fp = fopen("agenda.db", "a")) == NULL)				//Abre um arquivo texto para gravação. Os dados serão adicionados no fim do arquivo ("append") 
        {														//se ele já existir, ou um novo arquivo será criado, no caso de arquivo não existente anteriormente.
			printf ("O arquivo da lista nao pode ser aberto!\n");
			printf ("Insira dados!\n");
			getch();
			exit(1);
        }
		
		if(inicio==NULL) {
			printf("\n\t\t\tAgenda esta vazia....\n");
			getch();
			return;
		}
		printf("Entre com o Codigo para apagar : ");
		scanf("%d",dstr);
		dprev=dptr=inicio;
		
		retorno = fread(&dptr, sizeof(struct agenda), 1, fp); // retorna o número de unidades no arquivo efetivamente lidas
		
		 while(dptr->codigo != dstr){
			dprev=dptr;
			dptr= dptr->proximo;
		if (dptr == NULL) break;
		 }
			if(dptr!=NULL){
				printf("\nApagar Contatos.....Confirma [s/n]: ");
				dyn=getch();
		printf("\n\n---------------------------------------------------------");
				printf("\nCodigo : %d\n",dptr->codigo);
				printf("Nome : %s\n",dptr->nome);
				printf("Data Nasc : %s\n",dptr->dtnascimento);
				printf("E-mail : %s\n",dptr->email);
				printf("Telefone : %s\n",dptr->telefone);
		printf("---------------------------------------------------------");
				if(dyn=='s') {
					if (dptr==inicio) {
						temporario=inicio->proximo;
						free(inicio);
						inicio=temporario;
					}
					else {
						temporario=dptr->proximo;
						free(dptr);
						dprev->proximo=temporario;
					}
					printf("\n\n1 Contato Apagado....");
				}
				else
					printf("\n\nContato nao Apagado....");
			}
			else {
				printf("\nNenhum registro encontrado .......");
			}
			fclose(fp);
		 getch();
	}
	
	//##################################################
	//##################################################	
	void listar()
	{
		int retorno;
		contato *dptr;
		
		if ((fp = fopen("agenda.db", "a")) == NULL)				//Abre um arquivo texto para gravação. Os dados serão adicionados no fim do arquivo ("append") 
        {														//se ele já existir, ou um novo arquivo será criado, no caso de arquivo não existente anteriormente.
			printf ("O arquivo da lista nao pode ser aberto!\n");
			printf ("Insira dados!\n");
			getch();
			exit(1);
        }

		
		if(inicio==NULL) {
			printf("\n\t\t\tAgenda esta vazia....\n");
			getch();
			return;
		}
		
		retorno = fread(&dptr, sizeof(struct agenda), 1, fp); // retorna o número de unidades no arquivo efetivamente lidas

		system("cls");
		printf("\t\t------------------------------\n");
		for(dptr=inicio; dptr!=NULL; dptr=dptr->proximo) {
			printf("\t\tCodigo: %d\n", dptr->codigo);
			printf("\n\t\tNome : %s",dptr->nome);
			printf("\n\t\tData Nasc:%s", dptr->dtnascimento);
			printf("\n\t\tE-mail: %s", dptr->email);
			printf("\n\t\tTelefone : %s\n",dptr->telefone);
			printf("\n\t\t------------------------------\n");
	 }
	 
	 fclose(fp);
	 getch();
	}
	
	
	//##################################################
	//##################################################
	
	void main()
	{
		int dch;
		inicio=(contato *)malloc(sizeof(contato));
		inicio=NULL;
		do{
	//		clrscr();
	system("cls");
			dch=menu();
	//clrscr();
	system("cls");
			switch(dch) {
				case 1: incluir();
							break;
				case 2: consultar();
							break;
				case 3: alterar();
							break;
				case 4: excluir();
							break;
				case 5: listar();
							break;
		 }
	 }while(dch!=6);
	}

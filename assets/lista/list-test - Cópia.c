				
//**************************************
// Name: Linked List Example - Telephone Directory
// Description:I hope that this code will be helpful to those (specially the beginners) who want to know about using linked lists. This is actually a very simple program which shows the basic linked list operations like insertion, deletion, searching, modifying and traversing. Any queries related to this code is very welcome.
// Tell me if this piece of code was useful to you !!
// By: Arati Rajbhandari Joshi (from psc cd)
//**************************************

/*---------------------*/
 /* TELEPHONE DIRECTORY */
 /*---------------------*/
# include <stdio.h>
# include <conio.h>
# include <string.h>
# include <stdlib.h>

struct dnode {
char dlname[20], dfname[20], dtel[15];
struct dnode *dnext;
};
typedef struct dnode node;
node *dstart, *dtemp;

int dmenu(); //main menu
void dadd(); //add to list
void dfind(); //search from the list
void dedit(); //edit the record
void ddel(); //delete from the list
void ddisp(); //display all

int dmenu()
{
int dch;
//	gotoxy(30,5);
	printf("\n\t\t TELEPHONE DIRECTORY ");
//gotoxy(30,6);
printf("\n\t\t  =================== ");
//gotoxy(3,24);
printf("\n\t\t Programmed By: Arati Rajbhandari");
//	gotoxy(30,10);
	printf("\n\t\t  1. Add ");
//	gotoxy(30,11);
	printf("\n\t\t  2. Find ");
//	gotoxy(30,12);
	printf("\n\t\t  3. Edit ");
//	gotoxy(30,13);
	printf("\n\t\t  4. Delete ");
//	gotoxy(30,14);
	printf("\n\t\t  5. Display All ");
//	gotoxy(30,15);
	printf("\n\t\t  6. EXIT ");
//	gotoxy(30,20);
	printf("\n\t\t  Enter your choice(1-6):");
//	gotoxy(55,20);
	scanf("%d", &dch);
	return dch;
}
void dadd()
{
	node *dptr,*dprev;
	dtemp=(node *)malloc(sizeof(node));
	printf("First name: ");
	scanf("%s", dtemp->dfname);
	printf("Last name:");
	scanf("%s", dtemp->dlname);
	printf("Telephone No.: ");
	scanf("%s", dtemp->dtel);
	dtemp->dnext=NULL;
	if(dstart==NULL) dstart=dtemp;
	else {
 	dprev=dptr=dstart;
 	while(strcmp(dtemp->dfname,dptr->dfname)>0){
 		dprev=dptr;
 		dptr= dptr->dnext;
	if (dptr == NULL) break;
 	}
		if(dptr==dprev) {
			dtemp->dnext=dstart;
			dstart=dtemp;
}
		else if(dptr==NULL)
			dprev->dnext=dtemp;
		else {
			dtemp->dnext=dptr;
			dprev->dnext=dtemp;
		}
	}
}
void dfind()
 {
	node *dptr;
	char dstr[20];
	if(dstart==NULL) {
		printf("\n\t\t\tTelephone Directory is Empty....\n");
getch();
		return;
	}
	printf("First Name to Find : ");
	scanf("%s",dstr);
 dptr=dstart;
 while(strcmp(dptr->dfname,dstr)!=0){
 	dptr= dptr->dnext;
if (dptr == NULL) break;
 }
	if(dptr!=NULL) {
		printf("First Name : %s\n",dptr->dfname);
		printf("Last Name : %s\n",dptr->dlname);
		printf("Phone Number : %s\n",dptr->dtel);
	}
	else {
		printf("No Matching Records Found .......\n");
	}
 getch();
}
void dedit()
{
	node *dptr;
	char dstr[20];
	if(dstart==NULL) {
		printf("\n\t\t\tTelephone Directory is Empty....\n");
getch();
		return;
	}
	printf("First Name to Edit : ");
	scanf("%s",dstr);
 dptr=dstart;
 while(strcmp(dptr->dfname,dstr)!=0){
 	dptr= dptr->dnext;
if (dptr == NULL) break;
 }
	if(dptr!=NULL) {
		printf("\n\t\t First Name : %s", dptr->dfname);
//		gotoxy(14,19);
		scanf("%s", dptr->dfname);
		printf("\n\t\t Last Name : %s", dptr->dlname);
//		gotoxy(13,20);
		scanf("%s", dptr->dlname);
		printf("\n\t\t Phone Number : %s", dptr->dtel);
//		gotoxy(16,21);
		scanf("%s", dptr->dtel);
	}
	else {
		printf("No Matching Records Found .......\n");
	}
 getch();
}
void ddel()
 {
	node *dptr,*dprev,*dtemp;
	char dstr[20],dyn='n';
	if(dstart==NULL) {
		printf("\n\t\t\tTelephone Directory is Empty....\n");
getch();
		return;
	}
	printf("First Name to Delete : ");
	scanf("%s",dstr);
 dprev=dptr=dstart;
 while(strcmp(dptr->dfname,dstr)!=0){
 	dprev=dptr;
 	dptr= dptr->dnext;
if (dptr == NULL) break;
 }
	if(dptr!=NULL){
		printf("\nDeleting Record.....Confirm [y/n]: ");
		dyn=getch();
printf("\n\n---------------------------------------------------------");
		printf("\nFirst Name : %s\n",dptr->dfname);
		printf("Last Name : %s\n",dptr->dlname);
		printf("Phone Number : %s\n",dptr->dtel);
printf("---------------------------------------------------------");
		if(dyn=='y') {
			if (dptr==dstart) {
				dtemp=dstart->dnext;
				free(dstart);
				dstart=dtemp;
			}
			else {
				dtemp=dptr->dnext;
				free(dptr);
				dprev->dnext=dtemp;
			}
			printf("\n\n1 Record Deleted....");
		}
		else
			printf("\n\nRecord not Deleted....");
	}
	else {
		printf("\nNo Matching Records Found .......");
	}
 getch();
}
void ddisp()
{
	node *dptr;
	if(dstart==NULL) {
		printf("\n\t\t\tTelephone Directory is Empty....\n");
getch();
		return;
	}
//	clrscr();
system("cls");
	printf("\t\t------------------------------\n");
	for(dptr=dstart; dptr!=NULL; dptr=dptr->dnext) {
		printf("\t\tFirst name: %s", dptr->dfname);
		printf("\n\t\tLast name:%s", dptr->dlname);
		printf("\n\t\tTelephone No.: %s", dptr->dtel);
		printf("\n\t\t------------------------------\n");
 }
 getch();
}
void main()
{
	int dch;
	dstart=(node *)malloc(sizeof(node));
	dstart=NULL;
	do{
//		clrscr();
system("cls");
		dch=dmenu();
//clrscr();
system("cls");
		switch(dch) {
			case 1: dadd();
						break;
			case 2: dfind();
						break;
			case 3: dedit();
						break;
			case 4: ddel();
						break;
			case 5: ddisp();
						break;
	 }
 }while(dch!=6);
}

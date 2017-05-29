#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


typedef struct carro
{
    char modelo[30];
    float potenciaMotor;
    int anoFabricacao,
        numPortas;
}CARRO;

Exibe(CARRO *car)
void Exibe(CARRO *car)
{
    printf("Modelo: %s\n", car->modelo);
    printf("Motor: %.1f\n", car->potenciaMotor);
    printf("Ano: %d\n", car->anoFabricacao);
    printf("%d portas\n", car->numPortas);
}


int main(int argc, char *argv[]) {
	CARRO fusca = {"Fuscao preto", 1.5, 74, 2};
    Exibe(*fusca);
	return 0;
}

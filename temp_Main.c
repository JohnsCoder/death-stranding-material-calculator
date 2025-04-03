#include <stdio.h>


int* calcMaterias(const int* materialList, const int materialListLength);

int main() {

int listaMetaisSize = 7;
int listaMetais[] = {1000, 800, 600, 400, 200, 100, 50};
int indiceMetais = 0;

int listaMetaisNecessarios[100] = {0};
int indiceMetaisNecessarios = 0;

int totalMetais;
int metaisProgresso;


int listaCeramicasSize = 7;
int listaCeramicas[] = {800, 640, 480, 320, 160, 80, 40};
int indiceCeramicas = 0;

int listaCeramicasNecessarias[100] = {0};
int indiceCeramicasNecessarias = 0;

int totalCeramicas;
int ceramicasProgresso;

int ceramicasFaltantes;


printf("Insira progresso da autopavimentadora: ex. 1020/2050\n");
printf("Metais: \n");
scanf("%d/%d", &metaisProgresso, &totalMetais);
// printf("Cerâmicas: \n");
// scanf("%d, %d", &ceramicasProgresso, &totalCeramicas);

int metaisFaltantes = totalMetais - metaisProgresso;
int debugCounter = 0;
while(indiceMetais < listaMetaisSize) {
debugCounter++;
if (debugCounter > 20) {
return 0;
}
	int metal = listaMetais[indiceMetais];
	int restante = metaisFaltantes - metal; 
// printf("metal %d\n", metal);
// printf("metaisFaltantes %d\n", metaisFaltantes);
//  printf("restante %d\n", restante);	
	if (restante > 0) {
		listaMetaisNecessarios[indiceMetaisNecessarios] = listaMetais[indiceMetais];
		indiceMetaisNecessarios++;
		metaisFaltantes = restante;	
		
	}
// printf("restante %d\n", restante);
	if (restante < 0) {

		int modulosRestante = restante * -1;
		int overflow = 0; 
		for (int i = 0; i < listaMetaisSize; i++) {
//			printf("modulosRestante %d\n", modulosRestante);
//			printf("listaMetais[i] %d\n", listaMetais[i]);

			if (modulosRestante >= listaMetais[i]) {
				overflow = 1;			
			
			}


		}
// printf("modulosRestante %d",modulosRestante);

			if (overflow < 1) {
				listaMetaisNecessarios[indiceMetaisNecessarios] = listaMetais[indiceMetais];
				indiceMetais = listaMetaisSize;
	
			} else {
							indiceMetais++;
}	
	}

if (restante == 0) {
listaMetaisNecessarios[indiceMetaisNecessarios] = listaMetais[indiceMetais];
indiceMetais = listaMetaisSize;
	}	
}


printf("Lista Metais:\n");
	for (int i = 0; i < sizeof(listaMetaisNecessarios) / sizeof(listaMetaisNecessarios[0]) - 1; i++) {
		if (listaMetaisNecessarios[i] > 0) {
		printf("%d\n", listaMetaisNecessarios[i]);	
}

}
return 0;
}


int* calcMaterials(const int* materialList, const int materialListSize) {






} 

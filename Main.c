#include <stdio.h>


int* calcMaterials(const int* materialList, const int materialListLength, int needMaterialAmount);

int main() {

int listaMetaisSize = 7;
int listaMetais[] = {1000, 800, 600, 400, 200, 100, 50};

int totalMetais;
int metaisProgresso;

int listaCeramicasSize = 7;
int listaCeramicas[] = {800, 640, 480, 320, 160, 80, 40};

int totalCeramicas;
int ceramicasProgresso;


printf("Insira progresso da autopavimentadora: ex. 1020/2050\n");
printf("Metais: \n");
scanf("%d/%d", &metaisProgresso, &totalMetais);
printf("Cerâmicas: \n");
scanf("%d/%d", &ceramicasProgresso, &totalCeramicas);

int metaisFaltantes = totalMetais - metaisProgresso;
int ceramicasFaltantes = totalCeramicas - ceramicasProgresso;
int debugCounter = 0;

int* listaMetaisNecessarios = calcMaterials(listaMetais, listaMetaisSize, metaisFaltantes);
int* listaCeramicasNecessarias = calcMaterials(listaCeramicas, listaCeramicasSize, ceramicasFaltantes);

printf("Lista Metais:\n");
	for (int i = 0; i < 20; i++) {
		if (listaMetaisNecessarios[i] > 0) {
		printf("%d\n", listaMetaisNecessarios[i]);	
}

}

printf("Lista Cerâmicas:\n");
	for(int i = 0; i < 20; i++) {
		if (listaCeramicasNecessarias[i] > 0) {
			printf("%d\n", listaCeramicasNecessarias[i]);
}
}

return 0;
}


int* calcMaterials(const int* materialList, const int materialListLength, int needMaterialAmount) {

int needMaterialList[100] = {0};
int indexNeedMaterial = 0;

int indexMaterial = 0;

while(indexMaterial < materialListLength) {

int material = materialList[indexMaterial];
int remaindMaterial = needMaterialAmount - material;
//  printf("needMaterial: %d\n", needMaterialAmount);

 printf("Material: %d\n", material);

 printf("remaindMaterial: %d\n", remaindMaterial);
if (remaindMaterial > 0) {

needMaterialList[indexNeedMaterial] = material;
indexNeedMaterial++;
needMaterialAmount = remaindMaterial;


}

if (remaindMaterial < 0) {

int modulosRemaindMaterial = remaindMaterial * -1;
int overflowMaterial = 0;

for (int idx = 0; idx < materialListLength; idx++) {

if (modulosRemaindMaterial >= materialList[idx]) {

overflowMaterial = 1;

}
}

if (overflowMaterial < 1) {

needMaterialList[indexNeedMaterial] = material;
indexMaterial = materialListLength;
 



} else {

indexMaterial++;

}
}
if (remaindMaterial == 0) {

needMaterialList[indexNeedMaterial] = material;
indexMaterial = materialListLength;
}
}


return needMaterialList;

} 

#include <iostream>
void imprimir(int arreglo[], int tam) {
	for (int i = 0; i < tam; i++)
	{
		std::cout << arreglo[i]<<" ";
	}

}
void bubbleSort(int arreglo[], int tam,int tam2) {
	int temp; // creo variable temporal donde almacenare el valor que quiero mover
	for (int i = 0; i < tam-1; i++)
	{
		for (int j = 1; j < tam2; j++)
		{
			if (arreglo[j] < arreglo[j - 1]) {// intercambia de lugar la mayor por la menor.
				temp = arreglo[j];
				arreglo[j] = arreglo[j - 1];
				arreglo[j - 1] = temp;
			}
		}
		tam2--;
	}
}
void insertionSort(int arreglo[],int tam, int pos=0,int temp=0) {//creamos una variable para almacenar el dato que vamos a insertar, y una que useamos para saber posision 
	for (int i = 0; i < tam; i++)
	{
		pos = i;
		temp = arreglo[i];
		while ((pos>0)&&(arreglo[pos-1]>temp))// mietras el numero anterior sea mayor se ira moviendo el dato hacia la "izquierda".
		{
			arreglo[pos] = arreglo[pos - 1];
			pos--;
		}
		arreglo[pos] = temp;// inserta el menor a la izquierda.
	}
}
void seleccionSort(int arreglo[], int tam, int temp = 0, int min = 0) { // hacemos  una variable que contenga el dato minimo, y una que guarde la posision del dato minimo
	for (int i = 0; i < tam; i++)
	{
		min = i;// ponemos la posicion de hasta la izquierda como la menor, asi si detectamos otro numero mas pequenio
		for (int j = i+1; j < tam; j++)
		{
			if (arreglo[j]<arreglo[min]) // encuentra el dato minimo del arreglo
			{
				min = j;
			}
		}
		temp = arreglo[i]; // Intercambia de lugar el menor con el de hasta la izquierda.
		arreglo[i] = arreglo[min];// Intercambia de lugar el menor con el de hasta la izquierda.
		arreglo[min] = temp;// Intercambia de lugar el menor con el de hasta la izquierda.
	}
}
void quickSort(int arreglo[], int der, int izq) {
	int i = izq, j = der, temp;
	int p = arreglo[(izq + der) / 2];
	while (i <= j) {
		while (arreglo[i] < p) i++;
		while (arreglo[j] > p) j--;
		if (i <= j) {
			temp = arreglo[i];
			arreglo[i] = arreglo[j];
			arreglo[j] = temp;
			i++;
			j--;
		}
	}
	if (izq < j) {
		quickSort(arreglo, j, izq);
	}
	if (der > i) {
		quickSort(arreglo, der, i);
	}
}

int main() {
	int arreglo[] = { 65,54,2,46,8,35,46,95,85,22,15,3 };
	int tam = sizeof(arreglo) / sizeof(arreglo[0]);

	//bubbleSort(arreglo, tam, tam); // Acomoda de menor a mayor.
	//insertionSort(arreglo, tam);// Acomoda de menor a mayor.
	//seleccionSort(arreglo, tam);// Acomoda de menor a mayor.
	quickSort(arreglo, tam-1, 0);
	imprimir(arreglo, tam); //Imprime la lista.
	std::cin.get();
	return 0;
}
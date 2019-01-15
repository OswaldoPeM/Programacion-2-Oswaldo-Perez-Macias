#include <iostream>
void imprimir(int arreglo[], int tam) {
	for (int i = 0; i < tam; i++)
	{
		std::cout << arreglo[i]<<" ";
	}

}

void bubbleSort(int arreglo[], int tam,int tam2) {
	int temp, c = 0; // creo variable temporal donde almacenare el valor que quiero mover
	bool orden = true;
	for (int i = 0; i < tam-1; i++)
	{
		orden = true;
		for (int j = 1; j < tam2; j++)//
		{
			c++;
			if (arreglo[j] < arreglo[j - 1]) {// intercambia de lugar la mayor por la menor.
				temp = arreglo[j];
				arreglo[j] = arreglo[j - 1]; // cuando ya esta ordenado hace iteraciones de mas.
				arreglo[j - 1] = temp;
				orden = false;
			}
		}
		if (orden) break;
		tam2--;
	}
	std::cout << c << " iteraciones reales\n";
}
void insertionSort(int arreglo[],int tam, int pos=0,int temp=0) {//creamos una variable para almacenar el dato que vamos a insertar, y una que useamos para saber posision 
	int c = 0;
	for (int i = 0; i < tam; i++)
	{
		pos = i;
		temp = arreglo[i];
		while ((pos > 0 ) && (arreglo[pos-1] > temp))// mietras el numero anterior sea mayor se ira moviendo el dato hacia la "izquierda".
		{
			c++;
			arreglo[pos] = arreglo[pos - 1];
			pos--;
			
		}
		arreglo[pos] = temp;// inserta el menor a la izquierda.
		
	}
	std::cout << c << " iteraciones reales\n";
}
void seleccionSort(int arreglo[], int tam, int temp = 0, int min = 0) { // hacemos  una variable que contenga el dato minimo, y una que guarde la posision del dato minimo
	int c = 0;
	bool orden ;
	for (int i = 0; i < tam; i++)
	{
		orden = true;
		min = i;// ponemos la posicion de hasta la izquierda como la menor, asi si detectamos otro numero mas pequenio
		for (int j = i+1; j < tam; j++)
		{
			c++;
			if (arreglo[j]<arreglo[min]) // encuentra el dato minimo del arreglo
			{
				min = j;
				
			}
			if ((j != 0) && (arreglo[j] < arreglo[j - 1])) {
				orden = false;
			}
		}
		if (orden) break;
		temp = arreglo[i]; // Intercambia de lugar el menor con el de hasta la izquierda.
		arreglo[i] = arreglo[min];// Intercambia de lugar el menor con el de hasta la izquierda.
		arreglo[min] = temp;// Intercambia de lugar el menor con el de hasta la izquierda.
	}
	std::cout << c << " iteraciones reales\n";
}
void quickSort(int arreglo[], int der, int izq) { // pide un rango de donde a donde va a comparar
	int i = izq, j = der, temp;
	int p = arreglo[der]; //    // este numero sera el de referencia para comparar de izquierda a derecha.
	while (i <= j) {
		while (arreglo[i] < p) i++; //compara con el numero de la izquierda y si es menor al de referencia se mueve un lugar a la derecha
		while (arreglo[j] > p) j--; // compara con el numero de la derecha y si este es mayor al de la referencia se mueve un lugar a la izquierda
		if (i <= j) { // mientras izquierda sea menor o igual a derecha hacer un intercambio como el que se ha visto en el bubble sort.
			temp = arreglo[i];
			arreglo[i] = arreglo[j];
			arreglo[j] = temp;
			i++;
			j--;
		}
	}
	if (izq < j) { // ya con los numeros menores a la referencia acomoda los numeros menores de la misma forma
		quickSort(arreglo, j, izq);
	}
	if (der > i) { // acomoda los numero mayores al numero de referencia
		quickSort(arreglo, der, i);
	}
}

int main() {
	int arreglo[] = { 1,2,3,4,5 };
	int tam = sizeof(arreglo) / sizeof(arreglo[0]);
	int opc = 0;
	std::cout << "1 BubbleSort, 2 inserionSort,3 seleccionSort, 4 quickSort" << std::endl;
	std::cin >> opc;
	switch (opc)
	{

	case 1:
		bubbleSort(arreglo, tam, tam); // Acomoda arreglos de menor a mayor.
		break;
	case 2:
		insertionSort(arreglo, tam);// Acomoda arreglos de menor a mayor.
		break;
	case 3:
		seleccionSort(arreglo, tam);// Acomoda arreglos de menor a mayor.
		break;
	case 4:
		quickSort(arreglo, tam-1, 0);// Acomoda arreglos de menor a mayor.
		break;
	default:
		break;
	}
	imprimir(arreglo, tam); //Imprime la lista.
	std::cin.ignore();
	std::cin.get();
	return 0;
}
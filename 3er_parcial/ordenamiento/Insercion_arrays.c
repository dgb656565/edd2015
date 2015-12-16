void ordenar(int arr[], int n)
{
	int i; 
	int a;
	int aux;

	for (i=1; i < n -1; i++){
		aux = arr[i];

		for (a=i-1; a >= 0 && arr[a] > aux; a--)
		arr[a + 1] = arr[a];
		
		arr[a+1] = aux;
	}
}﻿

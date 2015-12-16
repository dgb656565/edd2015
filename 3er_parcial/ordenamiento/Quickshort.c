int pivot(int *unarray, int izq, int der)
{
	int i;
	int pivote
	int valor_pivote;
	int aux;

	pivote = izq;
	valor_pivote = unarray[pivote];
	for (i=izq+1; i<=der; i++){
		if (unarray[i] < valor_pivote){
			pivote++;
			aux = unarray[i];
			unarray[i] = unarray[pivote];
			unarray[pivote] = aux;
		}
	}
	aux = unarray[izq];
	unarray[izq] = unarray[pivote];
	unarray[pivote] = aux;

	return pivote;
}

void Quicksort(int *unarray, int izq, int der)
{
	int pivote;

	if(izq < der){
		pivote = pivot(unarray, izq, der);
		Quicksort(unarray, izq, pivote - 1);
		Quicksort(unarray, pivote + 1, der);
	}
}

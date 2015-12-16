void Merge(int *A,int *L,int conta_izq,int *R,int conta_der)
{
	int i,j,k;

	i = 0; j = 0; k =0;

	while(i<conta_izq && j< conta_der) {
		if(L[i]  < R[j]) 
			A[k++] = L[i++];
		else 
			A[k++] = R[j++];
	}
	while(i < conta_izq) 
		A[k++] = L[i++];
	while(j < conta_der) 
		A[k++] = R[j++];
}

 
void MergeSort(int *A, int num)
{
	int medio;
	int i; 
	int *L; 
	int *R;

	if(num < 2) 
		return; 

	medio = num / 2; 

	L = (int*) malloc(medio*sizeof(int)); 
	R = (int*) malloc((num - medio)*sizeof(int)); 

	for(i = 0;i<medio;i++) 
		L[i] = A[i];
	for(i = medio;i<n;i++)
		R[i - medio] = A[i];

	MergeSort(L, medio);
	MergeSort(R, num - medio);
	Merge(A, L, medio, R, num - medio);

	free(L);
	free(R);
}

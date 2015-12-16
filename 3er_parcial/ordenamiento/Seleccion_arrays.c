void seleccion(arr[], int n)
{
	int i;
	int j;
	int indicemenor;
	int aux;

	for(i=0; i < n-1; i++){
 		indicemenor=i;
 		for(j=i+1; j < n; j++)
  			if(arr[j] < arr[indicemenor])
  			indicemenor = j;
				if(i != indicemenor){
    				aux = a;
    				a = arr[indicemenor];
    				arr[indicemenor] = aux;
   				}
  	}
}

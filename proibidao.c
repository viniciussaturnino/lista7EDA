#include<stdio.h>
#include<stdlib.h>

void merge(int vetor[], int inicio, int meio, int fim) {
    int com1 = inicio, com2 = meio+1, com_aux = 0, tam = fim-inicio+1;
    int *aux;
    aux = (int*)malloc(tam * sizeof(int));
    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            aux[com_aux] = vetor[com1];
            com1++;
        } else {
            aux[com_aux] = vetor[com2];
            com2++;
        }
        com_aux++;
    }
    while(com1 <= meio){
        aux[com_aux] = vetor[com1];
        com_aux++;
        com1++;
    }
    while(com2 <= fim) {
        aux[com_aux] = vetor[com2];
        com_aux++;
        com2++;
    }
    for(com_aux = inicio; com_aux <= fim; com_aux++){
        vetor[com_aux] = aux[com_aux-inicio];
    }
}
void mergeSort(int vetor[], int inicio, int fim){
    if (inicio < fim) {
        int meio = (fim+inicio)/2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, inicio, meio, fim);
    }
}
int bSearch(int v[], int tam, int x) {
		int a=0, b=tam-1;
		while(a<=b){
				int m=(a+b)/2;
				if(v[m]==x)
          return 1;
				else if(v[m] < x)
          a=m+1;
				else
          b=m-1;
		}
		if(v[a]==x)
      return 1;
  return 0;
}

int main(){
    int n, *vetor;
    int x;
    scanf("%d",&n);
    vetor = malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d",&vetor[i]);
    mergeSort(vetor,0,n);
    while(scanf("%d",&x)!=EOF){
        if(bSearch(vetor,n,x))
          printf("sim\n");
        else
          printf("nao\n");
    }
    return 0;
}

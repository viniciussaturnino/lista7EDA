#include<stdio.h>
#include<stdlib.h>

int buscaBinaria(long int *v,long int n,long int x){
    int e,d,m;
    e=-1;
    d=n;
    while(e<d-1){
        m=(e+d)/2;
        if (v[m]==x)
          return m;
        if(v[m]<x)
          e=m;
        else
          d=m;
    }
    return d;
}

int main(){
    long int c,n,x,y,v,p=0,*circulo;
    scanf("%ld%ld",&c,&n);
    circulo = malloc(c*sizeof(int));
    for(int i=0;i<c;i++){
        scanf("%ld",&circulo[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%ld%ld",&x,&y);
        if(x<0)
          x*=-1;
        if(y<0)
          y*=-1;
        if(x>y)
          v=x;
        else
          v=y;
        v=buscaBinaria(circulo,c,v);
        p+=c-v;
        if((circulo[v]==x&&y!=0)||(circulo[v]==y&&x!=0)){
            p--;
        }
    }
    printf("%ld\n",p);
    free(circulo);
    return 0;
}

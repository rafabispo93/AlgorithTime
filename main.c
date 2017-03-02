/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: rafael
 *
 * Created on 2 de Março de 2017, 13:21
 */

#include <stdio.h>
#include <stdlib.h>

int N;
int * A;
int contMergeSort;
int contQuickSort;

long bolha(void) {
   int parar=0;  
   int aux;
   long cont=0;
   int i;
   long trocas = 0;
   
   while(parar == 0)
   {
       parar = 1;   
       for(i=0;i<N;++i)
       {
           cont++;
           if(A[i]>A[i+1])
           {   
               trocas++;
               parar = 0;
               aux = A[i];
               A[i] = A[i+1];
               A[i+1] = aux;
           }
       }
   }
   printf("trocas da bolha: %d e ", trocas);
   return cont;     
}

long selecao(void) {
  long cont=0;
  int i, j, min;
  long trocas = 0;
  
  for (i = 0; i < (N-1); i++) 
   {
    min = i;
    for (j = (i+1); j < N; j++) {
      cont++;
      if(A[j] < A[min]) {
        min = j;
      }
    }
    if (i != min) {
      trocas++;
      int swap = A[i];
      A[i] = A[min];
      A[min] = swap;
    }
  }
  printf("trocas da seleçao: %d e ", trocas);
  return cont;
}

long insercao(void) {

    int i, j, aux;
    long cont = 0;
    long trocas = 0;
    
    for(i = 0; i < N; i++){
                 j = i;
                 while((A[j] < A[j - 1])&&(j!=0)) {
                        trocas++;
                        cont++;
                        aux = A[j];
                        A[j] = A[j - 1];
                        A[j - 1] = aux;
                        j--;    
                }               
     }
    printf("trocas da insercao: %lu e ", trocas);
    return cont;   
}
long trocasMerge = 0;
void merge(int vec[], int vecSize) {
  int mid;
  int i, j, k;
  int* tmp;
 
  tmp = (int*) malloc(vecSize * sizeof(int));
  if (tmp == NULL) {
    exit(1);
  }
 
  mid = vecSize / 2;
 
  i = 0;
  j = mid;
  k = 0;
  while (i < mid && j < vecSize) {
    contMergeSort++;
    if (vec[i] < vec[j]) {
      tmp[k] = vec[i];
      ++i;
    }
    else {
      tmp[k] = vec[j];
      ++j;
    }
    ++k;
  }
 
  if (i == mid) {
    while (j < vecSize) {
      tmp[k] = vec[j];
      ++j;
      ++k;
    }
  }
  else {
    while (i < mid) {
      tmp[k] = vec[i];
      ++i;
      ++k;
    }
  }
 
  for (i = 0; i < vecSize; ++i) {
    vec[i] = tmp[i];
    trocasMerge++;
  }
 
  free(tmp);
}
 
void mergeSort(int vec[], int vecSize) {
  int mid;
  
  contMergeSort++;
  if (vecSize > 1) {
    mid = vecSize / 2;
    mergeSort(vec, mid);
    mergeSort(vec + mid, vecSize - mid);
    merge(vec, vecSize);
  }

}

void swap(int *a, int i, int j) {
   int t = a[i];
   a[i] = a[j];
   a[j] = t;
}
long trocasQuick = 0;
int partition(int *a, int left,int right,int pivot)
{
    int pos, i;
    swap(a, pivot, right);
    trocasQuick++;
    pos = left;
    for(i = left; i < right; i++)
    {
       contQuickSort++;
       if (a[i] < a[right])
       {
          swap(a, i, pos);
          trocasQuick++;
          pos++;
       }
     }
     swap(a, right, pos);
     trocasQuick++;
     return pos;
}
 
void quickSort(int *a, int left, int right)
{
    contQuickSort++;
    if (left < right)
    {
        int pivot = left;
        int pos = partition(a,left,right,pivot);
        quickSort(a,left,pos-1);
        quickSort(a,pos+1,right);
    }
}




int main(void) {
    int i; long j;
    
    printf("digite o tamanho do vetor n: ");
    scanf("%d", &N);
    
    if ( (A = (int *) malloc(N*sizeof(int)) ) == NULL ) {
         printf("Memória Insuficiente!\n");
         exit(1);
    }
    
    if (N<16) printf("vetor = \n");
    for (i=0;i<N;i++) {
        A[i] = N* ((double)rand()/RAND_MAX);    
        if (N<16) printf("%d ", A[i]);             
    }
    printf("\n");
            
    j = bolha();
    printf("comparacoes da bolha: %lu\n", j);
    
    if (N<16) for (i=0;i<N;i++) 
        printf("%d ", A[i]);   
    printf("\n");
    
    if (N<16) printf("vetor = \n");
    for (i=0;i<N;i++) {
        A[i] = N* ((double)rand()/RAND_MAX);    
        if (N<16) printf("%d ", A[i]);             
    }
    printf("\n");
        
    j = selecao();
    printf("comparacoes da selecao: %lu\n", j); 
    
    if (N<16) for (i=0;i<N;i++)
        printf("%d ", A[i]);   
    printf("\n");
    
    if (N<16) printf("vetor = \n");
    for (i=0;i<N;i++) {
        A[i] = N* ((double)rand()/RAND_MAX);    
        if (N<16) printf("%d ", A[i]);             
    }
    printf("\n");
    
    j = insercao();
    printf("comparacoes da insercao: %lu\n", j); 
    
    if (N<16) for (i=0;i<N;i++)
        printf("%d ", A[i]);   
    printf("\n");
    
    contMergeSort = 0;
    
    if (N<16) printf("vetor = \n");
    for (i=0;i<N;i++) {
        A[i] = N* ((double)rand()/RAND_MAX);    
        if (N<16) printf("%d ", A[i]);             
    }
    printf("\n");
    
    mergeSort(A, N);
    printf("trocas do mergesort: %d e", trocasMerge); 
    printf("comparacoes do mergesort: %d\n", contMergeSort); 
    
    if (N<16) for (i=0;i<N;i++)
        printf("%d ", A[i]);   
    printf("\n");    
    
    contQuickSort = 0;
    
    if (N<16) printf("vetor = \n");
    for (i=0;i<N;i++) {
        A[i] = N* ((double)rand()/RAND_MAX);    
        if (N<16) printf("%d ", A[i]);             
    }
    printf("\n");
    
    quickSort(A, 0, N-1);
    printf("trocas da quick: %d e ", trocasQuick);
    printf("comparacoes do quicksort: %d\n", contQuickSort);
    
    
    if (N<16) for (i=0;i<N;i++)
        printf("%d ", A[i]);   
    printf("\n");     
    
    
    system("pause");
    return 0;   
}


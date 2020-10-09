#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// colocando o vetor em ordem decrecente
void selectionSortD(int vetor[], int n)
{
    int min, temp, i;
    for(i=0; i < n; i++)
    {
        min=i;
        for(int j=i+1; j<n; j++)
        {
            if(vetor[j]> vetor[min])
            {
                min=j;
            }
        }
        if(vetor[i]!=vetor[min])
        {
            temp=vetor[i];
            vetor[i]=vetor[min];
            vetor[min]=temp;
        }
    }

}
//ordenção crescente
void bubbleSort(int array[], int length)
{
    int i, j;
    for(i = length - 1; i > 0; i--) {
        for(j = 0; j < i; j++) {
            if(array[j] > array[j+1])
            {
                int temp;
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
void insert_sort(int vetor[], int n)
{
    int j, temp;
    for(int i=1; i< n; i++)
    {
        temp=vetor[i];
        j=i-1;
        while(j>=0 && temp < vetor[j])
        {
            vetor[j+1]=vetor[j];
            j--;
        }
        vetor[j+1]=temp;
    }

}
void selectionSort(int vetor[], int n)
{
    int min, temp, i;
    for(i=0; i < n; i++)
    {
        min=i;
        for(int j=i+1; j<n; j++)
        {
            if(vetor[j]< vetor[min])
            {
                min=j;
            }
        }
        if(vetor[i]!=vetor[min])
        {
            temp=vetor[i];
            vetor[i]=vetor[min];
            vetor[min]=temp;
        }
    }

}
 void quicksort(int values[], int began, int end)
{
    int i, j, pivo, aux;
    i = began;
    j = end-1;
    pivo = values[(began+end)/2];
    while(i <= j)
    {
        while(values[i] < pivo && i < end) i++;
        while(values[j] > pivo && j > began) j--;
        if(i <= j)
        {
            aux = values[i];
            values[i] = values[j];
            values[j] = aux;
            i++;
            j--;
        }
    }
    if(j > began)
    quicksort(values, began, j+1);
    if(i < end)
    quicksort(values, i, end);
}
//mergeSort
void mergesort(int vec[], int vecSize){
    int mid;
    if (vecSize >1){
        mid=vecSize/2;
        mergesort(vec, mid);
        mergesort(vec + mid,vecSize - mid);
        merg(vec, vecSize);
    }

}
void merg(int vec[], int vecSize){
    int mid, i, j, k;
    int *tmp;
    tmp=(int*)malloc(vecSize * sizeof(int));//criando um espaco para o vetor
    if(tmp==NULL){
        exit(1);
    }
    mid=vecSize/2;
    i=0;
    j=mid;
    k=0;
    while((i < mid)&&(j< vecSize)){
        if(vec[i] < vec[j]){
            tmp[k]=vec[i];
            i++;
        }
        else{
            tmp[k]=vec[j];
            j++;
        }
        k++;
    }
    if(i==mid){
        while(j < vecSize){
            tmp[k]=vec[j];
            j++;
            k++;
        }
    }
    else{
        while(i < mid){
            tmp[k]=vec[i];
            i++;
            k++;
        }
    }
    for(i=0; i<vecSize;i++){
        vec[i]=tmp[i];
    }
    free(tmp);
}
//exit mergeSort
//heapsort
void heapsort(int a[], int n) {
   int i = n / 2, pai, filho, t;
   while(n^2) {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n <= 0) return;
          t = a[n];
          a[n] = a[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      a[pai] = t;
   }
}

int main()
{
    double start, stop, elapsed; // variaveis para medir o tempo
    srand(time(NULL));

    int n=100000;
    int vetor[n];
    /*int vselec[n];
    int vins[n];
    int vbubl[n];*/
    int vquick[n];
    int vmer[n];
    int vheap[n];
    for(int i=0; i < n; i++){
        vetor[i] = rand();
    }

    selectionSortD(vetor, n);//ordem decrescente
    for(int i=0; i < n; i++){
        /*vselec[i] = vetor[i];
        vins[i] = vetor[i];
        vbubl[i] = vetor[i];*/
        vquick[i] = vetor[i];
        vmer[i] = vetor[i];
        vheap[i] = vetor[i];
    }

    /*start = (double) clock() / CLOCKS_PER_SEC;
    bubbleSort(vbubl, n);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("Tempo total em segundos do BubbleSort: %f\n", elapsed);

    start = (double) clock() / CLOCKS_PER_SEC;
    insert_sort(vins, n);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("Tempo total em segundos do Insert: %f\n", elapsed);

    start = (double) clock() / CLOCKS_PER_SEC;
    selectionSort(vselec, n);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("Tempo total em segundos do Selection: %f\n", elapsed);*/

    start = (double) clock() / CLOCKS_PER_SEC;//quickSort
    quicksort(vquick, 0, n);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("Tempo total em segundos do QuickSort: %f\n", elapsed);
    start = (double) clock() / CLOCKS_PER_SEC;//mergeSort
    mergesort(vmer, n);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("Tempo total em segundos do MergeSort: %f\n", elapsed);
    start = (double) clock() / CLOCKS_PER_SEC;//heapsort
    heapsort(vheap, n);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("Tempo total em segundos do HeapSort: %f\n", elapsed);

    return 0;
}

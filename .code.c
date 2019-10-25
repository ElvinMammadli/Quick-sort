#include <stdio.h>
#include <stdlib.h>

int partition(int  *arr, int low, int high, int  pivot);
void quickSort(int * nuts, int * bolts, int low, int high);
int al(int a);

int randomize(int first , int last);


void yazdir(int *dizi,int n);
int main()
{
    int n; //dizinin boyutu
    int i;//dizinin elemanlarina erismek icin
    printf("Dizinin boyutunu giriniz  giriniz:");
    scanf("%d",&n);

    int Lock[n],Key[n]; // diziler

    for(i=0;i<n;i++){
        printf("Lock dizisinin %d. elemanini giriniz",i);
        scanf("%d",&Lock[i]);
        printf("\n");
    }
   for(i=0;i<n;i++){
        printf("Key dizisinin %d. elemanini giriniz",i);
        scanf("%d",&Key[i]);
        printf("\n");
    }
            quickSort(Lock, Key, 0, n);

    yazdir(Key,n);//ekrana yazdirir
    yazdir(Key,n);//ekrana yazdirir

//

    return 0;
}



void yazdir(int * array,int n){
    printf("\n dizinin elemanlari : ");
    for(int i=0;i<n;i++){
       printf("%d   ",array[i]);
    }
    printf("\n");
}


int randomize(int first , int last){//random fonksiyonu
        srand(time(NULL));
        return rand()%last+first;

}



 void quickSort(int * Keys, int * Locks, int first, int last)
    {
        if (first < last)
        {   int a= randomize(first,last+1);
            int b= Keys[a];
            int pivot = partition(Locks, first, last,b);

            partition(Keys, first, last, Locks[pivot]);
            quickSort(Keys, Locks, first, pivot-1);
            quickSort(Keys, Locks, pivot+1, last);
        }
    }



int partition(int  *array, int first, int last, int  pivot)
    {
        int i = first;
        int temp1, temp2;
        for (int j = first; j < last; j++)
        {
            if (array[j] < pivot){
                temp1 = array[i];
                array[i] = array[j];
                array[j] = temp1;
                i++;
            } else if(array[j] == pivot){
                temp1 = array[j];
                array[j] = array[last];
                array[last] = temp1;
                j--;
            }
        }
        temp2 = array[i];
        array[i] = array[last];
        array[last] = temp2;

              return i;
    }



#include <iostream>

using namespace std;

void print(int arr[], int cant)
{
    for (int i=0; i<cant ; i++)
    {
        cout << arr[i]<<'\t';
    }
}

int sumaIterativa(int arr[], int cant)
{
    int suma=0;
    for (int i=0; i<cant ; i++)
    {
        suma+=arr[i];
    }
    return suma;
}

int sumaRecursiva(int arr[], int cant)
{
    if (cant==1)
    {
        return arr[cant-1];
    }
    return arr[cant-1] + sumaRecursiva(arr, --cant);
}

void invertir_Iterativo(int arr[], int cant)
{
    int i;
    int guardado;
    int cantidad=cant;
    cant-=1;
    for (i=0; i<cant; i++)
    {
        guardado=arr[i];
        arr[i]=arr[cant];
        arr[cant]=guardado;
        cant-=1;
    }
    print(arr, cantidad);
}

void invertir_Recursiva(int arr[], int cant, int i=0)
{
    if (cant<=i)
    {
        return;
    }
    int guardado=arr[i];
    arr[i]=arr[cant-1];
    arr[cant-1]=guardado;

    invertir_Recursiva(arr, cant-1, i+1);
}

void ordenamientoBurbuja(int arr[], int cant)
{
    int guardado;
    for (int i=1; i<cant ; i++)
    {
        for (int j=0; j<cant-i;j++)
        {
            if (arr[j]>arr[j+1])
            {
                guardado=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=guardado;
            }
        }
    }
    print(arr, cant);
}

void ordenamientoInsertion(int arr[], int cant)
{
    int i=1;
    while (i<cant)
    {
        int j=i;
        while (j>0 && arr[j-1]>arr[j])
        {
            int guardo= arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=guardo;
            j-=1;
        }
        i+=1;
    }
    print(arr,cant);
}

int particion(int arr[], int comienzo, int fin)
{
    int follower=comienzo;
    int lider=comienzo;
    int guardado;
    int guarda;
    while (lider < fin)
    {
        if (arr[lider]<=arr[fin])
        {
            guardado=arr[follower];
            arr[follower]=arr[lider];
            arr[lider]=guardado;
            follower +=1;
        }
        lider+=1;
    }
    guarda=arr[follower];
    arr[follower]=arr[fin];
    arr[fin]=guarda;
    return follower;
}

int _quicksort(int arr[],int comienzo, int fin)
{
    if (comienzo>=fin)
    {
        return 0;
    }
    int p = particion(arr, comienzo, fin);
    _quicksort(arr, comienzo, p-1);
    _quicksort(arr, p+1, fin);
}

void quicksort(int arr[], int cant)
{
    _quicksort(arr,0,cant-1);
    print(arr,cant);
}

int main()
{
    int arr[4]={1,2,4,5};
    print(arr,4);

    cout<<endl;

    cout << "suma Iterativa: " << sumaIterativa(arr, 4)<< endl;

    cout << "suma Recursiva: " << sumaRecursiva(arr, 4)<< endl;

    cout << "inversion Iterativa: " ;
    invertir_Iterativo(arr,4);

    cout<<endl;

    cout << "inversion Recursiva: " ;
    invertir_Recursiva(arr,4);
    print(arr, 4);

    cout<<endl;

    int arra[6]={6,346,2,1,9,334};
    print(arra,6);

    cout<<endl;

    cout<< "ordenamimento Burbuja: ";
    ordenamientoBurbuja(arra,6);

    cout<<endl;

    int lista[4]={82,8,17,48};
    print(lista,4);

    cout<< endl;

    cout<< "ordenamiento InsertionSort: ";
    ordenamientoInsertion(lista,4);

    cout<<endl;

    int l[10]={5,4,3,6,2,7,1,8,9,10};
    print(l,10);

    cout<< endl;

    cout<< "ordenamiento Quicksort: ";
    quicksort(l,10);


    return 0;
}


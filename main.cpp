#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;
//vectores y funciones
//lectura del vector
void leer_vector(int num[], int tamanio)
{
    for(int i=0; i<tamanio; i++)
    {
        cout<<"Ingrese el elemnto #" <<(i+1)<<" : ";
        cin>>num[i];
    }
}
//
void imprime_vectore(int vector[], int tamanio)
{
    cout<<endl<<endl<<"ELEMENTOS DEL VECTOR";
    for(int i=0; i<tamanio; i++)
    {
        cout<<endl<<"Elemento # " << (i+1) <<" : " <<vector[i];
    }
}
//Realizar la sumatoria del elemento del vector
double sumatoria_vector(int vector[], int tamanio)
{
    double suma=0;
    for(int i=0; i<tamanio; i++)
        suma+=vector[i];

    return suma;
}
//Realezar el promedio de los elemtos del vector
int promedio_vector (int vector[], int tamanio)
{
    double promedio=0;
    promedio = sumatoria_vector(vector, tamanio)/tamanio;
    return promedio;
}

//EJERCICIO 1) Funcion que devuelve el elemento minimo del vector
int minimo (int vector[], int tamanio)
{
    int min=vector[0];
    for(int i=0; i<tamanio; i++)
    {
        if(vector[i]<min)
            min=vector[i];
    }
    return min;
}
//2)Función que devuelve el elemento maximo del vector
int maximo (int vector[], int tamanio)
{
    int max=vector[0];
    for(int i=0; i>tamanio; i++)
    {
        if(vector[i]<max)
            max=vector[i];
    }
    return max;
}
//3)Función que devuelve por referencia el elemento mínimo y máximo del vector
void mayor_menor (int vector[], int tamanio, int &mayor, int &menor)
{
    mayor = maximo(vector, tamanio);
    menor = minimo(vector, tamanio);
}
//4)Función que llene el vector con valores aleatorios
void vector_aleatorio(int num[], int tamanio) {
    srand(time(NULL));
    for (int i = 0; i < tamanio; i++) {
        num[i] = 1 + rand() % 1000;
    }
}
//ordenar el vector
void ordenacion_secuencia(int vector[],int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        for (int j = i + 1; j < tamanio; j++) {
            if (vector[i] > vector[j + 1]) {
                int aux;
                aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
            }
        }
    }
}
//1) DISEÑE la funcion que busque un numero entero en el vector.
//la funcion debe devolver verdadero si el elemto existe en el vector,
//o falso en caso contrario.
bool vector_entero(int num[], int tamanio)
{
    bool a;
    for(int i=0;i<tamanio;i++)
    {
        if(num[i]%2==0)
        {
            a= true;
            break;
        }else
        {
            a= false;
        }
    }
    return a;
}

//2) diseñe la funcion que busque un numero entero en el vector.
//la funcion debe devolver la posicion donde el elemento fue encontrado.
//Devuelve -1 si no existe
int vector_entero2(int num[], int tamanio) {
    int acu = 0;

    for (int i = 0; i < tamanio; i++) {
        if (num[i] % 2 == 0) {
            acu = i;
            break;
        } else {
            acu = -1;
        }
    }
    return acu;
}
int main()
{
    const int MAX=7;
    int num[MAX];

    //Llamada a la funcion para leer el vector
    //leer_vector(num, MAX);
    vector_aleatorio(num,MAX);
    imprime_vectore(num, MAX);

    int suma=sumatoria_vector(num,MAX);
    cout<<endl<<"LA SUMATORIA DEL VECTOR ES: "<<suma;
    cout<<endl<<"EL PROMEDIO ES: "<<promedio_vector(num, MAX);

    cout<<endl<<"EL ELEMENTO MAYOR ES: "<<maximo(num,MAX);
    cout<<endl<<"EL ELEMENTO MINIMO ES: "<<minimo(num,MAX);

    int may, men;
    mayor_menor(num,MAX,may,men);
    cout<<endl<<endl<<"Mayor encontrado: "<<may;
    cout<<endl<<endl<<"Menor encontrado: "<<men;

    const int maxi=7;
    int vector[maxi];

    if(vector_entero(vector,maxi)==true)
        cout<<endl<<"VERDADERO";
    if(vector_entero(vector, maxi)==false)
        cout<<endl<<"FALSO";
    cout<<endl<<"la pocision del entero es: "<<vector_entero2(vector, maxi);

    return 0;
}
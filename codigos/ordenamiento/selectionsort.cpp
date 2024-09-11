#include <bits/stdc++.h>
using namespace std;
int MAX_SIZE=10000000;
void selectionSort(int arr[], int n)
{
    //Recorre cada elemento del arreglo. Además, sirve como puntero para determinar desde que posicion empezar la busqueda en el
    //siguiente for.
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        //Por cada posición, se determina si el elemento que ya esta en la posición  es el más menor que los que la siguen. Se recorre
        //el resto del arreglo según la posición y si se encuentra uno más pequeño despues de recorrer todo se intercambian de posición.
        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        if (min_idx != i){
            swap(arr[min_idx], arr[i]);
        }
    }
}

int main(){
    int* arr = new int[MAX_SIZE]; 
    int count = 0;
    ifstream file("sort_dataset10000000.txt");
    string line;
    while (getline(file, line) && count < MAX_SIZE) {
        // Convierte la línea en un número entero y lo guarda en el arreglo
        stringstream ss(line);
        ss >> arr[count];
        count++;
    }
    // Cierra el archivo
    file.close();
    int n = MAX_SIZE;
    auto inicio = std::chrono::high_resolution_clock::now();
    selectionSort(arr,n);
    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracion = fin - inicio;
    std::cout << "El algoritmo tardó: " << duracion.count() << " ms" << std::endl;
    /*
    for (int i = 0; i < MAX_SIZE; i++) {
        cout << arr[i] << " ";
    }
    */
    return 0;
}
//https://www.geeksforgeeks.org/selection-sort-algorithm-2/
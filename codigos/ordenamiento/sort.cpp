#include <bits/stdc++.h>
using namespace std;
int MAX_SIZE=10000000;
int main() {
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
    auto inicio = std::chrono::high_resolution_clock::now();
    //Esta función propia de c++, es un algortimo de ordenamiento que se basa principalmente en la implementación
    //de quicksort pero más optimizado. Incluso puede iterrar entre otros algoritmos de ordenamiento como insertionSort para arreglos
    //relativamente pequeños o HeapSort si le toma más tiempo de lo usual.
    std::sort(arr,arr+ MAX_SIZE);
    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracion = fin - inicio;
    std::cout << "El algoritmo tardó: " << duracion.count() << " ms" << std::endl;
    /*for (int i = 0; i < MAX_SIZE; i++) {
        cout << arr[i] << " ";
    }
    */
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int MAX_SIZE = 100000;

int partition(int arr[], int low, int high) {
  
    // Selecciona el pivote
    int pivot = arr[high];
  
    // Index of smaller element and indicates 
    // the right position of pivot found so far
    int i = low - 1;

    // Recorre el arreglo y compara los elementos con el pivote para finalmente dejar a la derecha de este los numeros menores
    // a él y a su derecha los mayores o iguales. Esto lo realiza mediante el uso de una variable que sivre como apuntador
    // y el intercambio de elementos. Finalmente, intercambia la posición de pivote por el apuntado en i+1 dejando al pivote en su
    //posición correcta. 
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    // Se mueve el pivote por el apuntado por i +1
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

// The QuickSort function implementation
void quickSort(int arr[], int low, int high) {
  
    if (low < high) {
      
        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);

        // Se llama recursivamente a quicksort para que trabaje con los dos arreglos que se pueden generar, a la izquierda
        //del pivote (donde estan los elementos menores al pivote) y a la derecha de este (donde estan los elementos iguales
        //o mayores al pivote).
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main() {
    int* arr = new int[MAX_SIZE]; 
    int count = 0;
    ifstream file("reversesort_dataset100000.txt");
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
    quickSort(arr, 0, count-1);
    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracion = fin - inicio;
    std::cout << "El algoritmo tardó: " << duracion.count() << " ms" << std::endl;
    cout << "Sorted Array\n";
    /*for (int i = 0; i < count; i++) {
        cout << arr[i] << " ";
    }*/
    return 0;
    //https://www.geeksforgeeks.org/quick-sort-algorithm/
}
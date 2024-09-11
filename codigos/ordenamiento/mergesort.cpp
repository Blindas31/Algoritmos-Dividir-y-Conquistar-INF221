#include <bits/stdc++.h>
using namespace std;
int MAX_SIZE=10000000;
// Función auxiliar para empezar el rodenamiento de las divisiones a medida que la recrusividad termina
void merge(int arr[], int p, int q, int r) {
  
  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;
  //Crea dos arreglos dinámicos para guardar las dos partes del arreglo arr en distintos conjuntos.
  int* L = new int[n1];
  int* M = new int[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Finalmente, iteramos entre los dos arreglos para guardar en el arreglo principal los numeros ordenados obtenidos de ambos arreglos. La función merge
  //de toda la vida
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }

}

// Función principal que ejecuta la division de los arreglos en dos partes. Primeramente, el arreglo principal se divide en dos
// y las 2 divisiones se pana nuevamente a un mergesort, iniciando asi la divison recursiva de las partes del arreglo.
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}

// Print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
        cout << endl;
}

// Driver program
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
    mergeSort(arr, 0, MAX_SIZE - 1);
    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracion = fin - inicio;
    std::cout << "El algoritmo tardó: " << duracion.count() << " ms" << std::endl;
    cout << "Sorted array: \n";
    //printArray(arr, count);
    return 0;
}
//https://www.programiz.com/dsa/merge-sort
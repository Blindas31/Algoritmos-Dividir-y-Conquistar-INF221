
#include <bits/stdc++.h>
using namespace std;

// Definición de dimensiones de las matrices A[R1][C1] y B[R2][C2]
#define R1 100 // number of rows in Matrix-1
#define C1 16384 // number of columns in Matrix-1
#define R2 16384 // number of rows in Matrix-2
#define C2 100 // number of columns in Matrix-2


void mulMat(int** mat1, int** mat2,int** rslt)
{
    //Realiza la multiplicacion tradicional de matrices mediante tres ciclos for anidados. Logrando simular el comportamiento
    //de mutliplicacion que conocemos, "fila por columna"
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            rslt[i][j] = 0;

            for (int k = 0; k < R2; k++) {
                rslt[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void cargarMatrizDesdeArchivo(const string& nombreArchivo, int** matriz, int filas, int columnas) {
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            archivo >> matriz[i][j];
        }
    }

    archivo.close();
}

void imprimirMatrizA(int** matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}
void imprimirMatrizB(int** matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int** A = new int*[R1];
    int** B = new int*[R2];
    int** rslt = new int*[R1];
    for (int i = 0; i < R1; ++i)
        A[i] = new int[C1];
    for (int i = 0; i < R2; ++i)
        B[i] = new int[C2];
    for (int i = 0; i < R1; ++i)
        rslt[i] = new int[C2];
    cargarMatrizDesdeArchivo("matrizintA16384.txt",A,R1,C1);
    cargarMatrizDesdeArchivo("matrizintB16384.txt",B,R2,C2);
    
    //imprimirMatrizA(A,R1,C1);
    cout << endl;
    //imprimirMatrizB(B,R2,C2);
    auto inicio = std::chrono::high_resolution_clock::now();
    mulMat(A,B,rslt);
    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracion = fin - inicio;
    cout << endl;
    //imprimirMatrizB(rslt,R1,C2);
    cout << endl;
    std::cout << "El algoritmo tardó: " << duracion.count() << " ms" << std::endl;
    return 0;
}
//https://www.geeksforgeeks.org/c-program-multiply-two-matrices/

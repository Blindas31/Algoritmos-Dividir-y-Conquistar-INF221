// C++ program to multiply two matrices

#include <bits/stdc++.h>
using namespace std;

// Edit MACROs here, according to your Matrix Dimensions for
// mat1[R1][C1] and mat2[R2][C2]
#define R1 100 // number of rows in Matrix-1
#define C1 16384 // number of columns in Matrix-1
#define R2 16384 // number of rows in Matrix-2
#define C2 100 // number of columns in Matrix-2


void mulMat(int** mat1, int** mat2,int** rslt)
{
    //Es similar a la multiplicacion tradicional, pues tambien utiliza 3 ciclos for anidados, sin embargo, esta vez la
    //vision es "fila por fila",por lo que el último for tiene un ligero cambio en la forma de acceder a los datos de la segunda
    //matriz 
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            rslt[i][j] = 0;

            for (int k = 0; k < C1; k++) {
                rslt[i][j] += mat1[i][k] * mat2[j][k];
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
void imprimirMatrizT(int** matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

//Funcion que transpone una matriz
void transponerMatriz(int** matriz, int** transpuesta, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            // Intercambiamos filas por columnas
            transpuesta[j][i] = matriz[i][j];
        }
    }
}

int main() {
    int** A = new int*[R1];
    int** B = new int*[R2];
    int** T = new int*[C2];
    int** rslt = new int*[R1];
    for (int i = 0; i < R1; ++i)
        A[i] = new int[C1];
    for (int i = 0; i < R2; ++i)
        B[i] = new int[C2];
    for (int i = 0; i < C2; ++i)
        T[i] = new int[R2];
    for (int i = 0; i < R1; ++i)
        rslt[i] = new int[C2];
    cargarMatrizDesdeArchivo("matrizintA16384.txt",A,R1,C1);
    cargarMatrizDesdeArchivo("matrizintB16384.txt",B,R2,C2);
    
    //imprimirMatrizA(A,R1,C1);
    cout << endl;
    transponerMatriz(B,T,R2,C2);
    //imprimirMatrizT(T,R2,C2);
    auto inicio = std::chrono::high_resolution_clock::now();
    mulMat(A,T,rslt);
    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracion = fin - inicio;
    cout << endl;
    //imprimirMatrizT(rslt,R1,C2);
    cout << endl;
    std::cout << "El algoritmo tardó: " << duracion.count() << " ms" << std::endl;
    return 0;
}
//https://www.geeksforgeeks.org/c-program-multiply-two-matrices/
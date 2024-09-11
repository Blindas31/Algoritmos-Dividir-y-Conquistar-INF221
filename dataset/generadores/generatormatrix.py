import random
R1 = 512  # Número de filas de la primera matriz
C1 = 100  # Número de columnas de la primera matriz
R2 = 100  # Número de filas de la segunda matriz
C2 = 512  # Número de columnas de la segunda matriz

def guardar_matriz_en_txt(matriz, nombre_archivo):
    with open(nombre_archivo, 'w') as archivo:
        for i, fila in enumerate(matriz):
            archivo.write(" ".join(map(str, fila)))
            if i != len(matriz) - 1:  # Evita el salto de línea para la última fila
                archivo.write("\n")
            
def generar_matriz(rows, cols):
    return [[random.randint(0, 10) for _ in range(cols)] for _ in range(rows)]

matriz1 = generar_matriz(R1, C1)
matriz2 = generar_matriz(R2, C2)

guardar_matriz_en_txt(matriz1,'matrizfuerA16384.txt')
guardar_matriz_en_txt(matriz2,'matrizfuerB16384.txt')
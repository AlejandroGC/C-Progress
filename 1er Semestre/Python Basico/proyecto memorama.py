# Proyecto Integrador
#
#

def crea_matriz(tam_ren, tam_col):
    matriz = []
    for ren in range(tam_ren):
        matriz.append([ren] * tam_col)
    return matriz

def carga_datos_matriz():
    ren_mat = int(input('Cantidad de renglones: '))
    col_mat = int(input('Cantidad de columnas: '))
    matriz = crea_matriz(ren_mat, col_mat)
    muestra_matriz(matriz)
    for ren in range(ren_mat):
        for col in range(col_mat):
            dato = int(input(f'Teclea el dato para el renglon {ren} y la columna {col}: '))
            matriz[ren][col] = dato
    return matriz

def nuestra_matriz():
    for ren in range(len(mat)):
        for col in range(len(mat[ren])):
            print(f'{mat[ren][col]:15}', end='')
    print()

def main():
    tam_ren = int(input())
    tam_col = int(input())
    matriz = crea_matriz(tam_ren, tam_col)
    
    
main()
    
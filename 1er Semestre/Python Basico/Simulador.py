import random

def crear_matriz(tam_ren, tam_col):
    matriz = []
    for ren in range(tam_ren):
        matriz.append([0] * tam_col)
    return matriz

def desplegar(matriz):
    for iR in range(len(matriz)):
        for iC in range(len(matriz[iR])):
            print(f'{matriz[iR][iC]:>5}', end=' ')
        #salto de renglon
        print()
        
def inicializar(matriz):
    valor = 0
    for iR in range(len(matriz)):
        for iC in range(len(matriz[iR])):
            matriz[iR][iC] = valor
            valor = valor + 5
    #retornar matriz actualizada
    return matriz

def inicializa2(matriz):
    for iR in range(len(matriz)):
        for iC in range(len(matriz[iR])):
            matriz[iR][iC] = random.randint(-100,100)
    #retornar matriz actualizada
    return matriz

def mayor(matriz):
    mayor = -2147483637
    for iR in range(len(matriz)):
        imayor = -2147483637
        for iC in range(len(matriz[iR])):
            if matriz[iR][iC] > imayor:
                imayor = matriz[iR][iC]
                mess = iC
        print(f'Empleado {iR}, Maximo: {imayor}, Mes: {mess}')
        if imayor > mayor:
            mayor = imayor
            emp = iR
            mes = mess
    print(f'Empleado con mejores ventas:\n Empleado: {emp}, Maximo: {mayor}, Mes: {mes}')
    
def menor(matriz):
    menor = 2147483637
    for iR in range(len(matriz)):
        imenor = 2147483637
        for iC in range(len(matriz[iR])):
            if matriz[iR][iC] < imenor:
                imenor = matriz[iR][iC]
                mess = iC
        print(f'Empleado {iR}, Minimo: {imenor}, Mes: {mess}')
        if imenor < menor:
            menor = imenor
            emp = iR
            mes = mess
    print(f'Empleado con menor ventas:\n Empleado: {emp}, Minimo: {menor}, Mes: {mes}')

def suma(matriz):
    acumulador = 0
    for iR in range(len(matriz)):
        for iC in range(len(matriz[iR])):
            acumulador += matriz[iR][iC]
    return acumulador
    
    
def promedio(matriz):
    acumulador = 0
    contador = 0
    for iR in range(len(matriz)):
        contador += len(matriz[iR])
        for iC in range(len(matriz[iR])):
            acumulador += matriz[iR][iC]
    return acumulador/contador

def pino(niv):
    p = crear_matriz(niv, niv*2-1)
    ast = 1
    blank = niv-1
    
    for iR in range(len(p)):
        #Dibuja '' , inicializa
        for iC in range(blank):
            p[iR][iC] = ' '
        #dibuja *
        for iC in range(blank, blank+ast):
            p[iR][iC] = '*'
        #rellenar
        for iC in range(blank+ast, len(p[iR])):
            p[iR][iC] = ' '
        
        ast = ast + 2
        blank = blank - 1
    return p
    
def menu():
    print('''1. sumar
2. promedio
3. mayor desplegando r,c
4. menor desplegando r,c
5. mayor por renglon
6. menor por renglon
7. inicializar con multiplos de 5
8. inicializar con valores random
9. Pino
0.Salir''')
    return int(input())

def main():
    matriz = crear_matriz(6,6)
    desplegar(matriz)
    
    opcion = menu()
    
    while opcion != 0:
        if opcion == 1:
            print('La suma =', suma(matriz))
            print("<Enter> para continuar...")
        elif opcion == 2:
            print('El promedio =', promedio(matriz))
            print("<Enter> para continuar...")
        elif opcion == 3:
            desplegar(matriz)
            grande = mayor(matriz)
            print("<Enter> para continuar...")
        elif opcion == 4:
            desplegar(matriz)
            pequeno = menor(matriz)
            print("<Enter> para continuar...")
        elif opcion == 5:
            pass
        elif opcion == 6:
            pass
        elif opcion == 7:
            matriz = inicializar(matriz)
            desplegar(matriz)
            print("<Enter> para continuar...")
        elif opcion == 8:
            ran = inicializa2(matriz)
            desplegar(ran)
            print("<Enter> para continuar...")
        elif opcion == 9:
            niv = int(input("Introduce el nivel: "))
            elpino = pino(niv)
            desplegar(elpino)
            
        else:
            print("Error opcion no existe.")
    
        opcion = menu()

main()
def crear_tableros():
    return [[0] * 5] * 6

def desplegar_matriz(tablero, juego, r1,c1,r2,c2):
    for iR in range(len(tablero)):
        for iC in range(len(tablero[iR])):
            print(tablero[iR][iC], end=' ')
        
        print(iR)
    
def inicializar_tablero(matriz):
    pass

def inicializar_juego(juego):
    pass

def menu():
    return int(input('''1. iniciar juego memorama
0. Salir
Teclea la opcion:
'''))
def main():
    ren = int(input())
    col = int(input())
    cartaF = []
    cartaA = []
    tablero = crear_tableros()
    juego = crear_tableros()
    r1 = int(input())
    r2 = int(input())
    c1 = int(input())
    c2 = int(input())
    matriz = desplegar_matriz(tablero, juego, r1,c1,r2,c2)
    
    
main()
#A01570396

def sumatoria(num):
    sum = 0  # la suma de los digitos
    while num > 0:
        sum = sum + num
        num = num - 1

    print(f'La sumatoria es: {sum}')

def Cpnc(iN):
    cc = 0
    cn = 0
    cp = 0
    iK = 1
    
    while (iK <= iN):
        iV = int(input(f'Ingresa el valor {iK}:'))
        if (iV > 0):
            cp = cp+1
        elif(iV == 0):
            cc = cc+1
        else:
            cn = cn+1
        iK = iK+1
    
    print(f'positivo={cp}\nnegativos={cn}\nceros={cc}')

def tablita(iX):
    iK = 10
    while(iK >= 1):
        print(f'{iK}X{iX}={iX*iK}')
        iK = iK - 1

def promedio(iN):
    iK = 1
    prom = 0.0
    
    while iK <= iN:
        iV = int(input(f'Ingresa el valor {iK}: '))
        prom = prom + iV
        iK = iK + 1
    
    print(prom/iN)

def mayor(iN):
    iK = 1
    mayor = 0
    
    while iK <= iN:
        iV = int(input(f'Introduce el valor {iK}: '))
        if mayor < iV:
            mayor = iV
            print("Ahora es el mayor")
        else:
            print("Es menor")
            
        iK = iK + 1
    
    print(f'El numero mayor es: {mayor}')

def menor(iN):
    iK = 1
    menor = 10000000000000000000000000000
    
    while iK <= iN:
        iV = int(input(f'Introduce el valor {iK}: '))
        if menor > iV:
            menor = iV
            print("Ahora es el numero mas chico")
        else:
            print("Es mayor")
            
        iK = iK + 1
    
    print(f'El numero menor es: {menor}')

def tiofibo(iN):
    v1 = 0
    v2 = 1
    temp = 0
    while temp < iN:
        v3 = v1 + v2
        print(v3)
        v1 = v2
        v2 = v3
        temp = temp + 1
    
def adivina():
    a = 8
    r = 0
    c = 0
    d = 0
    while d <= 3:
        d = d + 1
        c = c + 1
        b = a + c
        a = a + c
        print(b)
    
    resp = int(input('Cual es el siguiente numero de la serie: '))
    resp2 = 23
    while resp == resp2:
        if resp == resp2:
            print('Excelente Respuesta')
        else:
            print('Respuesta incorrecta vuelve a intentar.')

def mmp(iN):
    iK = 1
    prom = 0.0
    mayor = 0
    menor = 1000000000
    
    while iK <= iN:
        iV = int(input(f'Ingresa el valor {iK}: '))
        prom = prom + iV
    
        if mayor < iV:
            mayor = iV
        
        if menor > iV:
            menor = iV
            
        iK = iK + 1
    
    print(f'El numero mayor es: {mayor}, El numero menor es: {menor}, El promedio es {prom/iN}')
    
def mayorc():
    iK = 1
    mayor = 0
    iV = 1
    while iV != 0:
        iV = int(input(f'Introduce el valor {iK}: '))
        if mayor < iV:
            mayor = iV
        iK = iK + 1
            
    
    print(f'El numero mayor es: {mayor}')

def menorc():
    iK = 1
    menor = 100000000
    iV = 1
    while iV != 0:
        iV = int(input(f'Introduce el valor {iK}: '))
        if iV != 0:
            if menor > iV:
                menor = iV
        iK = iK + 1
            
    print(f'El numero menor es: {menor}')

def promedioc():
    iK = 1
    iV = int(input(f'Ingresa valor: '))
    suma = iV
    prom = suma/iK
    while iV != 0:
        prom = suma / iK
        iV = int(input(f'Ingresa valor: '))
        suma = suma + iV
        iK = iK + 1
    
    print(prom1)

def pi():
    print('Teclea la cantidad de elementos de la aproximacion: ', end='')
    iN = int(input())
    iK = 1
    aprox = 0
    while (iK <= iN*2-1):
        if(iK%4 == 1):
            aprox = aprox + 1/iK
        else:
            aprox = aprox - 1/iK
        iK = iK + 2
    
    print(f'La aproximacion de pi es {4*aprox}')
    
def pastel():
    renglones = int(input("Teclea la cantidad de renglones: "))
    columnas = int(input('Teclea la cantidad de columnas: '))
    asterisco = "*"
    linea = asterisco*columnas
    c = 1
    while (c <= renglones):
        print(f'{linea}')
        c = c + 1

def escalera():
    lineas = int(input("Teclea la cantidad de lineas: "))
    asterisco = "*"
    linea = 0
    c = 1
    while (c <= lineas):
        linea = asterisco*c
        print(f'{linea}')
        c = c + 1
        

        
        
def menu():
    print('''
    BIENVENIDO SELECCIONA LA ACTIVIDAD:
            1. Sumatoria 1 + 2+ 3 +...+ iN
            2. Cuenta Positivos Negativos Ceros de iN valores
            3. Tabla de Multiplicar del número x
            4. Promedio de iN números
            5. Encuentra el Mayor de iN números
            6. Encuentra el Menor de iN números
            7. Sucesión de Fibonacci
            8. Adivina el siguiente número de la serie
            9. Encuentra el Menor, el Mayor y el Promedio de iN valores
            10. Encuentra el Mayor hasta que teclee 0
            11. Encuentra el Menor hasta que teclee 0
            12. Encuentra el Promedio hasta que teclee 0
            13. Sumatoria Día Pi
            14. Dibuja Pastel en forma de Rectangulo
            15. Dibuja Escalera
            16. Dibuja Pino
        0. Salir  
            ''')
    return int(input())

def main():
    opcion = menu()
    
    if opcion == 1:
        iN = int(input('Hasta:'))
        sumatoria(iN)
        
    elif opcion == 2:
        iN = int(input('Ingresa la cantidad de numeros:'))
        Cpnc(iN)
        
    elif opcion == 3:
        iX = int(input('Ingresa tu valor que multiplicara: '))
        tablita(iX)
        
    elif opcion == 4:
        iN = int(input('Ingresa la cantidad de numeros:'))
        promedio(iN)
        
    elif opcion == 5:
        iN = int(input('Ingresa la cantidad de numeros:'))
        mayor(iN)
        
    elif opcion == 6:
        iN = int(input('Ingresa la cantidad de numeros:'))
        menor(iN)
        
    elif opcion == 7:
        iN = int(input('Ingresa numero maximo de la sucesion:'))
        tiofibo(iN)
        
    elif opcion == 8:
        adivina()
        
    elif opcion == 9:
        iN = int(input('Ingresa la cantidad de numeros:'))
        mmp(iN)
        
    elif opcion == 10:
        mayorc()
        
    elif opcion == 11:
        menorc()
        
    elif opcion == 12:
        promedioc()
        
    elif opcion == 13:
        pi()
        
    elif opcion == 14:
        pastel()
        
    elif opcion == 15:
        escalera()
        
    elif opcion == 16:
        pino()
    else:
        exit()
        
main()
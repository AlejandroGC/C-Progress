import random

def suma(b):
    print("Forma el numero: ",b)
    c = int(input("Introduce tu numero 1: "))
    d = int(input("Introduce tu numero 2: "))
    while b != c + d and c > 2 and d > 2:
        c = int(input("Vuelve a introducir tu numero 1: "))
        d = int(input("Vuelve a introducir tu numero 2: "))
    
    return print("Correcto\n")   

def resta(b):
    print("Forma el numero: ", b)
    c = int(input("Introduce tu numero 1: "))
    d = int(input("Introduce tu numero 2: "))
    while b != c - d and c > 2 and d > 2:
        c = int(input("Vuelve a introducir tu numero 1: "))
        d = int(input("Vuelve a introducir tu numero 2: "))
    
    return print("Correcto\n") 

def multiplicacion(b):
    print("Forma el numero: ", b)
    c = int(input("Introduce tu numero 1: "))
    d = int(input("Introduce tu numero 2: "))
    while b != c * d and c > 2 and d > 2:
        c = int(input("Vuelve a introducir tu numero 1: "))
        d = int(input("Vuelve a introducir tu numero 2: "))
    
    return print("Correcto\n") 

def division(b):
    print("Forma el numero: ", b)
    c = int(input("Introduce tu numero 1: "))
    d = int(input("Introduce tu numero 2: "))
    while b != c / d and c > 2 and d > 2:
        c = int(input("Vuelve a introducir tu numero 1: "))
        d = int(input("Vuelve a introducir tu numero 2: "))
    
    return print("Correcto\n")

def main():
    nombre = input("Introduce tu Nombre: ")
    n = int(input("Introduce las operaciones que tiene que contestar: "))
    print("Hola", nombre,", obten las", n,"operaciones correctas y ganaras!\n")
    
    for i in range(n):
        
        a = random.randint(1,4)
        b = random.randint(6,106)
        if a == 1:
            print("Debe ser una suma!")
            sumar = suma(b)
        elif a == 2:
            print("Debe ser una resta!")
            restar = resta(b)
        elif a == 3:
            print("Debe ser una multiplicacion!")
            multi = multiplicacion(b)
        else:
            print("Debe ser una division!")
            divi = division(b)
    
    print("Excelente! tu viste la(s) ",n, "operaciones correctas." )
    
    

main()
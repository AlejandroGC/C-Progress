import random  

nombre = str(input("Hola, dime tu nombre:"))
print("Hola", nombre, "Para terminar el juego tienes que tener 5 respuestas bien.")

operaciones = ("suma","multiplicación","división","resta")
n = 5
contador = 0
totales = 0

while n != 0:
    a = random.randint(0,4)
    b = random.randint(6,106)
    
    for i in  range (a):
        print (operaciones[i])
        
    print(b)
    

    uno = int(input("pon el primer valor:"))
    print("en el caso de ser división el primer número es el dividendo y el segundo el divisor")
    dos = int(input("pon el segundo valor:"))
    
    if a  ==  "suma" and uno + dos == b:
        print("correcto")
        n = n-1
        contador += 1
        totales += 1
    elif a  ==  "multiplicación" and uno * dos == b:
        print("correcto")
        n = n-1
        contador += 1
        totales += 1
        
    elif a  ==  "división" and uno / dos == b:
        print("correcto")
        n = n-1
        contador += 1
        totales += 1
        
    elif a  ==  "resta" and uno / dos == b:
        print("correcto")
        n = n-1
        contador += 1
        totales += 1
        
    else:
        print("incorrecto")
        n = n+1
        totales += 1
    
print ("Obtuviste ", contador, "bien de ", totales)
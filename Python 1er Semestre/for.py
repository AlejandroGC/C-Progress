# A01570396



def ciclo_contador_creciente():
    # Desplegar que hace la funcion
    print('Esta funcion despliega los numeros del 1 ')
    print('Hasta el valor ', end='')
    
    #Leer la cantidad de veces que se ejecutara el ciclo
    iN = int(input('ingreses valor:'))
    
    for iK in range(1,iN+1):
        print(iK)
        
def ciclo_contador_decreciente():
    #Desplegar que hace la funcion
    print('Esta funcion despliega los numero de iN a 1')
    
    #Leer la cantidad de veces que se ejecutara el ciclo
    print('Teclea el valor:', end='')
    iN = int(input())
    
    for iK in range(iN,0,-1):
        print(iK)
        
#Ciclo contador creciente con acumulador
def alcancia():
    #Leer la cantidad de valores a sumar en iN
    print('Cantidad de valores a sumar:')
    iN = int(input())
            
    #1 Inicializar el acumulador y el vcc
    iAcum = 0
    #2 Incluir en la condicion la vcc
    for iN in range(1,iK+1):
        #Acumular l iK en iAcum
        iAcum = iAcum + iK
        
        #3 Actualizar iK
        iK = iK + 1
        
    print('El total $', iAcum)
        
def tiendita_chonita():
    print('Calcular el total a pagar:')
    print('Teclea la cantidad de productos', end='')
    iN = int(input())
    
    #1 Inicializar acumulador y la vcc
    dAcum = 0
    iK = 1
    
    #2 Incluir en la condicion la vcc
    while( iK <= iN):
        #Teclea el precio
        print('Teclea el precio', iK,': ', end='')
        dPrecio = float(input())
        
        #2 Incluir en la condicion la vcc
        while (iK <= iN):
            #Teclea el precio
            print('Teclea el precio', iK, ': ', end='')
            dPrecio = float(input())
            
            #Acumulador el iK en iAcum
            dAcum = dAcum + dPrecio
            
            
            
            #3 Actualizar iK
            iK = iK + 1
            
            #Desplegar los resultados
            print('Total a pagar $', dAcum)
            
def menu():
    print('''
                1. Ciclo creciente
                1.1 Ciclo decreciente
                1.2 Alcancia
                1.3 Tiendita doña Chonita
                1.4 Elevar x^n
         2.       
                6. Terminar ´''')
    return int(input())

def main():
    #Leer la opcion menu
    opcion = menu()
    
    #Determinar a opcion que ingreso el usuario
    if opcion == 1:
        ciclo_contador_creciente()
    elif opcion == 2:
        ciclo_contador_decreciente()
    elif opcion == 3:
        alcancia()
    elif opcion == 4:
        tiendita_chonita()
    elif opcion == 5:
        elevado()
        
    else:
        exit()


#Llamar a la funcion main
main()
                
          
 
        
def archivitos():
    #Crea una lista de palabras
    lista = []
    
    # Leer la cantidad de palabras
    iN = int(input("Cantidad de palabras a ingresar: "))
    
    for iK in range(1, iN + 1):
        palabrita = input(f'Teclea la palabra {iK}: ')
        lista.append(palabrita)
    
    print(lista)
    
    with open("palabras.txt", "w") as archivo:
        for palabrita in lista:
            archivo.write(palabrita)
            # print(palabrita, file = archivo)
            
    with open("palabras.txt", "w") as archivo:
        for palabrita in lista:
            archivo.write(palabrita)
            # print(palabrita, file = archivo)
    
    lista = []
    
    with open("palabras.txt", "r") as archivo:
        for linea in archivo:
            lista.append(linea[:-1])

    
    lista.sort()
    print("lista ordenada en forma menor a mayor")
    print(lista)
    lista.sort(reverse = True)
    print("Lista ordenada en forma de mayor a menor")
    print(lista)
    
    with open("palabras.txt", "w") as archivo:
        for palabra in lista:
            archivo.write(palabra + '\n')
            
    # Cierra el archivo y borra el contenido de la variable que almacena las palabras        
    lista = []
    # Lee nuevamente el archivo y guarda el contenido en una lista
    with open("palabras.txt", "r") as archivo: 
        for linea in archivo: #esa lineas recuerda que alfinal tiene \n
            lista.append(linea[:-1])
    
    print("ordenada sort()")
    lista.sort()
    print(lista)
    print("ordenada con key = str.lower")
    lista.sort(key = str.lower)
    print(lista)

archivitos()
    
    
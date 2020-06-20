def contar():
    frase = input('Escribe la frase: ')
    palabra = input('Que palabra quieres contar: ')
    contador = 0
    pos = frase.find(palabra)
    while pos != -1:
        frase = frase.replace(palabra,'',1)
        contador = contador + 1
        pos = frase.find(palabra)
            
        
    return(contador)
        


print(contar())
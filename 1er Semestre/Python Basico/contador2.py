def contador():
    name = input()
    caracter = input('Ingresa la letra a contar: ')
    contador = 0
    for letra in name:
        if letra == caracter:
            contador = contador + 1
    return contador

print(contador())
    
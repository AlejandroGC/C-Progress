

datos = [input("Introduce tu nombre: "), input("Introduce tu apellido: "), int(input("Introduce tu edad: ")), float(input("Introduce tu estatura: ")), int(input("Introduce tu peso: "))]

# Los datos de la lista corresponderán a: nombre, apellido, edad, estatura, peso

nombre, apellido, edad, estatura, peso = datos

imc = peso / estatura ** 2 # Estatura al cuadrado (exponente 2)


print("Calculadora de IMC")

print("¡Hola,",nombre,apellido,"!")

print("Tu peso registrado es de:",peso,"kgs")

print("Tu estatura registrada es de:",estatura,"mts")

print("De acuerdo con estos datos tú IMC es",imc,"lo que indica:")


if imc <= 18.4: # si el IMC es menor a 18.4

   print("Peso bajo")

elif imc >= 18.5 and imc <= 24.9: # sino, si el IMC es mayor a 18.5 y menor 24.9 

   print("Peso normal")

elif imc >= 25 and imc <= 29.9: # sino, si el IMC es mayor a 25 y menor a 29.9

   print("Sobre peso")

else: # sino cae en ninguno de los rangos anteriores entonces es mayor

   print("Obesidad")
# Alejandro Daniel Gonzalez Carrillo
# A01570396

grado = int(input())

if grado == 0 or grado == 90 or grado == 180 or grado == 270 or grado == 360:
    print("eje")

elif grado < 0 or grado > 360:
    print("excede")

elif 0 < grado < 90:
    print("1")
    
elif 90 < grado < 180:
    print("2")
    
elif 180 < grado < 270:
    print("3")
    
elif 270 < grado < 360:
    print("4")
    
else:
    print("Introduce un # valido")
    
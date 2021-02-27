# Alejandro Daniel Gonzalez Carrillo
# A01570396

mes = int(input())

if mes == 4 or mes == 6 or mes == 9 or mes == 11:
    print("30")

elif mes == 1 or mes == 3 or mes == 5 or mes == 7 or mes == 8 or mes == 10 or mes == 12:
    print("31")

elif mes == 2:
    print("28")

else:
    print("0")
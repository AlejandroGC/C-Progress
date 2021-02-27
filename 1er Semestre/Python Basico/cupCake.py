a = int(input())
b = int(input())
n = int(input())

precio = float(a + b/100)
precioTotal = (precio * n)

costoTotalDolares = int(precioTotal)
costoTotalCentavos = int((precioTotal - costoTotalDolares)* 100) 
print(costoTotalDolares, costoTotalCentavos)


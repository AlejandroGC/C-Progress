#Alejandro Daniel Gonzalez Carrillo
# A01570396

test = [{'Arizona':'Phoenix','California':'Sacramento','Hawaii':'Honolulu'}, 1000, 2000, 3000,['hat','t-shirt','jeans',{'socks1':'red','socks2':'blue'}]]
print(test[2])
print(test[0])
print(test[0]["Arizona"])
print(test[4][2])
print(test[4][3]["socks2"])

producto = {'Calorias': int(input("Introduce Calorias: ")), 'Carbohidratos': int(input("Introduce carbohidratos: ")), 'Lipidos': int(input("Introduce lipidos: ")), 'Proteinas': int(input("Introduce proteinas: ")), 'Sodio': int(input("Introduce sodio: "))}
producto2 = {'Calorias': int(input("Introduce Calorias: ")), 'Carbohidratos': int(input("Introduce carbohidratos: ")), 'Lipidos': int(input("Introduce lipidos: ")), 'Proteinas': int(input("Introduce proteinas: ")), 'Sodio': int(input("Introduce sodio: "))}
producto3 = {'Calorias': int(input("Introduce Calorias: ")), 'Carbohidratos': int(input("Introduce carbohidratos: ")), 'Lipidos': int(input("Introduce lipidos: ")), 'Proteinas': int(input("Introduce proteinas: ")), 'Sodio': int(input("Introduce sodio: "))}
producto4 = {'Calorias': int(input("Introduce Calorias: ")), 'Carbohidratos': int(input("Introduce carbohidratos: ")), 'Lipidos': int(input("Introduce lipidos: ")), 'Proteinas': int(input("Introduce proteinas: ")), 'Sodio': int(input("Introduce sodio: "))}
producto5 = {'Calorias': int(input("Introduce Calorias: ")), 'Carbohidratos': int(input("Introduce carbohidratos: ")), 'Lipidos': int(input("Introduce lipidos: ")), 'Proteinas': int(input("Introduce proteinas: ")), 'Sodio': int(input("Introduce sodio: "))}

print(producto)
print(producto2)
print(producto3)
print(producto4)
print(producto5)

obtener = producto.get('Calorias')
print(obtener)




import math

metros = float(input())

bulto = int(math.ceil(metros * 35 / 10))

kgsobrantes = float(bulto * 10 - (metros * 35))

print(bulto, "Bultos")
print(kgsobrantes, "Kg sobrantes")
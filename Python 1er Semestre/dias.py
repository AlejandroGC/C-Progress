# Alejandro Daniel Gonzalez Carrillo
# A01570396  08/19/19

import math

km_a_recorrer_por_dia = int(input())
total_de_km_viaje = int(input())

dias = math.ceil(total_de_km_viaje / km_a_recorrer_por_dia)
print(dias)
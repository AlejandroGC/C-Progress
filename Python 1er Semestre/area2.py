# Alejandro Daniel Gonzalez Carrillo
# A01570396  08/19/19

import math

A = int(input())
B = int(input())
c = int(input())

C = 180 - (A + B)

radianes = math.radians

A = radianes(A)
B = radianes(B)
C = radianes(C)

a = c * (math.sin(A)/math.sin(C))
b = c * (math.sin(B)/math.sin(C))

x = ((a + b + c)/2)

area = math.sqrt(x*(x-a)*(x-b)*(x-c))
print(area)
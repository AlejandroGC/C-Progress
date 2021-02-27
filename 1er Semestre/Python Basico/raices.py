# Alejandro Daniel Gonzalez Carrillo
# A01570396  08/19/19

from math import sqrt

a = int(input())
b = int(input())
c = int(input())

x1 = (-b + (sqrt((b**2)-4*a*c))) / (2*a)
x2 = (-b - (sqrt((b**2)-4*a*c))) / (2*a)

print(x1)
print(x2)
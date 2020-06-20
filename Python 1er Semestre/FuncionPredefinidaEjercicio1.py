import math

a = int(input("Introduce punto a: "))
b = int(input("Introduce punto b: "))
c = int(input("Introduce punto c: "))

s = ((a + b + c) / 2)

area = math.sqrt(s*(s - a)*(s - b)*(s - c))
print(area)
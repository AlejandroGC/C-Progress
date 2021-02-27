sobra = int(input())

b100 = int(sobra//100)
print(b100 ," Billetes de $100")
sobra = sobra%100

b50 = int(sobra/50)
print(b50 ," Billetes de $50")
sobra = sobra%50

b20 = int(sobra/20)
print(b20 ," Billetes de $20")
sobra = sobra%20

m10 = int(sobra/10)
print(m10 ," Monedas de $10")
sobra = sobra%10

m5 = int(sobra/5)
print(m5 ," Monedas de $5")
sobra = sobra%5

m2 = int(sobra/2)
print(m2 ," Monedas de $2")
sobra = sobra%2

m1 = int(sobra/1)
print(m1 ," Monedas de $1")
sobra = sobra%1

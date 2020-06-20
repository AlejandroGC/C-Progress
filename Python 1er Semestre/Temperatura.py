def celsius(t):
    cel = ((t-32)*5/9)
    return cel
    
def kelvin(t):
    kel = ((t-32)*5/9)+273
    return kel
    
def rankin(t):
    ran = t+460
    return ran
    
def main():
    t = int(input("Introduce tu temperatura en farenheit: "))
    c = celsius(t)
    k = kelvin(t)
    r = rankin(t)
    print(f'Temperatura: {c} celsius, {k} kelvin y {r} rankin')

main()
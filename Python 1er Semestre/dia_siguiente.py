
def diaSiguiente(d,m,a):
    dM = diasMes(m)
    if ((d > 0 and d <= dM) and (m > 0 and m <= 12) and (a > 1900)):
        if d < dM:
            d=d + 1
        else:
            d = 1
            if (m == 12):
                m = 1
                a = a + 1
            else:
                m = m + 1
        print(d,'/',m,'/',a)
    else:
        print("ERROR")
    
  
def diasMes(m):
    if m > 0 and m <= 12:
        if m == 2:
            return 28
        elif m == 4 or m == 6 or m == 9 or m == 11:
            return 30
        else:
            return 31
    
    else:
        return 0

def main():
    d = int(input())
    m = int(input())
    a = int(input())
    
    diaSiguiente(d,m,a)
    
    
main()

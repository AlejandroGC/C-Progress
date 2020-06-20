# Alejandro Daniel Gonzalez Carrillo
# A01570396

peso = int(input())
altura = float(input())

indice = int(peso / (altura**2))

if indice < 20:
    
    print("PESO BAJO")
    
elif 20 <= indice < 25:
            
    print("NORMAL")
    
elif 25 <= indice < 30:
            
    print("SOBRE PESO")
    
elif 30 <= indice < 40:
            
    print("OBESIDAD")
    
else:
             
    print("OBESIDAD MORBIDA")
         
        


res = (input("�Colon descubri� Am�rica?\nSI o NO? ", "s"));
if res == "SI"
    res = (input("�La independencia de M�xico fue en el a�o 1810?\nSI o NO? ", "s"));
    if res == "SI"
        res = (input("�The Doors fue un grupo de rock Americano?\nSI o NO? ", "s"));
        if res == "SI"
            fprintf("Todas tus preguntas son correctas!")
        else
            fprintf("Estas Incorrecto.")
        end
    else
        fprintf("Estas Incorrecto.")
    end
else
    fprintf("Estas Incorrecto.")
end

function [r] = RaicesDP(A)
    ti = A(end); %termino independiente
    Ds = divisors(ti); %obtengo divisores
    Ds = [Ds Ds*-1]; %divisores positivos y negativos
    r = [ ]; %guardar las raices
    C(1) = A(1); %el primer elemento que no ira cambiando
    
    for i = 1:length(Ds) % por cada divisor
        Div = Ds(i);
        C(2) = (Div * A(1)); %primera operacion
        for j = 2:length(A)
           C(j)=C(j)+A(j); %suma
           C(j+1)=(Div * C(j)); 
            
        end
        
        C(end) = [ ];% se elimina la ultima multiplicacion
        if C(end) == 0
            r = [r; Div]; % se agrega divisor el divisor a la raiz
        C(end) = [ ]; %se elimina el cero de los nuevos coeficientes
        A = C; % 
        end
    end


end
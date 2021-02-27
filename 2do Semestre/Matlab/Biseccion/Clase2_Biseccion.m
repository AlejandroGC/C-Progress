% A01570396 Alejandro Daniel Gonzalez Carrillo
% Metodo de Biseccion
% F(x) = 0, cada vez que la funcion cruza por y = 0 hay existe una funcion
% de raiz.

function [raiz, Xm, iter] = Clase2_Biseccion(f,Xi,Xd,T)
    iter = 0;
    Xm = (Xi + Xd)/2;
    raiz = NaN;
    if f(Xi)*f(Xd)<0
        while abs(f(Xm))>T
            if f(Xi)*f(Xm)<0
               Xd = Xm;
            else
               Xi = Xm;
            end
            iter = iter + 1;
            Xm = (Xi + Xd)/2;
        end
        raiz = f(Xm);
    else
        disp('Error')
    end     
end



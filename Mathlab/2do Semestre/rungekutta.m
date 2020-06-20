% Equipo 2
% Alejandro Gonzalez Carrillo A01570396
% Rodolfo Sandoval Schipper A01720253
% Valeria Lopez de Leon A01283512
% Juan Pablo A01740200
% Oscar Reyna A01570385

clc;
clear;
close all;

f = @(x,y) 4*x.^2-2*y;
df = @(x,y) 8*x-2;
f2 = @(x,y) x.^2-3*y;
df2 = @(x,y) 2*x-3;
f3 = @(x,y) -2*x.^3+12*x.^2-20*x+8.5;
df3 = @(x,y) -6*x.^2+24*x-20;

h = 0.1;
li = 0;
ls = 4;
xh = (li:h:ls);
yh = f(xh,0);

% 1. funcion, 2. derivada de la funcion, 3. limite inferior, 4. limite
% superior, 5. intervalo, 6. orden que se elige, 7. tipo (solo aplica con
% 2do orden), 8. x inicial, 9. y inicial.
figure (1)
title("4*x.^2-2*y");
% Las lineas son muy parecidas es por eso que una que otra no se observa al
% menos que pongamos diferentes valores en cada una.
runge(f,df,0,4,h,4,0,0.4,3);
runge(f,df,0,4,h,2,2,0.4,3);
runge(f,df,0,4,h,1,0,0.4,3);
hold off

figure (2)
title("x.^2-3*y");
runge(f2,df2,0,1,h,4,0,1,0);
runge(f2,df2,0,1,h,2,2,1,0);
runge(f2,df2,0,1,h,1,0,1,0);
hold off

figure(3)
title("-2*x.^3+12*x.^2-20*x+8.5");
runge(f3,df3,0,4,h,4,0,0,1);

runge(f3,df3,0,4,h,2,1,0,1);

runge(f3,df3,0,4,h,1,0,0,1);


function [x,y] = runge(f,f1,li,ls,h,orden,tipo,xi,yi)

xh = (li:h:ls);
switch orden
    case 1
        x = xi;
        y = yi;
        for i = 1:length(xh)-1
            x(i+1) = x(i) + h;
            y(i+1) = y(i) + f1(x(i),y(i))*h;
        end
        plot(x,y);
        fprintf("X: ")
        disp(x)
        fprintf("Y: ")
        disp(y)
        hold on
    case 2
        if tipo == 1
            a2 = 1/2;
            a1 = 1/2;
            p1 = 1;
            q11 = 1;
        elseif tipo == 2
            a2 = 1;
            a1 = 0;
            p1 = 1/2;
            q11 = 1/2;
        else
            a2 = 2/3;
            a1 = 1/3;
            p1 = 3/4;
            q11 = 3/4; 
        end
        
        x = xi;
        y = yi;
        for i = 1:length(xh)-1
            k1 = f1(x(i),y(i));
            k2 = f1(x(i)+p1*h,y(i)+q11*k1*h);
            x(i+1) = x(i) + h;
            y(i+1) = y(i) + (a1*k1+a2*k2)*h;
        end
        plot(x,y);
        fprintf("X: ")
        disp(x)
        fprintf("Y: ")
        disp(y)
        hold on
    case 4
        x = xi;
        y = yi;
        for i = 1:length(xh)-1
            k1 = f1(x(i),y(i));
            k2 = f1(x(i)+1/2*h,y(i)+1/2*k1*h);
            k3 = f1(x(i)+1/2*h,y(i)+1/2*k2*h);
            k4 = f1(x(i)+h,y(i)+k3*h);
            x(i+1) = x(i) + h;
            y(i+1) = y(i) + 1/6*(k1+2*k2+2*k3+k4)*h;
        end
        plot(x,y);
        fprintf("X: ")
        disp(x)
        fprintf("Y: ")
        disp(y)
        hold on
    otherwise
        figure(1);
        plot(xh,yh,'linewidth',2,'color','b');
        grid on
        axis([li,ls+0.5,0,max(yh)+0.5]);
end
end

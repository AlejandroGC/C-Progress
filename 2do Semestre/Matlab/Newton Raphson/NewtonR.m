% Alejandro Daniel Gonzalez Carrillo - A01570396
% Metodo de Raphson

%% Problema A
syms x
f = (-1/10)*x^2+3;
b = -15:0.1:15;
y = double(subs(f,b));
plot(b,y)
grid on
hold on

xi = 4;
error = 10^-10;
fdx = diff(f);
[r,xi,iter] = metodoNewton(f,fdx,xi,error);
fprintf('El valor aproximado a la raiz es: %d\n', r);
fprintf('El valor de x es: %d\n', xi);
fprintf('Las iteraciones fueron: %i', iter);

plot(xi,r,'*r');
title(['Newton Raphson: ' num2str(xi)]) 

%% Problema B
syms x
f = cos(x)-x^3;
b = -3:0.1:4;
y = double(subs(f,b));
plot(b,y)
grid on
hold on

xi = 1;
error = 10^-10;
fdx = diff(f);
[r,xi,iter] = metodoNewton(f,fdx,xi,error);
fprintf('El valor aproximado a la raiz es: %d\n', r);
fprintf('El valor de x es: %d\n', xi);
fprintf('Las iteraciones fueron: %i', iter);

plot(xi,r,'*r');
title(['Newton Raphson: ' num2str(xi)])

%% Problema C
syms x
f = x^3+x+16;
b = -6:0.1:6;
y = double(subs(f,b));
plot(b,y)
grid on
hold on

xi = -2;
error = 10^-10;
fdx = diff(f);
[r,xi,iter] = metodoNewton(f,fdx,xi,error);
fprintf('El valor aproximado a la raiz es: %d\n', r);
fprintf('El valor de x es: %d\n', xi);
fprintf('Las iteraciones fueron: %i', iter);

plot(xi,r,'*r');
title(['Newton Raphson: ' num2str(xi)])

%% Problema D
syms x
f = x^4+2*x-1;
b = -2:0.1:4;
y = double(subs(f,b));
plot(b,y)
grid on
hold on

xi = 0;
error = 10^-10;
fdx = diff(f);
[r,xi,iter] = metodoNewton(f,fdx,xi,error);
fprintf('El valor aproximado a la raiz es: %d\n', r);
fprintf('El valor de x es: %d\n', xi);
fprintf('Las iteraciones fueron: %i', iter);

plot(xi,r,'*r');
title(['Newton Raphson: ' num2str(xi)]) 

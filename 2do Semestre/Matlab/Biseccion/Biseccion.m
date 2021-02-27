% A01570396 Alejandro Daniel González Carrillo

%% Ejercicio 1 - El rango utilizado es -10 a 2 de 0.1 en 0.1, con una tolerancia de  10^-20
f = @(x) x-cos(x);
x = -10:0.1:10;
y = f(x);
plot(x,y)

hold on

f = @(x) x-cos(x);
x = -10:0.1:2;
y = f(x);
plot(x,y)

Xi = -10;
Xd = 2;
T = 10^-20;
[raiz, Xm, iter] = Clase2_Biseccion(f,Xi,Xd,T);
fprintf('El valor de la raiz es: %f \n', raiz);
fprintf('El valor de la X media es: %f \n', Xm);
fprintf('El numero de iteraciones fue: %i \n', iter);

%% Ejercicio 2 - El rango utilizado es -10 a -8 de 0.1 en 0.1, con una tolerancia de  10^-10
f = @(x) x.^2.*sin(x);
x = -10:0.1:10;
y = f(x);
plot(x,y)

hold on

f = @(x) x.^2.*sin(x);
x = -10:0.1:-8;
y = f(x);
plot(x,y)

Xi = -10;
Xd = -8;
T = 10^-10;
[raiz, Xm, iter] = Clase2_Biseccion(f,Xi,Xd,T);
fprintf('El valor de la raiz es: %f \n', raiz);
fprintf('El valor de la X media es: %f \n', Xm);
fprintf('El numero de iteraciones fue: %i \n', iter);

%% Ejercicio 3 - El rango utilizado es 0.1 a 10 de 0.1 en 0.1, con una tolerancia de  10^-20
f = @(x) x.*log(x);
x = -10:0.1:10;
y = f(x);
plot(x,y)
grid on

hold on

f = @(x) x.*log(x);
x = 0.1:0.1:10;
y = f(x);
plot(x,y)
grid on

Xi = 0.1;
Xd = 10;
T = 10^-20;
[raiz, Xm, iter] = Clase2_Biseccion(f,Xi,Xd,T);
fprintf('El valor de la raiz es: %f \n', raiz);
fprintf('El valor de la X media es: %f \n', Xm);
fprintf('El numero de iteraciones fue: %i \n', iter);


%% Ejercicio 4 - El rango utilizado es -10 a 0 de 0.1 en 0.1, con una tolerancia de  10^-15
f = @(x) exp(0.3.*x)-x.^2;
x = -10:0.1:10;
y = f(x);
plot(x,y)
grid on

hold on

f = @(x) exp(0.3.*x)-x.^2;
x = -10:0.1:0;
y = f(x);
plot(x,y)
grid on

Xi = -10;
Xd = 0;
T = 10^-15;
[raiz, Xm, iter] = Clase2_Biseccion(f,Xi,Xd,T);
fprintf('El valor de la raiz es: %f \n', raiz);
fprintf('El valor de la X media es: %f \n', Xm);
fprintf('El numero de iteraciones fue: %i \n', iter);

%% Ejercicio 5 - El rango utilizado es 6 a 8 de 0.1 en 0.1, con una tolerancia de  10^-15
f = @(x) 2.*cos(x)-(sqrt(x)./2);
x = -10:0.1:10;
y = f(x);
plot(x,y)
grid on

hold on

f = @(x) 2.*cos(x)-(sqrt(x)./2);
x = 6:0.1:8;
y = f(x);
plot(x,y)
grid on

Xi = 6;
Xd = 8;
T = 10^-15;
[raiz, Xm, iter] = Clase2_Biseccion(f,Xi,Xd,T);
fprintf('El valor de la raiz es: %f \n', raiz);
fprintf('El valor de la X media es: %f \n', Xm);
fprintf('El numero de iteraciones fue: %i \n', iter);
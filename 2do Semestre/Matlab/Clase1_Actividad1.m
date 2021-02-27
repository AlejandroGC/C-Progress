%% A01570396 Alejandro Daniel Gonzalez Carrillo

%%Cuadratica - Mientras mas grande sea el valor que acompaña la x mas
% cerrada estara la parabola. En caso de que sea mas pequeño esta se abrira
% cada vez más.

% 1
x=-10:0.01:10;
y=x.^2;
plot(x,y,'r','LineWidth',2)

hold on 

% 2
y=2*x.^2;
plot(x,y,'g')

hold on

% 3
y=4*x.^2;
plot(x,y,'b')

hold on

% 4
y=0.2*x.^2;
plot(x,y,'r')
title('Cuadratica')
xlabel('x')
ylabel('y')
legend('x^2','2*x^2','4*x^2','0.2*x^2');

%% Senoidal - El valor a lado de la x determina la amplitud de la curva y el valor dentro del sin determina la longitud de onda. 

% 1
x = -10:0.01:10;
y = sin(x);
plot(x,y,'r')

hold on

% 2 - Es el doble de la amplitud de la primera ecuación.
y=2*sin(x);
plot(x,y,'b')

hold on

% 3 - La amplitud es mas pequeña.
y = 0.4*sin(x);
plot(x,y,'g')

hold on

% 4 - La longitud de onda se extiende
y=2*sin(2*x);
plot(x,y,'g','LineWidth',2)
title('Senoidal')
xlabel('x')
ylabel('y')
legend('sin(x)','2*sin(x)','0.4*sin(x)','2*sin(2*x)')

%% Graficación - !Este debe correrse en pantalla completa para observarse mejor!

% 1 - Ecuación Paramétrica
subplot(2,2,1)
t = 1:0.1:1000;
x = t.^2+2*t;
y = t.^10+t.^3+t.^2+t;
z = t;

% Nos una idea mas detallada de como se plotea la ecuación.
comet3(x,y,z)
title('Ejercicio 1 - Ecuación Paramétrica')
xlabel('lado x');
ylabel('lado y');
zlabel('lado z');

legend('x = t^2+2*t','y = t^10+t^3+t^2+t','z = t')

% 2 - Curva
subplot(2,2,2)
t = 1:0.1:600;
x = t.^5-10*t;
y = 2*t-4;

comet(x,y)
title('Ejercicio 2 - Curva')
xlabel('lado x');
ylabel('lado y');

legend('x = t^5-10*t;','y = 2*t-4;')

% 3 - Helice Circular Recta
subplot(2,2,3)
a = 2;
b = 0.25;
w = 2;
t = 0:0.001:12*pi;

x = a*cos(w*t);
y = a*sin(w*t);
z = b*t;

comet3(x,y,z);
title('Ejercicio 3 - Helice Circular Recta')
xlabel('lado x');
ylabel('lado y');
zlabel('lado z');

legend('x = a*cos(w*t)','y = a*sin(w*t)','z = b*t')

% 4 - Se realiza un Paraboloide Eliptico
subplot(2,2,4)
a = 1;
b = 1;
u = 0:0.001:2*pi;
t = 0:0.001:2*pi;

x = a*cos(t).*cos(u);
y = b*cos(t).*sin(u);
z = cos(t).^3;

plot3(x,y,z,'b');
title('Ejercicio 4 - Paraboloide Eliptico')
xlabel('lado x');
ylabel('lado y');
zlabel('lado z');

legend('x = a*cos(t)*cos(u)','y = b*cos(t)*sin(u)','z = cos(t)^3')

%% 5

%Proyecte los circulos en forma de escalera, en este caso el rectangle hace
%que se dibujen los rectangulos en la posicion seleccionada mediante puntos
%y se le incluye curvaturas de 1 que es lo maximo formando circulos.
rectangle('Position',[2 4 1 1.2], 'Curvature', [1,1], 'FaceColor','r','EdgeColor',[0 0 1]);
rectangle('Position',[4 4 1 1.2], 'Curvature', [1,1], 'FaceColor','b','EdgeColor',[1 0 0]);
rectangle('Position',[6 2 1 1.2], 'Curvature', [1,1], 'FaceColor','y','EdgeColor',[1 1 0]);
rectangle('Position',[4 2 1 1.2], 'Curvature', [1,1], 'FaceColor','g','EdgeColor',[0 1 0]);
rectangle('Position',[2 2 1 1.2], 'Curvature', [1,1], 'FaceColor','r','EdgeColor',[1 1 1]);
rectangle('Position',[2 6 1 1.2], 'Curvature', [1,1], 'FaceColor','b','EdgeColor',[1 0 1]);
title('Ejercicio 5 - Circulos')
xlabel('x')
ylabel('y')
axis([1 10 1 10])



%% 6

%Cambio en la direccion de las flechas, cambie el sin y cos de las
%funciones.
%El meshgrid esta compuesto por vectores x y y.
[x,y] = meshgrid(0:0.2:2,0:0.2:2);
u = sin(x).*y;
v = cos(x).*y;
figure
quiver(x,y,u,v)
title('Ejercicio 6 - Direccion de Flechas')
xlabel('x')
ylabel('y')
legend('u = sin(x)*y','v = cos(x)*y')















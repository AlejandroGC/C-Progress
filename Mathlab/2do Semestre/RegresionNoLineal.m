T = readtable("Regresion.csv");


X = [height(T),sum(T.xi),sum(T.xi.^2),sum(T.xi.^3),sum(T.xi.^4);...
    sum(T.xi),sum(T.xi.^2),sum(T.xi.^3),sum(T.xi.^4),sum(T.xi.^5)];

Y = [sum(T.yi);sum(T.xi.*T.yi)];

a = linsolve(X,Y);

a0 = a(1);
a1 = a(2);
f = @(x) a0+a1*x;

x = 0:0.1:10;
y = f(x);

p = polyfit(T.xi,T.yi,1);
fprintf('a0 = %f\n',a0);
fprintf('a1 = %f\n',a1);


scatter(T.xi,T.yi);
hold on
grid on
plot(x,y)
    
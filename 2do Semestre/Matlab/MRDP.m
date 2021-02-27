% Alejandro Daniel González Carrillo A01570396
% Solucion 1
p1 = @(x) x.^3 -6.*x.^2 +11.*x -6;
x = -1:0.1:5;
plot(x,p1(x))
grid on

hold on
A = [1 -6 11 -6];
r = RaicesDP(A);
disp('Las raices son = ')
disp(r)

% evalua las raices con el polinomio
a = p1(r);

% graficar raices
plot(r,a,'or');

%% Solucion 2

p1 = @(x) x.^3 -x.^2 -4.*x +4;
x = -5:0.1:5;
plot(x,p1(x))
grid on

hold on
A = [1 -1 -4 4];
r = RaicesDP(A);
disp('Las raices son = ')
disp(r)

% evalua las raices con el polinomio
a = p1(r);

% graficar raices
plot(r,a,'or');

%% Solucion 3

p1 = @(x) -x.^4 +10.*x.^2 -9;
x = -5:0.1:5;
plot(x,p1(x))
grid on

hold on
A = [-1 0 10 0 -9];
r = RaicesDP(A);
disp('Las raices son = ')
disp(r)

% evalua las raices con el polinomio
a = p1(r);

% graficar raices
plot(r,a,'or');

%% Solucion 4

p1 = @(x) 2.*x.^3 +x.^2 -13.*x +6;
x = -5:0.1:5;
plot(x,p1(x))
grid on

hold on
A = [2 1 -13 6];
r = RaicesDP(A);
disp('Las raices son = ')
disp(r)

% evalua las raices con el polinomio
a = p1(r);

% graficar raices
plot(r,a,'or');

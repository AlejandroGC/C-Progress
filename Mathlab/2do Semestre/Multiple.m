clc;
close all;
clear;

T = readtable("Multiple.csv");

X = [height(T),sum(T.x1),sum(T.x2);...
    sum(T.x1),sum(T.x2),sum(T.x1.*T.x2);...
    sum(T.x2),sum(T.x1.*T.x2),sum(T.x2.^2)];

Y = [sum(T.yi); sum(T.x1.*T.yi); sum(T.x2.*T.yi)];

a = linsolve(X,Y);

f = @(x1,x2) a(1) + a(2)*x1 + a(3)*x2;
scatter3(T.x1,T.x2,T.yi);

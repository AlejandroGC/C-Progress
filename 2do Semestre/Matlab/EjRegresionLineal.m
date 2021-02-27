T = readtable('regresion.csv');

scatter(T.xi,T.yi)

n = size(T.xi, 1);
for i = 1:n;
    xy(i) = T.xi(i)*T.yi(i)
    x2(i) = T.xi(i)^2;
    y2(i) = T.xi(i)^2;
end

a1 = (n*sum(xy)-sum(T.xi)*(T.yi))/(n*sum(x2)-(sum(T.xi)^2));
a0 = mean(T.yi)
hold on
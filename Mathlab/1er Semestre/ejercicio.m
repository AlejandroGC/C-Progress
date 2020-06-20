t = (0:0.5:100);
x = 4*t.^3;
y = 5*t.^2;

plot3(x,y,t)
hold on

xp = (12*t.^2);
yp = (10*t);

plot3(xp,yp,t)
grid on
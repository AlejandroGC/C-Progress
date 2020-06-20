t = 0:5:200;
x = (4*t.^3-10*t);
y = (9*t-t.^2);
plot3(x,y,t)
hold on
vx = (12*t.^2-10);
vy = (9-2*t);
plot3(vx,vy,t)
hold on



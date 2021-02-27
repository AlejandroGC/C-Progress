syms x
h = 0.1;
f = -0.5*x.^4+4*x.^3-10*x.^2+8.5*x+1;
f1 = diff(f);
x = 0:h:4;
y = subs(f,x);

subplot(2,1,1)
plot(x,y,'linewidth',2)
hold on
grid on

yi = 1;
xi = 0;
vyi = yi;

for i = h:h:4
    xi = xi + h;
    yi = yi + subs(f1,xi)*h;
    vyi = [vyi,yi];
    
end    

grid on
subplot(2,1,2)
plot(x,vyi)



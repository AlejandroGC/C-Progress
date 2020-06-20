t = [-10:1:10];
k = [(4*t.^2)+t];
A = [t' k'];
plot(t,k)
x = [0, A(1)];
y = [0, A(1,2)];
x2 = [0, A(2)];
y2 = [0, A(2,2)];
hold on
%line(x,y,'color','red','LineStyle','--');
%line(x,y,'color','red','LineStyle',':');
%line(x,y,'color','red','LineStyle','--');
%line(x2,y2,'color','green','LineStyle','-');
xlabel('tiempo')
ylabel('posicion')
title('vector R(t)')
hold on
plot(t,k)
grid on
grid off
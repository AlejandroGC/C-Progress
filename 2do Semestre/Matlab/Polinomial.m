% Regresión polinomial
clear
clc
% Datos experimentales
Cp=[1.00738,1.00129,0.99883,0.99802,0.99804,0.99854,0.99943,1.00067,...
1.00229,1.00437,1.00697];
T=[273,283,293,303,313,323,333,343,353,363,373];
% Cálculo de los parámetros de regresión lineal (no es el ajuste correcto)
p1=polyfit(T,Cp,1);
r2=corrcoef(T,Cp);
Cp1=polyval(p1,T);
ao=p1(2); bo=p1(1);
fprintf('ao =%5.3e\n',ao);
fprintf('bo =%5.3e\n',bo);
fprintf('r2 =%5.4f\n\n',r2(2,1));
% Cálculo de los parámetros de regresión polinomial con n = 4
p2=polyfit(T,Cp,4);
a=p2(5); b=p2(4); c=p2(3); d=p2(2); e=p2(1);
fprintf('a =%5.3e\n',a);
fprintf('b =%5.3e\n',b);
fprintf('c =%5.3e\n',c);
fprintf('c =%5.3e\n',d);
fprintf('d =%5.3e\n\n',e);
% Cálculo de los nuevos valores de Cp según la función de ajuste
T1=linspace(273,373,100);
Cp2=polyval(p2,T1);
% Tabla de resultados
fprintf(' T, K Cp, cal/mol K\n\n');
for i=1:10:length(T1)
   fprintf('%5.0f',T1(i));
   fprintf('%15.5f\n',Cp2(i));
end
% Gráfico de los datos experimentales, de la recta y de la función de ajuste
plot(T,Cp,'*',T,Cp1,T1,Cp2);
title('Capacidad calórica del agua')
xlabel('T, K');
ylabel('Cp, cal/mol K');
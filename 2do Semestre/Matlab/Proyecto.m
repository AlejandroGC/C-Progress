%% Avance de reto, entregable 1
% Alejandro Daniel González Carrillo…….. A01570396
%  Luis García Solís …………………………….A01733800
%  Carlos Astengo Macías……………………….A01570405
%  Adrián González Saldívar…………………...A00827845
%  Luis Angel Mendoza………………………...A00827838


Npuntos = 25; % Numero de puntos en la malla
cargas = [2,-2]; % Dos cargas una positiva y una negativa
Radio = 0.2; % Radio ambas cargas
xCarga = [-0.5,0.5]; % Define el vector de la posicion x
yCarga = [0,0]; % Define el vector de la posicion y
Eps = 8.854e-12; % Epsilon
k = 1/(4 * pi * Eps); % Constante K

% Definir dimensiones del grafico
minX = -1.5;
maxX = 1.5;
minY = -1.5;
maxY = 1.5;

% Inicializar espacio para guardar el campo electrico
CampoElectricoX = zeros(Npuntos);
CampoElectricoY = zeros(Npuntos);

X = linspace(minX,maxX,Npuntos);
Y = linspace(minY,maxY,Npuntos);

[XpuntosMalla, YpuntosMalla] = meshgrid(X,Y);

for i = 1:2
   DistanciaX = XpuntosMalla - xCarga(i);
   DistanciaY = YpuntosMalla - yCarga(i);
   R = sqrt(DistanciaX.^2 + DistanciaY.^2);
   R3 = R.^3;
   CampoElectricoX = CampoElectricoX + k .* cargas(i) .* DistanciaX ./ R3;
   CampoElectricoY = CampoElectricoY + k .* cargas(i) .* DistanciaY ./ R3; 
end

CampoE_Total = sqrt(CampoElectricoX .^2 + CampoElectricoY .^2);

% Graficar

quiver(XpuntosMalla,YpuntosMalla,CampoElectricoX ./ CampoE_Total,CampoElectricoY ./ CampoE_Total);

hold on 

pos1 = [-Radio + xCarga(1), -Radio, 2*Radio, 2*Radio];
pos2 = [-Radio + xCarga(2), -Radio, 2*Radio, 2*Radio];
rectangle('Position',pos1,'Curvature',[1,1],'FaceColor',[1 0 0])
rectangle('Position',pos2,'Curvature',[1,1],'FaceColor',[1 1 0])
xlabel('eje x')
ylabel('eje y')
title('Campo Electrico de dos cargas con signos opuestos')
text(-0.58,0,'+','Color','black','FontSize',35)
text(-0.57,0.13,'2c','Color','black','FontSize',15)
text(0.46,0.04,'-','Color','black','FontSize',35)
text(0.41,0.11,'-2c','Color','black','FontSize',15)
axis([-1 1 -1 1])
axis equal
grid on



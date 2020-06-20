%% 3
%  Alejandro Daniel González Carrillo…….. A01570396
%  Luis García Solís …………………………….A01733800
%  Carlos Astengo Macías……………………….A01570405
%  Adrián González Saldívar…………………...A00827845
%  Luis Angel Mendoza………………………...A00827838


Npuntos = 25; % Numero de puntos en la malla
vector = 100;
cargas = ones(1,vector)*(3*10^-9);
cargas(vector/2 + 1:vector) = cargas(vector/2 + 1:vector)*(-1);
Radio = 0.2; % Radio ambas cargas
xCarga = ones(1,vector); % Define el vector de la posicion x
xCarga(1:vector/2) = xCarga(1 :vector/2)*(-1);
xCarga(vector/2 + 1:vector) = xCarga(vector/2 +1: vector)*(1);
% yCarga = ones(1,vector/2); % Define el vector de la posicion y
y1 = 1;
y2 = 7;
y3 = 3;
y4 = 5;
distanciaCargasY1 = linspace(y1,y2,vector/2);
distanciaCargasY2 = linspace(y3,y4,vector/2);
yCarga = [distanciaCargasY1,distanciaCargasY2];
Eps = 8.854e-12; % Epsilon
k = 1/(4 * pi * Eps); % Constante K

% Definir dimensiones del grafico
minX = -3.0;
maxX = 3.0;
minY = -5.0;
maxY = 10.0;

% Inicializar espacio para guardar el campo electrico
CampoElectricoX = zeros(Npuntos);
CampoElectricoY = zeros(Npuntos);

X = linspace(minX,maxX,Npuntos);
Y = linspace(minY,maxY,Npuntos);

[XpuntosMalla, YpuntosMalla] = meshgrid(X,Y);

for i = 1:vector
   DistanciaX = XpuntosMalla - xCarga(i);
   DistanciaY = YpuntosMalla - yCarga(i);
   DistanciaTotalX = DistanciaX;
   DistanciaTotalY = DistanciaY;
   R = sqrt(DistanciaTotalX.^2 + DistanciaTotalY.^2);
   R3 = R.^3;
   CampoElectricoX = CampoElectricoX + k .* cargas(i) .* DistanciaTotalX ./ R3;
   CampoElectricoY = CampoElectricoY + k .* cargas(i) .* DistanciaTotalY ./ R3; 
end

CampoE_Total = sqrt(CampoElectricoX .^2 + CampoElectricoY .^2);



% Graficar

quiver(XpuntosMalla,YpuntosMalla,CampoElectricoX ./ CampoE_Total,CampoElectricoY ./ CampoE_Total);

hold on 

% pos1 = [-Radio + xCarga(1), -Radio + yCarga(1), 2*Radio, 2*Radio];
% pos2 = [-Radio + xCarga(2), -Radio + yCarga(2), 2*Radio, 2*Radio];
% pos3 = [-Radio + xCarga2(1), -Radio + yCarga2(1), 2*Radio, 2*Radio];
% pos4 = [-Radio + xCarga2(2), -Radio + yCarga2(2), 2*Radio, 2*Radio];
% pos5 = [-Radio + xCarga3(1), -Radio + yCarga3(1), 2*Radio, 2*Radio];
% pos6 = [-Radio + xCarga3(2), -Radio + yCarga3(2), 2*Radio, 2*Radio];
% 
% rectangle('Position',pos1,'Curvature',[1,1],'FaceColor',[1 0 0])
% rectangle('Position',pos2,'Curvature',[1,1],'FaceColor',[1 1 0])
% rectangle('Position',pos3,'Curvature',[1,1],'FaceColor',[1 0 0])
% rectangle('Position',pos4,'Curvature',[1,1],'FaceColor',[1 1 0])
% rectangle('Position',pos5,'Curvature',[1,1],'FaceColor',[1 0 0])
% rectangle('Position',pos6,'Curvature',[1,1],'FaceColor',[1 1 0])
% 
% xlabel('eje x')
% ylabel('eje y')
% title('Campo Electrico de dos conjuntos con signos opuestos (Campo Dipolo)')
% text(-0.60,0.95,'+','Color','black','FontSize',35)
% text(-0.57,1.12,'3nC','Color','black','FontSize',15)
% text(0.45,0.98,'-','Color','black','FontSize',35)
% text(0.38,1.11,'-3nC','Color','black','FontSize',15)
% axis([-1.6 1.7 -1.3 1.0])
% axis equal
% grid on



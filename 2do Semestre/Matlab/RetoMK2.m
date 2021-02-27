% RETO Mk 2

carga = 3*10^-9; % magnitud de cargas
ncargasp = 100; % numero de carags positivas
ncargasn = 60; % numero de cargas negativas
longp = 10; % longitud carga positiva
longn = 6; % longitud carga negativa

cargasp = ones(1, ncargasp)*(carga); % vector cargas positivas
cargasn = ones(1, ncargasn)*(carga)*(-1); % vector cargas negativas

cargasi = zeros (ncargasp, 2); % matriz posiciones c positivas
cargasd = zeros (ncargasn, 2); % matriz posiciones c negativas

xi = -1; % posicion inicial en x cargas postivas
yi = 5; % posicion inicial en y cargas positivas
xd = 1; % posicion inicial en x cargas negativas
yd = 3; % posicion incial en y cargas negativas

for i = 1:ncargasp % llena matriz posiciones positiva
   cargasi (i,:) = [xi, yi];
   yi = yi- longp/ncargasp; 
end
for i = 1:ncargasn % llena matriz posiciones negativas
   cargasd (i,:) = [xd, yd];
   yd = yd- longn/ncargasn; 
end

Eps = 8.854e-12; % Epsilon
k = 1/(4 * pi * Eps); % Constante K

Npuntos = 20;
% Definir dimensiones del grafico
minX = -10;
maxX = 10;
minY = -10;
maxY = 10;

% Inicializar espacio para guardar el campo electrico
CampoElectricoX = zeros(Npuntos);
CampoElectricoY = zeros(Npuntos);
CampoElectricoX2 = zeros(Npuntos);
CampoElectricoY2 = zeros(Npuntos);

X = linspace(minX,maxX,Npuntos);
Y = linspace(minY,maxY,Npuntos);

[XpuntosMalla, YpuntosMalla] = meshgrid(X,Y);

for i= 1:ncargasp
   DistanciaX = XpuntosMalla - cargasi (i, 1);
   DistanciaY = YpuntosMalla - cargasi(i, 2);
   
   R = sqrt(DistanciaX.^2 + DistanciaY.^2);
   R3 = R.^3;
   CampoElectricoX = CampoElectricoX + k .* cargasp(i) .* DistanciaX  ./ R3;
   CampoElectricoY = CampoElectricoY + k .* cargasp(i) .* DistanciaY ./ R3;
end
for i= 1:ncargasn
   DistanciaX = XpuntosMalla - cargasd (i, 1);
   DistanciaY = YpuntosMalla - cargasd(i, 2);
   
   R = sqrt(DistanciaX.^2 + DistanciaY.^2);
   R3 = R.^3;
   CampoElectricoX = CampoElectricoX + k .* cargasn(i) .* DistanciaX  ./ R3;
   CampoElectricoY = CampoElectricoY + k .* cargasn(i) .* DistanciaY ./ R3;
end
CampoE_Total = sqrt(CampoElectricoX.^2 + CampoElectricoY.^2);

quiver(XpuntosMalla,YpuntosMalla,CampoElectricoX./ CampoE_Total,CampoElectricoY./ CampoE_Total);
hold on

for i = 1:ncargasp
    pos1 = [cargasi(i,1),cargasi(i,2), 0.1, 0.1];
    rectangle('Position',pos1,'Curvature',[1,1],'FaceColor',[1 0 0])
    xlabel('eje x')
    ylabel('eje y')
    title('Campo Electrico de dos conjuntos con signos opuestos (Campo Dipolo)')
    grid on
end
for i = 1:ncargasn
    pos1 = [cargasd(i,1),cargasd(i,2), 0.1, 0.1];
    rectangle('Position',pos1,'Curvature',[1,1],'FaceColor',[1 0 0])
    xlabel('eje x')
    ylabel('eje y')
    title('Campo Electrico de dos conjuntos con signos opuestos (Campo Dipolo)')
    grid on
end

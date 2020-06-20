salario = input("Salario: ");
antiguo = input("Antiguedad: ");
ganancia = 0;
salarioA = 0;

if antiguo < 1
    salarioA = salario * .05;
    ganancia = salarioA + salario;
    fprintf("Tu salario es de %i de acuerdo a tu tiempo que es %i año(s)", ganancia, antiguo);
elseif (antiguo >= 1) && (antiguo < 2)
    salarioA = salario * .07;
    ganancia = salarioA + salario;
    fprintf("Tu salario es de %i de acuerdo a tu tiempo que es %i año(s)", ganancia, antiguo);
elseif (antiguo >= 2) && (antiguo < 5)
    salarioA = salario * .10;
    ganancia = salarioA + salario;
    fprintf("Tu salario es de %i de acuerdo a tu tiempo que es %i año(s)", ganancia, antiguo);
elseif (antiguo >= 5) && (antiguo < 10)
    salarioA = salario * .07;
    ganancia = salarioA + salario;
    fprintf("Tu salario es de %i de acuerdo a tu tiempo que es %i año(s)", ganacia, antiguo);
else
    salarioA = salario * .20;
    ganancia = salarioA + salario;
    fprintf("Tu salario es de %i de acuerdo a tu tiempo que es %i año(s)", ganancia, antiguo);
end
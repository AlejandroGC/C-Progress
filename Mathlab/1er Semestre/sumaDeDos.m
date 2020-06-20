n1 = input("n1: ");
n2 = input("n2: ");
n3 = input("n3: ");

if n1 + n2 == n3
    fprintf("%i + %i = %i",n1,n2,n3);
elseif n1 + n3 == n2
    fprintf("%i + %i = %i",n1,n3,n2);
elseif n2 + n3 == n1
    fprintf("%i + %i = %i",n2,n3,n1);
else
    fprintf("ninguno");
end
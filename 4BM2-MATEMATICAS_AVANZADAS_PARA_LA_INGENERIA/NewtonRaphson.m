clc
%clear all se dejo como comentario por falta de actualizaciones y eficiencia de la funcion
format short
syms x;
%Datos dados por el Usuario.
ec = input('Ingresa la función en términos de x: ', 's');
f = str2func(['@(x) ', ec]);

valorInicial = input('Ingrese x0: ');
x0 = valorInicial;

tol = double(0.1);
n = 70;

%%%%%%%%%%%%%%%%%Codigo del Metdo Newton-Raphson%%%%%%%%%%%%%%%%%%%
figure('color' , 'white');
disp('No.Iter   Xn+1    Error')
Error=[];
h = 0.001;
df_x0 = (f(x0 + h) - f(x0 - h)) / (2 * h);
for i = 1:n
     XNs = x0 - (double(f(x0)) / df_x0);
    raices(1:i) = XNs;
    errX = double(round(abs(XNs -x0) , 4));
    fprintf('%3d\t%11.4d\t%11.4d\n', i, x0, errX);

    if (errX < tol)
        break
    end
    x0 = XNs;
    Error=[Error;errX];

% Plotting the function
X = linspace(x0 - 1, x0 + 1, 100); % Adjust the range as needed
Y = f(X);
subplot(2, 1, 1)
plot(X, Y, XNs, f(XNs), 'ro-', 'linewidth', 2);
xlabel('X');
ylabel('f(x)');
title('Graph of the function');
grid on;

% Plotting the error
subplot(2, 1, 2)
plot(1:i, Error, 'r-', 'linewidth', 2)
xlabel('Number of Iterations');
ylabel('Error In Solution');
title('Graph of Errors');
grid on;
drawnow
end
if (i == n)
    fprintf('No se encontro solucion con el metodo o las iteraciones');
    XNs = ('Indefinido');
end
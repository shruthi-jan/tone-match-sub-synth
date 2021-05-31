function [E] = linear_energy(x,M)

% to calculate the number of windows
f = round(length(x)/M);

len = f*M;
x = x(1:len);
xe = reshape(x, [f,M]);
E = sum(xe.^2)'/14;


end


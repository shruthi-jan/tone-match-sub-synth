function [y1,y2,zi] = GoldRaderOsc(f0,fs,N,zi)
%%
% Input :
% f0 - fundamental frequency from the note
% fs - sampling frequency
% N - length of the time vector t
% zi - stores the previous values of the output (1 x 2)

% Output
%y1 - output vector 1 of the GR Oscillator ( Nx1)
%y2 - output vector 2 of the GR Oscillator ( 90  degree phase shift) ( Nx1)
%%
omega_c =(2*pi*f0)/fs;
r = 1;
a = r*sin(omega_c);
b = r*cos(omega_c);

y1 = zeros(N,1);
y2 = zeros(N,1);


prev_out1 = zi(1);
prev_out2 = zi(2);

for n = 1:N
    y1(n) = (b*prev_out1) + (a*prev_out2);
    y2(n) =(-a*prev_out1) + (b*prev_out2);
    prev_out1 = y1(n);
    prev_out2 = y2(n);
end
zi(1) = prev_out1;
zi(2) = prev_out2;


    
end


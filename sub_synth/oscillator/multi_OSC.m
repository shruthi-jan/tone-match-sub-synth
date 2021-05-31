
function [y,zi] = multi_OSC(f0,fs,N,wf,zi)
%%
% Input:
%f0 - fundamental frequency from the note
% fs - sampling frequency
% N - length of the time vector t
% zi - matrix that stores the previous values of the output.(3 x 2) ( 1strow - Oscillator, 2nd row - lowpass filter, 3rd row - sawtooth waveform )
% wf - integer value to choose waveform type ( 0 -sine, 1 - square, 2-
% triangle, 3 - sawtooth, 4 - noise)

% Output
 %y - Output vector (1xN) of the oscillator + 2nd order LPF (multi oscillator)
 %%
y = zeros(N,1);
for n = 1:N

[y(n),~,zi(1,:)] = GoldRaderOsc(f0,fs,1,zi(1,:));
y(n)= 1 *y(n);

switch round(wf)
case 0  % sine/ cosine
  
case 1  % rectangle/ square
    th = 0;
    for i = 1:N
        if (y(i)< th)
            y(i)= -1;
        end
        if(y(i) == th)
            y(i) = 0;
        end
        if (y(i) > th)
            y(i) = 1;
        end
    end
    

case 2 % triangle
N1 =fs/f0;
step = 4.*(1/N1);
prev_out1 = zi(3,2);
%y = zeros(N,1);
 for i = 1:N
     if (y(i) >= 0)
         y(i) = prev_out1 + step;

     elseif( y(i)<0 )
        y(i) = prev_out1 - step;    
     end
       
       prev_out1 = y(i);
   
 %[y] = taylor_series(y,p);
 end
zi(3,2) = prev_out1;

case 3  % sawtooth
  
N1 =fs/f0;
step = 2.*(1/N1);
y = zeros(N,1);
prev_out = zi(3,1);

for i = 1:N
       
       y(i)= prev_out+ step;
       
    if (y(i)>=1)
        y(i) = -1;
    end
  prev_out = y(i);
  
end
zi(3,1) = prev_out;

case 4  % noise
        
  y = 2*rand(1,N) -1;
        
        
otherwise
    disp('other value')
end

end

for n = 1:N  % filter

[y(n), zi(2,:)] = lowpass_2(y(n),20000,fs ,0.7,zi(2,:));

end

end











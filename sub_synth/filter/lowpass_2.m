function [y, zi] = lowpass_2(x,fc,fs,Q,zi)
%lowpass_2 Summary of this function goes here
%   Input:
% x - input vector of ones and zeros (1x 1000)
% fc - cut off frequency of the low pass filter (in Hz)
% fs - sampling frequency (44.1KHz or 96KHz)
% Q - Q factor/peak factor (controls the width of the peak at fc)
% zi - vector to store the previous value of the output (1x2)
%Output:
% y - output vector of the 2nd order low pass filter (1x1000)
%%
%b0, b1,b2, a1, a2 - filter coeffecients
K = tan((pi*fc)/fs);  % K depends on fc
b0 = ((K*K)*Q)/(((K*K)*Q) +K +Q);
b1 = (2*(K*K)*Q)/(((K*K)*Q) +K +Q);
b2 = ((K*K)*Q) /(((K*K)*Q) +K +Q) ;
a1 = (2*Q*((K*K)-1))/(((K*K)*Q) +K +Q);
a2 = (((K*K)*Q)- K +Q)/(((K*K)*Q) +K +Q);

prev_xh1 = zi(1);
prev_xh2 = zi(2);

xh = zeros(length(x),1);
y = zeros(length(x),1);

for n = 1:length(x)
    
    xh(n) = x(n)-(a1*prev_xh1)-(a2*prev_xh2);
    y(n) = (b0*xh(n))+(b1*prev_xh1)+((b2*prev_xh2));
    prev_xh2 = prev_xh1;
    prev_xh1 = xh(n);
         
end
  zi(1) = prev_xh1;
  zi(2) = prev_xh2;
  
%y = filter([b0 b1 b2],[1 a1 a2],x);

end


function [p_coeff,t,y1,y2] = P_coeff_costfunction(x,x1,fs,M,hopLength)
% Pearson coefficient - to check the correlation between the optimised
% sound and the reference sound from the synthesizer
[y1,~] = mfcc_plot(x1,fs,M,hopLength);
[y2,t] = mfcc_plot(x,fs,M,hopLength);


 sum_c_y1 = sum(y1,2);  % x
 sum_c_y2 = sum(y2,2);  % y
 prod_xy = (sum_c_y1).*(sum_c_y2); %xy
 sq_y1 = sum_c_y1.^2; % x^2
 sq_y2 = sum_c_y2.^2; % y^2
 M = M*14;
 n1 = M*(sum(prod_xy)) - ((sum(sum_c_y1))*(sum(sum_c_y2)));
 d1 = M*sum(sq_y1) -(sum(sum_c_y1))^2;
 d2 = M*sum(sq_y2) -(sum(sum_c_y2))^2;
 p_coeff = n1/sqrt(d1*d2);
 
 
end


function [rms_val,t,z,z1,E,E1] = mfcc_costfunction(x,x1,fs,M,M1,hopLength)
%%
%UNTITLED4 Summary of this function goes here
% Input :
%x - input audio signal in .wav format
%x1 - reference audio signal in .wav format
%fs - sampling frequency
%M - number of windows
% E - Energy is calculated to avoid -Inf values due to zeros in the sample
% sound.
%hopLength - Number of samples in the current frame before of the start of the next frame (Windowlength - Overlaplength)

% Output :
%rms_val - rms error value calculated from the difference of two audio signals
%t - time vector - starting point of each sample (Mx1)
%z - z is the matrix of (M x coef_vec) for audio input x
%z1 - z1 is the matrix of (M x coef_vec) for audio reference x1

 %%
[z1,~] = mfcc_plot(x1,fs,M,hopLength);
[z,t]  = mfcc_plot(x,fs,M,hopLength);
[E] = linear_energy(x,M1);
[E1] = linear_energy(x1,M1);
z= horzcat(E,z);
z1 = horzcat(E1,z1);
% to compute the rms error value between two mfcc functions. 
% z1 is the mfcc of the synthesizer output
% z is the mfcc of the audio input against which the mfcc of the
% synthesizer output is compared to.
diff = z1 - z;  % calculates the difference between the two mfcc matrices to give a diff matrix of the same dimension ( M X coef_vec)
p_square = diff.^2; % calculate the power of each sample
%sum_r = sum(p_square);  % summation along each column and stored as a  row vector 
%rms_vect = sqrt(sum_r)/M; % take the square root over the number of windows to get the rms vector
sum_c = sum(sum(p_square, 2)); % compute the sum again of the row vector to get a single value for the rms value.
rms_val = (sqrt(sum_c)/(M*14));% take the square root over the matrix of dimension ( M X coef_vec) to get rms error value

end


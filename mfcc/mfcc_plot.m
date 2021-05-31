function [mfcc_mat,t] = mfcc_plot(x,fs,M,hopLength)
%%
%Input :
%x -  input audio signal in .wav format
%fs - sampling frequency
%M - number of windows
%hopLength - Number of samples in the current frame before of the start of the next frame (Windowlength - Overlaplength)

%Output:
%mfcc_mat - y is the matrix of (M x coef_vec). for each window M we get 13 mfcc and log energy for that window
%t - time vector - starting point of each sample (Mx1)
%%
[mfcc_mat] = mfcc(x,fs,'WindowLength',2880,'OverlapLength',1920 ,'LogEnergy','Ignore');
%round(fs.*0.030)
%round(fs*0.02)
 n = zeros(round(M),1);
 t = zeros(round(M),1);
 
 % for the mfcc function to plot against time. 
 %n - indicates the index of the samples. 
 %n(m) gives the starting point of each window. 
 %The time ranges from (length of the signal / fs) in seconds. 
 %t(m) gives the starting time of each sample
 
for m = 1:M  
 n(m) = hopLength*(m-1);   
 t(m) = n(m)/fs;
end

end



% sanity check : to see if the RMS value decreases with increaing
% frequencies
[x,fs] = audioread('sample1_saw_ref.wav');
zi = [0, 0];
WindowLength = round(fs.*0.030);
OverlapLength = round(fs*0.02);
hopLength = WindowLength - OverlapLength;
M= (length(x)-WindowLength)/(hopLength)+1;
M1 = round(M);
%soundsc(x,fs);
%[y, zi] = lowpass_1(x,1000,fs,zi);
fc = 100:500:20000;
rms_val = zeros(1,40);
%y1 = zeros(1,10);
for n = 1:40
 [y1,zi] = lowpass_1(x,fc(n),fs,zi);
 audiowrite('sample1_saw_ref_lp.wav',y1,fs);
 [y1,fs] = audioread('sample1_saw_ref_lp.wav');
 [rms_val(n),t,z,z1,E,E1] = mfcc_costfunction(x,y1,fs,M,M1,hopLength);
 % [rms_val(n),t,z,z1] = mfcc_costfunction(x,y1,fs,M,hopLength);
end
 %soundsc(y1,fs);
 plot(rms_val);
 grid on;
 xlabel ('Number of iterations');
 ylabel('RMS error');
 title('RMS values with frequencies');
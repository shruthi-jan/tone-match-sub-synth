clear all

fs =96000;
noteON = 100 ; 
noteOFF =1400; 
t = 0:1000/fs:4500;
note = (t >= noteON) & (t <= noteOFF);
N = length(note);

zi(1,:) = [0, 0];
zi(2,:) = [sin(0), cos(0)]; % vector zi(2,:) stores intial phase for the oscillator 
zi(3,:) = [0, 0]; % vector zi(3,:) stores the intial values of the 2nd order LPF
zi(4,:) = [0, -1]; % vector zi(4,:) stores the intial values for sawtooth wfm
zi(5,:) = [0, 0];
zi(6,:) = [0, 0];

[~,x] = synth(note,fs,110,10,1,N,zi,2,500,0.05,400,10,600,0.7,600,0.5); % sample 2

% WindowLength - Number of samples in the analysis window.
WindowLength = round(fs.*0.030); % window and overlap length are taken as default values
% Overlaplength - Number of overlapping samples between adjacent windows.
% OverlapLength should always be smaller than WindowLength
OverlapLength = round(fs*0.02);
%hopLength - Number of samples in the current frame before of the start of the next frame
hopLength = WindowLength - OverlapLength;
 %the mfcc function reads the audio signal and depending on the windowlength, overlaplength,it divides the signals 
 %into frames(windows) (M - number of windows)
M= (length(x)-WindowLength)/(hopLength)+1;
% Vector gives the index for the 14 mfcc coeffecients (13 + 1 energy coeff)
 coef_vec = 1:14;
% %[y,t] = mfcc_plot(x,fs,M,hopLength);
% y= horzcat(E,y);
[y,t] = mfcc_plot(x,fs,M,hopLength);
 % y is the matrix of (M x coef_vec). for each window M we get 13 mfcc and
 % log energy for that window

imagesc(t,coef_vec,y');
%colormap parula;
xlabel('time in seconds');
ylabel('coefficient vector');
ax = gca; % current axis
ax.YDir = 'normal';
c = colorbar; 
c.Label.String = 'MFCC values';
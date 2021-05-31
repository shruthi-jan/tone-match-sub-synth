clear all
fs =96000;


noteON = 100 ; %100;
noteOFF =3500; %3500 ;
t = 0:1000/fs:4500;
note = (t >= noteON) & (t <= noteOFF);
N = length(note);
f0 = 110;

zi(1,:) = [0,0]; %vector zi(1,:) stores the previous value of the amplitude and state respectively.
zi(2,:) = [sin(0), cos(0)];% vector zi(1,:) stores intial phase for the oscillator
zi(3,:) = [0, 0]; % vector zi(3,:) stores the intial values of the 2nd order LPF
zi(4,:) = [0, -1];% vector zi(4,:) stores the previous values for constructing the sawtooth wave
zi(5,:) = [0,0];
zi(6,:) = [0,0];

 [~,x] = synth(note,fs,440,0.7,1,N,zi,200,400,0.4,500,300,200,0.2,300,1);
 [~,x1] = synth(note,fs,440,0.5,1,N,zi,50,400,0.4,200,100,300,0.8,200,1);
 % [~,x] = synth(note,fs,110,6,2,N,zi,200,800,0.03,400,50,700,0.8,600,0.7); % sample 3
% [x,fs] = audioread('test_rect_ex2_ft.wav');
% [x1,fs] = audioread('test_rect.wav');
x = x(1:length(x1));

WindowLength = 2880; %round(fs.*0.030);
OverlapLength = 1920; %round(fs*0.02);
hopLength = WindowLength - OverlapLength;
M= (length(x)-WindowLength)/(hopLength)+1;
M1 = round(M);
% t = zeros(round(M),1);
%M2= (length(x2)-WindowLength)/(hopLength)+1;
coef_vec = 1:13;

[rms_val,t,z,z1,E,E1] = mfcc_costfunction(x,x1,fs,M,M1,hopLength);
%[rms_val,t,z,z1] = mfcc_costfunction(x,x1,fs,M,hopLength);

figure();
imagesc(t,coef_vec,z1');
title('mfcc coefficients - ref'); % ideally from the synthesizer
xlabel('time');
ylabel('coefficient vector');
ax = gca; % current axis
ax.YDir = 'normal';
colorbar;

figure();
imagesc(t,coef_vec,z');
%colormap parula;
xlabel('time in seconds');
ylabel('coefficient vector');
ax = gca; % current axis
ax.YDir = 'normal';
c = colorbar; 
c.Label.String = 'MFCC values';
%%








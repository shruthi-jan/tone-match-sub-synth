function [rms_val] = gen_synth(p,note,fs,f0,xa)
%UNTITLED4 Summary of this function goes here
%Input :
% p -row vector containing all parameters which is passed to the function
%note - note - vector of ones and zeros( 1 - when noteON, 0 - when noteOFF) ( 1 xN)
%fs - Sampling frequency
%f0 - fundamental frequency from the note
% xa - input reference audio given to the genetic algorithm

%Output:
%rms_val - returns the least rms error value after the optimization
%%
Q =  p(1);
wf = p(2);
a1 = p(3);
d1 = p(4);
s1 = p(5);
r1 = p(6);
a2 = p(7);
d2 = p(8);
s2 = p(9);
r2 = p(10);
fa = p(11);

zi = zeros(6,2);
N = length(note);

zi(1,:) = [0,0]; %vector zi(1,:) stores the previous value of the amplitude and state respectively.
zi(2,:) = [sin(0), cos(0)];% vector zi(2,:) stores intial phase for the oscillator
zi(3,:) = [0, 0]; % vector zi(3,:) stores the intial values of the 2nd order LPF
zi(4,:) = [0, -1];% vector zi(4,:) stores the previous values for constructing the sawtooth wave
zi(5,:) = [0,0];
zi(6,:) = [0,0];


WindowLength = 2880;%round(fs.*0.030);
OverlapLength = 1920; %round(fs*0.02);
hopLength = WindowLength - OverlapLength;



 M= (length(xa)-WindowLength)/(hopLength)+1;
 M1 = round(M);

[~,x] = synth_mex(note,fs,f0,Q,wf,N,zi,a1,d1,s1,r1,a2,d2,s2,r2,fa); 
[rms_val] = mfcc_costfunction(xa,x,fs,M,M1,hopLength);  % added M1 for linear energy



end


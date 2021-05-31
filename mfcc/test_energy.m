clear all
fs =96000;


noteON = 100 ; %100;
noteOFF =2500; %3500 ;
t = 0:1000/fs:4500;
note = (t >= noteON) & (t <= noteOFF);
N = length(note);
f0 = 440;

zi(1,:) = [0,0]; %vector zi(1,:) stores the previous value of the amplitude and state respectively. ADSR 1
zi(2,:) = [sin(0), cos(0)];% vector zi(2,:) stores intial phase for the oscillator
zi(3,:) = [0, 0]; % vector zi(3,:) stores the intial values of the 2nd order LPF ( within oscillator)
zi(4,:) = [0, -1];% vector zi(4,:) stores the previous values for constructing the sawtooth wave
zi(5,:) = [0,0]; % vector zi(5,:) stores the intial values of the filter
zi(6,:) = [0,0]; % Amplifier ; ADSR 2

 [~,x] = synth(note,fs,440,0.7,1,N,zi,200,400,0.4,500,300,200,0.2,300,1);
 %[x,fs] = audioread('test_rect_ex2_ft.wav');

WindowLength = 2880; %round(fs.*0.030);
OverlapLength = 1920; %round(fs*0.02);
hopLength = WindowLength - OverlapLength;
M= round ((length(x)-WindowLength)/(hopLength)+1);

[E] = linear_energy(x,M);





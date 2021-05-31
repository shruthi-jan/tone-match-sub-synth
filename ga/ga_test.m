fs =96000;

noteON = 100;
noteOFF = 3500 ;  % sample 1
t = 0:1000/fs:4500;
note = (t >= noteON) & (t <= noteOFF);
N = length(note);

f0 = 440;

%sample 1 - parameter bounds
 lb = [4, 0,  100, 1200, 0.1, 1200, 10, 200, 0.1, 700, 0.4]; % lower bound
 ub = [7, 3,  500,  1700 ,0.8, 1700, 50,700, 0.5, 1200, 1];  % upper bound
% values that the ga uses as a threshold for inital calculation
wf = 2;
Q= 1;
a1 = 10;  
d1 = 100;
s1 =0.01;
r1 = 100;
a2 = 1;
d2 = 100;
s2 = 0.1;
r2 = 100;
fa = 0.5;

p = [Q,wf,a1,d1,s1,r1,a2,d2,s2,r2,fa];
load('intial_population.mat', 'p1');
zi(1,:) = [0,0]; %vector zi(1,:) stores the previous value of the amplitude and state respectively.
zi(2,:) = [sin(0), cos(0)];% vector zi(1,:) stores intial phase for the oscillator
zi(3,:) = [0, 0]; % vector zi(3,:) stores the intial values of the 2nd order LPF
zi(4,:) = [0, -1];% vector zi(4,:) stores the previous values for constructing the sawtooth wave
zi(5,:) = [0,0];
zi(6,:) = [0,0];


%options: can be changed for different results
thestate = rng;
IntCon = 2;
options = gaoptimset;
options.Generations = 300;
options.stallGenLimit = 150;
options.PlotFcns = {@gaplotdistance, @gaplotbestf};
options.PopulationSize = 250;
options.InitialPopulation = p1;
%options.EliteCount = 25;
options.Vectorized = 'on';
options.Display = 'iter';
options.OutputFcns =@gaoutputfcn; 
options.CrossoverFraction = 0.9;
 %% to run the same sample multiple times
% % Change the for loop to the number of iterations the sample has to be run
% % for eg : here 75 iterations
% % x_r = zeros(75,11);
% % fval_r = zeros(75,1);
% tic
%   for n = 1: 75
%  
% [~,xa] = synth_mex(note,fs,440,6,3,N,zi,300,1500,0.5,1500,20,600,0.2,1000,0.8); % sample 1
%   func= @(p) gen_synth_vect(p,note,fs,f0,xa);
%    [x, fval] = ga(func,11,[],[],[],[],lb,ub,[],IntCon,options);
%     x_r(n,:) = x; 
%   fval_r(n,:) = fval;
%    clear xa;
%    pause(2);
%   end
%   toc
 %% to run once
 tic
 [~,xa] = synth_mex(note,fs,440,6,3,N,zi,300,1500,0.5,1500,20,600,0.2,1000,0.8); % sample 1
 func= @(p) gen_synth_vect(p,note,fs,f0,xa); % rms values function
 [x, fval] = ga(func,11,[],[],[],[],lb,ub,[],IntCon,options);
 toc



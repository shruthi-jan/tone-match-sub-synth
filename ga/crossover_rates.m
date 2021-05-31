% to run the Genetic algorithm for different crossover rates

fs =96000;

noteON = 100 ; %100;
noteOFF =3500; %3500 ;
t = 0:1000/fs:4500;
note = (t >= noteON) & (t <= noteOFF);
N = length(note);
f0 = 440;
% sample 1
 lb = [4, 0,  100, 1200, 0.1, 1200, 10, 200, 0.1, 700, 0.4]; % lower bound
 ub = [7, 3,  500,  1700 ,0.8, 1700, 50,700, 0.5, 1200, 1];  % upper bound
wf = 2;
Q= 1/sqrt(2);
a1 = 0.0001;  % values that the ga uses as a threshold for intial calculation
d1 = 0.0001;
s1 = 0.2;
r1 = 0.0001;
a2 = 0.0001;
d2 = 0.0001;
s2 = 0.2;
r2 = 0.0001;
fa = 0.7;
 p = [Q,wf,a1,d1,s1,r1,a2,d2,s2,r2,fa];
load('intial_population.mat', 'p1');
  
 
zi(1,:) = [0,0]; %vector zi(1,:) stores the previous value of the amplitude and state respectively.
zi(2,:) = [sin(0), cos(0)];% vector zi(1,:) stores intial phase for the oscillator
zi(3,:) = [0, 0]; % vector zi(3,:) stores the intial values of the 2nd order LPF
zi(4,:) = [0, -1];% vector zi(4,:) stores the previous values for constructing the sawtooth wave
zi(5,:) = [0,0];
zi(6,:) = [0,0];


IntCon = 2;
tic

options = gaoptimset;
options.Generations = 1500;
%options.stallGenLimit = 150;
%options.PlotFcns = {@gaplotdistance, @gaplotrange, @gaplotbestf};
options.PopulationSize = 250;
options.InitialPopulation = p1;
%options.EliteCount = 25;
options.Vectorized = 'on';
%options.Display = 'iter';
%options.OutputFcns =@gaoutputfcn;
%thestate = rng;

[~,xa] = synth_mex(note,fs,440,6,3,N,zi,300,1500,0.5,1500,20,600,0.2,1000,0.8);

func= @(p) gen_synth_vect(p,note,fs,f0,xa); % rms values function

rates = 0:0.2:1;
%y = length(rates);
x_r = zeros(600,11);
iterations = 100;
results = zeros(iterations,length(rates));
j =1;
for iteration = 1:iterations
for i = 1:length(rates)

 options.CrossoverFraction = rates(i);                         
 [x, fval] = ga(func,11,[],[],[],[],lb,ub,[],IntCon,options);
 %y(i) = fval;
 x_r(j,:) = x; 
 j = j + 1;
 results(iteration,i) = fval;
 pause(2);
end
end
toc


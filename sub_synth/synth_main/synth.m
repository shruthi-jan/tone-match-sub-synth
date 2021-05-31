function [y,y2,zi,fc,amp1,amp2] = synth(note,fs,f0,Q,wf,N,zi,a1,d1,s1,r1,a2,d2,s2,r2,fa)
%function [y,y1,y2,fc,zi,amp1,amp2,amp2_db,amp2_r] = synth(note,fs,f0,Q,wf,N,zi,a1,d1,s1,r1,a2,d2,s2,r2,fa)
%synth Summary of this function goes here
%  The function can be used in 2 ways. Due to change in code to optimize
%  the code for optimal memory ustilization when running the genetic
%  algorithm. In the memory optimized code the plots and spectrograms cannot be generated.
 %To generate the plots, spectrograms and outputs at each block use the
 %function call for the original code ( code not optimized for memory)
 % Here some changes are made :
 % 1. comment the memory optimization section.
 % 2. Use the following function call :
 %[y,y1,y2,fc,zi,amp1,amp2,amp2_db,amp2_r] = synth(note,fs,f0,Q,wf,N,zi,a1,d1,s1,r1,a2,d2,s2,r2,fa);
 
 % The memory optimization code is packaged into a mex version and this mex
 % version of synth.m is given to thre ga. Changes to the code can be made
 % to synth.m and then regenerate the mex again.
 
%%
% fc = zeros(N,1);
% y = zeros(N,1);
% y1 = zeros(N,1); %m
% y2 = zeros(N,1); %m
% 
% amp1 = zeros(1,length(note));
% amp2 = zeros(1,length(note));
% amp2_db = zeros(N,1);
% amp2_r = zeros(N,1);
% 
% for i = 1: N % correct
%     [amp1(i),zi(1,:)] = ADSR_envelope1(a1,d1,s1,r1,note(i),fs,zi(1,:));
%     [y(i),zi(2:4,:)] = multi_OSC(f0,fs,1,wf,zi(2:4,:)); % output of the oscillator which takes the f0 ( fundamental frequency) from the note and the waveform. This is then ghiven to the LPF.
%     fc(i) = fa * (amp1(i)*(19980) + 20);  % To calculate fc at each sample of the note, which is given to the filter for shaping the signal.
%     %fc(i) = fa * log10((a*fc(i))+1)/log10(1+a);
%     [y1(i), zi(5,:)] = lowpass_2(y(i),fc(i),fs,Q,zi(5,:)); % output of the VCF after modulation with ADSR envelope 1
%     [amp2(i),zi(6,:)] = ADSR_envelope1(a2,d2,s2,r2,note(i),fs,zi(6,:));
%     amp2_db(i) = amp2(i)*80 -80; % amplitude of ADSR Envelope 2 mapped from -80db(0) to 0db(1)
%     amp2_r(i) = 10^(amp2_db(i)/20); % amplitude converted back to linear scale 
%     y2(i)= amp2_r(i)'.*y1(i) ;
% end
%    y = y./max(abs(y));
%    y1 = y1./max(abs(y1));
%    y2 = y2./max(abs(y2));
   
%% memory optimization

    
fc =0;
y = zeros(N,1);
y2 = zeros(N,1);
amp1 = 0;    
amp2 =0;
for i = 1: N
    [amp1,zi(1,:)] = ADSR_envelope1(a1,d1,s1,r1,note(i),fs,zi(1,:));%     
    [y(i), zi(2:4,:)] = multi_OSC(f0,fs,1,wf, zi(2:4,:)); % output of the oscillator which takes the f0 ( fundamental frequency) from the note and the waveform. This is then given to the LPF.
    fc = fa*(amp1*(19980) + 20);% To calculate fc at each sample of the note, which is given to the filter for shaping the signal.
    [y(i), zi(5,:)] = lowpass_2(y(i),fc,fs ,Q,zi(5,:)); % output of the VCF after modulation with ADSR envelope 1
    [amp2,zi(6,:)] = ADSR_envelope1(a2,d2,s2,r2,note(i),fs,zi(6,:)); % VCA
    amp2 = amp2*80 -80; % amplitude of ADSR Envelope 2 mapped from -80db(0) to 0db(1)
    amp2 = 10^(amp2/20); % amplitude converted back to linear scale 
    y2(i)= amp2'.*y(i) ;
   
end
    y = y./max(abs(y));
    y2 = y2./max(abs(y2));
    
  %%to find out the db values
  g1 = max(abs(y));
  %g1_db = 20*log10(g1);
  y = y./g1;
  g2 =  max(abs(y2));
  y2 = y2./g2;

end


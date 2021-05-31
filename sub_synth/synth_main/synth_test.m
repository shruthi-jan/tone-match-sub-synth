% addpath('ADSR_envelope');
% addpath('filter');
% addpath('oscillator')
% functions from oscillator, filter and ADSR envelope shoukd be added.
% synth_main is is the combination af all blocks

fs =96000;   % sampling frequency
f0 = 110;    % fundamental frequency
t = 0:1000/fs:4500;  % adjust time for the note
% noteON - when attack starts
% noteOFF - when release begins
noteON = 100;
noteOFF = 1400;
note = (t >= noteON) & (t <= noteOFF);
N=length(note);
% parameters of the synthesizer
Q= 10;  % Resonance
% ADSR envelope 1
a1 = 200; 
d1 =500;
s1 = 0.05;
r1 = 400;
% ADSR envelope 2
a2 = 10;
d2 = 600;
s2 = 0.7;
r2 = 600;
wf = 1; % ( 0 - sine, 1 - rect, 2 - triangle, 3 - sawtooth, 4 - noise)
fa =0.5;  % amount of filter
%a =3;
%fa = log10((a*fa)+1)/log10(1+a);


zi(1,:) = [0,0]; %vector zi(1,:) stores the previous value of the amplitude and state respectively. ADSR 1
zi(2,:) = [sin(0), cos(0)];% vector zi(2,:) stores intial phase for the oscillator
zi(3,:) = [0, 0]; % vector zi(3,:) stores the intial values of the 2nd order LPF ( within oscillator)
zi(4,:) = [0, -1];% vector zi(4,:) stores the previous values for constructing the sawtooth wave
zi(5,:) = [0,0]; % vector zi(5,:) stores the intial values of the filter
zi(6,:) = [0,0]; % Amplifier ; ADSR 2

[y,y2,zi,fc,amp1,amp2] = synth(note,fs,f0,Q,wf,N,zi,a1,d1,s1,r1,a2,d2,s2,r2,fa); % memory optimized call


%% Run this section to see plots of the outputs
% To run this section : use this call
%[y,y1,y2,fc,zi,amp1,amp2,amp2_db,amp2_r] = synth(note,fs,f0,Q,wf,N,zi,a1,d1,s1,r1,a2,d2,s2,r2,fa);
% and comment the memory optimization call
%% Uncomment from the line below
%  %% to check outputs at oscillator, filter, amplifier
% subplot(3,1,1);
% NFFT = 2*4096;
% f = 0:fs/NFFT:(fs - (fs/NFFT));
% y_fft = 20*log10(abs (fft(y(1:NFFT),NFFT)));
% %plot(f,y_fft);
% semilogx(f,y_fft);
% xlim([0 20000]);
% grid on;
% xlabel('frequency in Hz'), ylabel('amplitude in dB'),title('output of the VCO');
% 
% % output of VCF
% subplot(3,1,2);
% y1_fft = 20*log10(abs (fft(y1(1:NFFT),NFFT)));
% %plot(f,y1_fft);
% semilogx(f,y1_fft);
% xlim([0 20000]);
% grid on;
% xlabel('frequency in Hz'), ylabel('amplitude in dB'),title('output of the VCF');
% 
% % 
% subplot(3,1,3);
% y2_fft = 20*log10(abs (fft(y2(1:NFFT),NFFT)));
% % %plot(f,y2_fft);
% semilogx(f,y2_fft);
% xlim([0 20000]);
% ylim([-80 0]);
% grid on;
% xlabel('frequency in Hz'), ylabel('amplitude in dB'),title('output of the VCA');
% 
% 
% %% to check if ADSR envelope modulates fc
%  figure();
% plot(t,fc);
% grid on;
% xlabel('time in ms'), ylabel('frequency'),title('output of the VCF');
% % 
% %% Spectrogram of output at oscillator, filter, amplifier
% subplot(3,1,1);
%  NFFT =8192;
%  spectrogram(y,hamming(NFFT),NFFT - NFFT/8,NFFT,fs,'yaxis');
%  xlabel('time in s');
%  ylabel('Frequency in KHz');
%  title('Spectrogram of VCO output');
%  set(gcf, 'Position',  [300, 200, 900, 400]);
%  caxis([-100 -40]);
%  ylim([0 20]);
% 
%  subplot(3,1,2);
% % NFFT =8192;
%  spectrogram(y1,hamming(NFFT),NFFT - NFFT/8,NFFT/2,fs,'yaxis');
%  xlabel('time in s');
%  ylabel('Frequency in KHz');
%  title('Spectrogram of VCF output');
%  caxis([-100 -40]);
%  ylim([0 20]);
%  set(gcf, 'Position',  [300, 200, 900, 400]);
% 
%  subplot(3,1,3);
% % NFFT =8192;
%  spectrogram(y2,hamming(NFFT),NFFT - NFFT/8,NFFT,fs,'yaxis');
%  xlabel('time in s');
%  ylabel('Frequency in KHz');
%  title('Spectrogram of VCA output');
%  caxis([-100 -40]);
%  ylim([0 20]);
%  %colorgrad;
%  set(gcf, 'Position',  [300, 200, 900, 400]);
% 
% %colormap jet;
%   
% 
%  %% ADSR Envelope plot 
% % ADSR Envelope 1
% subplot(2,1,1);
% hold on 
% yyaxis left
% plot(t,y1,'linewidth', 2), xlabel('time in ms'),ylabel('amplitude');
% hold on
% yyaxis right
% plot(t,fc, 'linewidth', 2 ); %'color', 'black');
% ylim([20 20000]);
% legend('VCF output','ADSR envelope 1');
% xlabel('time in ms'),ylabel('Frequency in Hz');
% grid on;
% 
% % ADSR Envelope 2
% subplot(2,1,2);
% plot(t,y2,'linewidth', 2), xlabel('time in ms'),ylabel('amplitude');
% hold on;
% plot(t,amp2, 'linewidth', 2, 'color', 'black');
% legend('VCA output','ADSR envelope 2');
% title('ADSR Envelope 2');
% grid on;
% 

 %% sound
% %soundsc(y,fs);
% %soundsc(y1,fs);
% 
g = max(abs(y2));
g1 = 20*log10(g);
m = y2./g;
soundsc(m,fs);
audiowrite('sample7_saw_ref.wav',m,fs); 


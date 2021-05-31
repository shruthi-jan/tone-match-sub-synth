clear all

fs =44100;
f0 = 400;
t = 0:1000/fs:4000;
N=length(t);

zi(1,:) = [sin(0), cos(0)]; % previous state : osciallator
zi(2,:) = [0, 0];   % previous state : filter
zi(3,:) = [0, -1];  % previous state : sawtooth waveform
%p = 20;

fc = 4000;
wf = 2; %input('Enter a number: ' );
y = length(1:N);
 
for n = 1:N

 [y(n),zi] = multi_OSC(f0,fs,1,wf,zi);

end
figure();
plot(t,y), xlabel('Time in s'),ylabel('Amplitude');
hold on
plot(t,y);
xlim([0 3000/f0]);
hold off

NFFT = 2*4096;
f = 0:fs/NFFT:(fs - (fs/NFFT));
%y_fft = 20*log10(abs (fft(y(1:NFFT).*hann(NFFT)',NFFT)));
y_fft = 20*log10(abs (fft(y(1:NFFT),NFFT)));
figure();
% semilogx(f,y_fft);
plot(f,y_fft),xlabel('Frequency in Hz'),ylabel('Magnitude in dB');
grid on;
xlim([0 fs/2]);                                   

%sound(y,fs);




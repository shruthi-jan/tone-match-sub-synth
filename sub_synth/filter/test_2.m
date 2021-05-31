% clear all
fs =44100;
fc = 2000;
Q=  4; % defau1t value : 1/sqrt(2);

x = [0 0 0 1 zeros(1,1000)];

zi = [0, 0];
y = zeros(length(x),1);
for n = 1:length(x)

[y(n), zi] = lowpass_2(x(n),fc,fs,Q,zi);

end
    freqz(y,1,2048,fs);

    ax = gca;
    ax.XScale = 'log';
    ylim([-80 10])
%% to plot only the frequency response 

% figure();
% f= 0:fs/2048:(fs -(fs/2048));
% y_fft = abs(fft(y,2048));
% y_db = 20*log10(y_fft);
% semilogx(f,y_db);
% plot(f,y_db);
% grid on;
% xlim([0 20000]);
% ylim([-20 20]);
% xlabel('frequency');
% ylabel('|H(f)| (dB)');
% title('frequency response');


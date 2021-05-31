fs = 96000;
t = 0:1000/fs:4000;
noteON = 200;
noteOFF = 2500;
note = (t >= noteON) & (t <= noteOFF); % noteOFF - noteON;

atime = 300;
dtime = 500;
slevel = 0.6;
rtime = 400;
zi = [0 0];
amp = zeros(length(note),1);

for i =1:length(note)
    [amp(i),zi] = ADSR_envelope1(atime,dtime,slevel,rtime,note(i),fs,zi);
end


plot(t,amp);
grid on;
xlabel ('time in s');
ylabel ('amplitude (0 to 1)')
title ('ADSR Envelope');
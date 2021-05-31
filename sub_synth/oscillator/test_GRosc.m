clear all

fs =44100;
f0 = 400;
t = 0:1000/fs:3000/f0;
N=length(t);

zi = [sin(0), cos(0)]; % vector zi stores intial phase for the oscillator
y1 = zeros(N,1);
y2 = zeros(N,1);

 for n = 1:length(t)
    
[y1(n),y2(n),zi] = GoldRaderOsc(f0,fs,1,zi);
 end

plot(t,y1), xlabel('time in ms'),ylabel('amplitude');
hold on
plot(t,y2);
hold off
legend('y1 - sine', 'y2 - cosine');


 

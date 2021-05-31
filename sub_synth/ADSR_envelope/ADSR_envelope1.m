function [amp,zi] = ADSR_envelope1(atime,dtime,slevel,rtime,note,fs,zi)
%%
%UNTITLED3 Summary of this function goes here
%  Input:
%atime - attack time (in s)
%dtime - decay time ( in s)
%slevel - sustain is a level
%rtime - release time (in s)
%note - vector of ones and zeros( 1 - when noteON, 0 - when noteOFF) ( 1 xN)
%fs - sampling frequency

%Output:
%amp - amplitude vector of the ADSR envelope (1 xN)
%zi- vector that stores 2 values. zi(1)- previous amplitude, zi(2)- sores
%the state at each sample.
%%

% if nargin < 7
%     zi = [0 0];
% end

% sample_a = fs*atime;
% step_a = 1/sample_a;
% 
% sample_d = fs*dtime;
% step_d = (1-slevel)/sample_d;
% 
% sample_r = fs*rtime;
% step_r = slevel/sample_r;

sample_a = fs*atime;
step_a = 1000/sample_a;

sample_d = fs*dtime;
step_d = 1000*(1-slevel)/sample_d;

sample_r = fs*rtime;
step_r = 1000*slevel/sample_r;


prev_out = zi(1);
state = zi(2);

% si = 0;
% prev_state = si;

amp = zeros(1,length(note));

for i =1:length(note)
    switch state
        case 0
            if(note(i) == 1)
                state = 1;
            end
           
        case 1
            
            amp(i) = prev_out +step_a;
            prev_out = amp(i);
            if (amp(i) >= 1)
                state = 2;
            end
            if (note(i) == 0)
                state =4;
            end
            
        case 2
                amp(i) = prev_out - step_d;
                prev_out = amp(i);
                
            if(amp(i) <= slevel)
                state =3;
            end
             if (note(i) == 0)
                state =4;
             end
            
        case 3
             amp(i) = slevel;
               if(note(i)== 0)
                   state =4;
               end
        case 4
              amp(i) = prev_out - step_r;
              prev_out = amp(i);
              if(amp(i) <= 0)
              state =0;
              end  
    end 
    
end

 zi(1) = prev_out;
 zi(2) = state;
 
end
function [rms_values] = gen_synth_vect(p,note,fs,f0,xa)

N =  size(p,1);
rms_values = zeros(N,1);

parfor n= 1:N
   
    rms_values(n) = gen_synth(p(n,:),note,fs,f0,xa);
    
end

end



% to generate intial population
noteON = 100;
noteOFF =3500 ;
t = 0:1000/fs:4500;
note = (t >= noteON) & (t <= noteOFF);
N = length(note);

lb1 = [1, 0,  1, 1, 0.01, 1, 1, 1, 0.01, 1, 0.1]; % lower bound
ub1 = [12,3, 2000,2000 ,1,2000,1000,2000, 1,2000, 1];  % upper bound

 a = 250;
 Q = (ub1(1) - lb1(1)).*rand(a,1) + lb1(1);
 wf = randi([lb1(2),ub1(2)],a,1);
 a1 =(ub1(3) - lb1(3)).*rand(a,1) + lb1(3);
 d1 =(ub1(4) - lb1(4)).*rand(a,1) + lb1(4);
 s1 =(ub1(5) - lb1(5)).*rand(a,1) + lb1(5);
 r1 =(ub1(6) - lb1(6)).*rand(a,1) + lb1(6);
 a2 =(ub1(7) - lb1(7)).*rand(a,1) + lb1(7);
 d2 =(ub1(8) - lb1(8)).*rand(a,1) + lb1(8);
 s2 =(ub1(9) - lb1(9)).*rand(a,1) + lb1(9);
 r2 =0;
 if (noteOFF +r2  <= 4500)
 r2 =(ub1(10) - lb1(10)).*rand(a,1) + lb1(10);
 end
 fa =(ub1(11) - lb1(11)).*rand(a,1) + lb1(11);

  p1 = [Q,wf,a1,d1,s1,r1,a2,d2,s2,r2,fa];
  save('intial_population.mat', 'p1');
  
  

m = 200;    %masse på AUV
k = 100;    %motstand fra vannet

v0 = 0;
v(1) = v0;

u = 500;    %konstant propellkraft

h = 0.1;    %tidsskrittet

%15 = 150*0,1 ==> simulerer i 15 sekund

for i=2:151,
    v(i) = v(i-1) + h*(u/m - k/m*v(i-1));
end

%eksakt løsning

t = 0:h:15;

veks = exp((-(k/m)*t))*(v0-(u/k))+(u/k);

%plotting
plot(t,v,'-',t,veks);
legend('Euler','Eksakt')



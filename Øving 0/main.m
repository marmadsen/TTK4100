mu = 5;
x1_0 = 4;
x2_0 = 10;
tsim = 1000;

sim test2;

%time = simout.time;
x1 = x1.data;
x2 = x2.data;


figure(1); clf(1);
plot(x1,x2); grid on;
xlabel('x1');
ylabel('x2');

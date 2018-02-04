
ro = 1;
A_1 = 5;
A_2 = 5;
%k_1 = 1;
k_2 = 5;
k_3 = 2;
%g = 9.81;
%m_1 = ro*A_1*h_1;
%m_2 = ro*A_2*h_2;

w_1 = 7;
%w_2 = k_2*(h_1-h_2);
%w_3 = k_3*h_2;

%h_1_dot = (1/(ro*A_1))*(w_1-w_2);
%h_2_dot = (1/(ro*A_2))*(w_2-w_3);

sim to_tank_system_2;



%x1 = x1.data;
%x2 = x2.data;

%Plotter resultatet fra simuleringen

%figure(1); clf(1);
%plot(x1, x2); grid on;
%xlabel('x1');
%ylabel('x2');


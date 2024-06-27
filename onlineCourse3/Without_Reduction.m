% Initialize parameters
n = 2;  % Number of neurons
dt = 0.01;  % Time step
total_time = 12.0;
num_steps = floor(total_time / dt);

% Initialize system parameters
a = [5.34, 2.64];  % Real decay rates
b = [17.5, 19.2];
x1 = 0.2;
lambda = 0.3;

% Initialize quaternion matrices
c = [quaternion(0.36, -0.34, -0.48, 0.79), quaternion(0.81, 0.50, -0.23, -0.92); ...
     quaternion(-0.26, 0.68, 0.33, 0.82), quaternion(0.52, 0.55, 0.21, 0.16)];
d = [quaternion(0.51, 0.41, -0.66, -0.94), quaternion(-0.62, 0.53, -0.44, 0.99); ...
     quaternion(-0.63, -0.11, -0.32, 0.29), quaternion(0.22, -0.45, 0.51, 0.06)];
w = [quaternion(0.31, -0.41, 0.16, 0.38), quaternion(0.22, 0.39, -1.05, 0.25); ...
     quaternion(0.2, -0.64, 0.47, 0.59), quaternion(0.3, -0.39, 0.24, 0.78)];

% Initial conditions for state vectors and derivatives
e = zeros(n, num_steps+1, 'quaternion');
e_dot = zeros(n, num_steps+1, 'quaternion');
tilde_e = zeros(n, num_steps+1, 'quaternion');
tilde_e_dot = zeros(n, num_steps+1, 'quaternion');

% Set initial conditions
e(1, 1) = quaternion(1.2, 1.6, 1.1, 1.7);
e(2, 1) = quaternion(0.9, 1.2, 1.3, 1.1);
tilde_e(1, 1) = quaternion(-1.3, -0.9, -1.2, -0.7);
tilde_e(2, 1) = quaternion(-1.7, -1.1, -1.9, -0.3);

e_dot(1, 1) = quaternion(-0.1, -0.1, -0.1, -0.7);
e_dot(2, 1) = quaternion(0.1, -0.1, -0.3, -0.1);
tilde_e_dot(1, 1) = quaternion(0.2, 0.6, 0.1, 0.6);
tilde_e_dot(2, 1) = quaternion(0.3, 0.2, 0.3, 0.1);

% Define the activation functions
tanh_quaternion = @(q) quaternion(tanh(real(q)), tanh(imag(q)), tanh(jmag(q)), tanh(kmag(q)));
activation = @(q) quaternion((1-exp(-real(q)))/(1+exp(-real(q))), ...
    1/(1+exp(-imag(q))), 1/(1+exp(-jmag(q))), 1/(1+exp(-kmag(q))));

f = tanh_quaternion;
g = tanh_quaternion;
h = tanh_quaternion;

% Main simulation loop using Euler method
for i = 1:num_steps
    t = (i-1) * dt;  % Current time step
    delay_time = t - 0.5 * (cos(t))^2;
    delay_step = max(1, round(delay_time / dt));  % Index offset for delay

    % Initialize derivative terms
    e_ddot = -a' .* e_dot(:, i) - b' .* e(:, i);
    tilde_e_ddot = -a' .* tilde_e_dot(:, i) - b' .* tilde_e(:, i);

    % External forcing functions
    r = quaternion([3.2*sin(t), -3.5*cos(t), 3*sin(t), -3.4*cos(t); ...
                    -3.4*sin(t), 3*cos(t), -3.3*sin(t), 3.6*cos(t)]);
    
    for j = 1:n
        % Calculate sums
        sum_cij_fj = sum(c(j, :) .* f(e(:, i)));
        sum_dij_gj = sum(d(j, :) .* g(e(:, delay_step)));
        sum_wij_hj = sum(w(j, :) .* h(tilde_e(:, i)));

        % Update the acceleration values
        e_ddot(j) = e_ddot(j) + sum_cij_fj + sum_dij_gj + x1*sum_wij_hj + r(j);
        tilde_e_ddot(j) = tilde_e_ddot(j) + sum_cij_fj + sum_dij_gj + x1*sum_wij_hj + r(j);
    end
    
    % Update state derivatives
    e_dot(:, i+1) = e_dot(:, i) + e_ddot * dt;
    e(:, i+1) = e(:, i) + e_dot(:, i) * dt;
    tilde_e_dot(:, i+1) = tilde_e_dot(:, i) + tilde_e_ddot * dt;
    tilde_e(:, i+1) = tilde_e(:, i) + tilde_e_dot(:, i) * dt;
end

% Plotting results
t = linspace(0, total_time, num_steps+1);
components = {'Real', 'Imag', 'Jmag', 'Kmag'};
figure;
for i = 1:4
    subplot(4, 1, i);
    plot(t, real(e(1, :)), 'DisplayName', ['e_1 ', components{i}]);
    hold on;
    plot(t, real(tilde_e(1, :)), 'DisplayName', ['tilde_e_1 ', components{i}]);
    legend();
    grid on;
    xlabel('Time');
    ylabel('Value');
    title(['Component ', components{i}, ' of e_1 and tilde_e_1']);
end

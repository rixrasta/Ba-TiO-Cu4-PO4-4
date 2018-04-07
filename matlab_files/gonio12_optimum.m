function S = gonio12_optimum%(a0,b0,g0)
    %%This code runs the main functions to be used in the cluster
        %Arguments: a, b, g - euler angles or ranges of angles
                    %rot - 'a', 'b', 'c', 'd'
        %Return: [S a b g] or a list of these values
    %if rot == 'd'  rot = 'ab', end
    'hello'
    tic();
    a0=0:-1:-2;b0=10:-1:9;g0=27:-1:26;
    S = iterate_over_rotations(a0,b0,g0);
    save my_data.out S
    %S = diff(calculations(a, b, g, B1), rot);
    toc()
end
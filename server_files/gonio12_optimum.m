function S = gonio12_optimum(as, ae, bs, be, gs, ge)
    %%This code runs the main functions to be used in the cluster
        %Arguments: a, b, g - euler angles or ranges of angles
                    %rot - 'a', 'b', 'c', 'd'
        %Return: [S a b g] or a list of these values
    %if rot == 'd'  rot = 'ab', end
    tic();
    a0=as:-1:ae;b0=bs:-1:be;g0=gs:-1:ge;
    S = iterate_over_rotations(a0,b0,g0);
    ['BTCP_toplist_a=' num2str(as) '-' num2str(ae) '_b=' num2str(bs) '-' num2str(be) '_g=' num2str(gs) '-' num2str(ge) '.out']
    %save filename S
    %S = diff(calculations(a, b, g, B1), rot);
    elapsed = toc()/60;
    printf("Elapsed time: %.4f minutes", elapsed);
end

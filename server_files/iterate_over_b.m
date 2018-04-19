function SNX=iterate_over_b(rot, a1, a2, b1, b2, g1, g2)%(a00,b00,g00)
    %%gives the toplist of errors on all angles
    %tic();
    %B1a = poore(0,90,0);
    %B1b = poore(0,90,90);
    %B1c = poore(0,0,0);
    %B1ab = poore(0,90,46);
    rot
    if rot == 'a'
        a0=0;b0=90;g0=0;
    elseif rot == 'b'
        a0=0;b0=90;g0=90;
    elseif rot == 'c'
        a0=0;b0=0;g0=0;
    elseif rot == 'ab'
        a0=0;b0=90;g0=46;
    end
    %len_a=length(a00); len_b=length(b00);len_g=length(g00);
    SNX = [[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];
            [-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];
            [-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];
            [-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];
            [-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1]];
    angles = [[26 48 30]; [33 48 149]; [16 45 -33]; [-4 46 -148]; [4 134 32]; [13 135 147]; [-37 131 -33]; [21 133 -151]];
    Sb = zeros(1,8);
    %for r = 1:8
    %{
        SNP = [[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];
            [-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];
            [-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];
            [-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];
            [-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1]];
    %}
    tic();
        for a=a0+a1:-1:a0+a2%len_a
                %tic();
            for b=b0+b1:-1:b0+b2%len_b
                for g=g0+g1:-1:g0+g2%len_g
                    B1 = poore(a,b,g);
                    %Sa=difff(calculations(a00(a),b00(b),g00(g),B1a),'a');
                    for r=1:8
                    Sb(r)=difff(calculations(angles(r,1),angles(r,2),angles(r,3),B1),rot);
                    %Sc=difff(calculations(a00(a),b00(b),g00(g),B1c),'c');
                    %Sab=difff(calculations(a00(a),b00(b),g00(g),B1ab),'ab');
                    %SNX=toplist([mean([Sa Sb Sc Sab]),a00(a),b00(b),g00(g)],SNX);
                    end
                    SNX = toplist([mean(Sb),a,b,g],SNX);
                    %SNP = toplist([mean(Sb),angles(r,1),angles(r,2),angles(r,3)],SNP);
                    Sb = zeros(1,8);
                end
                %printf('Elapsed time: %.4f minutes', toc());
            end
            %toc()
        end
        toc();
        %SNX = [SNX; SNP];
        %[~,i] = min(abs(SNX(:,1)));
        %SN=SNX(i,:);
        %SNX(1,:) = SNP(1,:)
        %fit_rotations_b(SNX, 'b', false, 'test3')
    %end
end

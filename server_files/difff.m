function S = difff(F, rot)
%%Returns the difference of the provided results F from the lines.
    %Arguments:
        %F - lis of y values.
        %rot - states which rotation 'a', 'b', 'c', 'ab'
    %Return: normalized error S.
    
    x=(-12:372);
    n=length(x);
    if rot == 'a'
        y1=0.1658+0.0229*cos(2*pi*(x-34)/180);%+M; %eksperimenditulemused
        y2=0.1658+0.0229*cos(2*pi*(x+61)/180);%+M;
        Diff =abs(F(1,:) - y1(1,:) );
        S1 = (1/n)*sum(Diff);
        Diff =abs(F(1,:) - y2(1,:) );
        S2 = (1/n)*sum(Diff);
        S=min(S1,S2);
    elseif rot == 'b'
        Y1 =(0.1766+0.0111*cos(2*pi*(x-39)/180));%+M*(3*power(cos(x-90),2)-1);
        Y2 =(0.171+0.01716*cos(2*pi*(x-39)/180));%+M*(3*power(cos(x-90),2)-1);
        Y3 =(0.176+0.01173*cos(2*pi*(x+37)/180));%+M*(3*power(cos(x-90),2)-1);
        Y4=(0.1716+0.01600*cos(2*pi*(x+33)/180));%+M*(3*power(cos(x-90),2)-1);
        Diff =abs(F(1,:) - Y1(1,:) );
        S1 = (1/n)*sum(Diff);
        Diff =abs(F(1,:) - Y2(1,:) );
        S2 = (1/n)*sum(Diff);
        Diff =abs(F(1,:) - Y3(1,:) );
        S33 = (1/n)*sum(Diff);
        Diff =abs(F(1,:) - Y4(1,:) );
        S4 = (1/n)*sum(Diff);
        S=min([S1,S2,S33,S4]);
    elseif rot == 'c'
        y1=(0.1753+0.0136*cos(pi*(x-58)/90));%+M*(3*power(cos(x-90),2)-1); %eksperimenditulemused
        y2=(0.1753+0.0138*cos(pi*(x+50)/90));%+M*(3*power(cos(x-90),2)-1);
        Diff =abs(F(1,:) - y1(1,:) );
        S1 = (1/n)*sum(Diff);
        Diff =abs(F(1,:) - y2(1,:) );
        S2 = (1/n)*sum(Diff);
        S=min(S1,S2);
    elseif rot == 'ab'
        Y1 =(0.163+0.032700*cos(2*pi*(x-42)/180));%+M*(3*power(cos(x-90),2)-1);
        Y2 =(0.163+0.032720*cos(2*pi*(x+44)/180));%+M*(3*power(cos(x-90),2)-1);
        Y3 =(0.1766+0.01111*cos(2*pi*(x+90)/180));%+M*(3*power(cos(x-90),2)-1);
        Diff =abs(F(1,:) - Y1(1,:) );
        S1 = (1/n)*sum(Diff);
        Diff =abs(F(1,:) - Y2(1,:) );
        S2 = (1/n)*sum(Diff);
        Diff =abs(F(1,:) - Y3(1,:) );
        SS3 = (1/n)*sum(Diff);
        S=min([S1,S2,SS3]);
    end
end

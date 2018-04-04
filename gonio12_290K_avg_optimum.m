%tegelikult on tegemis rotb pööramisega!!!!!
function gonio12_290K_avg_optimum
%% sisendid_290K

%Larmori sagedus
w0=80.986e6;  %31P jaoks 600MHz väljas [Hz]
%nihke tensori peaväärtused PAS-s
Szz=1.952e-3;
Syy=1.832e-3;
Sxx=1.298e-3;
%Euleri nurgad b1,b2,b3, (kraadid) kristalli peatelgede pööramiseks goniomeetri teljestikku
b1=0; 
b2=90;   
b3=90;
%Euleri nurgad c1,c2,c3, (kraadid) goniomeetri peatelgede pööramiseks labori teljestikku
c3=0;
c2=90;
x=(-12:372);

n=length(x);

Shift=[1+Sxx 0 0;0 1+Syy 0; 0 0 1+Szz];     %nihke tensor PAS-s
%M=0.02;
%susc=0.019023290860303; %emu
%N=3*cos(theta)-1;
%Demagn=N*susc;
%Shift=Shift+Demagn;
i=sqrt(-1);
%5/2 tuuma spinni operaatorid
Ix=[0 1; 1 0]/2;
Iy=[0 1; -1 0]/(2*i);
Iz=[1 0; 0 -1]/2;
%mõõteoperaator:
Ip=2*Ix;

%pir=pi/180; %pir teeb kraadid radiaanideks
B1=0;%B1=poore(b1,b2,b3);
B1a = poore(0,90,0);
B1b = poore(0,90,90);
B1c = poore(0,0,0);
B1ab = poore(0,90,46);
F=zeros(1,n);
v=10;
%% euler angles
        rot_a_euler_angles = [[-3,53,146];[-37,42,-11];
                              [3,53,34];[37,42,-169];
                              [-3,127,-146];[-37,138,11];
                              [3,127,-34];[37,138,169]];
        rot_b_euler_angles = [[8, 41, 23];[-8, 41, 157];
                              [0, 36,-21];[ 0, 36,-159];
                              [0,144, 21];[ 0,144, 159];
                              [8,139,-23];[-8,139,-157];
                              [1, 34, 20];[-1, 34, 160];
                              [-3, 43,-23];[3, 43,-157];
                              [-3,137, 23];[3,137, 157];
                              [1,146,-20];[-1,146,-160]];
        rot_c_euler_angles = [[-31,59,19];[31,121,19];
                              [-31,59,-161];[31,121,-161];
                              [31,59,-27];[-31,121,-27];
                              [31,59,153];[-31,121,153]];
       rot_ab_euler_angles = [[16,33,7];[-16,33,173];
                              [2,2,-86];[2,178,86];
                              [-6,88,-90];[-6,92,90];
                              [16,147,-7];[-16,147,-173]];
%% functions

function S = diff(F, rot)
%%Returns the difference of the provided results F from the lines.
    %Arguments:
        %F - lis of y values.
        %rot - states which rotation 'a', 'b', 'c', 'ab'
    %Return: normalized error S.
    
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

function F = calculations(a1,a2,a3,B1)
    %%Finds a list of intentsities corresponding to the provided angles
        %Arguments: a1,a2,a3 - euler angles; B1 - rotation matrix
        %Return: List of values. 
    A1=poore(a1,a2,a3);%a1k(m),a2k(m),a3k(m));
    x=(-12:372);
    %A1i=inv(A1);

    %nivoode vahe
    f12=zeros(1,n);
    %intensiivsus
    I12=f12;

    freq1=f12;
    g12=zeros(n);
    for k=1:n
        c1=x(k);
        C1=poore(c1,c2,c3);
        %C1i=inv(C1);
        T1=C1*B1*A1*Shift/A1/B1/C1;
        freq1(k)=T1(3,3);
        Hz1=w0*(T1(3,1)*Ix + T1(3,2)*Iy + T1(3,3)*Iz);

        [X1,E1]=eig(Hz1); %X on maatriks omavektoritest ,E on omavaartused
        E=real(diag(E1));
        U=X1\Ip*X1;
        U2=abs(U) .^2;

        %sagedus
        g12(k)=E(2)-E(1);
        f12(k)=(g12(k)-w0)/w0*1e2;

        %intensiivsus
        I12(k)=U2(1,2);
    end
    F=zeros(1,n);
    F(1,:)=f12; %F(1,:)
end

function toplist=toplist(the_value, toplist)
%%This compares a new elemnt and adds it to the list if it suits.
    %The elemnts in toplist are in the form [S,a,b,g]
    %Arguments:
        %The_value - the value that is being compared
        %Toplist - the list that it is being inserted and compared to
    %Return: toplist with or without the the_value
    %toplist
    %the_value
    S_toplen=length(toplist);
    iszeero=true;
    if any(-1 == toplist(:,1)) == 0
        iszeero = false;
    end    
    if iszeero == false
        [m,i] = max(toplist(:,1));
        if m > the_value(1)
            toplist(i,:)=[the_value(1), the_value(2), the_value(3), the_value(4)];
        end
    else
        for i=1:S_toplen
            if toplist(i,1) == -1
                toplist(i,:)=[the_value(1), the_value(2), the_value(3), the_value(4)];
                break
            end
        end 
    end
    if any(toplist(:,1)==-1)
        %'yes'
        I=find(toplist(:,1)==-1);
        %I
        I=I(1)-1;
        %toplist(1:I,:)
        toplist(1:I,:)=sortrows(toplist(1:I,:),1);
    else
    toplist=sortrows(toplist,1);
    end
end

function ss=display_toplist(toplist, displ, list)
%%presents and displays the top value, if disp=true;
    %Arguments:
        %toplist - the list of best errors in the form [S,a,b,g]
        %displ - if true then prints out the results
        %list - if true return [S,a,b,g], if false S.
    %Return: S or [S,a,b,g].
    %NB! Actually all of this is only for the case of two sets of angles
    %with the same S. At the momnt a very small part is actually needed.
    toplist1=toplist;
    toplist=zeros(length(find(toplist1(:,1) ~= -1)),4); %preallocating
    m=1;
    for k=1:length(toplist1(:,1)) %cuts out -1 values
        if toplist1(k,1) ~=-1
            toplist(m,:) = toplist1(k,:);
            m=m+1;
        end
    end
    toplist=sortrows(toplist,1);
    [m,i] = min(toplist(:,1));
    S_min=toplist(i,:);
    minIndex = find(toplist(:,1) == S_min(1)); %same value S angles
    S_min=zeros(length(minIndex),4);%preallocation
    nn=1;
    for j = minIndex(1) % adds same value angles
        if nn == 2 % ei tööta hetkel
            break
        end
        try
            S_min(nn,:)=toplist(j,:);
        catch ME
            switch ME.identifier
                case 'MATLAB:subsassigndimmismatch'
                    warning(['Hei siin Riho. Sama viga esines toplistis kaks' ...
                    ' korda. Esitan need nurgad ja siis jätan alles vaid esimese'])
                    toplist(j,:)
                    warning('hoiatuse lõpp')
                    toplist=toplist(1,:);
                    S_min=S_min(1,:);
                    S_min(nn,:)=toplist(j,:);
                otherwise
                    rethrow(ME)
            end
        end
        nn=nn+1;
    end
    if list == true
        ss=S_min;
    else
        ss=S_min(1);
    end
    if displ==true
        toplist
        disp('The best values are:')
        disp(S_min)
    end
end

function fit_rotations(figures, rots, b123)
%%plots a figure how the lines fit the experimential data
    %Arguments: figures - a list of figure datas in the form [S, a, b, g].
    %Retrun: none. displays plot and saves .fig file.
    %f1=figure;f2=figure;f3=figure;f4=figure;
    figures
    if strcmp(rots,'all')
        rots = ['a','b','c','d'];
    end
    len_figs=length(figures(:,1));
    sb=figures(1);
    F=zeros(len_figs,385);%Fb=zeros(len_figs,385);Fc=zeros(len_figs,385);Fab=zeros(len_figs,385);
    legends={};%v=0;%legendsb={};legendsc={};legendsab={};n=0;
    for rot = rots
        
        if rot == 'a'
            B1 = B1a;
        elseif rot == 'b'
            B1 = B1b;
        elseif rot == 'c'
            B1 = B1c;
        elseif rot == 'd'
            rot = 'ab';
            B1 = B1ab;
        end
        v=v+1;
        figure(v);
        hold on
        for j=1:len_figs
            if ~(b123 == true && j == len_figs)
                F1=calculations(figures(j,2),figures(j,3),figures(j,4),B1);
                F(j,:)=F1(1,:);
                plot(x,F(j,:));legends{end+1}=[ '[' num2str(diff(F1,rot)) ', ' num2str(figures(j,2)) ', ' num2str(figures(j,3)) ', ' num2str(figures(j,4)) ']'];
        
            else
                plot(x,zeros(length(x),1));
                legends{end+1}=[ '[' num2str(figures(j,1)) ', ' num2str(figures(j,2)) ', ' num2str(figures(j,3)) ', ' num2str(figures(j,4)) ']'];
            end
        end

        if rot == 'a'
            legend(legends)
            legend('Location','southwest')
            x = linspace(0,120*pi,25);
            y1=0.1658+0.0229*cos(2*pi*(x-34)/180);%+M; %esituseks
            y2=0.1658+0.0229*cos(2*pi*(x+61)/180);%+M;
            plot(x,y1,'b*',x,y2,'r*')
            axis([-12 372 0.12 0.22]);
            grid on
            title('rot//a 290K','fontsize',15)
        elseif rot == 'b'
            legend(legends)
            legend('Location','southwest')
            x = linspace(0,120*pi,25);
            y1 =(0.1766+0.0111*cos(2*pi*(x-39)/180));%+M*(3*power(cos(x-90),2)-1);
            y2 =(0.171+0.01716*cos(2*pi*(x-39)/180));%+M*(3*power(cos(x-90),2)-1);
            y3 =(0.176+0.01173*cos(2*pi*(x+37)/180));%+M*(3*power(cos(x-90),2)-1);
            y4=(0.1716+0.016*cos(2*pi*(x+33)/180));%+M*(3*power(cos(x-90),2)-1);
            plot(x,y1,'b*',x,y2,'c*',x,y3,'r*',x,y4,'m*')
            axis([-12 372 0.12 0.22]);
            grid on
            title('rot//b 290K','fontsize',15)
        elseif rot == 'c'
            legend(legends)
            legend('Location','southwest')
            x = linspace(0,120*pi,25);
            y1=(0.1753+0.0136*cos(pi*(x-58)/90));%+M*(3*power(cos(x-90),2)-1); %esituseks
            y2=(0.1753+0.0138*cos(pi*(x+50)/90));%+M*(3*power(cos(x-90),2)-1);
            plot(x,y1,'b*',x,y2,'r*')
            axis([-12 372 0.1 0.3]);
            grid on
            title('rot//c 290K','fontsize',15)
        elseif rot == 'ab'
            legend(legends)
            legend('Location','southwest')
            x = linspace(0,120*pi,25);
            y1 =(0.1630+0.03270*cos(2*pi*(x-42)/180));%+M*(3*power(cos(x-90),2)-1);
            y2 =(0.1630+0.03272*cos(2*pi*(x+44)/180));%+M*(3*power(cos(x-90),2)-1);
            y3 =(0.1766+0.01111*cos(2*pi*(x+90)/180));%+M*(3*power(cos(x-90),2)-1);
            plot(x,y1,'b*',x,y2,'m*',x,y3,'r*')
            axis([-12 372 0.1 0.2]);
            grid on
            title('rot//ab 290K','fontsize',15)
        end
        hold off
    filename=['rot_avg_S=' num2str(sb) '_' num2str(v) '_fit'];
    no=1;
    len_filename=length(filename);
    while exist(filename) == 2
        filename = filename(1:len_filename);
        no = no + 1;
        filename = [filename '_no_' num2str(no)];
    end
    hgsave(filename)
    saveas(gcf, [filename '.png'])
    end
end

function Sb_toplist=iterate_over_b(berror,B1)
%%Iterates over a set of b values
    %Return: list of b_angles with error in the form [S,ba,b2,b3]
count=0;
%iszeero=true;

if B1 == B1a
    rot = 'a';
    b01=0;b02=90;b03=0;
elseif B1 == B1b
    rot = 'b';
    b01=0;b02=90;b03=90;
elseif B1 == B1c
    rot = 'c';
    b01=0;b02=0;b03=0;
elseif B1 == B1ab
    rot = 'ab';
    b01=0;b02=90;b03=46;
end
Sb=0;
Sb_toplist=[[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];
            [-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];
            [-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];
            [-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];
            [-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1]];
for b1=b01+berror:-1:b01-berror
    for b2=b02+berror:-1:b02-berror
        tic
        for b3=b03+berror:-1:b03-berror
            count=count+1;
            
            for h=[0]
                angles=[b1 b2 b3]
                if rot == 'a'
                    B1a=poore(b1,b2,b3);
                elseif rot == 'b'
                    B1b=poore(b1,b2,b3);
                elseif rot == 'c'
                    B1c=poore(b1,b2,b3);
                elseif rot == 'ab'
                    B1ab=poore(b1,b2,b3);
                end
                %Sb=iterate_over_angles_2(a,b,g,rot,B1,[0 0 0]); %error average on all lines
                Sb=findss(rot,false);
                Sb=Sb(1);
            end
            Sb_toplist=toplist([Sb angles], Sb_toplist); % adds to toplist
            
        end
        toc
        diary off
        diary on
        Sb(1,:)
        findss(rot, true);
    end
    angles
    findss(rot,true);
    Sb=display_toplist(Sb_toplist, true, false); %displays printout.
    disp([num2str(toc/60) ' minutes'])
    %end
end
['hello']
Sb_toplist=sortrows(Sb_toplist,1); %for cutting out -1
[m,i] = min(Sb_toplist(:,1));
while m == -1 %cuts out -1 values
    Sb_toplist(i,:)=[];
    [m,i] = min(Sb_toplist(:,1));
end
b1=Sb_toplist(i,2);
b2=Sb_toplist(i,3);
b3=Sb_toplist(i,4);
B1=poore(b1,b2,b3); %it is used in iteration functions later on.
'tulemus'
findss(rot,'pic');
end
%% käivitus
diary('rotb.txt')
format shorteng
tic

%iterate_over_b;
%M=0.01;
% for rot=['a' 'b' 'c']
%     if rot == 'a'
%     B1 = B1a;
% elseif rot == 'b'
%     B1 = B1b;
% elseif rot == 'c'
%     B1 = B1c;
% elseif rot == 'ab'
%     B1 = B1ab;
%     end
% toc
% a = -30:-1:-40;
% b = 60:-1:50;
% g = 60:-1:30;
% a=2;b=52;g=35;
%iterate_over_b(1,B1c)

BN=iterate_over_rotations(5:-1:0,36:-1:34,26:-1:23)

fit_rotations(BN,'all',false)
%fit_rotations(iteration(3:-1:1,36:-1:34,20:-1:18, 'a', true), 'a', false)
% B1
%B1=poore(-3,88,1);
% a = a+15:-1:a-15;
% b = b+15:-1:b-15;
% g = g+15:-1:g-15;
%a=2;b=52;g=35;
%Sxx=1.298e-3;Syy=1.832e-3;Szz=1.9520e-3;
%Shift=[1+Sxx 0 0;0 1+Syy 0; 0 0 1+Szz];
%iterate_over_angles(a,b,g,'a',B1a)
%diff(calculations(3,53,34,B1a),'a')
%iterate_over_shift(a,b,g,'a',B1a,1e-3)
%SBX=iterate_over_shift(3,53,34,'a',B1a)
% Shift;
% rot='a';
% SBX=iterate_over_angles_2(10,51,32,rot,B1,[0 0 0])
% toc
% [b1 b2 b3]
% fit_rotations(findss(rot + 'd'),rot,false)
%end
%% main functions
function SBB=iterate_over_angles_2(az0,bz0,gz0,rot,B1,rec)
    step=1;
    if rec == [az0,bz0,gz0]
        %'finish'
        SBB=iterate_over_angles(az0,bz0,gz0,rot,B1);
    else
        %'current'
        %[az0+step,az0,az0-step;bz0+step,bz0,bz0-step;gz0+step,gz0,gz0-step]
        SBX=iterate_over_angles(az0+step:-1:az0-step,bz0+step:-1:bz0-step,gz0+step:-1:gz0-step,rot,B1);
        %answer=[SBX(2),SBX(3),SBX(4)]
        SBB=iterate_over_angles_2(SBX(2),SBX(3),SBX(4),rot,B1,[az0 bz0 gz0]);
    end
    %'new angles';
    a=az0; b=bz0; g=gz0;
end
function SBX=iterate_over_angles(a0,b0,g0,rot,B1)
    SBX = [[0.9,a0(1),b0(1),g0(1)];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];
           [-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];
           [-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];
           [-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];
           [-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1]];
    len_a=length(a0); len_b=length(b0);len_g=length(g0);bz=1;gz=1;
    for az=1:len_a
%         best=SBX(1,:)
%         SZ=iterate_over_shift(SBX(2), SBX(3), SBX(4), rot, B1);
%         Shift
%         SBX
        for bz=1:len_b
            for gz=1:len_g
                %SBX=toplist(iterate_over_rotations(a0(az),b0(bz),g0(gz)),SBX)
                %SBX
                %[a0(az),b0(bz),g0(gz)]
                SBX=toplist([diff(calculations(a0(az),b0(bz),g0(gz),B1),rot) a0(az) b0(bz) g0(gz)],SBX);
                
            end
        end
            %[a0(az) b0(bz) g0(gz)]
            %SBX
    end
    if any(SBX(:,1)==-1)
        i=find(SBX(:,1)==-1);
        SBX=SBX(1:i(1)-1,1:4);
    end
    %SBX
    SBX=SBX(1,:);
end
function SAZ=iterate_over_shift(ar,br,gr,rot,B1,step)
oxo=0:step:step*10;oyo=0:step:step*10;ozo=0:step:step*10;
%[diff(calculations(ar,br,gr,B1),rot) Sxx Syy Szz]
Szz=Szz-5*step;
Syy=Syy-5*step;
Sxx=Sxx-5*step;
SAZ = [[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];
       [-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];
       [-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];
       [-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];
       [-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1]];
for ox = oxo
   for oy = oyo
      for oz = ozo
          Shift=[1+Sxx+ox 0 0;0 1+Syy+oy 0; 0 0 1+Szz+oz]+Demagn;
          SX=iterate_over_angles(ar,br,gr,rot,B1);
          %[SX Sxx+ox Syy+oy Szz+oz];
          SAZ=toplist([SX(1) Sxx+ox Syy+oy Szz+oz], SAZ);
      end
      [SX Sxx+ox Syy+oy Szz+oz]
      SX;
      SAZ
   end
end
SAZ
SZ=SAZ(1,:);
Sxx=SZ(2);Syy=SZ(3);Szz=SZ(4);
Shift=[1+Sxx 0 0;0 1+Syy 0; 0 0 1+Szz]+Demagn;
%[diff(calculations(ar,br,gr,B1),rot) Sxx Syy Szz]
end
function SN=iterate_over_rotations(a00,b00,g00)
    %%gives the toplist of errors on all angles
    len_a=length(a00); len_b=length(b00);len_g=length(g00);
    SNX = [[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];
            [-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];
            [-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];
            [-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];
            [-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1]];
    for a=1:len_a
        for b=1:len_b
            for g=1:len_g
                Sa=iteration(a00(a),b00(b),g00(g),'a',false);
                Sb=iteration(a00(a),b00(b),g00(g),'b',false);
                Sc=iteration(a00(a),b00(b),g00(g),'c',false);
                Sab=iteration(a00(a),b00(b),g00(g),'ab',false);
                SNX=toplist([max([Sa Sb Sc Sab]),a00(a),b00(b),g00(g)],SNX);
            end
            
            %b00(b)
        end
        %[max([Sa Sb Sc Sab]),a00(a),b00(b),g00(g)]
        %a00(a)
    end
    [~,i] = min(abs(SNX(:,1)));
    SN=SNX(i,:);
end
function ss=findss(rot,d)
%%calculates the error for all lines
    %% angles
    if rot == 'a'
        B1 = B1a;
        euler_angles = rot_a_euler_angles;
    elseif rot == 'b'
        B1 = B1b;
        euler_angles = rot_b_euler_angles;
    elseif rot == 'c'
        B1 = B1c;
        euler_angles = rot_c_euler_angles;
    elseif rot == 'ab'
        B1 = B1ab;
        euler_angles = rot_ab_euler_angles;
    end
    %%
    len_euler=length(euler_angles);
    S2=zeros(len_euler,1);
    S2k=zeros(len_euler+1,4);
    for k=1:len_euler
        %S2(k)=diff(calculation(euler_angles(k,1),euler_angles(k,2),euler_angles(k,3),B1),rot);
        S2k(k,:)=iterate_over_angles_2(euler_angles(k,1),euler_angles(k,2),euler_angles(k,3),rot,B1,[0 0 0]);
        if rot == 'a'
            rot_a_euler_angles(k,:)=S2k(k,2:4);
        elseif rot == 'b'
            rot_b_euler_angles(k,:)=S2k(k,2:4);
        elseif rot == 'c'
            rot_c_euler_angles(k,:)=S2k(k,2:4);
        elseif rot == 'ab'
            rot_ab_euler_angles(k,:)=S2k(k,2:4);
        end
        S2(k)=S2k(k,1);
    end
    ss=mean(S2);
    S2k(length(S2k),:)=[ss,b1,b2,b3];
    if d == true
        S2k
    elseif d == 'pic'
        S2k
        fit_rotations(S2k,rot,true)
    end
end
function ss=iteration(a000,b000,g000, rot, fittt)
%%Iterates over the angles defined on the first part and finds a toplist
    %Arguments:
        %a000,b000,g000 - renges in which to be iterated. Just calculation if
        %single valuses
        %fittt - true or false. if true then ss is a list [S,a,b,g], if false
        %then just S.
    %Return: S or [S,a,b,g]
if rot == 'a'
    B1 = B1a;
elseif rot == 'b'
    B1 = B1b;
elseif rot == 'c'
    B1 = B1c;
elseif rot == 'ab'
    B1 = B1ab;
end
S=ndgrid(a000,b000,g000);
percent=0;
S_topten = [[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];
            [-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];
            [-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];
            [-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];
            [-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1];[-1,-1,-1,-1]];
a_len=length(a000);
b_len=length(b000);
g_len=length(g000);
%for time masurement.
a_step0=(100/a_len);
time=clock;
for a = 1:a_len
    a_step=(a*100/a_len);
    for b = 1:b_len
        b_step=(b/b_len);
        step=int8(a_step+a_step0*b_step);
        if any(step == 1:100)==  1 && percent < step
            percent=step;
            time0=etime(clock,time);
            time=clock;
            %disp([num2str(step) '%, aega kulus: ' num2str(time0/60) ' min'])
        end
        for g = 1:g_len
            F = calculations(a000(a),b000(b),g000(g),B1);
            S(a,b,g) = diff(F,rot);
            S_topten=toplist([S(a,b,g),a000(a),b000(b),g000(g)], S_topten);
        end
    end    
end
if fittt == true
    ss = display_toplist(S_topten, false, true);
else
    ss = display_toplist(S_topten, false, false);
end

%this part plots and saves surface plots.
% filename='rotb';
% plots=zeros(g_len,1);
% for r=1:g_len;
%     figs(r)=figure;
%     plots(r)=g000(r);
%     mesh(S(:,:,r));
%     if length(num2str(g000(r))) == 3
%         name = ['_' num2str(g000(r))];
%     else
%         name=num2str(g000(r));
%     end
%     saveas(gcf,[filename '_' name char(0176) '.png'])
% end
% s=repmat(['%d' char(0176) ', '],1,length(plots));
% s(end)=[];
% disp(sprintf(['plots at ' char(0947) ' = (' s ')'], plots))

% savefig(figs,filename,'compact');
% close(figs);
% regmax=imregionalmin(S);
% for x=1:a_len
%     for y=1:b_len
%         for z=1:g_len
%             if regmax(x,y,z)==1
%                 S(x,y,z)
%             end
%         end
%     end
% end
end
disp(['aega kulus: ' num2str(toc/60) ' min'])
disp(['lõpetas: ' datestr(now,'yyyy.mmm.dd HH:MM')])
end
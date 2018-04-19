function F = calculations(a1,a2,a3,B1) %#codegen
    %%Finds a list of intentsities corresponding to the provided angles
        %Arguments: a1,a2,a3 - euler angles; B1 - rotation matrix
        %Return: List of values. 
        
    Sxx=1.952e-3;
    Syy=1.832e-3;
    Szz=1.298e-3;
    w0=80.986e6;  %31P jaoks 600MHz väljas [Hz]
    Shift=[1+Sxx 0 0;0 1+Syy 0; 0 0 1+Szz];     %nihke tensor PAS-s
    A1=poore(a1,a2,a3);%a1k(m),a2k(m),a3k(m));
    x=(-12:372);
    n=length(x);
    %A1i=inv(A1);
    
    %5/2 tuuma spinni operaatorid
    Ix=[0 1; 1 0]/2;
    Iy=[0 1; -1 0]/(2*i);
    Iz=[1 0; 0 -1]/2;
    %mõõteoperaator:
    Ip=2*Ix;
    
    
    %nivoode vahe
    f12=zeros(1,n);
    %intensiivsus
    I12=f12;

    freq1=f12;
    g12=zeros(n);
    c3=0;
    c2=90;
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
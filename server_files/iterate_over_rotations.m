function SN=iterate_over_rotations(a00,b00,g00)
    %%gives the toplist of errors on all angles
    B1a = poore(0,90,2);
    B1b = poore(0,90,90);
    B1c = poore(0,0,0);
    B1ab = poore(0,90,46);
    len_a=length(a00); len_b=length(b00);len_g=length(g00);
	SNX = zeros(20,4);
    for e=1:20
        SNX(e,:) = [-1,-1,-1,-1];
    end
    for a=1:len_a
        for b=1:len_b
            for g=1:len_g
                Sa=difff(calculations(a00(a),b00(b),g00(g),B1a),'a');
                %Sb=difff(calculations(a00(a),b00(b),g00(g),B1b),'b');
                Sc=difff(calculations(a00(a),b00(b),g00(g),B1c),'c');
                %Sab=difff(calculations(a00(a),b00(b),g00(g),B1ab),'ab');
                SNX=toplist([mean([Sa Sc]),a00(a),b00(b),g00(g)],SNX);
            end
        end
    end
    %[~,i] = min(abs(SNX(:,1)));
    %SN=SNX(i,:);
    SN=SNX;
end

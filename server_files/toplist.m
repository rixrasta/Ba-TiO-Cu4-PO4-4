
function toplist=toplist(the_value, toplist)
%%This compares a new elemnt and adds it to the list if it suits.
    %The elemnts in toplist are in the form [S,a,b,g]
    %Arguments:
        %The_value - the value that is being compared
        %Toplist - the list that it is being inserted and compared to
    %Return: toplist with or without the the_value
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

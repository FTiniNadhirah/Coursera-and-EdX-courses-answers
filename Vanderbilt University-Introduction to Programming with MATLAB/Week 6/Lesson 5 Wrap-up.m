function valid = valid_date(y,m,d)
if ~isscalar(y)||~isscalar(m)||~isscalar(d)
    valid=1<0
else
    if m>=1&&m<=12
        if m==1||m==3||m==5||m==7||m==8||m==10||m==12
            if d>=1&&d<=31
                valid=1>0
            else
                valid=1<0
            end
        elseif m==4||m==6||m==9||m==11
            if d>=1&&d<=30
                valid=1>0
            else
                valid=1<0
            end
        else
            if rem(y,100)==0
                if rem(y,400)==0
                    if d>=1&&d<=29
                        valid=1>0
                    else
                        valid=1<0
                    end
                else
                    if d>=1&&d<=28
                        valid=1>0
                    else
                        valid=1<0
                    end          
                end
            elseif rem(y,4)==0
                    if d>=1&&d<=29
                        valid=1>0
                    else
                        valid=1<0
                    end
            else
                    if d>=1&&d<=28
                        valid=1>0
                    else
                        valid=1<0
                    end
            end
        end
    else
        valid=1<0
    end
end
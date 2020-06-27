function too_young=under_age(age,limit)
if nargin==1
    limit=21;
end

if age<limit
    too_young=1>0
else
    too_young=1<0 
end
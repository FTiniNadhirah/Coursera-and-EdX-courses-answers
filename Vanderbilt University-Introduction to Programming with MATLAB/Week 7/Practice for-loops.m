function summa= halfsum(A)
total= 0;
for i=1 : size(A,1)
    
    for j=size(A,2) : -1:i
        total=total+A(i,j)
    end
end
    summa=total;
function s = saddle(M)   
% Create logical vector that are true for each saddle condition separately 
    minLocs = M <= min(M, [], 1);
    maxLocs = M >= max(M, [], 2);
% Find the indices where both conditions are true!
    [row, col] = find(minLocs & maxLocs);
% If the input is a row vector, row and col returned from the find
% function need to be transposed to fit the output format
    if isrow(M)
        s = [row', col'];
    else
        s = [row, col];
    end
end
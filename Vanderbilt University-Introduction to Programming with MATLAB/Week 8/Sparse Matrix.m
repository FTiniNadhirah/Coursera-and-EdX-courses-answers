function matrix = sparse2matrix(cellvec)
sizecell=numel(cellvec);
default = cellvec{1,2}*ones(cellvec{1,1}(1,:));
for i=3:sizecell
    row=cellvec{1,i}(1);
    col=cellvec{1,i}(2);
    val=cellvec{1,i}(3);
    default(row,col)=val;
end
matrix=default;
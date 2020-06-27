function distance = get_distance(city1,city2)
[num,text]=xlsread('Distances.xlsx');
row=-1;
column=-1;
rowcity=text(1,:);
columncity=text(:,1);
for i=2:numel(rowcity)
    if strcmpi(city1,rowcity(i))
        row=i;
    else
        continue;
    end
end
for i=2:numel(columncity)
    if strcmpi(city2,columncity(i))
        column=i;
    else
        continue;
    end
end
if row==-1||column==-1
    distance=-1;
else
    distance=num(row-1,column-1);
end
function charnum = char_counter(fname,ch)
fid=fopen(fname,'rt');
if fid<0
    charnum=-1;
    return;
end
oneline = fgets(fid);
str=[oneline];
while ischar(oneline)
    oneline=fgets(fid);
    str=[str oneline];
end
count = 0;
if (ischar(ch))
    for i=1:numel(str)
        if ch==str(i)
            count=count+1;
        else
            continue;
        end
    end
    charnum=count;
else
    charnum = -1;
end
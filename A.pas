var 
n,i:integer;
a:array[1..100000] of integer;
min,cur:longint;
begin
readln(n);
for i:=1 to n do read(a[i]);
cur:=0;
min:=0;
for i:=1 to n do
begin 
cur:=cur+a[i];
if min>cur then min:=cur;
end;
write(0-min);
end.
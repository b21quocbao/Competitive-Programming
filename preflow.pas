{$MODE OBJFPC}
program MaximumFlow;
const
maxN = 1000;
maxM = 100000;
maxC = 10000;
type
TEdge = record //Cấu trúc một cung
x, y: Integer; //Hai đỉnh đầu mút
c, f: Integer; //Sức chứa và luồng
end;
TQueue = record //Cấu trúc hàng đợi
items: array[0..maxN - 1] of Integer; //Danh sách vòng
front, rear, nItems: Integer;
end;
var
e: array[-maxM..maxM] of TEdge; //Mảng chứa các cung
link: array[-maxM..maxM] of Integer;
//Móc nối trong danh sách liên thuộc
head, current: array[1..maxN] of Integer;
//con trỏ tới đầu và vị trí hiện tại của danh sách liên thuộc
excess: array[1..maxN] of Integer; //mức tràn của các đỉnh
h: array[1..maxN] of Integer; //hàm độ cao
count: array[0..2 * maxN - 1] of Integer;
//count[k] = số đỉnh có độ cao k
Queue: TQueue; //Hàng đợi chứa các đỉnh tràn
n, m, s, t: Integer;
FlowValue: Integer;

procedure Enter; //Nhập dữ liệu
var
i, u, v, capacity: Integer;
begin   
    ReadLn(n, m, s, t);
    FillChar(head[1], n * SizeOf(head[1]), 0);
    for i := 1 to m do
    begin
        ReadLn(u, v, capacity);
        with e[i] do
        begin
            x := u;
            y := v;
            c := capacity;
            link[i] := head[u];
            head[u] := i;
        end;
        with e[-i] do 
        begin
            x := v;
            y := u;
            c := 0;
            link[-i] := head[v];
            head[v] := -i;
        end;
    end;
    for v := 1 to n do current[v] := head[v];
end;

procedure PushToQueue(v: Integer); //Đẩy một đỉnh v vào hàng đợi
begin
    with Queue do
    begin
        rear := (rear + 1) mod maxN;
        //Dịch chỉ số cuối hàng đợi, rear = maxN - 1 sẽ trở lại thành 0
        items[rear] := v; //Đặt v vào vị trí cuối hàng đợi
        Inc(nItems); //Tăng biến đếm số phần tử trong hàng đợi
    end;
end;

function PopFromQueue: Integer; //Lấy một đỉnh khỏi hàng đợi
begin
    with Queue do
    begin
        Result := items[front]; //Trả về phần tử ở đầu hàng đợi
        front := (front + 1) mod maxN;
        //Dịch chỉ số đầu hàng đợi, front = maxN - 1 sẽ trở lại thành 0
        Dec(nItems); //Giảm biến đếm số phần tử trong hàng đợi
    end;
end;

procedure Init; //Khởi tạo
var v, sf, i: Integer;
begin
    //Khởi tạo tiền luồng
    for i := -m to m do e[i].f := 0;
    FillChar(excess[1], n * SizeOf(excess[1]), 0);
    i := head[s];
    while i <> 0 do
    //Duyệt các cung ñi ra khỏi ñỉnh phát và ñẩy bão hòa các cung ñó, cập nhật các mức tràn excess[.]
    begin
        sf := e[i].c;
        e[i].f := sf;
        e[-i].f := -sf;
        Inc(excess[e[i].y], sf);
        Dec(excess[s], sf);
        i := link[i];
    end;
    //Khởi tạo hàm độ cao
    for v := 1 to n do h[v] := 1;
    h[s] := n;
    h[t] := 0;
    //Khởi tạo các biến đếm: count[k] là số đỉnh có độ cao k
    FillChar(count[0], (2 * n) * SizeOf(count[0]), 0);
    count[n] := 1;
    count[0] := 1;
    count[1] := n - 2;
    //Khởi tạo hàng đợi chứa các đỉnh tràn
    Queue.front := 0;
    Queue.rear := -1;
    Queue.nItems := 0; //Hàng đợi rỗng
    for v := 1 to n do //Duyệt tập đỉnh
    if (v <> s) and (v <> t) and (excess[v] > 0) then
    //v tràn213
    PushToQueue(v); //đẩy v vào hàng đợi
end;

procedure Push(i: Integer); //Phép đẩy luồng theo cung e[i]
var Delta: Integer;
begin
    with e[i] do
    if excess[x] < c - f then Delta := excess[x]
    else Delta := c - f;
    Inc(e[i].f, Delta);
    Dec(e[-i].f, Delta);
    with e[i] do
    begin
        Dec(excess[x], Delta);
        Inc(excess[y], Delta);
    end;
end;

procedure SetH(u: Integer; NewH: Integer);
//Đặt độ cao của u thành NewH, đồng bộ hóa mảng count
begin
    Dec(count[h[u]]);
    h[u] := NewH;
    Inc(count[NewH]);
end;

procedure PerformGapHeuristic(gap: Integer);
//Đẩy nhãn theo khe gap
var v: Integer;
begin
    if (0 < gap) and (gap < n) and (count[gap] = 0) then
    //gap đúng là khe thật
    for v := 1 to n do
    if (v <> s) and (gap < h[v]) and (h[v] <= n) then
    begin
        SetH(v, n + 1);
        current[v] := head[v];
    //Nâng độ cao của v cần phải cập nhật lại con trỏ current[v]
    end;
end;

procedure Lift(u: Integer); //Phép nâng đỉnh u
var minH, OldH, i: Integer;
begin
    minH := 2 * maxN;
    i := head[u];
    while i <> 0 do //Duyệt các cung đi ra khỏi u
    begin
        with e[i] do
        if (c > f) and (h[y] < minH) then
        //Gặp cung thặng dư (u, v), ghi nhận đỉnh v thấp nhát
        minH := h[y];
        i := link[i];
    end;
    OldH := h[u]; //Nhớ lại h[u] cũ
    SetH(u, minH + 1); //nâng cao đỉnh u
    PerformGapHeuristic(OldH); //Có thể tạo ra khe OldH, đẩy nhãn theo khe
end;

procedure FIFOPreflowPush; //Thuật toán FIFO Preflow-Push
var
NeedQueue: Boolean;
z: Integer;
begin
    while Queue.nItems > 0 do //Chừng nào hàng đợi vẫn còn đỉnh tràn
    begin
        z := PopFromQueue; //Lấy một đỉnh tràn x khỏi hàng đợi
        while current[z] <> 0 do //Xét một cung đi ra khỏi x
        begin
            with e[current[z]] do
            begin
                if (c > f) and (h[x] > h[y]) then
                //Nếu có thể đẩy luồng được theo cung (u, v)
                begin
                    NeedQueue := (y <> s) and (y <> t)
                    and (excess[y] = 0);    
                    Push(current[z]); //Đẩy luồng luôn
                    if NeedQueue then
                    //v đang không tràn sau phép đẩy trở thành tràn
                    PushToQueue(y); //Đẩy v vào hàng đợi
                    if excess[z] = 0 then Break;
                    //x hết tràn thì chuyển qua xét đỉnh khác ngay
                end;
            end;
            current[z] := link[current[z]];
            //x chưa hết tràn thì chuyển sang xét cung liên thuộc tiếp theo
        end;
        if excess[z] > 0 then //Duyệt hết danh sách liên thuộc mà x vẫn tràn
        begin
            Lift(z); //Nâng cao x
            current[z] := head[z];
            //Đặt con trỏ current[x] trỏ lại về đầu danh sách liên thuộc
            PushToQueue(z); //Đẩy lại x vào hàng đợi chờ xử lý sau
        end;
    end;
    FlowValue := excess[t];
    //Thuật toán kết thúc, giá trị luồng bằng tổng luồng đi vào đỉnh thu (= - excess[s])
end;

procedure PrintResult; //In kết quả
var i: Integer;
begin
    WriteLn('Maximum flow: ');
    for i := 1 to m do
    with e[i] do
    if f > 0 then //Chỉ cần in ra các cung có luồng > 0
    WriteLn('e[', i, '] = (', x, ', ', y, '): c
    = ', c, ', f = ', f);
    WriteLn('Value of flow: ', FlowValue);
end;

begin
    Enter; //Nhập dữ liệu
    Init; //Khởi tạo
    FIFOPreflowPush; //Thực hiện thuật toán đẩy tiền luồng
    PrintResult; //In kết quả
end.
/*Untuk File .pl*/

/*============================================================================*/
                                /* Bagian 1 */
/*============================================================================*/

/* Deklarasi Fakta */
pria(qika).
pria(panji).
pria(shelby).
pria(barok).
pria(aqua).
pria(eriq).
pria(francesco).

wanita(himatsuru).
wanita(makio).
wanita(suma).
wanita(frieren).
wanita(yennefer).
wanita(roxy).
wanita(ruby).
wanita(suzy).
wanita(aihoshino).
wanita(eve).

usia(himatsuru,105).
usia(qika, 109).
usia(makio,96).
usia(suma,86).
usia(panji,124).
usia(frieren,90).
usia(shelby,42).
usia(yennefer,61).
usia(barok,59).
usia(roxy,70).
usia(aqua,66).
usia(ruby,63).
usia(eriq,69).
usia(suzy,23).
usia(francesco,25).
usia(aihoshino,48).
usia(eve,5).

menikah(himatsuru,qika).
menikah(qika,himatsuru).
menikah(qika,suma).
menikah(suma,qika).
menikah(qika,makio).
menikah(makio,qika).
menikah(panji,frieren).
menikah(frieren,panji).
menikah(barok,roxy).
menikah(roxy,barok).
menikah(ruby,eriq).
menikah(eriq,ruby).
menikah(suzy,francesco).
menikah(francesco,suzy).

anak(shelby,himatsuru).
anak(shelby,qika).
anak(yennefer,himatsuru).
anak(yennefer,qika).
anak(barok,qika).
anak(barok,makio).
anak(aqua,panji).
anak(aqua,frieren).
anak(ruby,panji).
anak(ruby,frieren).
anak(suzy,barok).
anak(suzy,roxy).
anak(aihoshino,ruby).
anak(aihoshino,eriq).
anak(eve,suzy).
anak(eve,francesco).


/* Deklarasi Rules */
saudara(X,Y) :-
    anak(X,Z),
    anak(Y,Z),
    pria(Z), /*Asumsi tiri selalu dari bapak*/
    X \== Y.

saudaratiri(X, Y) :- 
    X \== Y,
    anak(X, Z),
    anak(Y, Z),
    menikah(Z, A),
    menikah(Z, B),
    anak(X, A),
    anak(Y, B),
    A \== B.

kakak(X, Y) :- 
    saudara(X, Y),
    usia(X, U1),
    usia(Y, U2),
    U1 > U2.

keponakan(X, Y) :- 
    anak(X, Z),
    saudara(Z, Y),
    \+saudaratiri(Z, Y).

mertua(X, Y) :- 
    anak(Z, X),
    menikah(Z, Y).

nenek(X, Y) :- 
    anak(Z, X),
    anak(Y, Z),
    wanita(X).

keturunan(X, Y) :- /*Basis*/
    anak(X, Y). 
keturunan(X, Y) :- /*Rekurens*/
    anak(A, Y),
    keturunan(X, A).

lajang(X) :-
    usia(X, _),
    \+menikah(X, _).

anakbungsu(X) :-
    saudara(X, Y),
    \+ saudaratiri(X, Y),
    \+ (usia(X, UX), usia(Y, UY), UX > UY).

anaksulung(X) :-
    saudara(X, Y),
    \+ saudaratiri(X, Y),
    \+ (usia(X, UX), usia(Y, UY), UX < UY).

yatimpiatu(X) :-
    usia(X, _),
    \+anak(X, _).

/*============================================================================*/
                                /* Bagian 2 */
/*============================================================================*/

/*=========================== 1. (6 Poin) Exponent ===========================*/
exponent(A, 0, 1).
exponent(A, B, X) :-
    B1 is B-1, 
    exponent(A, B1, X1), 
    X is X1*A.

/*============================= 2. (6 Poin) Growth ===========================*/
isPrime(2).
isPrime(X) :-
    X > 2,
    \+ hasFactor(X, 2).

hasFactor(X, Y) :-
    X mod Y =:= 0.
hasFactor(X, Y) :-
    Y * Y =< X,
    Y1 is Y + 1,
    hasFactor(X, Y1).

growth(I, G, H, 0, I).
growth(I, G, H, T, X) :-
    T1 is T-1,
    growth(I, G, H, T1, X1),
    (isPrime(T) -> X is X1+G
    ; X is X1-H).

/*======================= 3. (6 Poin) Si Imut Anak Nakal =====================*/
harvestFruits(N, Fruits, TreeNumber, FinalFruits) :-
    Fruits =< 0, !,
    FinalFruits = 0,
    write('Si Imut pulang sambil menangis :('), nl.
harvestFruits(N, Fruits, TreeNumber, FinalFruits) :-
    TreeNumber > N, !,
    FinalFruits = Fruits.
harvestFruits(N, Fruits, TreeNumber, FinalFruits) :-
    TreeNumber1 is TreeNumber+1,
    ((TreeNumber mod 3) =:= 0 -> Cek1 = 2 ; Cek1 = 0), 
    ((TreeNumber mod 4) =:= 0 -> Cek2 = -5 ; Cek2 = 0),
    ((TreeNumber mod 5) =:= 0 -> Cek3 = 3 ; Cek3 = 0),
    (isPrime(TreeNumber) -> Cek4 = -10 ; Cek4 = 0),
    NewFruits is Fruits + Cek1 + Cek2 + Cek3 + Cek4,
    harvestFruits(N, NewFruits, TreeNumber1, FinalFruits).

/*============================= 4. (6 Poin) KPK ==============================*/
fpb(A, 0, A).
fpb(A, B, X) :-
    R is A mod B,
    fpb(B, R, X).

kpk(A, B, X) :-
    fpb(A, B, FPB),
    X is (A*B)//FPB.

/*=========================== 5. (6 Poin) Factorial ==========================*/
factorial(0, 1).
factorial(N, X) :-
    N1 is N-1,
    factorial(N1, X1),
    X is N*X1.

/*========================= 6. (6 Poin) Make Pattern =========================*/
minManual(X, Y, Min) :-
    (X > Y -> Min = Y ; Min = X).

makeRow(CurrentRow, CurrentCol, N) :-
    CurrentCol =< N,
    Y is N - CurrentRow + 1, X is N - CurrentCol + 1,
    minManual(X, Y, Temp), minManual(CurrentRow, CurrentCol, Temp1),
    minManual(Temp, Temp1, Elmt),
    write(Elmt), write(' '),
    CurrentCol1 is CurrentCol + 1, makeRow(CurrentRow, CurrentCol1, N).
makeRow(_, _, _).

makeRectangle(CurrentRow, N) :-
    CurrentRow =< N,
    makeRow(CurrentRow, 1, N), nl,
    CurrentRow1 is CurrentRow + 1,
    makeRectangle(CurrentRow1, N).
makeRectangle(_, _).

makePattern(N) :-
    makeRectangle(1, N).

/*============================================================================*/
                                /* Bagian 3 */
/*============================================================================*/
/*============================== 1.1. min ====================================*/
minElmt([X], X).
minElmt([Head|Tail], Min) :-
    minElmt(Tail, Min1),
    ((Head < Min1) -> Min = Head 
    ; Min = Min1).
/*
Query: minElmt([5, -8, 4, 2, -1, 12], Max).

Min = -8?

yes 
*/

/*============================== 1.2. max ====================================*/
maxElmt([X], X).
maxElmt([Head|Tail], Max) :-
    maxElmt(Tail, Max1),
    ((Head > Max1) -> Min = Head 
    ; Max = Max1).
/*
Query: maxElmt([5, -8, 4, 2, -1, 12], Max).

Max = 12?

yes 
*/

/*============================== 1.3. range ==================================*/
range(List, Range) :-
    minElmt(List, Min),
    maxElmt(List, Max),
    Range is Max - Min.

/*============================== 1.4. count ==================================*/
count([X],  1).
count([Head|Tail], Count) :-
    count(Tail, Count1),
    Count is Count1+1.

/*============================== 1.5. sum ====================================*/
sum([X],  X).
sum([Head|Tail],  Sum) :-
    sum(Tail,  Sum1),
    Sum is Sum1+Head.

/*========================= 2.a. (6 Poin) mergeSort ==========================*/
mergeSort([], List2, List2).
mergeSort(List1, [], List1).
mergeSort([Head1|Tail1], [Head2|Tail2], [Head|Tail]) :-
    (Head1 < Head2 -> Head = Head1, mergeSort(Tail1, [Head2|Tail2], Tail)
    ; Head = Head2, mergeSort([Head1|Tail1], Tail2, Tail)).

/*========================= 2.b. (6 Poin) filterArray =======================*/
isValid(X, Element1, Element2) :-
    X > Element1,
    X mod Element2 =:= 0.

filterArray([], Element1, Element2, []).
filterArray([Head|Tail], Element1, Element2, [HeadRes|TailRes]) :-
    (isValid(Head, Element1, Element2) -> HeadRes = Head, 
        filterArray(Tail, Element1, Element2, TailRes)
    ; filterArray(Tail, Element1, Element2, [HeadRes|TailRes])).

/*========================= 2.c. (6 Poin) reverse ===========================*/
reverseListWithAcm([], Acm, Acm).
reverseListWithAcm([Head|Tail], Acm, Result) :-
    reverseListWithAcm(Tail, [Head|Acm], Result).

reverseList(List, Result) :-
    reverseListWithAcm(List, [], Result).

/*========================= 2.d. (6 Poin) cekPalindrom ======================*/
getElmt([Head|Tail], 0, Head).
getElmt([Head|Tail], Idx, Elmt) :-
    Idx1 is Idx-1,
    getElmt(Tail, Idx1, Elmt).

isPalindrom(List, IdxStart, IdxEnd) :-
    IdxEnd =< IdxStart, !.
isPalindrom(List, IdxStart, IdxEnd) :- 
    getElmt(List, IdxStart, ElmtStart),
    getElmt(List, IdxEnd, ElmtEnd),
    ElmtStart == ElmtEnd,
    IdxStart1 is IdxStart+1,
    IdxEnd1 is IdxEnd-1,
    isPalindrom(List, IdxStart1, IdxEnd1).

cekPalindrom(List) :-
    count(List, Count),
    IdxEnd is Count-1,
    isPalindrom(List, 0, IdxEnd).

/*========================= 2.e. (6 Poin) rotate ============================*/
normalisasi(N, Len, Norm) :-
    (N < 0 -> Temp is N * -1, Norm is Temp mod Len 
    ; Norm is N mod Len).

splitList(List, IdxStart, IdxEnd, Acm, Result) :-
    IdxEnd < IdxStart, !,
    Result = Acm.
splitList(List, IdxStart, IdxEnd, Acm, Result) :-
    getElmt(List, IdxEnd, Elmt),
    IdxEnd1 is IdxEnd-1,
    splitList(List, IdxStart, IdxEnd1, [Elmt|Acm], Result).

rotate(List, N, Result) :-
    count(List, Len),
    normalisasi(N, Len, Norm),
    IdxStart = 0, IdxEnd is Len-Norm-1, 
    splitList(List, IdxStart, IdxEnd, [], ResultTemp),
    IdxStart1 is Len-Norm, IdxEnd1 is Len-1,
    splitList(List, IdxStart1, IdxEnd1, ResultTemp, Result).

/*========================= 2.f. (6 Poin) Mapping ===========================*/
average([], 0).
average([X], X).
average(ListNilai, Avg) :-
    count(ListNilai, N),
    sum(ListNilai, Sum),
    Avg is Sum/N.

indeksConvert(Nilai, Indeks) :-
    (Nilai >= 80 -> Indeks = 'A'
    ; Nilai >= 70 -> Indeks = 'B'
    ; Nilai >= 60 -> Indeks = 'C'
    ; Nilai >= 50 -> Indeks = 'D'
    ; Indeks = 'E').

indeksMapping(ListNilai, Acm, IdxMax, ListIndeks) :-
    IdxMax < 0, !,
    ListIndeks = Acm.
indeksMapping(ListNilai, Acm, IdxMax, ListIndeks) :-
    getElmt(ListNilai, IdxMax, Nilai),
    indeksConvert(Nilai, Indeks),
    IdxMax1 is IdxMax-1,
    indeksMapping(ListNilai, [Indeks|Acm], IdxMax1, ListIndeks).

isPass(Avg, Status) :-
    (Avg >= 80 -> Status = 'Pass'
    ; Status = 'Fail').

prosesMahasiswa(Name, Grades, Result) :-
    average(Grades, Avg),
    count(Grades, N), IdxMax is N-1,
    indeksMapping(Grades, [], IdxMax, ListIndeks),
    isPass(Avg, Status),
    Result = [Name, ListIndeks, Avg, Status].

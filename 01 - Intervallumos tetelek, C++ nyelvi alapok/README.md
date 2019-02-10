# Függvény paraméterek

A C++ lehetőséget ad arra, hogy tóbb módon adjuk át a paramétereket egy függvénynek.
Az alapértelmezett érték szerinti paraméterátadással már mindenki találkozott Programozáson, ez úgy adja át a paramétert, hogy bemásolja az értékét a paraméternek, hogy a függvény azt használja (vagyis egy új változót kap a függvény, melynek ugyanaz lesz az értéke, mint a híváskor adott változóé, literálé, stb.).
Új féle átadás a referencia szerinti paraméterátadás. A fő különbsége az érték szerintihez képest, hogy a külső hívásból kapott változóval dolgozunk.
Tehát ha a függvény módosítja a változót, akkor az eredeti változó is módosul, amivel hívtuk a függvényt.
Ezen kívül memóriakezelés szempontjából is van különbség, a referenciákból nem készül másolat, mint általában a sima paraméterekből.
Ez akkor jó, ha mondjuk valamilyen nagy méretű adatot (pl. egy vector-t) szeretnénk átadni a függvénynek, ahol a másolás költséges lehet.
Általában a függvény paraméterlistájában ilyen alakban kell megadni: <típusnév> &<változónév>.

Az átadáson kívül mást is befolyásolhatunk a paramétereinkben, nekünk a const lesz fontos. Const jelzővel ellátott változókat/paramétereket nem lehet módosítani, különben fordítási hibát kapunk (biztosíték arra, hogy nem lesz változás).
Ez azért fontos, mert egyes műveletek változtathatják a változó értékét (referenciák), mellékhatásokkal járhatnak (elég csak egy i++, inkrementálásra gondolni).
Az is előfordul, hogy a fentiek valamelyike úgy megy végbe, hogy nem számítunk rá, és a változás a program többi részének futását is befolyásolja.
Ajánlott tehát ahol csak lehet const-ot írni, általánosan programokban lévő bugok egy jó része abból következik, hogy változók nem vártan módusulnak.

## Megjegyzések.:

1. Lehet const referenciát is csinálni, ekkor egy olyan paramétert kapunk, mely nem másolódik, és nem is módosítható
2. Ha egy függvénynek referencia paramétere van, akkor a függvényhíváskor csakis olyan értéket adhatunk paraméternek, melynek van memóriacíme (általában a lényeg, hogy változók kell legyenek a paraméterek). 
Ez röviden annyit tesz, hogy csakis olyan értéket adhatunk híváskor paraméternek, mely valahol le van tárolva a memóriában, és adható neki érték.
Pl. A max_horpadas(9, 10, "input.txt"); hívás hibát dob, mert a 9 és a 10 úgynevezett számliterálok, nem változók, nincs memóriacímük, nem adhatunk nekik értéket

# Fájlkezelés
Szeretnénk, ha nem csak billentyűzetről, vagy a programba beleégetve tudnánk adatot átadni, hanem külön fájlból tudnánk beolvasni.
A C++-ban az inputstream-ek (és outputstream-ek) mögött megbújó felépítés miatt a filestream-ből való beolvasás hasonló a konzolból beolvasáshoz.
Az ifstream (és később ofstream) csatornáinkat hasonlóan kezelhetjük beolvasás és írás szempontjából mint a cin-t és a cout-ot.
Azonban fontos odafigyelni, hogy a bekérés körülményei megváltoztak, szükséges tehát extra feltételeket hozzáadni a beolvasáshoz (Mi van, ha nincs megadva, vagy nem tudjuk előre, hogy hány beolvasandó adatunk van?).

A fájl végét kell ellenőrizni (illetve egyéb formai követelményeket is lehetne még check-olni), ha vége a fájlnak, ne olvassunk többet.
A istream (inputstream) objektumoknak vannak különféle  fail(), eof(), stb. függvényeik, ezzel tudjuk ellenőrizni a stream állapotát.
A beolvasás többféle módon megvalósítható ezekkel, mi most egy fail()-al való változatot nézünk meg. A fenti állapotfüggvények logikai értékűek, és általában valamilyen állapotbit-et (flag) ellenőriznek.
Akkor igaz, hogyha valamilyen művelet hibával végződött Pl.: fájlt akarumk nyitni, de a fájl nem létezik, olvasni akarunk, de már nincs adat stb.

# Órai feladat
Legmagasabban fekvő horpadás keresése. Egy felszínen adott távolságonként mérték a tengerszint feletti magasságot.
Horpadásnak veszünk egy értéket, ha a körülötte (balra és jobbra) lévő magasságok nagyobbak ennél az értéknél.
A feltételes maximum keresés programozási tétellel oldjuk meg a feladatot.

### Egyéb olvasmány/dokumentáció a fenti témakörökről (csak annak akit érdekel)
Referencia paraméterek: https://www.learncpp.com/cpp-tutorial/73-passing-arguments-by-reference/

Const változók, paraméterek: http://duramecho.com/ComputerInformation/WhyHowCppConst.html

Az istreamek doksija: http://www.cplusplus.com/reference/istream/istream/ 
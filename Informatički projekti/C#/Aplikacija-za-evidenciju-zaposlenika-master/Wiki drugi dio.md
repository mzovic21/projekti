# 2. Specifikacija dizajna programskog proizvoda _Valval_

## 2.1. Opis slučajeva korištenja
Za razvoj softvera potrebna su razna znanja, vještine i iskustva, a često zahtjeva dobru koordinaciju i implementaciju rješenja. Kako bi se izbjegle poteškoće pri izradi softvera potrebno je ustanoviti određene standarde, odnosno zajednički jezik koji će biti razumljiv i intuitivan. U tu svrhu izrađuju se UML (_Unified Modeling Language_) dijagrami. Oni prikazuju detaljni pregled nekog procesa, sustava ili funkcija te njegovu interakciju i razmjenu poruka s okolinom. Prvi od UML dijagrama koji će biti spomenut je _Use Case Diagram_ to jest Dijagram slučajeva korištenja. Općenito gledano, on opisuje što bi sustav trebao raditi, navodi korisnike sustava, te definira korisničke zahtjeve, odnosno ono što korisnik želi da sustav radi.

[![usecase](https://user-images.githubusercontent.com/126497323/232629080-0e31c216-d80e-4583-8ef9-6a0bd67e9ca0.png)](https://user-images.githubusercontent.com/126497323/232629080-0e31c216-d80e-4583-8ef9-6a0bd67e9ca0.png)


Na priloženoj slici prikazan je Dijagram slučaja korištenja za programski proizvod _Valval_. Iz njega očitavamo da su korisnici ovog softvera vlasnica obrta i zaposlenici. Vlasnica ima veći opseg funkcionalnosti od zaposlenika. Ono što im je zajedničko je prijava u sustav, gdje se vlasnica obrta prijavljuje kao administrator, dok zaposlenici imaju ulogu korisnika u sustavu. Vrijednosti u zagradama (npr. FZ-1) predstavljaju koje zahtjeve obuhvaća određeni funkcionalnost sustava. Neke od funkcionalnosti vlasnice jesu upravljanje zaposlenicima i klijentima, što uključuje pregled podataka, dodavanje, brisanje i njihovo ažuriranje. Evidentiranje poslova u raspored jest složenija funkcionalnost jer uključuje pretraživanje slobodnih termina zaposlenika, definiranje zadataka s vremenskim razmakom, a uz sve to je prisutno i automatizacija sustava. Drugim riječima, vlasnici se pri evidentiranju poslova pružaju mnoge opcije vođenja evidencije poslova u obrtu, a automatizacija sustava osigurava zaposlenicima praćenja obaveza i zadataka na dnevnoj/tjednoj razini. Prikaz statističkih podataka omogućava praćenje osnovnih informacija u obrtu, a izradom izvještaja se ti podaci prikazuju u preglednijem i sažetom obliku. Funkcionalnosti softvera koje se pružaju zaposlenicima jesu prikazivanje jedinstvenog rasporeda koji je proširenom svojstvom vođenja evidencije trajanja usluge čišćenja. Dakle, zaposlenik može odabrati posao koji obavlja te za njega unosi vrijeme početka i završetka trajanja usluge. Automatiziranje sustava obavijesti omogućava zaposlenicima praćenje obaveza i dužnosti, koje je potrebno izvršiti, ali također sadrži i neke informativne poruke, poruke dobrodošlice i slično.


## 2.2. Specifikacija slučaja korištenja Upravljanje klijentima

### 2.2.1. Detaljna specifikacija Evidentiranje klijenata (FZ-4, FZ-5)

| **Naziv** | **Opis** |
|--|--|
| Naziv | Evidentiranje klijenata |
| Kratki opis | Softversko rješenje nudi evidenciju svih trenutnih klijenata obrta, što uključuje njihove kontakt podatke i lokaciju na kojoj se obavlja usluga. Vlasnica mora u svakom trenutku imati mogućnost pregleda svojih klijenata, kako bi mogla pratiti zakazane termine obavljanja usluge čišćenja. Za neke klijente usluge čišćenja obavljaju se uvijek na istoj lokaciji, a neki klijenti usluge koriste za više lokacija. Omogućavanje pregleda evidencije klijenata omogućuje vlasnici obrta učinkovitije upravljanje svojim klijentima. Pregled podataka o lokacijama klijenata olakšava organizaciju rasporeda poslova i učinkovito planiranje radnih aktivnosti. Prikaz svih relevantnih podataka o klijentima u jednom sučelju pomaže u smanjenju vremena i resursa potrebnih za administrativne poslove. |
| Sudionici | Vlasnica obrta |
| Okidači | Vlasnica obrta traži pristup podacima klijenata, želi dodati novog klijenta, želi obrisati postojećeg klijenta ili samo želi izmijeniti podatke o već zapisanom klijentu (na primjer dodavanje nove lokacije). |
| Preduvjet | Osoba mora biti prijavljena u sustav kao administrator, te mora imati bazu podataka o klijentima, ako želi mijenjati ili brisati postojeće klijente. Potrebno je unijeti sve podatke o klijentu kod dodavanja klijenta. U slučaju dodavanja klijenata nije potrebna baza podataka. |
| Stanje sustava nakon uspješnog izvršenja | Kreirana je poruka o uspješnom unosu podataka, ako se radi o dodavanju, promjeni ili brisanju podataka klijenata. U slučaju samo pregleda informacija, ništa ne događa. |
| Iznimke | Pri unosu, promjeni ili brisanju podataka, unesene su pogrešne vrijednosti za određeno polje u tablici. |
| Stanje sustava nakon pojave iznimke | Sustav izbacuje poruku o pogrešci te traži ponovni upis podataka od strane korisnika sustava. |
| Standardni proces | (1) Vlasnica obrta pristupa evidenciji klijenata. <br> (2) Sustav prikazuje popis klijenata. <br> (3) Vlasnica odabire opciju dodaj klijenta. <br> (4) Sustav vraća formu za unos podataka o klijentu. <br> (5) Vlasnica unosi podatke o klijentu. <br> (6) Vlasnica, nakon što unese podatke, sprema unesene promjene. <br> (7) Sustav vraća poruku o uspješnom unosu podataka. <br> (8) Sustav prikazuje ažuriranu verziju popisa klijenata i njihovih podataka. |
| Alternativni procesi | **A** <br> (1-2) Kao i standardni proces. <br> (3') Vlasnica obrta odabire klijenta čije podatke želi izmijeniti. <br> (4') Sustav prikazuje podatke o odabranom klijentu. <br> (5') Vlasnica odabire opciju izmjeni. <br> (6') Sustav vraća popunjenu formu za unos podataka o klijentu. <br> (7') Vlasnica unosi željene promjene podataka. <br> (6-8) Kao i standardni proces. <br> **B** <br> (1-2) Kao i standardni proces. <br> (3') Vlasnica obrta odabire klijenta kojeg želi izbrisati. <br> (4') Sustav prikazuje poruku upozorenja. <br> (5') Vlasnica potvrđuje opciju brisanja odabranog klijenta. <br> (7') Sustav vraća poruku o uspješnom brisanju podataka. <br> (8) Kao i standardni proces. <br> **C** <br> (1-2) Kao i standardni proces. <br> (3') Vlasnica obrta odabire klijenta čije podatke želi pregledati. <br> (4') Sustav prikazuje podatke o odabranom klijentu. <br> **D** <br> (1-4) Kao i standardni proces. <br> (5') Vlasnica unosi podatke, međutim ne ispunjava sva polja (neka polja ostaju prazna). <br> (6) Kao i standardni proces. <br> (7') Sustav vraća poruku o pogrešnom unosu podataka. <br> (6-8) Kao i standardni proces.|

### 2.2.2. Skice ekrana uključenih u Evidentiranje klijenata
[![evidencija_klijenataUC](https://user-images.githubusercontent.com/126497323/232246326-2ff9d210-76fe-441d-a422-25700d41dbcf.png)](https://user-images.githubusercontent.com/126497323/232246326-2ff9d210-76fe-441d-a422-25700d41dbcf.png) <br clear="left"/>
Skica 1: Evidencija klijenata (pregled podataka)

[![dodaj_klijentaUC](https://user-images.githubusercontent.com/126497323/232246329-af5dd125-e160-4886-85b4-8b256c1a48c8.png)](https://user-images.githubusercontent.com/126497323/232246329-af5dd125-e160-4886-85b4-8b256c1a48c8.png) <br clear="left"/>
Skica 2: Dodavanje klijenata (unos podataka)

[![izmjena_klijentaUC](https://user-images.githubusercontent.com/126497323/232246341-d65a3f3a-4151-4ab2-8430-1ad14139c2dd.png)](https://user-images.githubusercontent.com/126497323/232246341-d65a3f3a-4151-4ab2-8430-1ad14139c2dd.png) <br clear="left"/>
Skica 3: Podaci o klijentu (detaljan pregled podataka)

[![obavijest drawio](https://user-images.githubusercontent.com/126497323/232246367-cc8ba46f-6b2d-4225-bc4e-1080c28d667a.png)](https://user-images.githubusercontent.com/126497323/232246367-cc8ba46f-6b2d-4225-bc4e-1080c28d667a.png) <br clear="left"/>
Skica 4: Obavijest (informacija uspješno)

[![neisparavan_unos drawio](https://user-images.githubusercontent.com/126497323/232246460-f3ebd596-3ed8-47bc-a253-980d9b44bf59.png)](https://user-images.githubusercontent.com/126497323/232246460-f3ebd596-3ed8-47bc-a253-980d9b44bf59.png) <br clear="left"/>
Skica 5: Obavijest (informacija neuspješno)

[![obavijest_uspjesno drawio](https://user-images.githubusercontent.com/126497323/232246420-12c0f258-59a5-4d68-bec6-932e0f7bf6ef.png)](https://user-images.githubusercontent.com/126497323/232246420-12c0f258-59a5-4d68-bec6-932e0f7bf6ef.png) <br clear="left"/>
Skica 6: Upozorenje (brisanje podataka)

[![uspjesno_brisanje drawio](https://user-images.githubusercontent.com/126497323/232246441-ac3c9a6f-3f38-49c0-a3d6-eba36e43f997.png)](https://user-images.githubusercontent.com/126497323/232246441-ac3c9a6f-3f38-49c0-a3d6-eba36e43f997.png) <br clear="left"/>
Skica 7: Obavijest (informacija uspješno brisanje)


### 2.2.3. Dijagram slijeda Evidentiranje klijenata

Dijagrami slijeda su jedna od vrsta UML dijagrama, koji omogućuju modeliranje međudjelovanja različitih sudionika u sustavu s naglaskom na redoslijed razmjene poruka. Osnovna svrha im je kronološki prikazati interakciju između sudionika, gdje se sudionici mogu sastojati od osoba, strojeva, softverskih sustava i komponenti. Dijagrami slijeda mogu se koristiti za dvije razine apstrakcije, prva je analitičke razina, dok je druga razina dizajna. Ovdje će biti prikazana razina dizajna koja pruža detaljan prikaz odnosa okoline i sustava. Razina dizajna prikazuje razmjene poruka između korisnika, sustava i različitih entiteta. Osnovni elementi dijagrama slijeda jesu životna crta, poruke i objekti.

[![dijagram_slijeda1](https://user-images.githubusercontent.com/126497323/232259104-8848b9f3-f396-41d8-882a-94957ee1e123.jpeg)](https://user-images.githubusercontent.com/126497323/232259104-8848b9f3-f396-41d8-882a-94957ee1e123.jpeg)

Prikazani dijagram slijeda objedinjuje pet različitih objekata. To su korisnik sustava (vlasnica obrta), korisničko sučelje, repozitorij klijenata, forma sa podacima klijenta i sloj za pristup bazi. Vlasnica obrta je osoba koja inicijalizira zahtjeve od sustava. Ona pokreće ovaj dijagram slijeda. Korisničko sučelje je ono što vlasnica vidi i ono s čime vlasnica uspostavlja interakciju. Korisničko sučelje je ustvari vizualna slika softvera (grafičko sučelje temeljno na izrađenim skicama ekrana). Nadalje repozitorij klijenta predstavlja bazu podataka gdje su sadržani podaci klijenata. Repozitorij se nadovezuje na formu sa podacima klijenta. Forma sadrži zapisane podatke klijenata, a navedena je kao zasebna cjelina jer korisnik sustava često dolazi u interakciju sa formom (dodavanje klijenata, ažuriranje, brisanje i pregledavanje klijenata). Na kraju se nalazi objekt naziva sloj za pristup bazi. On predstavlja granicu sustava, a služi za provjeru vrijednosti unesenih podataka, koji se pamte te vraća povratnu vrijednost ostalim objektima sustava. Sloj za pristup bazi je na neki način kontrola unesenih podataka i on odobrava mijenjanje podataka, dodjeljuje posebnu identifikacijsku oznaku svakog zahtjeva i osigurava očuvanje urednosti i kompozicije baze podataka.

Dijagram slijeda, iako dosta složen, može se podijeliti u tri sekcije odnosno samostalne cjeline. Prikazuje standardni proces slučaja korištenja, kao i alternativne procese, koji su objedinjeni u jedan dijagram. Standardni proces - proces dodavanja klijenta započinje zahtjevom vlasnice obrta za pristupom evidenciji klijenta. Sustav to jest korisničko sučelje joj vraća popis klijenata, gdje ona ima mogućnost biranja različitih funkcionalnosti/zahtjeva. Vlasnica ima na odabir dodati novog klijenta, obrisati postojećeg ili pak pogledati podatke o zapisanim klijentima. Ako se odluči za opciju pregleda podataka o klijentu tada joj se otvara još jedna mogućnost, a to je unošenje promjena nad zapisanim podacima o klijentu.


### 2.2.4. Dijagram aktivnosti Evidentiranje klijenata

Dijagrami aktivnosti su vrsta UML dijagrama ponašanja koji se koriste za modeliranje koraka (aktivnosti) koji se izvode u nekoj operaciji ili procesu. Iako su najčešće povezani s razvojem softvera, oni se mogu primijeniti i u drugim domenama. Dijagrami aktivnosti se obično koriste za modeliranje poslovnih pravila, procesa, te slučajeva korištenja. U kontekstu razvoja softvera, dijagrami aktivnosti se mogu koristiti na više razina apstrakcije. Na višoj razini, oni modeliraju tok rada između više slučajeva korištenja unutar sustava, prikazujući svaki slučaj korištenja kao akciju unutar aktivnosti. Na srednjoj razini, dijagrami aktivnosti modeliraju tok rada unutar jednog određenog slučaja korištenja. Na nižoj razini, dijagrami aktivnosti modeliraju unutarnju logiku metode unutar klase. Dijagrami aktivnosti služe za vizualizaciju kako se određena funkcionalnost izvršava u određenom procesu. Omogućuju identifikaciju potencijalnih problema, a time mogu pomoći pri poboljšanju učinkovitosti sustava. Izrađeni dijagram aktivnosti spada pod srednju razinu apstrakcije (složenosti). 

[![dijagram_aktivnosti1](https://user-images.githubusercontent.com/126497323/232329462-48cf5962-b44a-4041-a9e3-db6e5fc3f64c.png)](https://user-images.githubusercontent.com/126497323/232329462-48cf5962-b44a-4041-a9e3-db6e5fc3f64c.png)

Prikazani dijagram definira interakciju između vlasnice obrta i softvera _Valval_. Početni događaj se nadovezuje na aktivnost otvaranja prikaza evidencije klijenata, koji proizlazi od zahtjeva vlasnice. Softversko rješenje dohvaća sve klijente, te skupa s njima dohvaća i njihove podatke. Softver prikazuje podatke o klijentima, koje vlasnica pregledava i donosi odluku. Odlučuje želi li odabrati neku od dodatnih mogućnosti koje softver nudi. U slučaju da ne odabire niti jednu opciju, ovdje sustav interakcija sustava i korisnika završava. U slučaju da se vlasnica odluči za izvođenje dodatne mogućnosti (dodavanje, brisanje ili izmjena klijenta), sustav izvodi odabranu promjenu te ažurira podatke klijenta. Naposljetku sustav prikazuje ažurirani popis klijenata te ovisno je li odabrana dodatna mogućnost, sustav ponavlja prethodno opisani postupak ažuriranja podataka ili u drugom slučaju, proces završava sa svojim izvođenjem.


### 2.2.5. Dijagram klasa Evidentiranje klijenata

Dijagram klasa je najčešće korišteni UML dijagram koji prikazuje objekte i klase potrebne za implementaciju funkcionalnosti softverskog sustava. Njegova je svrha prikazati dijelove sustava i odnose među njima. Dijagram se sastoji od klasifikatora, koji mogu biti klase, sučelja, tipovi podataka, paketi, objekti, enumeracije ili artefakti. Najčešće korišteni klasifikatori su klase i sučelja. U dijagramu klasa svaka je klasa predstavljena pravokutnikom koji je vodoravno podijeljen na tri dijela: gornji, srednji i donji. Gornji dio sadrži naziv klase ili klasifikatora. Srednji dio sadrži atribute koji omogućuju pohranjivanje informacija koje su zajedničke svim instancama klase. Donji dio sadrži operacije koje definiraju kako se podaci mijenjaju i stanje objekata.

[![klasa1](https://user-images.githubusercontent.com/126497323/232629189-c6a02da6-e56a-4741-ac47-5c6549c71032.png)](https://user-images.githubusercontent.com/126497323/232629189-c6a02da6-e56a-4741-ac47-5c6549c71032.png)

Dijagram klasa Evidentiranje klijenata prikazuje vlasnicu obrta u obliku klase koja uspostavlja interakciju s okolnim klasama. Vlasnica obrta komunicira i razmjenjuje informacije s repozitorijem klijenata, koji izvodi niz operacija, i s formom sa podacima klijenta, koja većinom sadrži javne atribute. Opća klasa naspram vlasnice obrta je klasa Osoba, u kojoj je sadržano ime i prezime korisnika te njegov ID. Također vidljivo je kojeg su tipa navedeni podaci. Klasa Vlasnica obrta sadrži i neke operacije/metode. To su provjera lozinke, pregled evidencije i pregled klijenata. Vlasnica je povezana s repozitorijem klijenata, koji sadrži definirane operacije, poput dohvaćanja klijenta i stvaranja objekta. Repozitorij klijenata je, također u interakciji sa slojem za pristup bazi. Ova klasa ima ulogu provjere stanja sustava i dohvaćanja povratnih vrijednosti. Poveznice na dijagramu se mogu podijeliti na poveznice generalizacije, osnovne agregacije i jake agregacije. Primjer generalizacije je Osoba - Vlasnica obrta, dok su agregacije prikazane rombom. Crno ispunjeni romb predstavlja jaku agregaciju i ona se opisuje na način da bez postojanja jedne klase ne bi postajala ni druga klasa (suprotno ne mora vrijediti). Osnovna agregacija, kao što joj i samo ime kaže predstavlja osnovnu vezu elemenata i nema nekakve uzročno-posljedične veze promjenom sadržaja klasa. Shodno tome, repozitorij klijenata ne bi postojao bez da ne postoji forma sa podacima klijenta, dok forma može postojati bez postojanja repozitorija.

## 2.3. Specifikacija slučaja korištenja Prikazivanje statističkih podataka

### 2.3.1. Detaljna specifikacija Prikazivanje statističkih podataka (FZ-14)

| **Naziv** | **Opis** |
|--|--|
| Naziv | Prikazivanje statističkih podataka |
| Kratki opis | Softver bi različitim statističkim podacima dao uvid u količinu obavljenog posla, povećanje posla i napretka u radu zaposlenika. Softver će omogućiti prikaz statističkih podataka obavljenog posla zaposlenika kako bi se mogao pratiti njihov napredak i uspješnost u radu. Ti podaci će također pomoći u donošenju odluka vezanih za potrebne promjene u organizaciji i rasporedu posla. Na primjer, u slučaju povećanja posla, statistički podaci će pomoći u odluci o dodatnom zapošljavanju ili drugačijoj raspodjeli posla između zaposlenika. Prema dobivenim podacima moći će se kreirati izvještaji. |
| Sudionici | Vlasnica obrta |
| Okidači | Vlasnica obrta traži pristup podacima klijenata, želi pregledati statistiku poslovanja u obrtu ili uvid u količinu obavljenog posla. |
| Preduvjet | Osoba mora biti prijavljena u sustav kao administrator, te mora imati bazu podataka o klijentima i obavljenom radu. Podaci moraju biti bilježeni dulje vrijeme kako bi prikaz statističkih podataka bio vjerodostojan. |
| Stanje sustava nakon uspješnog izvršenja | Vlasnica obrta ima uvid u statističke podatke svojih zaposlenika i obavljenom poslu. |
| Iznimke | Nije primjenjivo. |
| Stanje sustava nakon pojave iznimke | Nije primjenjivo. |
| Standardni proces | (1) Vlasnica obrta pristupa statističkim podacima. <br> (2) Sustav prikazuje grafikon statističkih podataka. <br> (3) Vlasnica odabire opciju promjeni prikaz. <br> (4) Sustav prikazuje promijenjeni grafikon. <br> (5) Vlasnica pregledava i analizira dobivene grafikone. <br> (6) Vlasnica izrađuje izvještaj grafikona. <br> (7) Sustav vraća kreirani izvještaj. |
| Alternativni procesi | Nije primjenjivo. |

### 2.3.2. Skice ekrana uključenih u Prikazivanje statističkih podataka
[![graf2](https://user-images.githubusercontent.com/126497323/232290727-5bc6d9d2-9664-40a1-8fd8-4612d80ed3c0.png)](https://user-images.githubusercontent.com/126497323/232290727-5bc6d9d2-9664-40a1-8fd8-4612d80ed3c0.png) <br clear="left"/>
Skica 1: Statistički podaci (prikaz podataka - graf1)

[![graf1](https://user-images.githubusercontent.com/126497323/232290743-49a822e2-8007-4bd1-90bd-df40d7b3b588.png)](https://user-images.githubusercontent.com/126497323/232290743-49a822e2-8007-4bd1-90bd-df40d7b3b588.png) <br clear="left"/>
Skica 2: Statistički podaci (prikaz podataka - graf2)

[![izvjestaj](https://user-images.githubusercontent.com/126497323/232290751-e4d752a4-dd3c-4388-9844-f3ac79dce3ec.png)](https://user-images.githubusercontent.com/126497323/232290751-e4d752a4-dd3c-4388-9844-f3ac79dce3ec.png) <br clear="left"/>
Skica 3: Izvještaj (prikaz podataka)


### 2.3.3. Dijagram slijeda Prikazivanje statističkih podataka

Kao što je već spomenuto, osnovni elementi dijagrama slijeda su životna crta, poruke i objekti. Životna crta predstavlja vremenski tijek života objekta, dok poruke označavaju razmjenu poruka između objekata. Objekti su elementi sustava koji se pojavljuju u dijagramu i sudjeluju u interakciji. Ovdje je prikazan dijagram slijeda na razini dizajna, a omogućuju detaljan prikaz interakcije između objekata. Osim toga, dijagrami slijeda pomažu u testiranju softvera jer se mogu koristiti za provjeru ispravnosti izvođenja procesa.

[![dijagram_slijeda2](https://user-images.githubusercontent.com/126497323/232295322-004bed7a-02aa-48a6-9ed4-6b1d29487df6.png)](https://user-images.githubusercontent.com/126497323/232295322-004bed7a-02aa-48a6-9ed4-6b1d29487df6.png)

Prikazani dijagram se sastoji od vlasnice obrta, koja pokreće cijeli slijed aktivnosti u sustavu, a koristi se korisničkim sučeljem, koje prikazuje stanje sustava i moguće opcije (funkcionalnosti). Repozitorij zaposlenika sadrži podatke o zaposlenicima, njihovom obavljenom učinku, vremenu izvođenja pojedinih zadataka te osnovne podatke o svakom zaposleniku, koji su nužni za pravilan prikaz statističkih podataka. Softversko rješenje nudi mogućnost kreiranja izvještaja, pa je zato naveden entitet izvještaj. On ima ulogu spremanja podataka koji su dohvaćeni iz repozitorija, a sloj za pristup bazi provjerava unesene vrijednosti i odobrava daljnje izvođenje toka. Vlasnica ima mogućnost promjene prikaza grafikona, što joj omogućuje bolji uvid u statističke podatke. Radi boljeg prikaza rezultata vlasnica ima opciju izrade izvještaja, koji joj daje uvid na sve grafikone istovremeno.

### 2.3.4. Dijagram aktivnosti Prikazivanje statističkih podataka

UML dijagram aktivnosti vrsta je dijagrama ponašanja koji prikazuje tijek aktivnosti i akcija unutar sustava ili procesa. Koristi se za modeliranje i opisivanje koraka ili zadataka uključenih u određeni poslovni proces ili softversku aplikaciju. Dijagrami aktivnosti sastoje se od skupa čvorova i rubova koji predstavljaju aktivnosti i odnose među njima. Čvorovi mogu predstavljati zadatke, odluke ili događaje, dok rubovi definiraju tijek kontrole između njih. Dijagrami aktivnosti korisni su za analizu i optimizaciju složenih sustava jer daju jasnu i sažetu vizualizaciju ponašanja sustava. Mogu se koristiti za prepoznavanje potencijalnih uskih grla ili neučinkovitosti u procesu te za dizajniranje učinkovitijih radnih procesa ili softverskih sustava.

[![dijagram_aktivnosti2](https://user-images.githubusercontent.com/126497323/232305754-d84fcf23-35d2-4bf3-94d8-bc2612872017.png)](https://user-images.githubusercontent.com/126497323/232305754-d84fcf23-35d2-4bf3-94d8-bc2612872017.png)

Dijagram aktivnosti započinje zahtjevom vlasnice obrta za prikazom statističkih podataka. Sustav _Valval_ dohvaća sve zaposlenike, te skupa s njima pribavlja sažete podatke zaposlenika. Zatim započinje s provjerom grafa koji se prikazuje. Ova aktivnost ima početni događaj, koji se nadovezuje na prikaz prvog grafa. Ovisno je li se dogodila promjena prikaza sustav određuje hoće li se prikazati drugi graf ili će ostati prikaz prvog grafa. U slučaju promjene prikaza, prikazuje se drugi graf i ponovno se ispituje je li se dogodila promjena. U slučaju kada nema promjene prikaza, aktivnost dolazi do svojeg završnog događaja. Nadalje sustav prikazuje podatke i odgovarajući grafikon, gdje vlasnica pregledava statističke podatke. Vlasnica ima opciju izrade izvještaja, gdje joj u potvrdnom slučaju sustav prikazuje izvještaj svih grafikona. Nakon pregleda izvještaja, dijagram aktivnosti dolazi do završnog događaja.


### 2.3.5. Dijagram klasa Prikazivanje statističkih podataka

Klase predstavljaju skup sličnih objekata i opisuju njihove karakteristike i ponašanje. Objekti, s druge strane, imaju vlastiti identitet, ali često dijele identične karakteristike i ponašanja s drugim objektima unutar sustava. Klase omogućuju opis sličnih objekata bez prikazivanja njihovih detalja. Osim klasa, dijagram klasa također može prikazati druge klasifikatore, kao što su sučelja, tipovi podataka, objekti, enumeracije i artefakti. Međutim, oni se rjeđe koriste.  Ukratko, dijagram klasa se koristi za prikaz strukture softverskog sustava, dijelova sustava i odnosa između njih. Sastoji se od klasifikatora, koji mogu biti klase, sučelja, tipovi podataka, paketi, objekti, enumeracije ili artefakti. Klase predstavljaju skup sličnih objekata i opisuju njihove karakteristike i ponašanje. Dijagram klasa je najčešće korišteni UML dijagram.

[![klasa2](https://user-images.githubusercontent.com/126497323/232629268-b5298af5-bcdd-4734-9a46-e392aa838e28.png)](https://user-images.githubusercontent.com/126497323/232629268-b5298af5-bcdd-4734-9a46-e392aa838e28.png)

Nazivi pojedinih klasa dijagrama jesu Osoba, Vlasnica obrta, Izvještaj, Podaci zaposlenika, Repozitorij zaposlenika i Sloj za pristup bazi. Klasa Osoba predstavlja opću klasu, to jest klasa Vlasnica obrta nasljeđuje ovu klasu. U klasi su zapisani osnovni podaci kao ime, prezime, i primarni ključ ID. Vlasnica ima atribute korisničko ime i lozinka. Također sadrži operacije poput provjera lozinke, pregled evidencije i pregled izvještaja. Operacije imaju povratni tip void, osim provjere lozinke koja vraća vrijednost istine ili laž (0 ili 1). Vlasnica je povezana s ostalim klasama osnovnom agregacijom. Ova vezu tumačimo na način da ako cjelinu obrišemo, dijelovi cjeline ne prestaju postojati. Također, ona daje dodatnu informaciju o odnosu klasa i njihovim životnim ciklusima. Klasa Podaci zaposlenika sadrži javne tipove atributa koji opisuju osnovne podatke zaposlenika. Podaci zaposlenika su sa ostalim klasama povezani pomoću jake agregacije, što je na slici prikazano crnim, ispunjenim rombom. Sloj za pristup bazi sadrži metode kojima provjerava stanje sustava i vraća povratnu vrijednost. Repozitorij zaposlenika je u interakciji s vlasnicom, slojem za pristupom bazi i s podacima zaposlenika. U slučaju brisanja klase Podaci zaposlenika obrisao bi se i repozitorij zaposlenika jer je tako određeno korištenjem poveznice jake agregacije. Bez postojanja jedne klase ne bi mogla postojati ni druga klasa (obostrano ne mora vrijediti).


## 2.4. Kompletan dijagram klasa

Kompletan dijagram klasa objedinjuje prethodna dva izrađena dijagrama. Na dijagramu su objedinjeni slučajevi korištenja Evidentiranje klijenata i Prikazivanje statističkih podataka. Navedeni dijagram prikazan je sljedećom slikom:

[![klasa3](https://user-images.githubusercontent.com/126497323/232629355-d9712de0-12e9-4134-8d9d-223e971e72f2.png)](https://user-images.githubusercontent.com/126497323/232629355-d9712de0-12e9-4134-8d9d-223e971e72f2.png)

Vlasnica obrta je ovdje postavljena kao središnja klasa, koja uspostavlja komunikaciju sa skoro svim klasama ovog dijagrama. Poopćena klasa vlasnice obrta jest klasa Osoba, gdje su zapisani podaci o korisniku. Vlasnica uspostavlja interakciju s klasom Izvještaj i Formom sa podacima klijenta. Međusobno su povezane poveznicom osnovne agregacije. Vlasnica je, također povezana i sa repozitorijem klijenata i repozitorijem zaposlenika. Ti repozitoriji ne sadrže podatke već samo operacije koje se mogu izvoditi. Na dijagramu je moguće uočiti poveznice jake agregacije, koje definiraju da određena klasa ne bi postojala bez da ne postoji druga klasa. Primjer toga je da izvještaj ne može postojati bez podataka o zaposleniku, a također klasa repozitorij zaposlenika ne bi imao nikakvu funkciju bez da nema podataka o zaposlenicima kojima može upravljati i izvoditi određene operacije. Sloj za pristup bazi ovdje ima ulogu dohvaćanja povratnih vrijednosti i odobravanje izvođenja određenih akcija.


## 2.5. Kompletan model podataka (ERA dijagram)

ERA (Entitet-Relacija-Atribut) model podataka je grafički model podataka koji se koristi za prikazivanje logičke strukture baze podataka. Ovaj model je osmišljen kako bi vizualno prikazao podatke i njihove odnose u bazi podataka. ERA model podataka se sastoji od tri osnovna elementa: entiteta, relacija i atributa. Entiteti predstavljaju pojedinačne objekte ili koncepte koji se spremaju u bazu podataka, poput korisnika, predmeta ili bilo koje sredstvo promatranja. Relacije opisuju način na koji su ti entiteti povezani, poput toga da jedan korisnik može posjedovati više proizvoda ili da jedan proizvod može biti u vlasništvu samo jednog korisnika. Atributi su karakteristike koje opisuju svaki entitet, poput imena, datuma ili cijene proizvoda.

[![era_model](https://user-images.githubusercontent.com/126497323/232320240-77b5750b-c699-4a21-ba05-415335e665ac.png)](https://user-images.githubusercontent.com/126497323/232320240-77b5750b-c699-4a21-ba05-415335e665ac.png)

Na ERA dijagramu su prikazani entiteti Klijent, Zaposlenik, Evidencija klijenata, Izvještaj, Korisnik te Forma sa podacima klijenta i Statistički podaci. Zadnja dva navedena entiteta se razlikuju od ostalih entiteta, zato što oni predstavljaju slabi entitet. Entiteti sadrže atribute, atributi opisuju stanja i svojstva entiteta, dakle entitet Klijent karakteriziraju atributi Ime, Prezime, Kontakt i tako dalje. Klijent može biti prikazan na jednoj ili više evidencija, ali također ne mora biti prikazan na nijednoj. S druge strane entitet Evidencija klijenata može sadržavati u sebi nula, jednog ili više klijenata. Veza između klijenta i evidencije bila bi više na više, međutim takve veze nisu dopuštene jer su dosta nedorečene i mogu uzrokovati problem pri radu s bazom podataka. Iz tog razloga se uvodi slabi entitet, u ovom slučaju Forma sa podacima klijenta. Slabi entiteti su karakteristični po tome što sadrže vanjske ključeve tablica koje su trebale biti spojene vezom više naprema više. Veza više na više se pretvara u vezu jedan naprema više gdje je oznaka više na strani slabog entiteta. 

Svaka tablica mora sadržavati primarni ključ, kako bi zapisi podataka u njoj bili jedinstveni. Pomoću primarnog ključa podaci se lakše pronalaze u bazi podataka te se shodno tome i lakše uređuju. Primarni ključ može biti i složen što bi značilo da je sastavljen od dva atributa. Primjer takvog primarnog ključa može se vidjeti unutar entiteta Statistički podaci, gdje je primarni ključ sastavljen od dva vanjska ključa tablica koje povezuje. Vanjski ključ ustvari predstavlja referencu na atribute iz drugog entiteta.

Ukratko, na ovome dijagramu uočavamo da korisnik može pregledavati evidenciju klijenata ili izvještaj statističkih podataka, a pritom sustav zapisuje podatke o korisniku kada je pristupao određenoj opciji. Pri kreiranju prikaza evidencije klijenata ili prikaza izvještaja, sustav obavlja pozadinske poslove kao što je dohvaćanje podataka iz entiteta Klijent ili dohvaćanje podataka iz entiteta Zaposlenik.

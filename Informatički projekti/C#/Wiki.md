# Specifikacija softverskih zahtjeva za Obrt za čišćenje
***
## 1. UVOD
### 1.1. Svrha

Svrha dokumenta je predstaviti specifikaciju softverskih zahtjeva. Zahtjevi su proizašli od korisnika, a odnose se na softver za praćenje rada obrta usluge čišćenja. Korisnik aplikacije je prvenstveno vlasnica obrta i njeni zaposlenici. Vlasnica je iznijela zahtjeve koje softver mora ispunjavati, a ti zahtjevi uključuju temeljitu organizaciju podataka u obrtu i mogućnost praćenja rada poslovanja. Dokument je namijenjen programerima, dizajnerima, testerima i sistemašima (inženjeri sustava). Zadaća programera jest implementacija softverskog rješenja, ali i njegovo osmišljavanje prema prikupljenim zahtjevima korisnika. Dizajneri imaju ulogu osmišljavanja preglednog prikaza sučelja softvera, pritom pazeći na njegovu jednostavnost i intuitivnost. Testeri su zaduženi za testiranje funkcionalnosti svega izrađenog, a posao sistemaša je planiranje, analiza i organizacija procesa implementacije rješenja. Također, dokument je namijenjen i vlasnici obrta, jedan razlog tome je da vlasnica ima uvid u izvođenje projekta, a drugi razlog je ustvari da ovaj dokument predstavlja ugovor između vlasnice i izvođača. 

Struktura cijelog dokumenta prati predložak koji je definiran dokumentom _IEEE 830-1998 Recommended Practice for Software Requirements Specifications_.

### 1.2. Opseg

Trenutno u obrtu za čišćenje vlasnica vodi sve podatke o zaposlenicima i klijentima koje zapisuje u excel tablicu. U nju upisuje osnovne podatke klijenta, njegovu lokaciju, vrijeme i trajanje usluge čišćenja. Uz sve navedeno vlasnica se služi i bilježnicom za vođenje evidencije zaposlenika i tjednih zadataka. Softversko rješenje će nastojati pojednostaviti trenutnu organizaciju rada u obrtu, na način da vlasnica ima uvid u sve podatke te da joj se pruži lakša komunikacija, bilo sa klijentima ili sa zaposlenicima. Obrt se trenutno sastoji od 5 zaposlenika (4 zaposlenika + vlasnica). Posao u obrtu započinje pozivom klijenta. Vlasnica upoznaje klijenta s mogućim uslugama obrta, nudi mu slobodne termine te dogovara posjet lokaciji izvođenja usluge. U nekim slučajevima je dovoljno da klijent dostavi slike prostora koji je potrebno očistiti. Na kraju, vlasnica pridružuje posao slobodnom zaposleniku, te na kraju tjedna objavljuje raspored izvođenja poslova za slijedeći tjedan. Za izradu softvera potreban je uvid u već postojeće podatke, koji su zapisani u excel tablici i bilježnici, a sam softver će predstavljati nadogradnju već postojećeg sustava organizacije. Softver će pružiti prikaz podataka na jednom mjestu, a uz to će prikazivati i tjedni raspored izvođenja poslova. Vlasnica će moći po želji dodavati nove zaposlenike, imati će uvid u postojeće zaposlenike, vodit će evidenciju klijenata, uključujući evidenciju njihovih podataka i lokacija (mjesta izvođenja usluga). Od mnogih funkcionalnosti koje će pružiti softver bitno je izdvojiti da će imati mogućnost pretrage slobodnih termina i slobodnih zaposlenika, što će poboljšati trenutnu raspodjelu poslova unutar obrta. Postojat će mogućnost odabira i pregleda vrste usluge čišćenja (moguće 4 kategorije) kojima se obrt bavi. Usluge čišćenja dane su slijedećom tablicom:

| Vrsta čišćenja | Podvrsta čišćenja |
|---|---|
| 1. Redovito čišćenje | 1.1. čišćenje stambenih i poslovnih prostora <br> 1.2. čišćenje apartmana <br> 1.3. čišćenje i održavanje stubišta |
| 2. Generalno čišćenje | 2.1. generalno čišćenje stambenih i poslovnih prostora <br> 2.2. generalno čišćenje nakon radova <br> 2.3. generalno čišćenje pojedinih prostorija |
| 3. Kemijsko čišćenje | 3.1. kemijsko čišćenje tapeciranog namještaja <br> 3.2. kemijsko čišćenje tepiha |
| 4. Čišćenje vanjskih površina i objekata |

Sveobuhvatno gledano, softver će unaprijediti trenutno stanje u obrtu, u vidu organizacije rada, raspodjele poslova, a zaposlenicima će biti omogućeno lakše praćenje tjednih obaveza i zadataka. Vlasnica će moći lakše upravljati obrtom i donositi bolje odluke na temelju kreiranih izvještaja. Naziv softverskog rješenja glasit će _Valval_.


### 1.3. Definicije, akronimi i skraćenice

* **Redovito čišćenje** – vrsta čišćenja, uključuje neke najučestalije usluge čišćenja prostora koje se obavljaju redovno (čišćenje stambenih i poslovnih prostora, apartmana, održavanje stubišta).
* **Generalno čišćenje** – vrsta čišćenja, odnosi se na temeljito čišćenje prostora, u odnosu na redovito čišćenje, ova vrsta je po obujmu posla zahtjevnija (generalno čišćenje stambenih i poslovnih prostora, čišćenje nakon radova, čišćenje pojedinih prostorija).
* **Kemijsko čišćenje** – vrsta čišćenja koja ne uključuje čišćenje cijelog prostora, bavi se čišćenjem tapeciranog namještaja i tepiha.
* **Čišćenje vanjskih površina i objekata** – vrsta čišćenja, uključuje sve vanjske površine i objekte koji nisu obuhvaćeni prošlim vrstama čišćenja.
* **Excel tablica** – tablica koja sadrži određene podatke, koji su potrebni za vođenje poslovanja unutar obrta, excel predstavlja naziv programa u kojem je tablica zapisana.
* **Automatizacija** – proces kojim se zamjenjuje ili smanjuje udio ljudskog rada pri izvođenju pojedinih zadataka, a omogućeno je primjenom tehnologije. 

### 1.4. Reference

1. “830-1998 - IEEE Recommended Practice for Software Requirements Specifications.” IEEE, 1998. [Online]. Available: http://ieeexplore.ieee.org/servlet/opac?punumber=5841
2. Dokument opisa problemske domene

### 1.5. Struktura dokumenta

**Poglavlje 2** bavi se proizvodom, to jest softverskim rješenjem kakvo ono mora biti. Opisuje se sam proizvod, njegove karakteristike i definiraju se njegove funkcionalnosti. Uz navedeno poglavlje 2 uključuje i karakteristične korisnike softvera. Identificirane su različite grupe i uloge korisnika kojima je softver _Valval_ namijenjen. Potrebno je definirati i skup ograničenja softvera, koji mogu bitno utjecati na sam razvoj softvera. Ovdje također spadaju pretpostavke i neka otvorena pitanja, koja predstavljaju okolnosti koje nisu pod našom kontrolom. 

**Poglavlje 3** navodi funkcionalne zahtjeve i njihova obilježja i specifikacije. Zahtjevi su sastavljeni na način da pružaju dovoljno informacija programerima i dizajnerima za razvoj i implementaciju softvera. Zahtjevi će se međusobno razlikovati po jedinstvenom identifikatoru.

**Poglavlje 4** obrađuje nefunkcionalne zahtjeve. Slično kao treće poglavlje, ono opisuje karakteristike zahtjeva s tom razinom detaljnosti da su zahtjevi razumljivi programerima i dizajnerima. Ovi zahtjevi su više vezani za izgled softvera, performanse, upotrebljivost, okruženje te sigurnost softvera.

**Poglavlje 5** sadrži skice zaslona te je prikazana skica softverskog rješenja. Svrha skica jest da vizualno predoči što aplikacija radi i kakve mogućnosti korisniku pruža. Ona predstavlja interakciju između korisnika i softvera.

## 2. OPĆENITI OPIS

### 2.1. Perspektiva proizvoda

Softversko rješenje _Valval_ zamišljeno je kao samostalni softver, odnosno proizvod koji je zamjena za već postojeći sustav. Kao što je prethodno navedeno, softver će zamijeniti postojeću organizaciju rada u obrtu na način da će se svi podaci bilježiti na jednome mjestu, softveru _Valval_. Za ispravan rad softvera potrebna je baza podataka, u kojoj su zapisani svi podaci o klijentima i zaposlenicima. Baza podataka je implementirana putem excel tablice. Kako bi vlasnica mogla kreirati tjedni raspored zadataka i obaveza, softveru je potreban kalendar. Analizirajući podatke, bilo iz excel tablice ili iz tjednih rasporeda postoji mogućnost kreiranja izvješća za određeni vremenski period. Za kreiranja izvješća nije potreban nikakav vanjski softver, jer _Valval_ omogućava sortiranje podataka i njihov ispis.

Softver _Valval_ ne koristi hardver i komunikacijske tehnologije jer nema potrebu. Zamišljeno je da se softver može primjenjivati na bilo kojem operacijskom sustavu, koji sam određuje korištenje hardvera ili komunikacijskih tehnologija.

### 2.2. Funkcije proizvoda

Glavne funkcije i mogućnosti koje softversko rješenje _Valval_ treba sadržavati, kojima će se budući korisnici koristiti, a temeljene su na očekivanjima vlasnice obrta jesu:
* Dodavanje i uvid u zaposlenike
* Evidencija klijenta, njihovih podataka i lokacije (moguće više lokacija)
* Pretraga slobodnih termina i slobodnih zaposlenika unutar rasporeda
* Automatizacija sustava (raspored, obavijesti)
* Zaposlenik prijavljuje kada započinje i kada završava s radom
* Mogućnost definiranja zadatka s određenim vremenskim razmakom
* Izrada izvješća za određeno vremensko razdoblje
* Jedinstven raspored za svakog zaposlenika

### 2.3. Karakteristike korisnika

U softveru _Valval_ se razlikuju dvije vrste korisnika, administrator i zaposlenik. Ulogu administratora u obrtu za čišćenje će imati vlasnica obrta. Vlasnica ima pristup svim funkcijama i mogućnostima softvera (od kojih je većina nabrojana u prethodnom poglavlju), dok zaposlenici imaju svega par mogućnosti i opcija. Osoba u ulozi zaposlenika može pregledavati samo svoj raspored, i nema pristup tuđem rasporedu. Uz to, zaposlenik ima opciju dodavanja vremena kada je započeo s izvođenjem posla te bilježenje završnog vremena kada je posao obavio. Očekuje se da će se softversko rješenje koristiti na dnevnoj razini, za koju je potrebno nekakva prosječna razina obrazovanja u pogledu računalne i tehničke pismenosti. Pri korištenju softvera, potrebna je prijava, kako bi se razlikovala uloga vlasnika od zaposlenika, te zaposlenik od zaposlenika (svaki zaposlenik ima jedinstven raspored).

### 2.4. Ograničenja

Problemska domena softvera _Valval_ uključuje zaštitu podataka klijenata i zaposlenika. Naime, ne bi bilo dobro da svi imaju pristup podacima klijenata i zaposlenika, stoga samo vlasnica ima mogućnost uvida u sve podatke. Zaposlenici vide samo nužno potrebne podatke bez kojih ne mogu obaviti posao, kao na primjer lokaciju klijenta. Podaci unutar obrta moraju imati neku vrstu sigurnosti radi čuvanja privatnosti klijenta. Još jedno ograničenje koje se pojavljuje pri izradi softvera je da bi softver trebao biti neovisan o uređaju na kojem se koristi (računalo, tablet, mobitel). Većina zaposlenika će radi jednostavnosti koristiti softver na mobitelu. Primjer tome je pregled dnevnog rasporeda, pregled lokacije čišćenja, evidentiranje početka i završetka posla. Nasuprot zaposlenicima, vlasnica će većinu vremena koristiti softver na računalu gdje će evidentirati nove klijente, zakazivati termine čišćenja i kreirati nove rasporede i izvještaje poslovanja. Ograničenje koje vlasnica očekuje od softvera jest da zaposlenici nemaju mogućnost uvida u druge rasporede izuzev svojeg.

### 2.5. Pretpostavke i ovisnost

Pretpostavlja se da bi vlasnica mogla izmijeniti popis usluga čišćenja koje obrt obavlja. U tom slučaju trebale bi se ažurirat i upotpunit već postojeća lista usluga čišćenja. Ova akcija bi uključila i promjenu nad dodavanjem termina u raspored jer se pri dodavanju termina mora izabrati vrsta čišćenja koja se izvodi na određenoj lokaciji. Postoji mogućnost da vlasnica zatraži dodavanje još neke uloge u softver koja će imati posebna prava, na primjer osoba koja će biti zadužena za uređivanje baze podataka. Također, postavlja se pitanje hoće li vlasnica htjeti još neke dodatne funkcionalnosti unutar rasporeda poslova (poseban prikaz, mogućnost sortiranja).

### 2.6. Ostalo

Nema potrebe za elaboracijom dodatnih aspekata, te se smatra da je softver dovoljno opisan i predstavljen pomoću prethodnih specifikacija.

## 3. FUNKCIONALNI ZAHTJEVI

| Identifikator | FZ-1 |
|---|---|
| Zahtjev | Sustav će omogućiti prijavu u sustav samo ovlaštenim korisnicima. |
| Obrazloženje | Samo vlasnica obrta i njeni zaposlenici će imati pravo prijave u sustav putem korisničkog imena i zaporke, razlog tome je zaštita i privatnost podataka. Sustav će imati ugrađene sigurnosne mjere koje će omogućiti prijavu samo ovlaštenim korisnicima. Samo oni korisnici koji su prethodno registrirani imat će pravo na prijavu u sustav. Ovakav sustav prijave omogućuje bolju sigurnost i zaštitu podataka u sustavu. |
| Način provjere | Korisnik softvera mora ispravno unijeti podatke prijave, što uključuje korisničko ime i zaporku. |
| Prioritet [1-5] | 1 |
| Izvor/Porijeklo | Vlasnica obrta |

[![prijava_u_sustav](https://user-images.githubusercontent.com/126497323/226192513-61690aac-43e1-492e-9a52-f5b28bd09a28.png)](https://user-images.githubusercontent.com/126497323/226192513-61690aac-43e1-492e-9a52-f5b28bd09a28.png)


| Identifikator | FZ-2 |
|---|---|
| Zahtjev | Sustav će omogućiti uvid u postojeće zaposlenike samo administratoru. |
| Obrazloženje | U slučaju da administrator želi pregledati podatke već postojećih zaposlenika obrta može ih vidjeti u tablici popis zaposlenika. Ograničavanje pregleda popisa zaposlenika samo na administratora osigurava veću razinu zaštite i privatnosti podataka zaposlenika. Prikaz popisa zaposlenika u okviru softverskog sučelja olakšava administratoru uvid u sve relevantne informacije o zaposlenicima na jednom mjestu. Ova funkcija omogućuje učinkovito upravljanje zaposlenicima, kao i praćenje promjena u radnom osoblju unutar obrta.|
| Način provjere | Korisnik softvera mora biti prijavljen kao administrator, gdje će imati opciju pregleda popisa zaposlenika. |
| Prioritet [1-5] | 1 |
| Izvor/Porijeklo | Vlasnica obrta |

[![popis_zaposlenika](https://user-images.githubusercontent.com/126497323/226192693-af36fed3-8a6b-4605-b4d3-798d9aa94fda.png)](https://user-images.githubusercontent.com/126497323/226192693-af36fed3-8a6b-4605-b4d3-798d9aa94fda.png)


| Identifikator | FZ-3 |
|---|---|
| Zahtjev | Sustav će omogućiti dodavanje novog zaposlenika samo administratoru. |
| Obrazloženje | U slučaju da se pojavi novi zaposlenik u obrtu, administrator ga lako može evidentirati u popis zaposlenika. Ograničavanje dodavanja novih zaposlenika samo na administratora osigurava kontrolu nad unosom podataka unutar obrta. Učinkovito upravljanje popisom zaposlenika može pomoći u izbjegavanju nepotrebnih troškova i potencijalnih problema sa zaposlenicima. Dodavanje novih zaposlenika putem softverskog sučelja smanjuje mogućnost pogreške i olakšava administrativni posao vezan uz upravljanje zaposlenicima.|
| Način provjere | Korisnik softvera mora biti prijavljen kao administrator, gdje će imati opciju dodavanja novog zaposlenika, te mora ispravno unijeti podatke novog zaposlenika. |
| Prioritet [1-5] | 2 |
| Izvor/Porijeklo | Vlasnica obrta |

[![dodavanje_zaposlenika](https://user-images.githubusercontent.com/126497323/226192714-b98bd758-b6cd-49d9-92ab-b6b934a13102.png)](https://user-images.githubusercontent.com/126497323/226192714-b98bd758-b6cd-49d9-92ab-b6b934a13102.png)


| Identifikator | FZ-4 |
|---|---|
| Zahtjev | Sustav će omogućiti uvid u evidenciju klijenata, uključujući pregled njihovih podataka i lokacije. |
| Obrazloženje | Vlasnica mora imati evidenciju svih svojih trenutnih klijenata, njihove kontakt podatke i lokaciju na kojoj se obavlja usluga. Za neke klijente usluge čišćenja obavljaju se uvijek na istoj lokaciji, a neki klijenti usluge koriste za više lokacija. Omogućavanje pregleda evidencije klijenata omogućuje vlasnici obrta učinkovitije upravljanje svojim klijentima. Pregled podataka o lokacijama klijenata olakšava organizaciju rasporeda poslova i učinkovito planiranje radnih aktivnosti. Prikaz svih relevantnih podataka o klijentima u jednom sučelju pomaže u smanjenju vremena i resursa potrebnih za administrativne poslove.|
| Način provjere | Korisnik softvera mora biti prijavljen kao administrator, gdje će imati opciju pregleda evidencije klijenata. |
| Prioritet [1-5] | 1 |
| Izvor/Porijeklo | Vlasnica obrta |

[![evidencija_klijenata](https://user-images.githubusercontent.com/126497323/226192924-b2c61829-7254-4339-b4f2-59511d40bfc3.png)](https://user-images.githubusercontent.com/126497323/226192924-b2c61829-7254-4339-b4f2-59511d40bfc3.png)


| Identifikator | FZ-5 |
|---|---|
| Zahtjev | Sustav će omogućiti dodavanje novog klijenta samo administratoru. |
| Obrazloženje | Vlasnica mora imati opciju dodavanja novih klijenata, kako bi mogla zabilježiti njihove podatke, vrstu usluge i lokaciju mjesta usluge čišćenja. Omogućavanje dodavanja novog klijenta olakšava vlasnici obrta praćenje i upravljanje svojim klijentima, kontakt podacima i uslugama koje pruža. Dodavanje novog klijenta putem softverskog sučelja eliminira potrebu za ručnim unosom podataka i olakšava evidenciju klijenata. Administrator će imati potpunu kontrolu nad procesom dodavanja novih klijenata i moći će brzo i jednostavno zabilježiti sve relevantne podatke o novom klijentu. |
| Način provjere | Korisnik softvera mora biti prijavljen kao administrator, gdje će imati opciju evidencije klijenata, te mora ispravno unijeti podatke klijenta. |
| Prioritet [1-5] | 1 |
| Izvor/Porijeklo | Vlasnica obrta |

[![dodavanje_klijenta](https://user-images.githubusercontent.com/126497323/226193019-b00fc2bd-94bb-4fd3-a4c7-371f72d7673c.png)](https://user-images.githubusercontent.com/126497323/226193019-b00fc2bd-94bb-4fd3-a4c7-371f72d7673c.png)


| Identifikator | FZ-6 |
|---|---|
| Zahtjev | Sustav će omogućiti evidenciju poslova u raspored samo administratoru. |
| Obrazloženje | Nakon što vlasnica donese odluku, u sustavu evidentira koja vrsta usluge je potrebna, za kojeg klijenta, termin obavljanja usluge i pridružuje zaposlenika zadatku. Moguće je da više zaposlenika obavlja isti zadatak. Sustav će omogućiti vlasnici obrta da lako evidentira poslove u rasporedu, uključujući vrstu usluge, klijenta, termin obavljanja i pridruženog zaposlenika. Ova funkcionalnost omogućuje vlasnici da efikasno upravlja rasporedom poslova i pridruženim zaposlenicima, te im pruža pregled nad trenutnim stanjem u poslovanju. Korisnik softvera mora biti prijavljen kao administrator kako bi imao ovlasti za evidenciju poslova u rasporedu, te mora unijeti ispravne podatke kako bi se osigurala točnost rasporeda.|
| Način provjere | Korisnik softvera mora biti prijavljen kao administrator, gdje će imati opciju evidencije poslova, te mora ispravno unijeti podatke posla u raspored. |
| Prioritet [1-5] | 1 |
| Izvor/Porijeklo | Vlasnica obrta |

[![dodavanje_stavke](https://user-images.githubusercontent.com/126497323/226194397-4550e3d4-9153-4505-9241-b0ced3f46157.png)](https://user-images.githubusercontent.com/126497323/226194397-4550e3d4-9153-4505-9241-b0ced3f46157.png)


| Identifikator | FZ-7 |
|---|---|
| Zahtjev | Sustav će omogućiti pretragu slobodnih termina zaposlenika unutar rasporeda. |
| Obrazloženje | Prilikom evidencije posla potrebna je mogućnost pretrage slobodnih termina i slobodnih zaposlenika radi lakšeg i bržeg određivanja termina usluge čišćenja. Ovaj zahtjev omogućava vlasnici da brzo i jednostavno pronađe slobodne termine zaposlenika koji su dostupni za obavljanje usluge čišćenja za određenog klijenta. Evidencija slobodnih termina zaposlenika unutar rasporeda omogućava bolju organizaciju posla i optimizaciju rasporeda, čime se smanjuje vrijeme potrebno za planiranje posla. Korisnik softvera može lako pretraživati slobodne termine zaposlenika u rasporedu, što omogućuje brzu i učinkovitu dodjelu poslova i smanjuje vrijeme koje se troši na ručno planiranje rasporeda. |
| Način provjere | Korisnik softvera mora biti prijavljen kao administrator, gdje će imati opciju evidencije poslova, te opcije pretraga slobodnih termina i pretraga slobodnih zaposlenika. |
| Prioritet [1-5] | 3 |
| Izvor/Porijeklo | Vlasnica obrta |


| Identifikator | FZ-8 |
|---|---|
| Zahtjev | Sustav će omogućiti zaposleniku prijavu trajanja usluge čišćenja na nekoj lokaciji. |
| Obrazloženje | Kako bi vlasnica mogla pratiti rad zaposlenika i poboljšati procjenu potrebnog vremena za obavljanje pojedine usluge vlasnica želi da svaki zaposlenik prijavi kada je krenuo s izvođenjem radova i kada je završio s istim. Ovaj zahtjev omogućuje zaposlenicima da prijave trajanje usluge čišćenja na nekoj lokaciji, što omogućuje vlasnici da bolje prati rad svojih zaposlenika. Ovo je važno jer vlasnica želi imati bolju procjenu potrebnog vremena za obavljanje pojedine usluge, te kako bi mogla optimizirati raspored rada svojih zaposlenika. Osim toga, praćenje trajanja usluge čišćenja pomaže u povećanju pouzdanosti u radu zaposlenika, što doprinosi povećanju kvalitete usluga koje se pružaju. |
| Način provjere | Korisnik softvera ne mora biti prijavljen kao administrator, u softveru će imati opciju prijavi početak i završetak posla, gdje unosi valjano vrijeme, datum i lokaciju. |
| Prioritet [1-5] | 3 |
| Izvor/Porijeklo | Vlasnica obrta |

[![prijava_usluge](https://user-images.githubusercontent.com/126497323/226193339-495c30f0-51d5-489b-be14-6842536e4069.png)](https://user-images.githubusercontent.com/126497323/226193339-495c30f0-51d5-489b-be14-6842536e4069.png)


| Identifikator | FZ-9 |
|---|---|
| Zahtjev | Sustav će omogućiti definiranje zadatka s određenim vremenskim razmakom. |
| Obrazloženje | Kako bi se izbjeglo pojedinačno upisivanje čišćenja za svaki mjesec, ili svaka tri mjeseca, vlasnica želi opciju automatskog definiranja zadataka s određenim vremenskim razmakom između svakog. Definiranje zadatka s određenim vremenskim razmakom omogućit će vlasnici tvrtke lakše planiranje i organizaciju poslova, što će doprinijeti učinkovitijem korištenju vremena i resursa. Ova opcija automatskog definiranja zadataka s određenim vremenskim razmakom uvelike će smanjiti vrijeme koje se troši na upisivanje čišćenja za svaki mjesec ili svaka tri mjeseca, što će olakšati rad i povećati produktivnost. Korisnik softvera koji je prijavljen kao administrator moći će jednostavno dodati zadatke u kalendar i definirati željeni vremenski razmak, što će doprinijeti boljoj organizaciji i preglednosti rasporeda poslova. |
| Način provjere | Korisnik softvera mora biti prijavljen kao administrator, gdje će imati opciju dodaj posao u kalendar, te potom opciju dodaj zadatak s određenim vremenskim zadatkom. |
| Prioritet [1-5] | 5 |
| Izvor/Porijeklo | Vlasnica obrta |


| Identifikator | FZ-10 |
|---|---|
| Zahtjev | Sustav će omogućiti izradu izvješća za određeno vremensko razdoblje. |
| Obrazloženje | Softver bi različitim izvještajima dao uvid u količinu obavljenog posla, povećanje posla i broja klijenata, točniju procjenu vremena potrebnog za obavljanje određene vrste usluge i napretka u radu zaposlenika te bi time poboljšao organizaciju i rad obrta za čišćenje. Izrada izvještaja za određeno vremensko razdoblje omogućila bi vlasnici obrta za čišćenje da prati količinu obavljenog posla i napredak u radu zaposlenika, što bi joj olakšalo planiranje poslovanja. Osim toga, preciznija procjena vremena potrebnog za obavljanje određene vrste usluge omogućila bi bolje planiranje i optimizaciju rasporeda. Konačno, različiti izvještaji bi omogućili bolje praćenje poslovanja, povećanje učinkovitosti i donošenje ključnih odluka. |
| Način provjere | Korisnik softvera mora biti prijavljen kao administrator, gdje će imati opciju izradi izvještaj, te potom odabire željeno razdoblje za koje želi kreirati izvještaj. |
| Prioritet [1-5] | 4 |
| Izvor/Porijeklo | Vlasnica obrta |


| Identifikator | FZ-11 |
|---|---|
| Zahtjev | Sustav će omogućiti jedinstveni raspored za svakog zaposlenika. |
| Obrazloženje | Zaposlenici ne mogu imati pristup drugim podacima, odnosno vide samo svoj raspored. Raspored mora sadržavati vrijeme obavljanja, lokaciju obavljanja, druge zaposlenike na istom zadatku (ako postoje), uslugu koja se obavlja i procijenjeno vrijeme obavljanja iste. Jedinstveni raspored za svakog zaposlenika omogućit će bolju organizaciju rada i veću produktivnost, s obzirom da će svaki zaposlenik točno znati kada i gdje treba obavljati svoje zadatke. Osim što će zaposlenicima biti olakšano praćenje vlastitog rasporeda, ovaj zahtjev će pomoći i u održavanju privatnosti i sigurnosti podataka, s obzirom da će zaposlenici imati pristup samo svojim podacima. Kreiranje jedinstvenog rasporeda za svakog zaposlenika bit će moguće putem softvera, a zaposlenici će moći pristupiti svom rasporedu putem korisničkog računa, bez potrebe za traženjem informacija od drugih zaposlenika ili vlasnika obrta. |
| Način provjere | Korisnik softvera mora biti prijavljen kao zaposlenik, gdje će imati opciju pregled rasporeda te su mu u rasporedu prikazane tjedne obaveze, svaki zaposlenik ima jedinstveni raspored. |
| Prioritet [1-5] | 2 |
| Izvor/Porijeklo | Vlasnica obrta |

[![raspored2 drawio](https://user-images.githubusercontent.com/126497323/226194650-fc47c989-de9b-4e76-8da7-96c168e530bd.png)](https://user-images.githubusercontent.com/126497323/226194650-fc47c989-de9b-4e76-8da7-96c168e530bd.png)


| Identifikator | FZ-12 |
|---|---|
| Zahtjev | Sustav će omogućiti automatizaciju sustava rasporeda. |
| Obrazloženje | Umjesto slanja tablice s tjednim rasporedom zadataka svakom zaposleniku, vlasnica želi da se raspored automatski kreira za svakog zaposlenika kojem ona dodjeli zadatke. Automatizacija sustava rasporeda omogućila bi uštedu vremena i smanjila mogućnost greške pri ručnom kreiranju rasporeda. Vlasnica bi mogla jednostavno dodijeliti zadatke za svakog zaposlenika, a sustav bi automatski kreirao tjedni raspored za svakog zaposlenika. Svi korisnici softvera bi imali uvid u svoj raspored, dok bi samo administrator mogao vidjeti sve rasporede odjednom. |
| Način provjere | Svi korisnici softvera moraju imati mogućnost uvida u tjedni raspored, gdje jedino administrator može vidjeti sve rasporede odjednom. |
| Prioritet [1-5] | 1 |
| Izvor/Porijeklo | Vlasnica obrta |


| Identifikator | FZ-13 |
|---|---|
| Zahtjev | Sustav će omogućiti automatizaciju sustava obavijesti. |
| Obrazloženje | Kako bi se unaprijedila komunikacija s klijentima potrebno je omogućiti automatsko slanje podsjetnika klijentima dan prije dogovorenog datuma obavljanja usluge. Automatizacija sustava obavijesti omogućava efikasniju komunikaciju s klijentima, jer se podsjetnici mogu automatski slati dan prije dogovorenog datuma obavljanja usluge. Ovo rješenje također pomaže u smanjenju mogućnosti zaboravljanja dogovorenih termina i nezadovoljstva klijenata, što nadalje poboljšava kvalitetu usluge. Funkcionalnost sustava obavijesti može se provjeriti razgovorom s klijentima te kroz testiranje sustava s "testnim klijentom" kako bi se osiguralo da se obavijesti ispravno šalju i stižu na vrijeme. |
| Način provjere | Razgovor s klijentom i provjera je li mu obavijest došla, odnosno testiranje funkcionalnosti na način da se zakaže termin za „testnog klijenta“ te se provjerava je li pristigla obavijest. |
| Prioritet [1-5] | 5 |
| Izvor/Porijeklo | Vlasnica obrta |

[![obavijest](https://user-images.githubusercontent.com/126497323/226193669-6a2286fd-b0d6-4ba9-b077-2e3f60738814.png)](https://user-images.githubusercontent.com/126497323/226193669-6a2286fd-b0d6-4ba9-b077-2e3f60738814.png)


| Identifikator | FZ-14 |
|---|---|
| Zahtjev | Sustav će omogućiti prikaz statističkih podataka obavljenog posla zaposlenika. |
| Obrazloženje | Osim što bi ovaj softver poboljšao organizaciju i rad obrta za čišćenje, različitim statističkim podacima dao bi uvid u količinu obavljenog posla, povećanje posla i napretka u radu zaposlenika. Softver će omogućiti prikaz statističkih podataka obavljenog posla zaposlenika kako bi se mogao pratiti njihov napredak i uspješnost u radu. Ti podaci će također pomoći u donošenju odluka vezanih za potrebne promjene u organizaciji i rasporedu posla. Na primjer, u slučaju povećanja posla, statistički podaci će pomoći u odluci o dodatnom zapošljavanju ili drugačijoj raspodjeli posla između zaposlenika. |
| Način provjere | Korisnik softvera mora biti prijavljen kao administrator, gdje će imati opciju prikaz statističkih podataka, te potom odabire željeno razdoblje za koje želi promatrati statističke podatke. |
| Prioritet [1-5] | 4 |
| Izvor/Porijeklo | Vlasnica obrta |


### 3.1. Dinamika realizacije zahtjeva
U inicijalnoj verziji softvera biti će realizirani ovi zahtjevi:
* **FZ-1** - Sustav će omogućiti prijavu u sustav samo ovlaštenim korisnicima.
* **FZ-2** - Sustav će omogućiti uvid u postojeće zaposlenike samo administratoru. 
* **FZ-3** - Sustav će omogućiti dodavanje novog zaposlenika samo administratoru.
* **FZ-4** - Sustav će omogućiti uvid u evidenciju klijenata, uključujući pregled njihovih podataka i lokacije.
* **FZ-5** - Sustav će omogućiti dodavanje novog klijenta samo administratoru.
* **FZ-6** - Sustav će omogućiti evidenciju poslova u raspored samo administratoru. 
* **FZ-7** - Sustav će omogućiti pretragu slobodnih termina zaposlenika unutar rasporeda. 
* **FZ-8** - Sustav će omogućiti zaposleniku prijavu trajanja usluge čišćenja na nekoj lokaciji. 
* **FZ-11** - Sustav će omogućiti jedinstveni raspored za svakog zaposlenika. 
* **FZ-12** - Sustav će omogućiti automatizaciju sustava rasporeda.

U narednim verzijama planirana je realizacija ostalih zahtjeva:
* **FZ-9** - Sustav će omogućiti definiranje zadatka s određenim vremenskim razmakom. 
* **FZ-10** - Sustav će omogućiti izradu izvješća za određeno vremensko razdoblje. 
* **FZ-13** - Sustav će omogućiti automatizaciju sustava obavijesti. 
* **FZ-14** - Sustav će omogućiti prikaz statističkih podataka obavljenog posla zaposlenika.


## 4. NEFUNKCIONALNI ZAHTJEVI

### 4.1. Izgled softvera
**NFZ-1** – Sustav će omogućiti grafičko sučelje za vođenje interakcije s korisnikom. 

**NFZ-2** – Sustav će omogućiti korištenje palete boja te postavljanje odnosno definiranjem boje nad cijelim softverom.

### 4.2. Upotrebljivost softvera
**NFZ-3** – Sustav će omogućiti prilagodbu za osobe s poteškoćama (pomoć pri disleksiji).

**NFZ-4** – Sustav će omogućiti odabir jezika (hrvatski ili engleski).

### 4.3. Performanse softvera
**NFZ-5** – Sustav će omogućiti dostupnost svih 24 sata u danu. 

### 4.4. Izvođenje softvera i okruženje 
**NFZ-6** – Sustav će omogućiti rad na bilo kojem operacijskom sustavu, te će podržavati rad na mobitelu.

### 4.5. Sigurnost i privatnost
**NFZ-7** – Sustav će omogućiti samo administratoru pristup podacima klijenata i zaposlenika radi zaštite podataka temeljnoj na Općoj uredbi o zaštiti podataka.

### 4.6. Ostalo
**NFZ-8** – Sustav će omogućiti personaliziranu poruku dobrodošlice osobi koja ima rođendan, prilikom prijave u softver.


## 5. Skice zaslona

### 5.1. Skica zaslona za softversko rješenje _Valval_

[![sve_skupa drawio (1)](https://user-images.githubusercontent.com/126497323/226490548-55fbcb98-3b32-4052-91c9-7091576ce3be.png)](https://user-images.githubusercontent.com/126497323/226490548-55fbcb98-3b32-4052-91c9-7091576ce3be.png)



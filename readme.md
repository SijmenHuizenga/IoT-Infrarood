# IoT Infrarood

Deze infroarood opdracht hoort bij het vak Things tijdens het semester Internet of Things bij de Hogeschool Arnhem Nijmegen. Hierbij de uitwerkingen.

## Opdracht 1: Algemene vragen

In de volgende antwoorden zijn alle berekeningen weggelaten sinds alleen standaard natuurkundinge formulus zijn gebruikt.  

### 1. Hoe kan het dat jij infrarood licht niet kunt zien, terwijl de tv dat wel kan?
Licht en infrarood zijn beide [elektromagnetische straling](https://nl.wikipedia.org/wiki/Elektromagnetische_straling). Elektromagnetische straling kan (net als elk ander deeltje) zowel beschreven worden als golf of als deeltje volgens het [Wave–particle duality](https://en.wikipedia.org/wiki/Wave–particle_duality) concept. 

Het verschil tussen zichtbaar licht en infrarood licht is dat beide elektromagnetische stralingen een andere frequentie hebben op het [elektromagnetisch spectrum](https://nl.wikipedia.org/wiki/Elektromagnetisch_spectrum). Zichtbaar licht zit tussen de 394 en 789 THz en infrarood tussen de 0.3 en 394 THz.

Om elektromagnetische stralingen te deteteren heb je een materiaal nodig dat fotonen detecteert en omzet naar electrische signialen.  De [sensor die ik gebruik](http://docs-europe.electrocomponents.com/webdocs/1196/0900766b81196de9.pdf) voor infrarood detectie is een [photodetector](https://en.wikipedia.org/wiki/Photodetector) die het materiaal [mercury cadmium telluride](https://en.wikipedia.org/wiki/Mercury_cadmium_telluride#Infrared_detection) gebruikt voor deze detectie. Deze sensor werkt op frequenties van elektromagnetische straling rond de 315 THz (zie Fig. 11 in datasheet sensor). 

Het menselijk oog bevat heel andere materialen. In het [netvlies van je oog zitten](https://nl.wikipedia.org/wiki/Netvlies) namelijk [lichtgevoelige cellen](https://en.wikipedia.org/wiki/Photoreceptor_cell) die op een voor mij onbegrijpelijke manier electrische signalen afgeven bij bepaalde frequenties. De vier verschillende 'detectie cellen' in je oog kunnen [samen](https://upload.wikimedia.org/wikipedia/commons/9/94/1416_Color_Sensitivity.jpg) licht zien tussen de [484 en 668 THz](https://www.ncbi.nlm.nih.gov/pmc/articles/PMC1279132/). 

De reden dat wij mensen geen infrarood signiaal kunnen zien terwijl tv's dat wel kunnen is omdat het oog van een mens een ander spectrum van het electromagnetische straling opvangt dan de sensor van een tv. 

### 2. Zijn er dieren die infraroodlicht kunnen zien? Worden zij verblind als ze door je woonkamer lopen terwijl je de tv bedient?
Slangen kunnen electromagnetische straling met een golflengte tussen de [5 en 30 μm detecteren](https://www.ncbi.nlm.nih.gov/pmc/articles/PMC2693128/). Hiervoor gebruiken ze niet hun ogen, maar aparte sensortjes op de snuit. Hierdoor kunnen ze niet infrarood zien zoals wij dat zien, maar wel detecteren waar warme objecten zijn. Slangen kunnen met hun detectie in het frequentiegebied tussen de 10 en 59 THz geen afstandsbediening zien.

Van bepaalde vogels werd gedacht dat ze door infraroodzicht in het donker kunnen zien. In [dit onderzoek](http://jgp.rupress.org/content/jgp/23/6/709.full.pdf) wordt bewezen dat dit niet het geval is.

Sommigge vissen kunnen [wel elektromagnetische straling detecteren](https://link.springer.com/article/10.1007%2Fs00114-012-0980-7). Het gaat hierbij om het 'near-infrared spectrum' met golflengtus tussen de 780 en 920nm. [Een ander onderzoek](http://www.cell.com/current-biology/fulltext/S0960-9822(15)01246-4) beschrijft dat sommigge vissoorten elektromagnetische straling met golflengtes van 590 en 770nm. Komt er op neer dat er vissen zijn die frequenties tussen de 326 en 508 THz kunnen zien. Ook deze vissen zullen dus de tv afstandsbediening niet zien.

Onderstaande plaatje laat zien hoe alle bovengenoemde frequenties zich tot elkaar verhouden.
![elektromagnetische straling spectrum](./imgs/elektromagnetische%20straling%20spectrum.png)

Conclusie is dat dieren geen infraroodlicht kunnen zien en dus ook niet verblind worden met een afstandsbediening. Deze conclusie kan worden gecontroleerd door op youtube te zoeken naar "animal infrared remote control". Als het mogelijk zou zijn om dieren bang te maken met je afstandbediening dan zouden er duizenden filmpjes hiervan te vinden zijn. Dit is niet het geval, dus deze conclusie is correct.

### 3. Welke “huis, tuin en keuken”-manieren zijn er te kunnen zien of je infraroodled wel echt licht geeft?
Met een digitale camera. De digitale camera ziet die frequentie in tegenstelling tot mensen wel. 
![IR Led camera](https://images.techhive.com/images/article/2014/01/remote_sensor_580-100227154-orig.gif)

### 4. Er is in huis meer dan alleen je afstandsbediening die IR-licht uitstraalt. Wat nog meer bijvoorbeeld? En hoe kan het dat je tv daar niet af en toe per ongeluk op reageert?
Elektromagnetische straling [wordt uitgestraald](http://www.qrg.northwestern.edu/projects/vss/docs/thermal/3-what-makes-em-radiation.html) wanneer electronen binnen een atoom terugvalt in de orginele positie nadat het atoom energy heeft geabsorbeerd. Bij warme materie is dit process continu aan de gang waardoor deze straling uitzenden. Aleen materie van 0 kelvin straalt geen straling uit. Deze straling wordt ook wel [black-body radiation](https://en.wikipedia.org/wiki/Black-body_radiation) genoemd. Volgens [de wet van Planck](https://en.wikipedia.org/wiki/Planck%27s_law) is de frequentie waarin een materie black-body radiation uitzend afhankelijk van de temepratuur van de materie. 

Gebruik makend van een [online black body emission calculator](http://www.calctool.org/CALC/phys/p_thermo/wien) zijn de volgende waardes berekend:
```
20 graden celsius = golflengte 9884.93nm = frequentie 0.30THz
40 graden celsius = golflengte 9251.61nm = frequentie 0.32THz
```
Het komt er dus op neer dat alle objecten van huiskamertemepratuur infrarood uitstralen! Maar deze frequenties zijn veel te laag om opgepikt te worden door de televisie. 

In theorie zou een materie van 2776.85 graden celsius een golflengte van 950nm produceren. Als die bron ook nog het bij toeval het protocol van de tv-afstandsbediening weet uit te zenden dan zou in theorie de tv aangezet kunnen worden. Maar dit is praktisch ongelofelijk onmogelijk.

### 5. Hoe kan je tv onderscheid maken tussen verschillende knoppen?
Elke knop op je afstandsbediening zend een andere code uit. Dus het pattroon waarin het infrarood ledje knippert is blij elke knop uniek. De tv herkent dit pattroon en weet zo welke knop is ingedrukt. 

### 6. Hoe kan het dat je tv (over het algemeen) niet reageert op de afstandsbediening van je dvd-speler of die van de tv van je buurvrouw?
Het pattroon dat de tv en afstandsbediening afspreken bevat ook een gedeelte dat voor elke tv anders is. Dit is de aparaatcode. Door deze code elke keer mee te sturen wanneer de afstandsbediening een signiaal verzend kunnen alle ontvangende apparaten contorleren of deze code overeenkomt met de eigen code. Als dit het geval dan weet het ontvangende aparaat dat het signiaal van zijn afstandsbediening komt. 

### 7. Hoe kan het dat sommige knoppen als ze ingedrukt worden steeds effect blijven houden (zoals de volumeknoppen) en andere niet (bijvoorbeeld de “2”-knop)?
De afstandsbediening is dom in de zin dat hij bij een ingedrukte knop continu het afgesproken pattroon blijft knipperen. Dit geld voor alle knoppen. De ontvangende partij kan doen met deze informatie wat hij wil. Zo zal een tv die een aan/uit knop pattroon ontvangt zichzelf uitzetten en pas weer een aan/uit knop pattroon accepteren wanneer het een tijdje stil is. Bij de vollumeknop zal er een andere logica in de tv zitten die er voor zorgt dat zolang het pattroon binnen komt elke halve seconde het volume wordt verhoogd. 

## Opdracht 2: Opdracht 2Aansluiten en testen
*Sluit de IR-sensor aan en voeg een ledje (met voor jou zichtbaar licht) toe. Schrijf een testprogramma dat het ledje aan laat gaan zodra er een IR-signaal binnenkomt, en weer uit zodra er (na een korte wachttijd) weer een IR-signaal binnenkomt. Als je klaar bent, kun je het ledje met een willekeurige druk op de afstandsbediening toggelen.*

Schema:
![Opdracht 2 fritzing schema](opdracht-2/schema.png)

Werking:
![Opdracht 2 gif](opdracht-2/result.gif)

### Geeft de sensor “HIGH” bij het ontvangen van een signaal of juist bij afwezigheid ervan?
De sensor geeft een LOW signiaal wanneer er geen infraroodsigniaal wordt ontvangen.

### Wat is de minimale wachttijd die je nodig hebt om te voorkomen dat het ledje gaat knipperen? Wat betekent dat?
Een delay van 99 ms zorgt ervoor dat hij 'het doet' met mijn eigen afstandsbediening en die van school. Dit betekent dat als een knop is ingedrukt bij beide afstandsbedieningen er binnen 99 ms een infrarood signiaal wordt ontvangen. 

## Opdracht 3: Code opvangen met digitalRead
*Schrijf een (nieuw) programma dat in de loop steeds een digitalRead op de IR-poort uitvoert. Laat het programma de lengte van een puls meten en de lengte naar de serial schrijven zodra de puls afgelopen is. Doe dan hetzelfde voor de afwezigheid van de puls, en blijf dit herhalen. Je krijgt dan dus een patroon te zien van hoe lang de HIGH heeft geduurd, hoe lang de LOW heeft geduurd, etc. Doe je metingen in microseconden, want de pulsjes duren heel kort.*

*Test je programma door een aantal keer dezelfde knop op de afstandsbediening te gebruiken en bekijk of het in de Serial geprinte resultaat steeds (ongeveer) hetzelfde is.*

Schema:
![Opdracht 3 fritzing schema](opdracht-3/schema.png)

Werking:
![Opdracht 3 gif](TODO)

## Opdracht 4: Onderzoek hoe lang een print naar Serial duurt
*Schrijf een (nieuw) programma waarmee je, onafhankelijk van de IR-opdracht, meet hoe lang het eigenlijk gemiddeld duurt om een print naar Serial te doen. Let op: het “opstarten” van de Serial (Serial.begin()) kost wat tijd. Geef je programma die tijd (met een delay van bijvoorbeeld 250ms in de setup) en start daarna pas je metingen.*
*Herhaal (ook bij de volgende opgaven) alle metingen een aantal keer: noteer de gemiddelden en de standaarddeviatie, en doe je metingen niet in milliseconden, maar in microseconden. Houd er ook rekening mee dat een actie soms zo kort duurt dat het weinig nut heeft om een enkele uitvoer te meten: herhaal de actie dan bijvoorbeeld 1000 keer, en deel het resultaat door 1000. Doe dit meerdere keren om de standaarddeviatie te kunnen bepalen.*

Ik verwacht dat de langere tekstlengte, lage baudrate en de toevoeging van een newline allemaal de snelheid verlagen. Verder verwacht ik dat de sneleheid van printen rond de 1 a 2 milliseconde zal zitten.

Test 1 test alle combinaties van verschillende baudrate's, teskstlengtes en printmethods. Hierbij wordt voor de korte tekst de letter `a` gebruikt en voor de lange tekst de volgende letterreeks: `aHR0cHM6Ly93d3cueW91dHViZS5jb20vd2F0Y2g/dj1kUXc0dzlXZ1hjUQ==`. Na elke testronde wordt de serial geflusht zodat alle data verzonden is. Verder wordt bij elke `Serial.begin()` de uitvoertijd van deze methode gemeten. De resultaten zijn:

| method | textsize | baudrate | average over 100 calls in micros |
| ------ | -------- | -------- | ---------------------- |
| println | short | 2400   | 12495 |
| println | short | 9600   | 3120 |
| println | short | 57600  | 510 |
| println | short | 115200 | 255 |
| println | long  | 2400   | 258230 |
| println | long  | 9600   | 64480 |
| println | long  | 57600  | 10540 |
| println | long  | 115200 | 5270 |
| print   | short | 2400   | 4165 |
| print   | short | 9600   | 1040 |
| print   | short | 57600  | 170 |
| print   | short | 115200 | 85 |
| print   | long  | 2400   | 249900 |
| print   | long  | 9600   | 62400 |
| print   | long  | 57600  | 10200 |
| print   | long  | 115200 | 5100 |
`Average time Serail.begin() over 16 runs is 945 micros`

### Maakt het uit hoeveel tekst je naar Serial stuurt?
Gemiddeld duren alle tests met lange teksten 83.265 milliseconden en gemiddeld alle korte teksten 2.730 milliseconden. Conclusie is dus dat de hoeveelheid tekst wel degelijk invloed heeft op de snelheid van berichten.

Wat interesant is is dat de lange tekst van 60 karakters per karakter 1.38775 ms duurde, terwijl de korte tekst met 1 karakter 2.730 milliseconde duurde. Het is dus efficienter om langere berichten te sturen in plaats van meerdere korte berichten.

### Kost het schrijven van een newline extra tijd?
Gemiddeld duren alle tests met de print methode 4.1632 ms en gemiddeld alle println methodes 4.43625 ms. De toevoeging van println zorgt dus voor een iets langere berichttijd. 

### Maakt de baudrate uit?

De gemiddelde baud rates per berichten zijn als volgt:

| baud rate | average message time in ms |
| ---- | -------- |
| 2400 | 131.1975 |
| 9600 | 32.760 |	
| 57600 | 5.355 |	
| 115200  | 2.6775 |

Een hogere baud rate zorgt dus voor een sneller berichtoverdracht.

### Maakt het uit of je Serial venster open staat (hint: om de metingen te kunnen inzien kun je het EEPROM-geheugen en een extra programma gebruiken)?
Deze test wordt uitgevoerd in test2.cpp. Zie `opdracht-4/test2/readme.txt` om meer over de werking van de test te lezen. De test gebruikt println, 60 karakter berichten en baudrate 9600. De connected test kostte dit 64.480 ms per bericht. De nieuwe niet-verbonden test kostte 64.480 ms per bericht. Dit is ongelofelijk precies gelijk, maar ook na herhaling van de test blijft dit getal gelijk. Er is dus geen verschil of de serial monitor aan of uit staat.

### Hierboven staat dat het opstarten van de Serial tijd kost. Is dat eigenlijk wel waar, en hoeveel tijd is dat dan?
Ja, het opstarten van Serial kost tijd, maar niet zo veel tijd. Om precies te zijn 0.945 ms zoals te zien is in de resultaten van test1.

### Conclusie
Met de standaard baudrate van 9600 is de snelheid van een 1-karakter bericht 2.080 ms. Bij de langere berichten van 60 karakters is dit 63.44 ms. Ik had verwacht dat alle berichten gemiddeld rond de 2 ms zouden zitten. Dit blijkt dus wel een stuk hoger te zijn. Ik neem hiervan mee dat ik voortaan beter een hogere baudrate kan gebruiken.
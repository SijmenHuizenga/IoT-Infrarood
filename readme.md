#IoT Infrarood
Deze infroarood opdracht hoort bij het vak Things tijdens het semester Internet of Things bij de Hogeschool Arnhem Nijmegen. Hierbij de uitwerkingen.

## Opdracht 1: Algemene vragen

Alle berekeningen zijn in de volgende teksten weggelaten sinds alleen standaard natuurkundinge formulus zijn gebruikt.  

### 1. Hoe kan het dat jij infrarood licht niet kunt zien, terwijl de tv dat wel kan?
Licht en infrarood zijn beide [elektromagnetische straling](https://nl.wikipedia.org/wiki/Elektromagnetische_straling). 

Elektromagnetische straling kan (net als elk ander deeltje) zowel beschreven worden als golf of als deeltje volgens het [Wave–particle duality](https://en.wikipedia.org/wiki/Wave–particle_duality) concept. 

Het verschil tussen licht en infrarood is dat beide elektromagnetische stralingen een andere frequentie hebben op het [elektromagnetisch spectrum](https://nl.wikipedia.org/wiki/Elektromagnetisch_spectrum). Zichtbaar licht zit tussen de 394 en 789 THz en infrarood tussen de 0.3 en 394 THz.

Om elektromagnetische stralingen te deteteren heb je een materiaal nodig dat fotonen detecteert en omzet naar electrische signialen.  De [sensor die wij gebruiken](http://www.produktinfo.conrad.com/datenblaetter/150000-174999/171093-da-01-en-IR_EMPFAENGER_MODUL_TSOP_4833__VIS.pdf) voor infrarood detectie is een [photodetector](https://en.wikipedia.org/wiki/Photodetector) die het materiaal [mercury cadmium telluride](https://en.wikipedia.org/wiki/Mercury_cadmium_telluride#Infrared_detection) gebruikt voor deze detectie. Deze sensor werkt op frequenties van elektromagnetische straling rond de 315 THz (zie Fig. 10 in datasheet sensor). 

Het menselijk oog bevat heel andere materialen. In het [netvlies van je oog zitten](https://nl.wikipedia.org/wiki/Netvlies) namelijk [lichtgevoelige cellen](https://en.wikipedia.org/wiki/Photoreceptor_cell) die op een voor mij onbegrijpelijke manier electrische signalen afgeven bij bepaalde frequenties. De vier verschillende 'detectie cellen' in je oog kunnen [samen](https://upload.wikimedia.org/wikipedia/commons/9/94/1416_Color_Sensitivity.jpg) licht zien tussen de [484 en 668 THz](https://www.ncbi.nlm.nih.gov/pmc/articles/PMC1279132/). 

De reden dat wij mensen geen infrarood signiaal kunnen zien terwijl tv's dat wel kunnen is omdat het oog van een mens een ander spectrum van het electromagnetische straling opvangt dan de sensor van een tv. 

### 2. Zijn er dieren die infraroodlicht kunnen zien? Worden zij verblind als ze door je woonkamer lopen terwijl je de tv bedient?
Slangen kunnen electromagnetische straling met een golflengte tussen de [5 en 30 μm detecteren](https://www.ncbi.nlm.nih.gov/pmc/articles/PMC2693128/). Hiervoor gebruiken ze niet hun ogen, maar aparte sensortjes op de snuit. Hierdoor kunnen ze niet infrarood zien zoals wij dat zien, maar wel detecteren waar warme objecten zijn. Slangen kunnen met hun detectie in het frequentiegebied tussen de 10 en 59 THz geen afstandsbediening zien.

Van bepaalde vogels werd gedacht dat ze door infraroodzicht in het donker kunnen zien. In [dit onderzoek](http://jgp.rupress.org/content/jgp/23/6/709.full.pdf) wordt bewezen dat dit niet het geval is.

Sommigge vissen kunnen [wel elektromagnetische straling detecteren](https://link.springer.com/article/10.1007%2Fs00114-012-0980-7). Het gaat hierbij om het 'near-infrared spectrum' met golflengtus tussen de 780 en 920nm. [Een ander onderzoek](http://www.cell.com/current-biology/fulltext/S0960-9822(15)01246-4) beschrijft dat sommigge vissoorten elektromagnetische straling met golflengtes van 590 en 770nm. Komt er op neer dat er vissen zijn die frequenties tussen de 326 en 508 THz kunnen zien. Ook deze vissen zullen dus de tv afstandsbediening niet zien.

Onderstaande plaatje laat zien hoe alle bovengenoemde frequenties zich tot elkaar verhouden.
![elektromagnetische straling spectrum](./imgs/elektromagnetische%20straling%20spectrum.png)

Conclusie is dat dieren geen infraroodlicht kunnen zien en dus ook niet verblind worden met een afstandsbediening. Deze conclusie kan worden gecontroleerd door op youtube te zoeken naar "animal infrared remote control". Als het mogelijk zou zijn om dieren bang te maken met je afstandbediening dan zouden er duizenden filmpjes hiervan te vinden zijn.

### 3. Welke “huis, tuin en keuken”-manieren zijn er te kunnen zien of je infraroodled wel echt licht geeft?
### 4. Er is in huis meer dan alleen je afstandsbediening die IR-licht uitstraalt. Wat nog meer bijvoorbeeld? En hoe kan het dat je tv daar niet af en toe per ongeluk op reageert?
### 5. Hoe kan je tv onderscheid maken tussen verschillende knoppen?
### 6. Hoe kan het dat je tv (over het algemeen) niet reageert op de afstandsbediening van je dvd-speler of die van de tv van je buurvrouw?
### 7. Hoe kan het dat sommige knoppen als ze ingedrukt worden steeds effect blijven houden (zoals de volumeknoppen) en andere niet (bijvoorbeeld de “2”-knop)?
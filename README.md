Tema ovog projektnog zadatka bila je upravljanje pristupom lokaciji. Drugim riječima, ovaj projektni zadatak usmjeren je na razvoj sustava kontrole pristupa koji omogućuje pristup lokaciji putem PIN-a unesenog preko tipkovnice. Nakon uspješno unesenog PIN-a, simulira se stanje ulaza ispisom odgovarajuće poruke na LCD-u te se pale odgovarajuće boje RGB LED. Otvaranje i zatvaranje ulaza simulira se servo motorom.

Zahtjevi na sklopovlje: 
•	Arduino ploča (Croduino): Služi kao središnja procesna jedinica za kontrolu ostalih hardverskih komponenti i izvođenje programirane softverske logike.
•	I2C adapter + LCD 16x2: Koristi se za prikazivanje poruka, statusa i povratnih informacija korisniku.
•	Matrix membranska tipkovnica: Omogućuje korisnicima unos njihovog PIN-a.
•	RGB LED: Indicira status sustava različitim bojama (npr. zeleno za odobren pristup, crveno za odbijen pristup).
•	Servo motor: Simulira mehanizam zaključavanja i otključavanja vrata.

Zahtjevi za softverom i bibliotekama: 
•	Arduino IDE: Softversko razvojno okruženje za programiranje Arduino ploče.
•	LiquidCrystal_I2C biblioteka: Za sučeljavanje s LCD-om putem I2C protokola.
•	Servo biblioteka: Za kontrolu pokreta servo motora.
•	Keypad biblioteka: Za hvatanje unosa s matrične membranske tipkovnice.

Funkcionalnosti sustava: 
1.	Unos PIN-a: Korisnik unosi PIN preko tipkovnice.
2.	Validacija: Sustav provjerava uneseni PIN s predefiniranim skupom važećih PIN-ova.
3.	Povratne informacije:
•	Povratne informacije na LCD-u: LCD prikazuje poruke poput "Unesite PIN", "Pristup odobren" ili "Pristup odbijen".
•	Povratne informacije LED diode: RGB LED svijetli u specifičnim bojama kako bi vizualno indicirala status sustava (zeleno za uspjeh, crveno za grešku).
4.	Simulacija mehanizma vrata: Nakon uspješne validacije PIN-a, aktivira se servo motor koji simulira otvaranje vrata; vraća se u početni položaj za zaključavanje kada je pristup zatvoren ili odbijen.

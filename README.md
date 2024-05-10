# Projekt_2

**Cílem našeho projektu je vytvořit _levný_ zabezpečovací systém, pro potřeby koncového zákazníka(byt/dům).**

**Tento projekt jsme si vybrali, protože zabezpečovací systém je něco co by měla mít každá domácnost a přijde nám oběma že v tomto směru velké množství zaostává.**

Projekt zpracovali **_Dominik Vicenec_** a **_Vojtěch Havlík_**.

## ESP - Dominik
### Klávesnice
Píše se zde kód pro zakódování/odkódování k alarmu --- Kód : 15AD.
### Displej
Bude se zde ukazovat zda je kód zadán dobře či špatně a při zadávání se zde ukazují pouze ****.
### Diody
Jsou zde dvě diody Zelená a Červená.

**Zelená:** Svítí pouze pokud je odkódováno.

**Červená:** Svítí pouze pokud je zakódováno.
### Společná komunikace
ESP bude odesílat hodnotu 0 nebo 1 druhému ESP a tím bude informovat jestli je odkódováno nebo zakódováno.
## ESP - Vojtěch
### Čidlo
Snímá vzdálenost mezi objektem a daným čidlem.
### Pípák
Pokud se data shodují a bylo odkódováno tak se nic neděje, ale v případě že se data neshodují pípák se spustí a začne pípat dokud se neodkóduje.
### Společná komunikace
ESP přijme informace odeslané z prvního ESP a vyhodnotí situaci.
## SMS/Oznámení
Pokud se dveře snímané čidlem otevřou, bude vyslána SMS do mobilního zařízení uživatele/ů.

V případě že mají aplikaci VoDo tak se oznámení vyšle do aplikace
## Mobilní aplikace 
Uživatel se bude muset nejdříve přihlásit a potom podle oprávnění bude mít přístup do různých sekcí.
       
**Sekce:**

1. Záznam z kamer
2. Nastavení
3. Všechna zařízení
4. Log
5. Cloud/server
      
**Sekce Záznam z kamer:** Zde jsou uvedeny kamerové záznamy které se v této sekci ukládají dva dny potom se kompletně přesunou na cloud/server
                          Také je zde možnost zapnout automatizaci kamer, kde se aktivuje světlo při pohybu přes noc od zadaného času a potom se vypne.
              
**Sekce Nastavení:** Můžete zde odebrat kamery z vašeho záznamového archu, přidat kamery, vypnout oznámení aplikace, nebo naopak zvýšit prioritu oznámení.Tato sekce má dvojí nastvaení a to je odlišné pro uživatele, administrátoři vidí cele nastavení a mohou měnit cokoliv, ale uživatel zde může změnit jenom své názvy zařízení, své oznámení a vzhled aplikace.

**Sekce Všechna zařízení:** Naše aplikace je schopna pojmout i zařízení které se připojí pomocí bluetooth a zobrazí je v této sekci s ostatními zařízeními např. kamery.

**Sekce Log:** Zaznamenává každé přihlášební do aplikace z důvodu bezpečnosti a případné manipulace administrátory.

**Sekce Cloud/Server:** Zde se posílají všechny záznamy z kamer.
Mají zde přístup jen administrátoři.
Záznamy se po uplynuté době jednoho měsíce samy vymažou, pokud administrátor neoznačí záznam a ten se nesmaže.
### Uživatelé
**Uživatel:** Uživatel má přístup do sekce kamerovových záznamů, sekce všechna zařízení a do omezené sekce nastavení. 
              Bude dostávat ozámení v případě otevření dveří a výsledku odódování.

              

**Administrátor:** Bude mít možnost přidat nového Uživatele/Administrítora.
                   Bude mít možnost přidat nové zařiízení.
                   Má přístup do všech sekcí aplikace a může v ní měnit prakticky cokliv.

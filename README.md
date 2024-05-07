# Projekt_2

**Cílem našeho projektu je vytvořit _levný_ zabezpečovací systém, pro potřeby koncového zákazníka(byt/dům)**.
Tento projekt jsme si vybrali, protože zabezpečovací systém je něco co by měla mít každá domácnost a přijde nám oběma že v tomto směru velké množství zaostává.

Projekt zpracovali **_Dominik Vicenec_** a **_Vojtěch Havlík_**.

## ESP - Dominik
### Klávesnice
Píše se zde kód pro zakódování/odkódování k alarmu --- Kód : 15AD.
### Displej
Bude se zde ukazovat zda je kód zadán dobře či špatně a při zadávání se zde ukazují pouze ****.
### Diody
Jsou zde dvě diody Zelená a Červená.
Zelená: Svítí pouze pokud je odkódováno.
Červená: Svítí pouze pokud je zakódováno.
### Společná komunikace
ESP bude odesílat hodnotu 0 nebo 1 druhému ESP a tím bude informovat jestli je odkódováno nebo zakódováno.
## ESP - Vojtěch
### Čidlo
Snímá vzdálenost mezi objektem a daným čidlem.
### Pípák
Pokud se data shodují a bylo odkódováno tak se nic neděje, ale v případě že se data neshodují pípák se spustí a začne pípat dokud se neodkóduje.
### Společná komunikace
ESP přijme informace odeslané z prvního ESP a vyhodnotí situaci.
## SMS
Pokud se dveře snímané čidlem otevřou, bude vyslána SMS do mobilního zařízení uživatele/ů.
## Mobilní aplikace 
Uživatel se bude muset nejdříve přihlásit a potom podle oprávnění bude mít přístup do různých sekcí.
### Uživatelé
Uživatel: Je mu udělen přístup pouze ke kamerovým záznamům 
Administrátor: Bude mít možnost přidat nového Uživatele/Administrítora 
               Bude mít možnost přidat nové zařiízení

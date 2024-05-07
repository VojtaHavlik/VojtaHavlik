# Projekt_2

**Cílem našeho projektu je vytvořit _levný_ zabezpečovací systém, pro potřeby koncového zákazníka(byt/dům)**.

Projekt zpracovali **_Dominik Vicenec_** a **_Vojtěch Havlík_**.

## ESP - Dominik
### Klávesnice
Píše se zde kód pro zakódování/odkódování k alarmu --- Kód : 15AD.
### Displej
Bude se zde ukazovat zda je kód zadán dobře či špatně a při zadávání se zde ukazují pouze ****.
### Diody
Jsou zde dvě diody Zelená a Červená
Zelená: Svítí pouze pokud je odkódováno 
Červená: Svítí pouze pokud je zakódováno 




## ESP - Vojtěch
### Čidlo
Snímá vzdálenost mezi objektem a daným čidlem.
### Pípák
Přijme informace odeslané z ESP - D a vyhodnotí situaci.
Pokud se data shodují a bylo odkódováno tak se nic neděje, ale v případě že se data neshodují pípák se spustí a začne pípat dokud se neodkóduje.

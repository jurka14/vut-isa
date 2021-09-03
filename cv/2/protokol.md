# ISA 2020: Odpovědní arch pro cvičení č. 2

## Vzdálený terminál - SSH, Secure Shell

### (2.) Bezpečné připojení na vzdálený počítač bez autentizačních klíčů

*Verze OpenSSH*: 7.4

*Vybraná podporovaná šifra*: chacha20, autentizační mechanismus HMAC je poly1305

*Co lze zjistit o obsahu komunikace?*: obsah komunikace je šifrovaný, nelze nic vyčíst bez dekrypce.

### (3.) Vytvoření veřejného a privátního klíče

*Jak se liší práva mezi souborem s privátním a veřejným klíčem?*: Veřejný klíč je přístupný ke čtení skupině i veřejně, zatímco privátní klíč může číst pouze vlastník.

### (4.) Distribuce klíčů

*Jaká hesla bylo nutné zadat při kopírovaní klíčů?*: bylo nutné zadat hesla uživatelů stroje

*Jaká hesla bylo nutné zadat při opětovném přihlášení?*: bylo nutné zadat heslo zadané v implicitním klíči, v případě uživatele root nebylo třeba heslo zadávat

### (6.) Pohodlné opakované použití klíče

*Museli jste znovu zadávat heslo?*: nemuseli

## Zabezpečení transportní vrstvy - TLS, Transport Layer Security

### (1.) Nezabezpečený přenos dat

*Je možné přečíst obsah komunikace?*: ano

### (2.) Přenos dat zabezpečený TLS

*Je možné přečíst obsah komunikace?*: ne

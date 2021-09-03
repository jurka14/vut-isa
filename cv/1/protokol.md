# ISA 2020: Odpovědní arch pro cvičení č. 1

## Zjišťování konfigurace

### (1.) Rozhraní enp0s3

*MAC adresa*: 08:00:27:9e:b5:b9

*IPv4 adresa*: 10.0.2.15

*Délka prefixu*: 24

*Adresa síťe*: 10.0.2.0

*Broadcastová adresa*: 10.0.2.255

### (2.) Výchozí brána

*MAC adresa*: 52:54:00:12:35:02

*IPv4 adresa*: 10.0.2.2

### (4.) DNS servery

*Soubor*: /etc/resolv.conf

*DNS servery*: nameserver 192.168.31.1

### (5.) Ping na výchozí bránu

*Soubor*: /etc/hosts

*Úprava*:<br> přidání záznamu pro překlad hostname na adresu (přidání řádku do souboru) pomocí příkazu
''sudo sed -i '$ a 10.0.2.2    gw' hosts''

### (6.) TCP spojení

*Záznam + popis*: <br>
State &nbsp;&nbsp;&nbsp;Recv-Q &nbsp;&nbsp;&nbsp;Send-Q &nbsp;&nbsp;&nbsp;Local Address:Port &nbsp;&nbsp;&nbsp;Peer Address:Port                
ESTAB &nbsp;0 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;10.0.2.15:53198 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;35.161.199.137:https

popis sloupců: <br>
1) stav spojení
2) počet bajtů nezkopírovaných uživ. programem připojeným k tomuto socketu
3) počet bajtů nepotvrzených vzdáleným hostem
4) lokální adresa s portem na socketu
5) adresa s portem vzdáleného hosta připojeného na socket 

### (8.) NetworkManager události

*Příkaz*: sudo journalctl -u NetworkManager

### (9.) Chybová hláška sudo

*Příkaz*: /bin/wireshark

*Chybová hláška*: command not allowed

## Wireshark

### (1.) Capture filter

*Capture filter*: port 80

### (2.) Zachycená HTTP komunikace

Komu patří nalezené IPv4 adresy a MAC adresy? 
Vypisovali jste již některé z nich?
Proč tomu tak je? <br>
IPv4 adresy patří koncovým zařízením, tj. klientu a serveru, mezi kterými probíhá komunikace. MAC adresy však patří rozhraní klienta a výchozí brány. Je tomu tak, protože klient v rámci svojí sítě podle IPv4 adresy serveru nepozná, kam by měl packet poslat. Pošle ho tedy na výchozí bránu (do další sítě), kde se stejná otázka směrování řeší znovu.

#### Požadavek HTTP

Cílová MAC adresa

  - *Adresa*: 52:54:00:12:35:02
  - *Role zařízení*: výchozí brána

Cílová IP adresa

  - *Adresa*: 147.229.177.179
  - *Role zařízení*: server na kterém sídlí doména cphoto.fit.vutbr.cz

Zdrojová MAC adresa

  - *Adresa*: 08:00:27:9e:b5:b9
  - *Role zařízení*: rozhraní enp0s3

Zdrojová IP adresa

  - *Adresa*: 10.0.2.15
  - *Role zařízení*: rozhraní enp0s3


#### Odpověď HTTP

Cílová MAC adresa

  - *Adresa*: 08:00:27:9e:b5:b9
  - *Role zařízení*: rozhraní enp0s3

Cílová IP adresa

  - *Adresa*: 10.0.2.15
  - *Role zařízení*: rozhraní enp0s3

Zdrojová MAC adresa

  - *Adresa*: 52:54:00:12:35:02
  - *Role zařízení*: výchozí brána

Zdrojová IP adresa

  - *Adresa*: 147.229.177.179
  - *Role zařízení*: server na kterém sídlí doména cphoto.fit.vutbr.cz

### (3.) Zachycená ARP komunikace

*Display filter*: arp or icmp

### (6.) Follow TCP stream

Jaký je formát zobrazených dat funkcí *Follow TCP stream*, slovně popište
význam funkce *Follow TCP stream*: <br> Data jsou zobrazenna ve zvoleném formátu, implicitně ve formě textu ASCII znaků. Funkce zobrazuje posloupně obsah samotných TCP packetů, které si po celou dobu komunikace posílaly dvě strany.
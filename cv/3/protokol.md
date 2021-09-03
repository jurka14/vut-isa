# ISA 2020: Odpovědní arch pro cvičení č. 3

## (1.) Resolving DNS dotazů

Jaké jsou autoritativní DNS servery pro doménu *vutbr.cz*?\
rhino.cis.vutbr.cz\
pipit.cis.vutbr.cz\
*Display filter* pro zobrazení pouze DNS provozu: dns

Počet zachycených paketů souvisejících s vyhledáním NS pro doménu *vutbr.cz*: 2

Provedený DNS dotaz (vyberte správnou variantu): **rekurzivní**

Podle čeho jste zjistili zakroužkovaný typ DNS dotazu v zachyceném paketu? Podle query flagu (recursion desired)

Cílová IP adresa paketu s DNS dotazem: 192.168.31.1

Jakému zařízení náleží zapsaná IP adresa? výchozí dns server, router, na kterém je pc připojený


## (2.) Zabezpečení a resolving pomocí DNS over HTTPS

Dokážete zjistit ze zachyceného DNS provozu, jaké domény jste předtím navštívili? Proč? Nedokážu, protože dns komunikace probíhá přes šifrovaný https kanál.
  \
  \
  \
*Display filter* pro zobrazení pouze TLS provozu: tls

Jeden řádek z položky *Answers* z libovolné DoH odpovědi:  
www.facebook.com: type CNAME, class IN, cname star-mini.c10r.facebook.com  \
 \
IP adresa, na kterou směřovaly pakety s DoH dotazem: 193.17.47.1

Doménové jméno patřící k doplněné IP adrese: odvr.nic.cz


## (3.) Zabezpečení a resolving pomocí DNS over TLS

*Display filter* pro zobrazení pouze provozu využívající TCP port 853: tcp.port == 853

*Display filter* pro zobrazení pouze provozu využívající TCP nebo UDP port 53: tcp.port == 53 || udp.port == 53

Služba běžící nad portem 53: DNS

Počet zachycených paketů se zdrojovým nebo cílovým portem 53: 0


## (4.) Blokování reklam a další



Jaký rozdíl jste zpozorovali na webu *idnes.cz* při jeho načtení s aktivním nástrojem *pi-hole*? Na webu nejsou vidět žádné reklamy.

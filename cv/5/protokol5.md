## Laboratorní protokol cv. 5

Jméno: Vojtěch Jurka <br>
Datum: 07.12.2020 <br>
Login: xjurka08 <br>

IP adresa rozhraní enp0s8 **cv5-master**: 192.168.56.101 <br>
IP adresa rozhraní enp0s8 **cv5-provider**: 192.168.56.102

### Úkol 1, Netflow
1. Uveďte TOP 10 IP adres podle počtu přenesených bytů

    1. 136.2.58.138
    2. 185.2.119.236
    3. 136.2.24.237
    4. 136.2.24.236
    5. 136.2.24.239
    6. 136.2.24.238
    7. 122.153.220.92
    8. 42.208.57.175
    9. 124.106.137.204
    10. 36.122.83.223

<br>

2. Uveďte 3 datové protokoly s nejvyšším objemem přenesených bytů

    1. TCP
    2. UDP
    3. GRE

<br>

### Úkol 2, Syslog
1. Uveďte pravidlo pro přeposílání všech syslog zpráv na **cv5-master**:

    \*.*    @192.168.56.101:514

2. Uveďte pravidlo, které omezí zprávy přeposílané z **cv5-provider** na zprávy týkající se pouze autentizace:

    authpriv.info    @192.168.56.101:514

3. Jakou zprávu odeslal **cv5-provider** při neúspěšném přihlášení? Stačí uvést pouze zkráceně:

    [3882]: pam_unix(sshd:auth): authentication failure; logname= uid=0 euid=0 tty=ssh ruser= rhost=192.168.56.101  user=user

### Úkol 3, Icinga
1. Jaký je časový interval mezi kontrolami pro HTTP službu?

    10 minut

2. Uveďte konfiguraci komunity pro SNMP ze stroje **cv5-provider**

    rocommunity    xjurka08    192.168.56.0/24

3. Uveďte množství volné paměti zaslané ve zprávě SNMP

    372724 kB
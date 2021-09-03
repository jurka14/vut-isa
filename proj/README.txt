Rozšíření SNMP agenta - ISA projekt 2020
Autor: Vojtěch Jurka (xjurka08)

Příklad spuštění: 

- po přeložení zdrojového kódu (příkazem make proj) nám vznikne soubor představující sdílený objekt rozšiřující SNMP agenta, který je třeba dynamicky načíst

- v jednom terminále spustíme snmpd server: sudo snmpd -f -L -DnstAgentPluginObject,dlmod

- ve druhém terminále načteme objekt:
 - snmpset localhost UCD-DLMOD-MIB::dlmodStatus.1 i create
 - snmpset localhost UCD-DLMOD-MIB::dlmodName.1 s "objects" UCD-DLMOD-MIB::dlmodPath.1 s "/cesta/k/objects.so"
 - snmpset localhost UCD-DLMOD-MIB::dlmodStatus.1 i load

- poté můžeme pomocí utility snmpget pracovat s daty ve sdíleném modulu
 - (příklad čtení dat z integer objektu) snmpget localhost MY-MIB::integer.0



Seznam odevzdaných souborů:

 - Makefile
 - MY-MIB.txt
 - README.txt
 - objects.c
 - objects.h
 - manual.pdf
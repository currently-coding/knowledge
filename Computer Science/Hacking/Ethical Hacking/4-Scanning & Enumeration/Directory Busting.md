# Dirbuster
```bash
dirbuster&
```
- http://192.168.241.136:80/
- select file: /usr/share/dirbuster/wordlists/<chosen list\>
- select 'go faster' for threading

## Tries to find existing directorys on website using brute-force attacks

# Dirb
```bash
dirb http://192.168.241.139
```

# FFUF
```bash
ffuf -w /usr/share/wordlists/dirbuster/directory-list-2.3-medium.txt:FUZZ -u http://192.168.241.139/FUZZ
```

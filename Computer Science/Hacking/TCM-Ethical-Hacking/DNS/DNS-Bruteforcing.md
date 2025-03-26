# DNS Bruteforcing
## Bruteforcing with nmap
```bash
nmap -p53 --script dns-brute --script-args=./usr/share/seclists/SecLists-master/Discovery/DNS/dns-Jhaddix.txt,dns-brute.domain=zonetransfer.me,dns-brute.threads=10
```

## Bruteforcing with dnsmap
```bash
dnsmap <domain> -w <wordlist>
```
```bash
dnsmap zonetransfer.me -w /usr/share/seclists/SecLists-master/Discovery/DNS/dns-Jhaddix.txt
```
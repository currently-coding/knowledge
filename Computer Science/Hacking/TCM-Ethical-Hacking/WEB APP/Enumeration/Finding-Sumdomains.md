# Finding Sumdomains


## crt.sh

### https://crt.sh

## Subfinder
```bash
subfinder -d tesla.com
# -d = Domain
```
<details>

<summary>Important flags</summary>

- -d = Domain
- -dL - Domain List(File with domains)
- -d = source
- -v = verbose
- -silent = list only subdomains in output
- -timeout = secodns before timing out(Default:30)

</details>

## AMASS
```bash
amass enum -d tesla.com
```

## Finding Alive Domains

```bash
cat <url>/recon/subdomains.txt | sort -u | httprobe -p https:433 | sed 's/https:\?\/\///' | tr -d ':443'
# sort -u = delete non unique results
# httprobe... = find alive subdomains
# sed... = get rid of 'http:' and ':80'
```
## Interesting Pages
- test
- dev
- stag (staging)
- admin
- etc.
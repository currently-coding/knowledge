Domain: tesla.com
Subdomains:
- dev.tesla.com
- shop.tesla.com
- ...


\*.website.com

## Finding Subdomains

- Sublist3r
```bash
sublist3r -d <site> -t 100
```
        -d -> Domain
        -t -> Threads (as high as possible for max speed)

- https://crt.sh

- Google:
```
site:<website> -www
```
excludes www.tesla.com
limits to \*.tesla.com
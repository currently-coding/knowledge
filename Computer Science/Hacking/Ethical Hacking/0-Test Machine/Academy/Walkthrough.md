- nmap scan [[0-Test Machine/Academy/Notes|Notes]]
- FTP open
- anonymous login
```bash
ftp 192.168.241.139
user:anonymous
passwd:anonymous
```
- get notes.txt
```bash
get note.txt
```
- check hash from notes.txt
-> Most likely MD5 hash(windows)
### Crack MD5 hash using hashcat
[[Hashcracking]]

- Dirbuster to find directorys
-> /academy
-> /phpmyadmin

- LOGIN to academy via found passwd-user data from FTP

#### upload reverse shell via photo upload on website

- connect to NFS
```bash
showmount -e 192.168.241.140
mkdir /mnt/dev
mount -t nfs 192.168.241.140:/srv/nfs /mnt/dev
```
![[Pasted image 20230720175306.png]]
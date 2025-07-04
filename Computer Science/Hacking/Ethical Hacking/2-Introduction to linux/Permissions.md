- R: Read
- W: Write
- X: Execute

#### Change permissions
```bash
chmod 777 myfile.txt
ls -la
-rwxr-x--- 1 user group 4096 May 10 12:34 myfile.txt
```

>**-rwxr-x---** 
- permissions

>**1** 
- Number of hardlinks to the file

>**user**
- File owner

>**4096**
- File size

>**May 10 12:34**
- Date of last modification

>**myfile.txt**
- File name

>**chmod** ***741*** **myfile.txt**
- 7 root user
- 4 file owner
- 1 rest


 - x = 1
 - w = 2
 - r = 4
 => 7 = r w x

e.g.
- 777 = rwx rwx rwx
- 700 = rwx --- ---
- 770 = rwx rwx ---
- 744 = rwx r-- r--
- 711 = rwx --x --x
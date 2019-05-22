# FTP

FTP server [RFC](https://www.rfc-editor.org/rfc-index.html) compliant.

## Requirements

- [A Linux distribution](https://en.wikipedia.org/wiki/Linux_distribution) 
- [Make](https://www.gnu.org/software/make/)
- [GCC](https://gcc.gnu.org/)

## Execution

```
make
./server [PORT] [DIR_PATH]
```

PORT is the port number on which the server socket listens <br/>
DIR_PATH is the path to the home directory for the Anonymous user


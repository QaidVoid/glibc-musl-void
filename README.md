## RUN GLIBC binary on Void Linux (MUSL)
### Make glibc rootdir
```sh
sudo mkdir /glibc
sudo env XBPS_ARCH=x86_64 xbps-install --repository=http://alpha.de.repo.voidlinux.org/current -r /glibc -S base-voidstrap
```

### Create glibc executable
```sh
gcc -s -o glibc glibc.c
sudo cp glibc /usr/bin
sudo chown root:root /usr/bin/glibc
sudo chmod +sx /usr/bin/glibc
```

### Install glibc package
```
glibc
sudo xbps-install pkg
```

### Run glibc binary from host
```
glibc binary
```

### SOURCE
https://www.dropbox.com/s/4nbh5f1xva84h1m/Contenedor_Void.pdf

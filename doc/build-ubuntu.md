## install dependecies
```
sudo apt-get -y install build-essential git cmake libboost-all-dev libgmp-dev libcryptopp-dev libjsoncpp-dev
```

## compile

from project root

```
mkdir build;
cd build;
cmake .. -DENABLE_TEST=1
make 
```


##run unit tests
```
./ethkey-tests
```


##install library
```
make install
```

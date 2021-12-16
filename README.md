
This is an example of using NASOQ and LBL out of source tree. 
The code downloads nasoq as a module and builds examples. 
You can alternatively define `NASOQ_ROOT` as where nasoq is installed.


You need to first clone NASOQ where you like (`NASOQ_ROOT`)
```
git clone --recursive  https://github.com/cheshmi/nasoq-example.git
```
Then, modify CMake and add necessary options based on the NASOQ guide.
In the current setting, CMake installs all dependencies automatically.

And finally you can build project by emitting following commands:
```bash
mkdir build
cd build
cmake  -DCMAKE_BUILD_TYPE=Release ..
make
```



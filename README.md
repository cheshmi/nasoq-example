
This is an example of using NASOQ and LBL out of source tree 
thus it needs nasoq repo to be cloned somewhere that is defined by 
`NASOQ_ROOT` cmake option. If `NASOQ_ROOT` is not defined, the current 
directory will be used, i.e., `nasoq`. 

You need to first clone NASOQ where you like (`NASOQ_ROOT`)
```
git clone --recursive  https://github.com/cheshmi/nasoq-example.git
```
Then, modify CMake and add necessary options based on the NASOQ guide. 

And finally you can build project by emitting following commands:
```bash
mkdir build
cd build
cmake  -DNASOQ_ROOT=path/ended/with/nasoq/  -DCMAKE_BUILD_TYPE=Release ..
make
```




This is an example of using NASOQ and LBL out of source tree. For details, please see [NASOQ documentation](https://nasoq.github.io/docs/getting-started-nasoq/#c-api-examples).
The code downloads NASOQ as a module and builds the NASOQ/LBL examples. 
You can alternatively define `NASOQ_ROOT` as where nasoq is installed.

## Build
```bash
git clone --recursive  https://github.com/cheshmi/nasoq-example.git
cd nasoq-example
cmake -DCMAKE_BUILD_TYPE=Release  -S . -B build
cmake --build build --config Release -j 6 
```

**important:** Make sure you have `--recursive` when you clone the repository. 

Before building the code, you can modify CMake and add necessary options based on the [NASOQ guide](https://nasoq.github.io/docs/getting-started-nasoq/#installation).
In the current setting, CMake installs all dependencies automatically.




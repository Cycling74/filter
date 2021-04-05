# Filter
![CI](https://github.com/Cycling74/filter/workflows/CI/badge.svg)


Filtering Toolbox for audio, visuals, and control data in Max.

To get started, use the Max **Package Manager** or download from CI.

## Getting Started

After installing, open the menu item **Extras > Filter Overview** to be guided through the package.

## Building

If you wish to build the software yourself from source-code, you must first have [CMake](https://cmake.org/download/) and Xcode 7/8 or Visual Studio 2017 installed.

0. Clone the code from Github, or download a zip and unpack it into a folder. You will need to clone the submodules as well:

    ```
    git clone --recurse-submodules -j8 git@github.com:Cycling74/filter.git
    ```
1. In the Terminal or Console app of your choice, change directories (cd) into the folder you created in step 0.
2. `mkdir build` to create a folder with your various build files
3. `cd build` to put yourself into that folder
4. Now you can generate the projects for your choosen build environment:

### Mac 

Run `cmake -G Xcode ..` and then run `cmake --build .` or open the Xcode project from this "build" folder and use the GUI.


### Windows

If you are using Visual Studio, You can run `cmake --help` to get a list of the options available.  Assuming some version of Visual Studio 2015, the commands to generate the projects will look like this:

* `cmake -G "Visual Studio 16 2019" ..`

Having generated the projects, you can now build by opening the .sln file in the build folder with the Visual Studio app (just double-click the .sln file) or you can build on the command line like this:

`cmake --build . --config Release`


### Unit Testing

On the command like you can run all unit tests using Cmake:

* on debug builds: `ctest -C Debug .`
* on release builds: `ctest -C Release .`

Or you can run an individual test, which is simply a command line program:

* `cd ..`
* `cd tests`
* mac example: `./test_dcblocker_tilde -s`
* win example: `test_dcblocker_tilde.exe -s`

Or run them your IDE's debugger.


## Contributors / Acknowledgements

See the [GitHub Contributor Graph](https://github.com/Cycling74/filter/graphs/contributors) 

## Support

For support, please use the issue tracker at:
https://github.com/Cycling74/filter/issues

# C Project template	
Aim of this Repository is to create a template repository for C executable projects with following properties:

* Cmake project
* Logging support

These requirements will keep updating.

## Cmake Project

* Cmake is the build automation system system used with this project. 
* Cmake can also be used to run tests.

### How to build

* Source of this repository is the git root folder.

* Go to source of repository.
* Create a folder `build`
* Go to build and use `cmake`.

```
$ mkdir build
$ cd build
/build$ cmake ..
```

* `Cmake` has not build the project yet. It will create the `Makefile`. 
* Run Make to create the executable.

```
$make
```

* The output executable will be in the `{source folder}/bin`. This has been configured in Cmake. You can edit this. 



## Logging support

* I have used [log.c](https://github.com/rxi/log.c) as the logging library. 
* It is added in the `{source folder}/ext` folder. 
* All external libraries used will be added here. 

### How is it used

* I am using logging library to create a file and writing logs to it.
* File will be created in `{source folder}/logs` . If the folder doesn't exits, it will create the folder.
* filename will be the timestamp when file is created. 
* I am initialising logging in `logging.c`, a call to `init_log()`.
  * NOTE: I have created a `init_utils()` that will tackle all initialisation for `utils`.



## The demo

* I have created the demo where I am doing a `dns` lookup and managing the heap memory. 
* I have created a `my_malloc` function which calls `malloc` and stores the allocated pointer in a linked list.
* I am freeing the memory in the function `FREE_HEAP()` that frees all elements of this linked list.
* I am then using `atexit` call when starting app to call `FREE_HEAP` whenever the app exits.   
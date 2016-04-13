# WebFrontend
Minimal example of a C++ image processing application that can be contacted using a web frontend.

A simple class representing an image, `TextImage` is used to represent the images processed in the real-life image processing application.
`TextImage` is *very* basic. Only pixels can only have single-digit values 0-9.
Attempting to set a pixel value larger than 9 will result in the pixel being set to `value%10`.
This choice is made primary because this is only a test application, and single-digit pixel values
make the images very easy to display in the console, for debugging.

As their name implies, TextImages are stored in text files with the following format:

```
<image width>
<image height>
<space-separated list of width*height pixel values>
```
An example is given in C++/images/image.txt

`TextImage` is used within the minimal `webfrontend` application. An image is read 
from a file; all of the pixel values in the image are incremented by 1; the image
is saved.

The goal is to create a Python API for the C++ code and use that to call the C++
application using a web frontend.

## Installation
The code in the C++ directory is compiled using CMake as follows:

```
 > cd C++/build/
 > cmake ../
 > make
 ```

The Python/ directory contains an attempt at integrating the TextImage class with Python, using Boost.Python.
(http://www.boost.org/doc/libs/1_60_0/libs/python/doc/html/index.html)

See https://www.youtube.com/watch?v=GE8EsGUsC2w for some excellent tutorials for
getting started with Boost.Python (quite a lot of C++ experience is assumed...).

Instructions for setting up Boost.Python can be found below.

The example Python module (webfrontend.so) can be built using CMake:

```
 > cd Python/build/
 > cmake ../
 > make
```

It should then be possible to import the module and test it:

```
 > python
 >>> import webfrontend
 >>> webfrontend.test(10,10)
 TextImage: size = 10 x 10
 0 0 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0 0 0
 >>>
 ```

Exposing the TextImage class itself to Python should be reasonably straight-forward using
Boost.Python. However, in the real-life image processing application I'm 
only interested in having a Python-accessible entry-point to the application.
The classes and implementation details of the image processing should be hidden from the user.

### Setting up Boost.Python
These are the steps I followed to compile Boost.Python on an Ubuntu 15.10 machine with g++ 4.9.3:

Download and extract the `boost` code:

```
 > export EXAMPLE_BOOST_DIR=/home/username/example/path/to/boost
 > cd $EXAMPLE_BOOST_DIR
 > wget http://downloads.sourceforge.net/project/boost/boost/1.60.0/boost_1_60_0.tar.bz2
 > tar xf boost_1_60_0.tar.bz2
 > rm boost_1_60_0.tar.bz2
 > cd boost_1_60_0/
 > ./bootstrap.sh --with-libraries=python
 > ./b2
 ...
 > export BOOST_ROOT=${EXAMPLE_BOOST_DIR}/boost_1_60_0
```

At this point it should be possible to compile and test the code in the Python/
directory, as described above.

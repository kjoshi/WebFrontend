# WebFrontend
Minimal example of a C++ image processing application that can be contacted using a web frontend.

A simple class representing an image, `TextImage` is used to represent the images processed in the real application.
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
The C++ code is compiled using CMake as follows:

```
 > cd build/
 > cmake ../
 > make
 ```


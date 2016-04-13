#include "boost/python.hpp"

#include "TextImage.h"

void test(int w, int h) {
    TextImage t(w,h);
    t.Display();
    return;
}

BOOST_PYTHON_MODULE(webfrontend)
{
    namespace bp = boost::python;
    bp::def("test", test);
}

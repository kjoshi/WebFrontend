#ifndef TEXT_IMAGE_H_
#define TEXT_IMAGE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using std::string;
using std::stringstream;
using std::cout;
using std::endl;

class TextImage {

    public:
        // Default constructor. Create a blank image.
        TextImage(int width, int height);

        // Create a TextImage by read it from a file.
        TextImage(string filename);

        // Copy constructor. Copy the contents of the array of pixels.
        TextImage(const TextImage& img);

        // Destructor, delete the array of pixels
        ~TextImage();

        // Print the image to std::cout
        void Display();

        // Save the image to a file.
        void SaveAs(string filename);

        // Check whether the requested pixel is in a valid location
        bool ValidPixel(unsigned int x, unsigned int y);

        // Getter functions
        unsigned int GetWidth() const { return width_; }
        unsigned int GetHeight() const { return height_; }
        unsigned int GetNumPixels() const { return n_pix_; }
        unsigned int GetPixel(int x, int y) const { return pix_array_[GetWidth()*y + x]; }

        // Setter functions
        void SetWidth(int w) { width_ = w; }
        void SetHeight(int h) { height_ = h; }
        void SetPixel(int x, int y, unsigned int val);

    private:
        unsigned int width_;
        unsigned int height_;
        unsigned int n_pix_;
        unsigned int* pix_array_;

        unsigned int* GetPixArray(){ return pix_array_; }


};

#endif

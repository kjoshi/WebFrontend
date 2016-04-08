#include "TextImage.h"

void Add(TextImage& img, int value) {
    for(unsigned int x=0; x<img.GetWidth(); ++x) {
        for(unsigned int y=0; y<img.GetHeight(); ++y) {
            img.SetPixel(x,y, img.GetPixel(x,y) + value);
        }
    }
}

int main(int argc, char* argv[])
{
    if(argc != 3) {
        cout << "Usage: ./webfrontend input output" << endl;
        cout << "Example: ./webfrontend image.txt processed_image.txt" << endl;
        return 1;
    }
    string input = argv[1];
    string output = argv[2];

    TextImage image(input);
    Add(image, 1);
    image.SaveAs(output);

    return 0;
}

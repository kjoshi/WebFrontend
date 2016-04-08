#include "TextImage.h"

TextImage::TextImage(int width, int height):
    width_(width),
    height_(height)
{
    n_pix_ = width_ * height_;

    pix_array_ = new unsigned int[n_pix_]();
}

TextImage::TextImage(string filename) {
    std::ifstream infile(filename, std::ios::in);
    if(!infile.is_open()) {
        cout << "[TextImage]\tERROR - Could not open file with name: "
             << filename << endl;
        cout << "[TextImage]\tERROR - Continuing with blank 3x3 pixel image" 
             << endl;

        width_ = 3;
        height_ = 3;
        n_pix_ = width_ * height_;
        pix_array_ = new unsigned int[n_pix_]();
        return;
    }
    string word;

    infile >> word;
    width_ = std::stoi(word);

    infile >> word;
    height_ = std::stoi(word);

    n_pix_ = width_ * height_;
    pix_array_ = new unsigned int[n_pix_]();

    for(unsigned int i=0; i<n_pix_; ++i) {
        infile >> word;
        pix_array_[i] = std::stoi(word);
    }
    return;
}

TextImage::TextImage(const TextImage& img) {
    this->SetWidth(img.GetWidth());
    this->SetHeight(img.GetHeight());
    n_pix_ = this->GetWidth() * this->GetHeight();

    pix_array_ = new unsigned int[n_pix_];
    for(unsigned int x=0; x<GetWidth(); ++x) {
        for(unsigned int y=0; y<GetHeight(); ++y) {
            this->SetPixel(x,y, img.GetPixel(x,y));
        }
    }
}

TextImage::~TextImage() {
    delete pix_array_;
}

void TextImage::Display() {
    cout << "TextImage: size = " << GetWidth() << " x " << GetHeight() << endl;
    for(unsigned int y=0; y<height_; ++y) {
        for(unsigned int x=0; x<width_; ++x) {
            cout << GetPixel(x,y) << " ";
        }
        cout << endl;
    }
    return;
}

void TextImage::SaveAs(string filename) {
    std::ofstream outfile(filename, std::ios::out);
    if(!outfile.is_open()) {
        cout << "[TextImage::SaveAs]\tERROR - Could not open output file with"
             << " name : " << filename << endl;
        return;
    }

    stringstream s;
    s << GetWidth() << '\n' << GetHeight() << '\n';
    for(unsigned int i=0; i<n_pix_; ++i) {
        s << pix_array_[i] << " ";
    }

    outfile << s.str();
    outfile.close();
}

void TextImage::SetPixel(int x, int y, unsigned int val) {
    if(!ValidPixel(x,y)) {
        return;
    }

    if(val > 9) {
        cout << "[TextImage::SetPixel]\tWARNING - Only pixel values between 0-9"
             << " are allowed in TextImage" << endl;
    }
    pix_array_[GetWidth()*y + x] = (val%10);
}


bool TextImage::ValidPixel(unsigned int x, unsigned int y) {
    if(x >= GetWidth() || y >= GetHeight()) {
        cout << "[TextImage::ValidPixel]\tERROR - Pixel " << x << "," << y
             << " is invalid." << endl;
             return false;
    } else {
        return true;
    }
}

#include "FileReader.h"
#ifndef PPM_H

typedef struct {
    unsigned char red, green, blue;
} PPMPixel;

typedef struct {
    int x, y;
    PPMPixel *data;
} PPMImage;

class PPM:public FileReader{
    private:
        PPMImage *image;
        void changeColorPPM();
    public:
        PPM(std::string file_name);
        void read_file(const char *filename);
        void write_toFile(const char *filename);
        void process();
};

#endif
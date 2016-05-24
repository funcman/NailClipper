#ifndef NCTEXTURE_H
#define NCTEXTURE_H

class ncTexture {
public:
    ncTexture(char const* filename);
    ~ncTexture();

    int getWidth(bool useOriginal=false);
    int getHeight(bool useOriginal=false);

    unsigned int handle();

private:
    int             width;
    int             height;
    int             original_width;
    int             original_height;
    unsigned int*   textures;
};

#endif//NCTEXTURE_H

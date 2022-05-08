/**
 * @file StickerSheet.h
 * Contains your declaration of the interface for the StickerSheet class.
 */
#pragma once
#include <string>
using namespace std;
#include "cs225/PNG.h"
using namespace cs225;
#include "Image.h"


class StickerSheet: public cs225::PNG {
    public:
    StickerSheet(const Image & picture, unsigned max);
    ~StickerSheet();
    StickerSheet(const StickerSheet & other);
    int addSticker(Image & sticker, unsigned x, unsigned y);
    void changeMaxStickers(unsigned max);
    Image * getSticker(unsigned index);
    const StickerSheet & operator=(const StickerSheet & other);
    void removeSticker(unsigned index);
    Image render()const;
    bool translate(unsigned index, unsigned x, unsigned y);
    void clear();
    void copy(const StickerSheet& other);
    Image getPic() const;
    void setPic() const;
    unsigned getMax() const;
    void setMax() const;
    Image** getStickerPointer() const;
    unsigned* getWidth() const;
    unsigned* getHeight() const;


    private:
    Image copyPic;
    unsigned copyMax;
    Image** stickerPointer;
    unsigned* width;
    unsigned* height;
    unsigned countSticker;
    

    


};
// #pragma once
// #include <iostream>
// #include "Image.h"
// using namespace std;
// using namespace cs225;

// class StickerSheet {
//     public:
//     void changeMaxStickers(unsigned max);
//     void copier(const StickerSheet & other);
//     void destroyer();
//     const StickerSheet & operator=(const StickerSheet & other);
//     int addSticker(Image &sticker, unsigned x, unsigned y);
//     bool translate(unsigned index, unsigned x, unsigned y);
//     void removeSticker(unsigned index);
//     StickerSheet(const Image &picture, unsigned maxq);
//     ~StickerSheet();
//     StickerSheet(const StickerSheet & other);
//     Image * getSticker(unsigned index) const;
//     Image render()const;

//     private: 
//     unsigned countSticker;
//     unsigned maxSticker;
//     unsigned * xCoors;
//     unsigned * yCoors;
//     Image defSticker;
//     Image ** stickers;
// };

 

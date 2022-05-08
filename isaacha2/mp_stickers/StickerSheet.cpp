#include "StickerSheet.h"
#include <string>
#include <iostream>
using namespace cs225;


void StickerSheet::copy(const StickerSheet& other) {
    // copyPic = other.getPic();
    // copyMax = other.getMax();
    copyPic = other.copyPic;
    copyMax = other.copyMax;
    width = other.width;
    height = other.height;
    countSticker = other.countSticker;
    stickerPointer = new Image*[copyMax];
    // for(unsigned int i = 0; i < copyMax; i++) {
    //     if (other.stickerPointer[i] == NULL) {
    //         stickerPointer[i] = NULL;
    //     } else {
    //         stickerPointer[i] = other.stickerPointer[i];
    //     }
        width = new unsigned[copyMax];
        height = new unsigned[copyMax];
        for (unsigned i = 0; i < countSticker; i++) {
            if (stickerPointer[i] != NULL) {
                
            // width[i] = other.getWidth()[i];
            // height[i] = other.getHeight()[i];
            width[i] = other.width[i];
            height[i] = other.height[i];
            stickerPointer[i] = other.stickerPointer[i];
        }
    }
}

StickerSheet::~StickerSheet() {
    delete[] width;
    delete[] height;
    delete[] stickerPointer;
    //clear();

}

// Image StickerSheet::getPic() const {
//     return copyPic;
// }
// unsigned StickerSheet::getMax() const {
//     return copyMax;
// }
// Image** StickerSheet::getStickerPointer() const{
//     return stickerPointer;
// }
// unsigned* StickerSheet::getWidth() const {
//     return width;
// }
// unsigned* StickerSheet::getHeight() const {
//     return height;
// }

int StickerSheet::addSticker(Image& sticker, unsigned x, unsigned y) {


    if (countSticker > copyMax - 1) {
        return -1;
    } else {
        stickerPointer[countSticker] = &sticker;
        width[countSticker] = x;
        height[countSticker] = y;
        countSticker++;
    }
    return countSticker - 1;
}



void StickerSheet::changeMaxStickers(unsigned max) {

    Image** temp = new Image*[max];
    unsigned* newWidth = new unsigned[max];
    unsigned* newHeight = new unsigned[max];
    if (max > countSticker) {
        for(unsigned i = 0; i < countSticker; i++) {
            temp[i] = stickerPointer[i];
            newWidth[i] = width[i];
            newHeight[i] = height[i];
        }
    } else {
        for(unsigned i = 0; i < max; i++) {
            temp[i] = stickerPointer[i];
            newWidth[i] = width[i];
            newHeight[i] = height[i];
            if (max < countSticker) {
                countSticker = max;
            }
        }
    }
    delete[] stickerPointer;
    delete[] width;
    delete[] height;
 
    
    stickerPointer = temp;
    width = newWidth;
    height = newHeight;
    copyMax = max;
}
// Image * StickerSheet::getSticker ( unsigned  index) {
//     return stickerPointer[index];
// }	
const StickerSheet & StickerSheet::operator=(const StickerSheet & other) {
    if (this != &other) {
        // clear();
        delete[] width;
        delete[] height;
        delete[] stickerPointer;
        copy(other);
    }
    return *this;

}
void StickerSheet:: removeSticker(unsigned index) {
//     if (stickerPointer[index] != NULL) {
//         delete stickerPointer[index];
//         stickerPointer[index] = NULL;
//     }
//     width[index] = 0;
//     height[index]= 0;
//     countSticker--;
// }

    if (index < countSticker) {
        countSticker--;
        stickerPointer[index] = NULL;
    }
    for (unsigned i=index; i<countSticker; i++) {
            stickerPointer[i] = stickerPointer[i+1];
            width[i] = width[i+1];
            height[i] = height[i+1];
    }
}

// Image StickerSheet::render() const {
//     Image renderImage = Image(copyPic);
//     for (unsigned i = 0; i < copyMax; i++) {
//         if (stickerPointer[i] != NULL) {
//             unsigned widthSticker = width[i];
//             unsigned heightSticker = height[i];
//         for (unsigned x = 0; x < stickerPointer[i]->width(); x++ ) {
//             for (unsigned y = 0; y < stickerPointer[i]->height(); y++) {
//                 if (stickerPointer[i]->getPixel(x, y).a != 0 ) {
//                     HSLAPixel & pixel = renderImage.getPixel(widthSticker + x , heightSticker + y);
//                     pixel = stickerPointer[i]->getPixel(x,y);
//                 }
//             }
//         }        
//     }
// }
// return renderImage;

// bool StickerSheet::translate(unsigned index, unsigned x , unsigned y) {
//     if (index < countSticker) {
//         width[index] = x;
//         height[index] = y;
//         return true;
//     } else {
//         return false;
//     }
// }

StickerSheet::StickerSheet(const Image &picture, unsigned max) {
    copyMax = max;
    copyPic = picture;
    width = new unsigned[max];
    height = new unsigned[max];
    stickerPointer = new Image*[max];
    for(unsigned i = 0; i < copyMax; i++) {
        stickerPointer[i] = NULL;
    }
    countSticker = 0;
    
}

StickerSheet::StickerSheet(const StickerSheet & other) {
    copy(other);
}
// void StickerSheet::clear() {
//     delete[] width;
//     delete[] height;
//     delete[] stickerPointer;
//     width = NULL;
//     height = NULL;
//     stickerPointer = NULL; 
// }

// void StickerSheet::copy(const StickerSheet & other) {
//     copyPic = other.copyPic;
//     countSticker = other.countSticker;
//     copyMax = other.copyMax;

//     stickerPointer = new Image*[copyMax];
//     width = new unsigned[copyMax];
//     height = new unsigned[copyMax];

//     for (unsigned i = 0; i < countSticker; i++) {
//         stickerPointer[i] = other.stickerPointer[i];
//     }
//     for (unsigned i = 0; i < countSticker; i++) {
//         width[i] = other.width[i];
//     }
//     for (unsigned i = 0; i < countSticker; i++) {
//         height[i] = other.height[i];
//     }
// }

bool StickerSheet::translate(unsigned index, unsigned x, unsigned y) {
    if (index < countSticker) {
        width[index] = x;
        height[index] = y;
        return true;
    }
    else {
        return false;
    }
}

// if ((index >= 0) && (index <= countSticker)) {
//     width[index] = x;
//     height[index] = y;
//     return true;
// } else{
// return false;
// }
// }
Image * StickerSheet::getSticker(unsigned index){
    if (index < countSticker) {
        return stickerPointer[index];
    }
    else {
        return NULL;
    }
}

// Image StickerSheet::render() const {
//     // Image renderImage = Image(copyPic);
//     Image renderImage = copyPic;
//     for (unsigned i = 0; i < countSticker; i++) {
//         if (stickerPointer[i] != NULL) {
//             unsigned widthSticker = width[i];
//             unsigned heightSticker = height[i];
//             for (unsigned x = 0; x < stickerPointer[i]->width(); x++ ) {
//                 for (unsigned y = 0; y < stickerPointer[i]->height(); y++) {
//                     if (stickerPointer[i]->getPixel(x, y).a != 0 ) {
//                         HSLAPixel & pixel = renderImage.getPixel(widthSticker + x , heightSticker + y);
//                         pixel = stickerPointer[i]->getPixel(x,y);
//                     }
//                 }
//             }        
//         }
//     }
//     return renderImage;
// }

// Image StickerSheet::render() const {
//     // Image renderImage = Image(copyPic);
//     Image renderImage = copyPic;
//     unsigned newWidth = copyPic.width();
//     unsigned newHeight = copyPic.height();


//     for(unsigned j = 0; j < countSticker; j++) {
//         if (newWidth < stickerPointer[j]->width() + width[j] ) {
//             newWidth =stickerPointer[j]->width() + width[j];
//         }
//         if (newHeight < stickerPointer[j]->width() +width[j] ) {
//             newHeight = stickerPointer[j]->width() +width[j];
//         }
//     }
//     renderImage.resize(newWidth, newHeight);
//     for (unsigned i = 0; i < countSticker; i++) {
//         if (stickerPointer[i] != NULL) {
//             unsigned widthSticker = width[i];
//             unsigned heightSticker = height[i];
//             for (unsigned z = 0; z < countSticker; z++) {
//                 for (unsigned x = 0; x < stickerPointer[z]->width(); x++ ) {
//                     for (unsigned y = 0; y < stickerPointer[z]->height(); y++) {
//                         if (stickerPointer[z]->getPixel(x, y).a != 0 ) {
//                             HSLAPixel & pixel = renderImage.getPixel(widthSticker + x , heightSticker + y);
//                             pixel = stickerPointer[z]->getPixel(x,y);
//                         }
//                     }
//                 }
//             }        
//         }
//     }
//     return renderImage;
// }
// Image StickerSheet::render() const {
//     // Image renderImage = Image(copyPic);
//     Image renderImage = copyPic;
//     unsigned originalWidth = copyPic.width();
//     unsigned originalHeight = copyPic.height();
//     unsigned newWidth = copyPic.width();
//     unsigned newHeight = copyPic.height();


//     for(unsigned j = 0; j < countSticker; j++) {
//         if (stickerPointer[j] != NULL) {
//             if (newWidth < stickerPointer[j]->width() + width[j]) {
//                 newWidth = stickerPointer[j]->width() + width[j];
//             }
//             if (newHeight < stickerPointer[j]->height() +height[j] ) {
//                 newHeight = stickerPointer[j]->height() +height[j];
//             }
//         }
        
//     }
//     renderImage.resize(newWidth, newHeight);
//     // for (unsigned i = 0; i < countSticker; i++) {
//         // if (stickerPointer[i] != NULL) {
//             // unsigned widthSticker = width[i];
//             // unsigned heightSticker = height[i];
//             for (unsigned z = 0; z < countSticker; z++) {
//                 if(stickerPointer[z] != NULL) {
//                     for (unsigned x = 0; x < stickerPointer[z]->width(); x++ ) {
//                         for (unsigned y = 0; y < stickerPointer[z]->height(); y++) {
//                             if (stickerPointer[z]->getPixel(x, y).a != 0 ) {
//                                 // HSLAPixel & pixel = renderImage.getPixel(widthSticker + x , heightSticker + y);
//                                 // pixel = stickerPointer[z]->getPixel(x,y);
//                                 renderImage.getPixel(width[z] + x, height[z] + y) = stickerPointer[z]->getPixel(x,y);
//                             }
//                         }
//                     }
//                 }    
//             }
//     return renderImage;
// }

Image StickerSheet::render() const {
    // Image renderImage = Image(copyPic);
    Image renderImage = copyPic;
    unsigned originalWidth = copyPic.width();
    unsigned originalHeight = copyPic.height();
    unsigned newWidth = copyPic.width();
    unsigned newHeight = copyPic.height();


    for(unsigned j = 0; j < countSticker; j++) {
        if (stickerPointer[j] != NULL) {
            if (newWidth < stickerPointer[j]->width() + width[j]) {
                newWidth = stickerPointer[j]->width() + width[j];
            }
            if (newHeight < stickerPointer[j]->height() +height[j] ) {
                newHeight = stickerPointer[j]->height() +height[j];
            }
                renderImage.resize(newWidth, newHeight);
        }
    // for (unsigned i = 0; i < countSticker; i++) {
        // if (stickerPointer[i] != NULL) {
            // unsigned widthSticker = width[i];
            // unsigned heightSticker = height[i];
            if (stickerPointer[j] != NULL) {
                    for (unsigned x = 0; x < stickerPointer[j]->width(); x++ ) {
                        for (unsigned y = 0; y < stickerPointer[j]->height(); y++) {
                            if (stickerPointer[j]->getPixel(x, y).a != 0 ) {
                                // HSLAPixel & pixel = renderImage.getPixel(widthSticker + x , heightSticker + y);
                                // pixel = stickerPointer[z]->getPixel(x,y);
                                renderImage.getPixel(width[j] + x, height[j] + y) = stickerPointer[j]->getPixel(x,y);
                            }
                        }
                    }
            }    
    }
    return renderImage;
}
// Image StickerSheet::render() const {
//     Image rendered = Image(copyPic);
//     unsigned newWidth = copyPic.width();
//     unsigned newHeight = copyPic.height();

//     for (unsigned i = 0; i < countSticker; i++) {
//         if (newWidth < width[i] + stickerPointer[i]->width()) {
//             newWidth = width[i] + stickerPointer[i]->width();
//         }
//         if (newHeight < height[i] + stickerPointer[i]->height()) {
//             newHeight = height[i] + stickerPointer[i]->height();
//         }
//     }
//     // if (copyPic.width() > newWidth) {
//     //     newWidth = copyPic.width();
//     // }
//     // if (copyPic.height() > newHeight) {
//     //     newHeight = copyPic.height();
//     // }
//     rendered.resize(newWidth,newHeight);
//     for (unsigned x = 0; x < countSticker; x++) {
//         for (unsigned y = width[x]; y < stickerPointer[x]->width(); y++) {
//             for (unsigned z = height[x]; z < stickerPointer[x]->height(); z++) {
//                 if (stickerPointer[x]->getPixel(y,z).a != 0) {
//                 rendered.getPixel(width[x] + y,height[x] + z) = stickerPointer[x]->getPixel(y,z);
//                 }
//             }
//         }
//     }
//     return rendered;
// }

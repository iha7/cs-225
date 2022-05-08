#include "Image.h"
#include "StickerSheet.h"
using namespace cs225;

int main() {
// Image inputPng;
// inputPng.readFromFile("alma.png");
  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //
//   Image base;
//   Image quote;
//   Image quote;
//   Image quote;
//   Image quote;
//   Image quote_;
//   Image quote__;
//   Image fionnsmug;
//   Image medusa;
//   Image othermedusa;
//   Image zeroquartz;
//   base.readFromFile("salty.png");
//   quote.readFromFile("quote1.png");
//   quote.readFromFile("quote2.png");
//   quote_.readFromFile("quote3.png");
//   quote.readFromFile("quote4.png");
//   quote_.readFromFile("quote5.png");
//   quote__.readFromFile("quote6.png");
//   fionn_smug.readFromFile("fionnsmug.png");
//   medusa.readFromFile("medusa.png");
//   othermedusa.readFromFile("medusa.png");
//   zeroquartz.readFromFile("zeroquartz.png");


//   quote.scale(.2);
//   quote.scale(.2);
//   quote_.scale(.2);
//   quote.scale(.2);
//   quote_.scale(.24);
//   quote__.scale(.21);
//   fionnsmug.scale(.09);
//   medusa.scale(.09);
//   othermedusa.scale(.09);
//   zeroquartz.scale(.5);

//   StickerSheet mySheet(base, 10);
//   mySheet.addSticker(quote, 50, 0);
//   mySheet.addSticker(quote, 0, 140);
//   mySheet.addSticker(quote_, 260, 10);
//   mySheet.addSticker(quote, 380, 130);
//   mySheet.addSticker(quote_, 10, 180);
//   mySheet.addSticker(quote__, 350, 200);
//   mySheet.addSticker(fionn_smug, 350, 300);
//   mySheet.addSticker(medusa, 260, 300);
//   mySheet.addSticker(othermedusa, 240, 300);
//   mySheet.addSticker(zeroquartz, 0, 320);
//   mySheet.render().writeToFile("myImage.png");

//   return 0;
// }
  Image block1;
  Image block2;
  Image block3;
  Image block4;
 
  block1.readFromFile("kirby1.png");
  block2.readFromFile("kirby2.png");
  block3.readFromFile("kirby3.png");
  block4.readFromFile("kirby4.png");


  block1.scale(.2);
  block2.scale(.2);
  block3.scale(.2);
  block4.scale(.2);


  StickerSheet outputStickerSheet(block1, 4);
  outputStickerSheet.addSticker(block1, 50, 0);
  outputStickerSheet.addSticker(block2, 0, 140);
  outputStickerSheet.addSticker(block3, 260, 10);
  outputStickerSheet.addSticker(block4, 380, 130);
  outputStickerSheet.render().writeToFile("myImage.png");

  return 0;
}

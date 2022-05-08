
// #include "cs225/PNG.h"
// #include "FloodFilledImage.h"
// #include "Animation.h"

// #include "imageTraversal/DFS.h"
// #include "imageTraversal/BFS.h"

// #include "colorPicker/RainbowColorPicker.h"
// #include "colorPicker/GradientColorPicker.h"
// #include "colorPicker/GridColorPicker.h"
// #include "colorPicker/SolidColorPicker.h"
// #include "colorPicker/MyColorPicker.h"

// using namespace cs225;

// int main() {

//   // @todo [Part 3]
//   // - The code below assumes you have an Animation called `animation`
//   // - The code provided below produces the `myFloodFill.png` file you must
//   //   submit Part 3 of this assignment -- uncomment it when you're ready.
  
//   /*
//   PNG lastFrame = animation.getFrame( animation.frameCount() - 1 );
//   lastFrame.writeToFile("myFloodFill.png");
//   animation.write("myFloodFill.gif");
//   */


//   return 0;
// }







#include "cs225/PNG.h"
#include "FloodFilledImage.h"
#include "Animation.h"

#include "imageTraversal/DFS.h"
#include "imageTraversal/BFS.h"

#include "colorPicker/RainbowColorPicker.h"
#include "colorPicker/GradientColorPicker.h"
#include "colorPicker/GridColorPicker.h"
#include "colorPicker/SolidColorPicker.h"
#include "colorPicker/MyColorPicker.h"

using namespace cs225;

int main() {

  // @todo [Part 3]
  // - The code below assumes you have an Animation called `animation`
  // - The code provided below produces the `myFloodFill.png` file you must
  //   submit Part 3 of this assignment -- uncomment it when you're ready.
  PNG inputPng; 
  inputPng.readFromFile("rainbow.png"); 
  FloodFilledImage image(inputPng);

  MyColorPicker secondColor = MyColorPicker();
  MyColorPicker firstColor = MyColorPicker();
  MyColorPicker thirdColor = MyColorPicker();


  BFS bfs(inputPng, Point(150,100), 250);
  DFS dfs(inputPng, Point(250, 500), 50000);
  
  
  image.addFloodFill(dfs, thirdColor);
  image.addFloodFill(dfs, firstColor);
  image.addFloodFill(bfs, secondColor);

  Animation animation = image.animate(1000);

  PNG lastFrame = animation.getFrame( animation.frameCount() - 1 );
  lastFrame.writeToFile("myFloodFill.png");
  animation.write("myFloodFill.gif");


  return 0;
}


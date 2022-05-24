/*
 * Copyright (c) 2020 Owen Osborn, Critter & Guitari, Inc.
 *
 * BSD Simplified License.
 * For information on usage and redistribution, and for a DISCLAIMER OF ALL
 * WARRANTIES, see the file, "LICENSE.txt," in this distribution.
 *
 */

#include "ofMain.h"
#include "ofApp.h"

int main() {
    ofWindowMode windowMode = OF_FULLSCREEN;
    std::string envShowWindow = std::getenv("EYESY_SHOW_WINDOW");
    if (envShowWindow == "true") {
      windowMode = OF_WINDOW;
    }
    int screenWidth = 1920;
    int screenHeight = 1080;
    std::string envScreenWidth = std::getenv("EYESY_SCREEN_WIDTH");
    std::string envScreenHeight = std::getenv("EYESY_SCREEN_HEIGHT");
    try {
      screenWidth = std::stoi(envScreenWidth);
      screenHeight = std::stoi(envScreenHeight);
    } catch (exception& e) {}
    ofSetupOpenGL(screenWidth, screenHeight, windowMode);

    // ofSetupOpenGL(1920, 1080, OF_FULLSCREEN);
    //ofSetupOpenGL(1280, 720, OF_FULLSCREEN);
    ofRunApp(new ofApp());
}

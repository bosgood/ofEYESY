/*
 * Copyright (c) 2020 Owen Osborn, Critter & Gutiari, Inc.
 *
 * BSD Simplified License.
 * For information on usage and redistribution, and for a DISCLAIMER OF ALL
 * WARRANTIES, see the file, "LICENSE.txt," in this distribution.
 *
 */
#pragma once

#include "ofMain.h"
#include "ofxLua.h"
#include "ofxOsc.h"

#define PORT 4000

class ofApp : public ofBaseApp, ofxLuaListener {

    public:

        // main
        void setup();
        void update();
        void draw();
        void exit();
        
        // input
        void keyPressed(int key);
        void mouseMoved(int x, int y);
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        
        // ofxLua error callback
        void errorReceived(std::string& msg);
        
        // script control
        void reloadScript();
        void nextScript();
        void prevScript();
	void recallScript(int num);
	void sendCurrentScript(int cur);
    
        ofxLua lua;
        vector<string> scripts;
        size_t currentScript;

        // osc control
        ofxOscReceiver receiver;
	ofxOscSender sender;

	
        // audio stuff
        void audioIn(ofSoundBuffer & input);
    
        vector <lua_Number> left;
        vector <lua_Number> right;

        int     bufferCounter;
        int     drawCounter;
    
        float smoothedVol;
        float scaledVol;
        
        ofSoundStream soundStream;

        int                 snapCounter;
        string              snapString;
        ofImage             img;

	bool 	osdEnabled;
	int 	midiTable[128];
	int totalScenes;
	
		
	vector<int> osdMidi{0,0};
	
	// osd stuff
	ofFbo osdFbo;
	ofTrueTypeFont osdFont;
	ofTrueTypeFont osdFontK;
	int dummyAudio;
	int seqStatus;
	int osdCount;
	float osdW;
	float osdH;
	float globalGain = 1;
	int globalTrigInput;
	int globalMidiChannel;
	int globalScene;
        bool globalTrig;
	bool globalLink;	
	bool globalMidiClock;
	bool shIft = false;
	
	// knob stuff
	float k1Local;
	float k1ShiftLocal;
	float k2Local;
	float k2ShiftLocal;	
	float k3Local;
	float k3ShiftLocal;
	float k4Local;
	float k5Local;
};

#pragma once

#include "ofMain.h"
#include "Circle.hpp"
#include "Epicycles.hpp"
#include "ofxGui.h"


class ofApp : public ofBaseApp{

	public:
		void setup() override;
		void update() override;
		void draw() override;
		void exit() override;

		void keyPressed(int key) override;
		void keyReleased(int key) override;
		void mouseMoved(int x, int y ) override;
		void mouseDragged(int x, int y, int button) override;
		void mousePressed(int x, int y, int button) override;
		void mouseReleased(int x, int y, int button) override;
		void mouseScrolled(int x, int y, float scrollX, float scrollY) override;
		void mouseEntered(int x, int y) override;
		void mouseExited(int x, int y) override;
		void windowResized(int w, int h) override;
		void dragEvent(ofDragInfo dragInfo) override;
		void gotMessage(ofMessage msg) override;
    
        void drawCircle(Circle circle);
        void drawEpicycles(Epicycles epicycle);
    void playPressed();
    void stopPressed();
    void lineButtonPressed();
    void triangleButtonPressed();
    void squareButtonPressed();
    void clearPathPressed();
   
    
    

    
    ofPath path;
    
    Circle *c;
    
    
    Epicycles *e;
    
    
    int i;

    //square
    Epicycles *square;
    float fSquare[2] = {0.333, 1};
    float arSquare[2] = {0.25, 0.1};
    bool signSquare[2] = {true, false};
    bool startSquare;
    ofPath pathSquare;
    
    //Triangle
    Epicycles *triangle;
    float fTriangle[2]= {0.5, 1.0};
    float arTriangle[2] = {0.333, 0.1};
    bool signTriangle[2] = {true, false};
    bool startTriangle;
    ofPath pathTriangle;
    
    //line
    Epicycles *line;
    float fLine[2] = {1.0, 1.0};
//    float arLine[2] = {1, 0.1};
//    bool signLine[2] = {true, false};
    bool startLine;
    ofPath pathLine;
    
    //interactive
    Epicycles *inter;
    float fInter[7];
    float arInter[7];
    bool signInter[7];
    bool startInter;
    ofPath pathInter;

    
    
    
    
    //Declare Components:
    ofxPanel gui;
    ofxPanel gui2;
    
    
    ofxButton squareButton;
    ofxButton triangleButton;
    ofxButton lineButton;
    
    
    ofxButton clearPath;
    ofxButton submit;
    ofxButton stop;
    
//    ofxIntSlider intSliderAmplitude[7];
//    ofxFloatSlider floatSliderAmplitude[7];
//    ofxIntSlider intSliderFrequency[7];
//    ofxFloatSlider floatSliderFrequency[7];
    ofxToggle toggleSign[7];
    

    ofxLabel label;
    ofxLabel label2;
    
    ofParameterGroup sliderGroup[7];
    ofParameter<int> intSliderAmplitude[7];
    ofParameter<float> floatSliderAmplitude[7];
    ofParameter<int> intSliderFrequency[7];
    ofParameter<float> floatSliderFrequency[7];
    


    
    
    bool start;
    
    

};

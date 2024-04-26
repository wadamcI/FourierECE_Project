#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(40);
    ofSetFrameRate(60);
    ofSetBackgroundColor(255, 255, 255);
    
    c = new Circle();
    c->setCircle(500, 500, 200);
    
    
    line = new Epicycles[2];
    triangle = new Epicycles[2];
    square = new Epicycles[2];
    inter =  new Epicycles[7];

    i=0;
    
//    e = new Epicycles();
    
    //Setting paths

//    path.setFilled(false);
//    path.setStrokeWidth(2);
//    path.setStrokeColor(ofColor::black);


    pathLine.setFilled(false);
    pathLine.setStrokeWidth(2);
    pathLine.setStrokeColor(ofColor::black);

    pathTriangle.setFilled(false);
    pathTriangle.setStrokeWidth(2);
    pathTriangle.setStrokeColor(ofColor::black);

    pathSquare.setFilled(false);
    pathSquare.setStrokeWidth(2);
    pathSquare.setStrokeColor(ofColor::black);

    pathInter.setFilled(false);
    pathInter.setStrokeWidth(2);
    pathInter.setStrokeColor(ofColor::black);

    // GUi
    submit.addListener(this, &ofApp::playPressed);
    stop.addListener(this, &ofApp::stopPressed);
    lineButton.addListener(this, &ofApp::lineButtonPressed);
    triangleButton.addListener(this,&ofApp::triangleButtonPressed);
    squareButton.addListener(this, &ofApp::squareButtonPressed);
    clearPath.addListener(this, &ofApp::clearPathPressed);


    gui.setup();
    gui.add(label.setup("", "Examples", 50, 50));
    gui.loadFont("/Users/wadamc/Desktop/ECE-270/of_v0.12.0_osx_release/apps/myApps/FinalProject/bin/data/arial.ttf", 30);


    //demo
    gui.add(lineButton.setup("Line", 50, 50));
    gui.add(triangleButton.setup("Triangle", 50, 50));
    gui.add(squareButton.setup("Square", 50, 50));
    
    
    gui2.setup();
    gui2.add(label2.setup("", "Control Board", 50, 50));
    gui2.loadFont("/Users/wadamc/Desktop/ECE-270/of_v0.12.0_osx_release/apps/myApps/FinalProject/bin/data/arial.ttf", 15);


    
    for(int i=0; i<7; i++){
        sliderGroup[i].setName("Epicycle"+std::to_string(i+1));
        sliderGroup[i].add(intSliderAmplitude[i].set("Amplitude"+std::to_string(i+1), 0, 0, 10));
        sliderGroup[i].add(floatSliderAmplitude[i].set("Amplitude"+std::to_string(i+1), 0, 0, 1));
        sliderGroup[i].add(intSliderFrequency[i].set("Frequency"+std::to_string(i+1), 0, 0, 10));
        sliderGroup[i].add(floatSliderFrequency[i].set("Frequency"+std::to_string(i+1), 0, 0, 1));
        
    }
    for(int i=0; i<7; i++){
        gui2.add(sliderGroup[i]);
        gui2.add(toggleSign[i].setup("Rotation Dir." +std::to_string(i+1), true));
    }
    gui2.add(clearPath.setup("CLEAR", 50, 50));
    gui2.add(submit.setup("SUBMIT", 50, 50));
    gui2.add(stop.setup("STOP", 50, 50));
    
    
    


    //  setting state
    start = false;
    startLine = false;
    startTriangle = false;
    startSquare = false;

}

//--------------------------------------------------------------
void ofApp::update(){
  
//    e->setEpicycles(c, 1, 1, i, true);
//    //setting demo epicycles
    if(startLine){
        line->setEpicycles(c, 1, 1, i, true);
        (line+1)->setEpicycles(line, c, 0.1, 1, i, false);
        
        pathLine.curveTo((line+1)->x, (line+1)->y);
        
        if (i%1000==0){
            pathLine.clear();
        }
    }
//
    if(startTriangle){
        triangle->setEpicycles(c, arTriangle[0], fTriangle[0], i, signTriangle[0]);
        (triangle+1)->setEpicycles(triangle, c, arTriangle[1], fTriangle[1], i, signTriangle[1]);
        pathTriangle.curveTo((triangle+1)->x, (triangle+1)->y);
        if (i%1000==0){
            pathTriangle.clear();
        }
    }

    if(startSquare){
        square->setEpicycles(c, arSquare[0], fSquare[0], i, signSquare[0]);
        (square+1)->setEpicycles(square, c, arSquare[1], fSquare[1], i, signSquare[1]);
        pathSquare.curveTo((square+1)->x, (square+1)->y);
        if (i%1000==0){
            pathSquare.clear();
        }
    }


//    if(start){
//        (inter)->setEpicycles(c, arInter[0], 1, i, signInter[0]);
//        pathInter.curveTo((inter)->x, (inter)->y);
//        if (i%1000==0){
//            pathInter.clear();
//        }
//    }
////
//
//
    if (start) {
        for (int n = 0; n < 7; n++) {
            arInter[n] = intSliderAmplitude[n]+floatSliderAmplitude[n];
            fInter[n] =intSliderFrequency[n]+floatSliderFrequency[n];
            signInter[n] = toggleSign[n];
            if (n == 0) {
                (inter + n)->setEpicycles(c, arInter[n], fInter[n], i, signInter[n]);
            } else {
                (inter + n)->setEpicycles((inter + n - 1), c, arInter[n], fInter[n], i, signInter[n]);
            }

            pathInter.curveTo((inter + 6)->x, (inter + 6)->y);

        
        }
    }
//
//
//
    i=i+1;

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    drawCircle(*c);
    
//    drawEpicycles(*e);
//
//    //demo
    if(startLine){
        for(int n=0; n<2; n++){
            drawEpicycles(*(line+n));
        }
        pathLine.draw();
    }
    if(startTriangle){
        for(int n=0; n<2; n++){
            drawEpicycles(*(triangle+n));
        }
        pathTriangle.draw();
    }
    if(startSquare){
        for(int n=0; n<2; n++){
            drawEpicycles(*(square+n));
        }
        pathSquare.draw();
    }
    if(start){
        for(int i=0; i<7; i++){
            drawEpicycles(*(inter+i));
        }
        pathInter.draw();
    }
    gui.draw();
    gui2.draw();
//
    
}

//--------------------------------------------------------------

void ofApp::playPressed(){
    start = true;
}
void ofApp::stopPressed(){
    start = false;
}
void ofApp::lineButtonPressed(){
    pathLine.clear();
    startLine = !startLine;
}
void ofApp::triangleButtonPressed(){
    pathTriangle.clear();
    startTriangle = !startTriangle;
}
void ofApp::squareButtonPressed(){
    pathSquare.clear();
    startSquare = !startSquare;
}
             
void ofApp::clearPathPressed(){
    pathInter.clear();
}



//--------------------------------------------------------------
void ofApp::exit(){
    delete c;

    delete[] line;
    delete[] triangle;
    delete[] square;
    delete[] inter;

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    

    

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
//--------------------------------------------------------------
void ofApp::drawCircle(Circle circle){

    ofSetColor(0, 0, 0);
    ofNoFill();
    ofDrawCircle(circle.getX(), circle.getY(), circle.getR());
    
}

//--------------------------------------------------------------

void ofApp::drawEpicycles(Epicycles epicycle){
    
    
    ofSetColor(0, 0, 0);
    ofNoFill();
    ofDrawCircle(epicycle.x, epicycle.y, epicycle.er);
    
}

//--------------------------------------------------------------


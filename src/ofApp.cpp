#include "ofApp.h"
#include <time.h>



//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(100);
    
    ofSetBackgroundColor(255, 255, 255);
    ofSetFrameRate(60);

    //Colors
    colorRed.setColor(255, 0, 0);
    colorWhite.setColor(255, 255, 255);
    colorBlack.setColor(0, 0, 0);
    
    //Lines
    l1.setLineColor(colorRed);
    d1.setPathLineWidth(2);
    d1.setPathColor(colorRed);
    d1.setClosed(false);
    
//    d1.setPath(3, x1, y1);
    d1.setPathColor(colorRed);
    d1.setPathLineWidth(3);
    d1.setClosed(false);
    
    d2.setPathColor(colorBlack);
    d2.setPathLineWidth(3);
    d2.setClosed(false);
    
    //Primary Circle
    circle1.setCircle(300, 500, 150);
    stroke1.setStroke(circle1, colorRed, 2);
    
    
    
//    std::cout << "Equidistant Points on the Circumference:" << std::endl;
//    for (int i = 0; i < 500; ++i) {
//        std::cout << "Point " << i + 1 << ": (" << path1[i].x << ", " << path1[i].y << ")" << std::endl;
//    }
    index = 0;
//    index2=1;
//    drawing1 = nullptr;
//    drawing2 = nullptr;
    
    r1.setLineColor(0, 0, 255);
    r1.setThickness(2);
    r2.setLineColor(0, 255, 0);
    r2.setThickness(2);
    r3.setLineColor(255, 0, 0);
    r3.setThickness(2);
    h.setLineColor(0, 0, 0);
    h.setThickness(2);


}

//--------------------------------------------------------------
void ofApp::update(){
    srand(time(NULL));
    
    
    path1 = circle1.calculateSetEquidistantpoints(500);
    circle2.setCircle(path1[index].x, path1[index].y, 125);
    stroke2.setStroke(circle2, colorRed, 1);
    int z =125;
    path2 = circle2.calculateSetEquidistantpoints(z);
    circle3.setCircle(path2[index2%z].x, path2[index2%z].y, 40);
    stroke3.setStroke(circle3, colorRed, 1);
//    std::cout << "\n" << path2[0].x <<", "<<path2[0].y;
    
    path3 = circle3.calculateSetEquidistantpoints(125);
    circle4.setCircle(path3[index%125].x, path3[index%125].y, 20);
    stroke4.setStroke(circle4, colorRed, 1);
    
    d1.addVertex(path2[index%z].x, path2[index%z].y);
    d2.addVertex(path3[index%125].x+500, path3[index%125].y);
    
    for(int i=0; i<d2.n; i++){
        d2.xptr[i] = d2.xptr[i]+4;
    }
    
    r1.setLine(300, 500, path1[index].x, path1[index].y);
    r2.setLine(path1[index].x, path1[index].y, path2[index2%z].x, path2[index2%z].y);
    r3.setLine(path2[index2%z].x, path2[index2%z].y, path3[index%125].x, path3[index%125].y);
    h.setLine(path3[index%125].x, path3[index%125].y, path3[index%125].x+500, path3[index%125].y);
//    // two arrays:
//    if (index%2==1 && drawing2!=nullptr){
//        delete[] drawing1;
//        drawing1 = new Pointt[index2+1];
//        for (int i = 0; i < index2; ++i) {
//            drawing1[i] = drawing2[i];
//        }
//        drawing1[index2-1] = path2[0];
//
//    }
//    if (index%2==0 && drawing1!=nullptr ){
//        delete[] drawing2;
//        drawing2 = new Pointt[index2+1];
//        for (int i = 0; i < index2; ++i) {
//            drawing2[i] = drawing1[i];
//        }
//        drawing2[index2-1] = path2[0];
//    }
    delete[] path2;
    delete[] path3;
    index = (index + 1) % 500;
    index2 = index2+1;
    std::cout<<"\n"<<ofGetFrameRate();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    drawCircle(circle1, colorWhite, stroke1);
    drawCircle(circle2, colorWhite, stroke2);
    drawCircle(circle3, colorWhite, stroke3);
    drawCircle(circle4, colorWhite, stroke4);
    drawPath(d1);
    drawPath(d2);
    drawLine(r1);
    drawLine(r2);
    drawLine(r3);
    drawLine(h);
//    ofSetColor(0, 0, 255);
//    ofSetLineWidth(2);
//    if (drawing1!=nullptr && drawing2!=nullptr){
//        for (int i = 0; i < index2+1; i++) {
//            ofDrawLine(drawing2[i].x, drawing2[i].y, drawing2[i + 1].x, drawing2[i + 1].y);
//            ofDrawLine(drawing1[i].x, drawing1[i].y, drawing1[i + 1].x, drawing1[i + 1].y);
//        }
//    }
    
}

//--------------------------------------------------------------
void ofApp::exit(){

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
void ofApp::drawCircle(Circle circle, Fill c, Stroke stroke){
    
    ofSetColor(c.r, c.g, c.b, c.alpha);
    ofFill();
    ofDrawCircle(circle.x, circle.y, circle.r);
    
    ofNoFill();
    ofSetColor(stroke.c.r, stroke.c.g, stroke.c.b, stroke.c.alpha);
    ofSetLineWidth(stroke.t);
    ofDrawCircle(stroke.circle.x, stroke.circle.y, stroke.circle.r);
    
}
//--------------------------------------------------------------
void ofApp::drawRectangle(Rectangle rectangle, Fill c, Stroke stroke){
    ofSetColor(c.r, c.g, c.b, c.alpha);
    ofDrawRectangle(rectangle.x, rectangle.y, rectangle.w, rectangle.h);
    ofNoFill();
    ofSetColor(stroke.c.r, stroke.c.g, stroke.c.b, stroke.c.alpha);
    ofSetLineWidth(stroke.t);
    ofDrawRectangle(stroke.rectangle.x, stroke.rectangle.y, stroke.rectangle.w, stroke.rectangle.h);
}
//--------------------------------------------------------------
void ofApp::drawLine(Line line){
    ofSetColor(line.c.r, line.c.g, line.c.b, line.c.alpha);
    ofSetLineWidth(line.t);
    ofDrawLine(line.x1, line.y1, line.x2, line.y2);
    
}
//--------------------------------------------------------------
void ofApp::drawPath(Path path){
    ofSetColor(path.c.r, path.c.g, path.c.b, path.c.alpha);
    ofSetLineWidth(path.t);
    
    for(int i = 1; i <= path.n-1 ; i++){
        ofDrawLine(path.xptr[i-1], path.yptr[i-1], path.xptr[i], path.yptr[i]);
    }
    
        
    if(path.closed){
        ofDrawLine(path.xptr[path.n - 1], path.yptr[path.n - 1], path.xptr[0], path.yptr[0]);
    }
}
//--------------------------------------------------------------


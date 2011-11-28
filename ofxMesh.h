//
//  ofxMesh.h
//
//  Created by Rick Companje on 10/20/11.
//  Copyright (c) 2011 Globe4D. All rights reserved.
//

#pragma once

#include "ofMain.h"

class ofxMesh : public ofMesh {
public:  

    void addFace(ofVec3f a, ofVec3f b, ofVec3f c);
    void addFace(ofVec3f a, ofVec3f b, ofVec3f c, ofVec3f d);
    void addFace(ofRectangle r);
    void addBox(ofRectangle r, float height);

    void translate(ofVec3f pos);
    void translate(float x, float y, float z);
    void rotate(float angle, ofVec3f axis);
    void scale(float x, float y, float z=1);
    void invertNormals();
    
//    ofVec3f getSize();
//    void unifyVertices();

    ofxMesh &addMesh(ofMesh b);
};

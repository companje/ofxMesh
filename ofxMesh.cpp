//
//  ofxMesh.cpp
//
//  Created by Rick Companje on 10/20/11.
//  Copyright (c) 2011 Globe4D. All rights reserved.
//

#include "ofxMesh.h"

void ofxMesh::addFace(ofVec3f a, ofVec3f b, ofVec3f c) {
    ofVec3f normal = ((c - a).cross(b - a)).normalize();
    
	addNormal(normal);
	addVertex(a);
	addNormal(normal);
	addVertex(b);
	addNormal(normal);
	addVertex(c);
    
    addIndex(getNumIndices());
    addIndex(getNumIndices());
    addIndex(getNumIndices());    
}

void ofxMesh::addFace(ofVec3f a, ofVec3f b, ofVec3f c, ofVec3f d) {
    addFace(a, b, d);
	addFace(b, c, d);
}

void ofxMesh::addFace(ofRectangle r) {
    ofVec2f lt(r.x,r.y);
    ofVec2f rt(r.x+r.width,r.y);
    ofVec2f rb(r.x+r.width,r.y+r.height);
    ofVec2f lb(r.x,r.y+r.height);
    addFace(lt,lb,rb,rt);
}

void ofxMesh::addBox(ofRectangle r, float height) {
    
    ofVec3f a(r.x,r.y);
    ofVec3f b(r.x,r.y+r.height);
    ofVec3f c(r.x+r.width,r.y+r.height);
    ofVec3f d(r.x+r.width,r.y);

    ofVec3f e = a+ofVec3f(0,0,height);
    ofVec3f f = b+ofVec3f(0,0,height);
    ofVec3f g = c+ofVec3f(0,0,height);
    ofVec3f h = d+ofVec3f(0,0,height);
    
    ofxMesh mesh;
        
    mesh.addFace(a,b,c,d); //top
    mesh.addFace(h,g,f,e); //bottom
    mesh.addFace(b,f,g,c); //front
    mesh.addFace(c,g,h,d); //right
    mesh.addFace(d,h,e,a); //back
    mesh.addFace(a,e,f,b); //left
    
    addMesh(mesh);
}

void ofxMesh::translate(ofVec3f pos) {
    for (int i=0; i<getNumVertices(); i++) {
        getVertices()[i] += pos;
    }
}

void ofxMesh::translate(float x, float y, float z) {
    for (int i=0; i<getNumVertices(); i++) {
        getVertices()[i] += ofVec3f(x,y,z);
    }
}

void ofxMesh::rotate(float angle, ofVec3f axis) {
    for (int i=0; i<getNumVertices(); i++) {
        getVertices()[i].rotate(angle, axis);
    }
}

void ofxMesh::scale(float x, float y, float z) {
    for (int i=0; i<getNumVertices(); i++) {
        getVertices()[i].x *= x;
        getVertices()[i].y *= y;
        getVertices()[i].z *= z;
    }
}

void ofxMesh::invertNormals() {
    for (int i=0; i<getNumNormals(); i++) {
        getNormals()[i] *= -1;
    }
}

ofxMesh &ofxMesh::addMesh(ofMesh b) {
    
    int numVertices = getNumVertices();    
    int numIndices = getNumIndices();
    
    //add b
    addVertices(b.getVertices());
    addNormals(b.getNormals());
    addIndices(b.getIndices());
    
    //shift indices for b
    for (int i=0; i<b.getNumIndices(); i++) {
        getIndices()[numIndices+i] += numVertices;
    }
    
    return *this;
}

//ofVec3f ofxMesh::getSize() {
//    for (int i=0; i<getNumVertices(); i++) {
//        getVertices()[i] += pos;
//    }
//
//}


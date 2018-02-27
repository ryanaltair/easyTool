// this is work for openFrameworks
// written by ryanaltair
float calcVolumeMilliliter(ofMesh m){
    float vol=0;
    for (size_t i=0; i<m.getNumIndices(); i+=3) {
        ofVec3f p1=m.getVertex(m.getIndex(i));
        ofVec3f p2=m.getVertex(m.getIndex(i+1));
        ofVec3f p3=m.getVertex(m.getIndex(i+2));
        vol+= p1.dot(p2.getCrossed(p3)) / 6.0f;// add SignedVolumeOfTriangle
    }
    return vol*0.001;// make it to milliliter
}

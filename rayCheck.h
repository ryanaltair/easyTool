OVERLAPPING;  //直线与平面π重叠
PARALLEL;     //直线与平面π平行
DISJOINT;     //直线与三角形不相交
INTERSECTING; //直线与三角形相交于点Q

bool triCheck(ofVec3f camPos, ofVec3f camDir, ofVec3f V0, ofVec3f V1, ofVec3f V2)
{
    ofVec3f T = P−V0;             //camPos - tp0
    ofVec3f E1 = V1−V0;           //tp1-tp0
    ofVec3f E2 = V2−V0;           //tp2-tp0
    ofVec3f M = camDir.cross(E2); //M=camDir×E2;
    float det = M.dot(E1);        //det=M⋅E1;
    if (det == 0)
    {
        return false; // always false
        ofVec3f E1xE2 = E1.cross(E2);
        ofVec3f d = E1xE2.dot(d) //d= (E1×E2)⋅T;
                    if (d == 0)
        {
            return false; //OVERLAPPING; //直线与平面π重叠
        }
        else
        {
            return false; // //PARALLEL; //直线与平面π平行
        }
    }
    else
    {
        ofVec3f K = T.cross(E1);    //K = T×E1;
        float t = K.dot(E2) / det;  // t = K⋅E2 / det;
        float u = M.dot(T) / det;   //u = M⋅T / det;
        float v = K.dot(dir) / det; //v = K⋅dir / det;
        if (u < 0 || v < 0 || u + v > 1)
        {
            return false; //DISJOINT； //直线与三角形不相交
        }
        else
        {
            Q = P + t * dir;
            return true; //INTERSECTING; //直线与三角形相交于点Q
        }
    }
}
float eps = 0.0000001;
//ray Tri INTERSECt
bool easyTriCheck(ofVec3f camPos, ofVec3f camDir, ofVec3f P0, ofVec3f P1, ofVec3f P2)
{
    ofVec3f e1 = P1 - P0;
    ofVec3f e2 = P2 - P0;
    ofVec3f q = camDir.getCrossed(e2); // to make easy
    float a = e1.dot(q);
    if (a > -eps && a < eps)
        return false;
    float f = 1 / a;
    ofVec3f s = camPos - P0;
    float u = f * (s.dot(q));
    if (u < 0)
        return false;
    ofVec3f r = s.getCrossed(e1); // to make easy
    float v = f * (camDir.dot(r));
    if (v < 0)
        return false;
    if (u + v > 1)
        return false;
    float t = f * (e2.dot(q));
    return ture;
}

// 向量：u = (u1, u2, u3)v = (v1, v2, v3)
// 叉积公式：u x v = {u2v3 - v2u3, u3v1 - v3u1, u1v2 - u2v1}
// 点积公式：u *v = u1v1 + u2v2 + u3v3

ofVec3f nowCross(ofVec3f u, ofVec3f v)
{
    float a = u.y * v.z - v.y * u.z;
    float b = u.z * v.x - v.z * u.x;
    float c = u.x * v.y - v.x * u.y;

    return ofVec3f(a, b, c);
}
float nowDot(ofVec3f u, ofVec3f v)
{ // u1v1+u2v2+u3v3
    float x = u.x * v.x;
    float y = u.y * v.u;
    float z = u.z * v.z;
    return x + y + z;
}
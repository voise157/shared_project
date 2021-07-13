#include "MinPhys.h"

bool MinPhys::circHitCirc(float x1, float x2, float y1, float y2, float r1, float r2) {
    return ((((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))) < ((r1 + r2) * (r1 + r2)));
}
bool MinPhys::circHitCircSFML(float x1, float x2, float y1, float y2, float r1, float r2) {
    return circHitCirc(x1+r1, x2+r2, y1+r1, y2+r2, r1, r2);
}
bool MinPhys::get_line_intersection(float p0_x, float p0_y, float p1_x, float p1_y,
    float p2_x, float p2_y, float p3_x, float p3_y)
{
    float s1_x, s1_y, s2_x, s2_y;
    s1_x = p1_x - p0_x;     s1_y = p1_y - p0_y;
    s2_x = p3_x - p2_x;     s2_y = p3_y - p2_y;

    float s, t;
    s = (-s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y)) / (-s2_x * s1_y + s1_x * s2_y);
    t = ( s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x)) / (-s2_x * s1_y + s1_x * s2_y);

    if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
    {
        // Collision detected
        return 1;
    }

    return 0; // No collision
}

std::pair <float, float> MinPhys::get_line_intersection_point(float p0_x, float p0_y, float p1_x, float p1_y,
    float p2_x, float p2_y, float p3_x, float p3_y)
{
    float s1_x, s1_y, s2_x, s2_y;
    s1_x = p1_x - p0_x;     s1_y = p1_y - p0_y;
    s2_x = p3_x - p2_x;     s2_y = p3_y - p2_y;

    float s, t;
    s = (-s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y)) / (-s2_x * s1_y + s1_x * s2_y);
    t = ( s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x)) / (-s2_x * s1_y + s1_x * s2_y);


        std::pair<float, float> ret;
        ret.first = p0_x + (t * s1_x);
        ret.second = p0_x + (t * s1_x);
        return ret;

}

float MinPhys::getRange(float x1, float x2, float y1, float y2) {
    float X, Y, RANGE;
    if(x1 > x2) {
        X = x1 - x2;
    } else {
        X = x2 - x1;
    }
    if(y1 > y2) {
        Y = y1 - y2;
    } else {
        Y = y2 - y1;
    }
    RANGE = X + Y;
    return RANGE;
}
float MinPhys::getDistance(float x1, float  x2, float  y1, float y2, float z1, float  z2) {
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1)); // +((z2-z1)*(z2-z1))
}
std::pair<float, float> MinPhys::getPointOnCirc(float radius, float angle, float X, float Y) {
    std::pair<float, float> ret;
    ret.first = radius*cos(angle*3.14f/180.0f)+X;
    ret.second= radius*sin(angle*3.14f/180.0f)+Y;
    return ret;
}

float MinPhys::getAngleFromPointOnCirc(float radius, float X, float Y, float XC, float YC) {
   //X = radius*cos(angle[0]*3.14/180)+X;
   //Y = radius*sin(angle[0]*3.14/180)+Y;
   float sideA = radius;
   float xc = XC, yc = YC;
   auto point = getPointOnCirc(radius, 0, xc, yc);

   float sideB = getDistance(point.first,X, point.second, Y);
   float notAngle = acos(sideB/(2*sideA));
   float angle = 180 - notAngle*2;
   return angle;
}
std::pair<float ,float> MinPhys::getMiddlePointOfLine(float x1, float x2, float y1, float y2) {
    std::pair<float ,float> point;
    point.first = (x1+x2)/2;
    point.second = (y1+y2)/2;
    return point;
}
std::pair<float ,float> MinPhys::findPerpendicularPoint(float x1,float x2,float x3,float y1,float y2,float y3) {
    std::pair<float ,float> coords;
    float dx = x2 - x1;
    float dy = y2 - y1;
    float mag = sqrt(dx*dx+dy*dy);
    dx /= mag;
    dy /= mag;
    float lambda  = (dx * (x3 - x1)) + (dy * (y3 - y1));
    coords.first  = (dx * lambda) + x1;
    coords.second = (dy * lambda) + y1;
    return coords;
}
bool MinPhys::lineHitCirc(std::pair<float ,float> perpendicularPoint, float xc, float yc, float radius) {
    if(getDistance(perpendicularPoint.first, xc, perpendicularPoint.second, yc)<=radius) {
        return true;
    } else {
        return false;
    }
}
;




MVec::MVec(float XV, float YV) {
    xv=XV;
    yv=YV;
}
MVec MVec::getMVec() {
    return MVec(xv, yv);
}
MVec MVec::vecCollision(MVec vec) {
    return MVec((xv+vec.xv)/2, (yv+vec.yv)/2);
}


FPoint::FPoint(float X, float Y) {
    x=X;
    y=Y;
}
FPoint::FPoint() {
    x=0;
    y=0;
}
float FPoint::getDistance(FPoint p1, FPoint p2) {
    return MinPhys::getDistance(p1.x, p2.x,p1.y,p2.y);
}
void FPoint::move(MVec vector) {
    x+=vector.xv;
    y+=vector.yv;
}
void FPoint::antiMove(MVec vector) {
    x-=vector.xv;
    y-=vector.yv;
}
FPoint FPoint::getPoint() {
    FPoint point(x, y);
    return point;
}




Circ::Circ(FPoint POINT, float RADIUS) : FPoint(POINT.x, POINT.y) {
    radius = RADIUS;
}
float Circ::r() {
    return radius;
}
void Circ::setR(float RADIUS) {
    radius = RADIUS;
}
bool Circ::circHitCirc(Circ circ1) {
    return MinPhys::circHitCirc(circ1.x, x, circ1.y, y, circ1.r(), r());
}
Circ Circ::getCirc() {
    return Circ(FPoint(x, y), radius);
}

CircObj::CircObj(FPoint POINT, float RADIUS, float VecX, float VecY) : Circ(POINT, RADIUS), MVec(VecX, VecY) {

}
void CircObj::mov() {
    x+=xv;
    y+=yv;

}
void CircObj::antiMov() {
    x-=xv;
    y-=yv;
}
bool CircObj::collisionCirc(Circ circ) {
    if(Circ::circHitCirc(circ)) {
        return true;
    } else {
        return false;
    }
}
/*bool operator==(CircObj &obj1, CircObj &obj2) {
    auto circ1 = obj1.getCirc();
    auto circ2 = obj2.getCirc();
    if(Circ::circHitCirc(circ1, circ2)) {
        return true;
    } else {
        return false;
    }
}*/


FLine::FLine(FPoint POINT1, FPoint POINT2) {
    p1 = POINT1;
    p2 = POINT2;
}
FLine FLine::getFLine() {
    return FLine(p1, p2);
}
float FLine::getDistance() {
    return MinPhys::getDistance(p1.x, p2.x, p1.y, p2.y);
}
FPoint FLine::getMidPoint() {
    auto T = MinPhys::getMiddlePointOfLine(p1.x, p2.x, p1.y, p2.y);
    return FPoint(T.first, T.second);
}
bool FLine::hitLine(FLine line) {
    bool isParallel = MinPhys::get_line_intersection(p1.x, p1.y, p2.x, p2.y, line.p1.x, line.p1.y, line.p2.x, line.p2.y);
    if(isParallel) {
        auto hitPoint = MinPhys::get_line_intersection_point(p1.x, p1.y, p2.x, p2.y, line.p1.x, line.p1.y, line.p2.x, line.p2.y);
        FPoint hitP(hitPoint.first, hitPoint.second);
        FPoint midOne = getMidPoint();
        FPoint midTwo = line.getMidPoint();
        bool isHitOne = (FLine(midOne, hitP).getDistance() <= getDistance()/2);
        bool isHitTwo = (FLine(midTwo, hitP).getDistance() <= line.getDistance()/2);
        if(!isParallel && isHitOne && isHitTwo) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}
FPoint FLine::findPerpPoint(FPoint p1,FPoint p2,FPoint p3) {
    auto point = MinPhys::findPerpendicularPoint(p1.x, p2.x, p3.x, p1.y, p2.y, p3.y);
    return FPoint(point.first, point.second);
}
bool FLine::lineHitCirc(FPoint  PerpPoint, FPoint CircCenter, float radius) {
        std::pair<float ,float> perpendicularPoint;
        perpendicularPoint.first = PerpPoint.x;
        perpendicularPoint.second = PerpPoint.y;
        float xc = CircCenter.x;
        float yc = CircCenter.y;
        return MinPhys::lineHitCirc(perpendicularPoint, xc, yc, radius);
}
bool FLine::lineHitCirc(FPoint p1,FPoint p2,FPoint CircCenter, float radius) {
    FPoint point = findPerpPoint(p1, p2, CircCenter);
    bool isLineHitCirc = lineHitCirc(point, CircCenter, radius);
    bool isInSise = hitLine(FLine(CircCenter, point));
    if(isLineHitCirc && isInSise) {
        return true;
    } else {
        return false;
    }
}


lineObj::lineObj(FPoint POINT1, FPoint POINT2, FPoint Vector) : FLine(POINT1, POINT2) ,MVec(Vector.x, Vector.y) {

}
bool lineObj::lineHitCirc(FPoint p1,FPoint p2,FPoint CircCenter, float radius) {
    if(FLine::lineHitCirc(p1, p2, CircCenter, radius)) {
        return true;
    } else {
        return false;
    }
}
bool lineObj::hitLine(FLine line) {
    if(FLine::hitLine(line)) {
        return true;
    } else {
        return false;
    }
}
void lineObj::move() {
    p1.move(MVec(xv, yv));
    p2.move(MVec(xv, yv));
}
void lineObj::antiMove() {
    p1.move(MVec(-xv, -yv));
    p2.move(MVec(-xv, -yv));
}



PPoint::PPoint(float XCenter, float YCenter, float Radius, float Angle) : FPoint(XCenter, YCenter) {
    radius = Radius;
    angle = Angle;
}
FPoint PPoint::getFPoint() {

    auto Point = MinPhys::getPointOnCirc(radius, angle, this->getCenter().x, this->getCenter().y);
    FPoint point(Point.first, Point.second);
    return point;
}
void PPoint::setCenter(FPoint center) {
    x = center.x;
    y = center.y;
}
FPoint PPoint::getCenter() {
    return getPoint();
}
float PPoint::getPDistance(FPoint point) {
    return FPoint::getDistance(getFPoint(), point);
}
float PPoint::getDistanceToCenter(FPoint point) {
    return FPoint::getDistance(getCenter(), point);
}



PCirc::PCirc(FPoint center, float centerRad, Circ circ, float angle) : Circ(circ.getPoint(), circ.r()), PPoint(center.x, center.y, centerRad, angle) {

}
void PCirc::setAngle(float Angle) {
    PPoint::angle = Angle;
    reMath();
}
float PCirc::angle() {
    return PPoint::angle;
}
void PCirc::reMath() {
    Circ::x = PPoint::getFPoint().x;
    Circ::y = PPoint::getFPoint().y;
}
void PCirc::rotate(float Angle) {
    PPoint::angle += Angle;
    reMath();
}



PLine::PLine(FPoint CENTER, float Rad1, float Ang1, float Rad2, float Ang2) : FLine(PPoint(CENTER.x, CENTER.y, Rad1, Ang1).getFPoint(), PPoint(CENTER.x, CENTER.y, Rad2, Ang2).getFPoint()) {
    center.x = CENTER.x;
    center.y = CENTER.y;
    radius1 = Rad1;
    radius2 = Rad2;
    angle1 = Ang1;
    angle2 = Ang2;
}
void PLine::reMath() {
    p1 = PPoint(center.x, center.y, radius1, angle1+angle).getFPoint();
    p2 = PPoint(center.x, center.y, radius2, angle2+angle).getFPoint();
}
void PLine::rotate(float rotAngle) {
    angle+=rotAngle;
    reMath();
}
FLine PLine::getLine() {
    return FLine(p1, p2);
}




PVEC::PVEC(float angle, float radius) : MVec(PPoint(0, 0, radius, angle).getFPoint().x, PPoint(0, 0, radius, angle).getFPoint().y) {
    ang = angle;
    rad = radius;
}
void PVEC::reMath() {
    xv = PPoint(0, 0, rad, ang).getFPoint().x;
    yv = PPoint(0, 0, rad, ang).getFPoint().y;
}
void PVEC::fromMVec(MVec vec) {
    rad = MinPhys::getDistance(0, vec.xv, 0, vec.yv);
    ang = MinPhys::getAngleFromPointOnCirc(rad, vec.xv, vec.yv, 0, 0);
}
MVec PVEC::getVec() {
    return MVec(xv, yv);
}
void PVEC::rotate(float angle) {
    ang+=angle;
    reMath();
}



PObjLine::PObjLine(float ANGLE, float radius, FPoint CENTER, float Rad1, float Ang1, float Rad2, float Ang2) : PLine(CENTER, Rad1, Ang1, Rad2, Ang2), PVEC(ANGLE, radius) {
    angle = ANGLE;
}
void PObjLine::ReMath() {
    PLine::reMath();
    PVEC::reMath();
    //angle = ang;
}
void PObjLine::rotateObj(float ANGLE) {
    angle+=ANGLE;
}
void PObjLine::rotateVec(float ANGLE) {
    ang+=ANGLE;
}
void PObjLine::move() {
    center.move(getVec());
    ReMath();
}



PObjCirc::PObjCirc(float angle, float radius, FPoint center, float centerRad, Circ circ, float angl) : PCirc(center, centerRad, circ, angl), PVEC(angle, radius) {

}
void PObjCirc::ReMath() {
    PCirc::reMath();
    PVEC::reMath();
    //angle = ang;
}
void PObjCirc::mov() {
    PCirc::PPoint::move(this->getVec());
    void ReMath();
}
void PObjCirc::rotateObj(float ANGLE) {
    PCirc::PPoint::angle+=ANGLE;
    void ReMath();
}
void PObjCirc::rotateVec(float ANGLE) {
    ang+=ANGLE;
}




extern "C" {

__declspec(dllexport) void del_MVec(void* obj) {
    delete static_cast<MVec*>(obj);
}

__declspec(dllexport) void del_FPoint(void* obj) {
    delete static_cast<FPoint*>(obj);
}

__declspec(dllexport) void del_Circ(void* obj) {
    delete static_cast<Circ*>(obj);
}

__declspec(dllexport) void del_CircObj(void* obj) {
    delete static_cast<CircObj*>(obj);
}

__declspec(dllexport) void del_FLine(void* obj) {
    delete static_cast<FLine*>(obj);
}

__declspec(dllexport) void del_lineObj(void* obj) {
    delete static_cast<lineObj*>(obj);
}

__declspec(dllexport) void del_PPoint(void* obj) {
    delete static_cast<PPoint*>(obj);
}

__declspec(dllexport) void del_PCirc(void* obj) {
    delete static_cast<PCirc*>(obj);
}

__declspec(dllexport) void del_PLine(void* obj) {
    delete static_cast<PLine*>(obj);
}

__declspec(dllexport) void del_PVEC(void* obj) {
    delete static_cast<PVEC*>(obj);
}

__declspec(dllexport) void del_PObjLine(void* obj) {
    delete static_cast<PObjLine*>(obj);
}

__declspec(dllexport) void del_PObjCirc(void* obj) {
    delete static_cast<PObjCirc*>(obj);
}

__declspec(dllexport) void* MVec_new(float XV, float YV) {
    return new(std::nothrow) MVec(XV, YV);
}

__declspec(dllexport) void* MVec_getMVec(void* obj, void* vec) {
    return new(std::nothrow) MVec(static_cast<MVec*>(obj)[0].vecCollision(static_cast<MVec*>(vec)[0]));
}

__declspec(dllexport) void* MVec_vecCollsion(void* obj) {
    return new(std::nothrow) MVec(static_cast<MVec*>(obj)[0].getMVec());
}

__declspec(dllexport) float FPoint_getDistance(void* one, void* two) {
    return FPoint::getDistance(static_cast<FPoint*>(one)[0], static_cast<FPoint*>(two)[0]);
}

__declspec(dllexport) void FPoint_move(void* obj, void* vector) {
    static_cast<FPoint*>(obj)[0].move(static_cast<MVec*>(vector)[0]);
}

/*
__declspec(dllexport) void FPoint_move(FPoint* obj, MVec* vector) {
    obj[0].move(*vector);
}
*/

__declspec(dllexport) void* FPoint_getPoint(void* obj) {
    return new(std::nothrow) FPoint(static_cast<FPoint*>(obj)[0].getPoint());
}

__declspec(dllexport) void* FPoint_new(float X, float Y) {
    return new(std::nothrow) FPoint(X, Y);
}

__declspec(dllexport) void* Circ_new(void* POINT, float RADIUS) {
    return new(std::nothrow) Circ(static_cast<FPoint*>(POINT)[0], RADIUS);
}

__declspec(dllexport) float Circ_r(void* obj) {
    return static_cast<Circ*>(obj)[0].r();
}

__declspec(dllexport) void Circ_setR(void* obj, float radius) {
    static_cast<Circ*>(obj)[0].setR(radius);
}

__declspec(dllexport) bool Circ_circHitCirc(void* circ1, void* circ2) {
    return static_cast<Circ*>(circ1)[0].circHitCirc(static_cast<Circ*>(circ2)[0]);
}

__declspec(dllexport) void* Circ_getCirc(void* obj) {
    return new(std::nothrow) Circ(static_cast<Circ*>(obj)[0].getCirc());
}

__declspec(dllexport) void* CircObj_new(void* POINT, float RADIUS, float VecX, float VecY) {
    return new(std::nothrow) CircObj(static_cast<FPoint*>(POINT)[0], RADIUS, VecX, VecY);
}

__declspec(dllexport) void CircObj_move(void* obj, void* vec) {
    static_cast<CircObj*>(obj)[0].move(static_cast<MVec*>(vec)[0]);
}

__declspec(dllexport) bool CircObj_collisionCirc(void* obj, void* circ) {
    return static_cast<CircObj*>(obj)[0].collisionCirc(static_cast<Circ*>(circ)[0]);
}

__declspec(dllexport) void* FLine_new(void* POINT1, void* POINT2) {
    return new(std::nothrow) FLine(static_cast<FPoint*>(POINT1)[0], static_cast<FPoint*>(POINT2)[0]);
}

__declspec(dllexport) void* getFLine_FLine(void* obj) {
    return new(std::nothrow) FLine(static_cast<FLine*>(obj)[0].getFLine());
}

__declspec(dllexport) float FLine_getDistance(void* obj) {
    return static_cast<FLine*>(obj)[0].getDistance();
}

__declspec(dllexport) void* FLine_getMidPoint(void* obj) {
    return new(std::nothrow) FPoint(static_cast<FLine*>(obj)[0].getMidPoint());
}

__declspec(dllexport) bool FLine_hitLine(void* obj, void* line) {
    return static_cast<FLine*>(obj)[0].hitLine(static_cast<FLine*>(line)[0]);
}

__declspec(dllexport) void* FLine_findPerpPoint(void* obj, void* p1,void* p2,void* p3) {
    return new(std::nothrow) FPoint(static_cast<FLine*>(obj)[0].findPerpPoint(static_cast<FPoint*>(p1)[0], static_cast<FPoint*>(p2)[0], static_cast<FPoint*>(p3)[0]));
}

__declspec(dllexport) bool FLine_linehitCirc(void* obj, void* p1,void* p2,void* CircCenter, float radius) {
    return static_cast<FLine*>(obj)[0].lineHitCirc(static_cast<FPoint*>(p1)[0], static_cast<FPoint*>(p2)[0], static_cast<FPoint*>(CircCenter)[0], radius);
}

__declspec(dllexport) void* lineObj_new(void* POINT1, void* POINT2, void* Vector) {
    return new(std::nothrow) lineObj(static_cast<FPoint*>(POINT1)[0], static_cast<FPoint*>(POINT2)[0], static_cast<FPoint*>(Vector)[0]);
}

__declspec(dllexport) bool lineObj_hitLine(void* obj, void* line) {
    return static_cast<lineObj*>(obj)[0].hitLine(static_cast<FLine*>(line)[0]);
}

__declspec(dllexport) void lineObj_move(void* obj) {
    static_cast<lineObj*>(obj)[0].move();
}
__declspec(dllexport) void lineObj_antiMove(void* obj) {
    static_cast<lineObj*>(obj)[0].antiMove();
}

__declspec(dllexport) bool lineObj_lineHitCirc(void* obj, void* p1,void* p2,void* CircCenter, float radius) {
    return static_cast<lineObj*>(obj)[0].lineHitCirc(static_cast<FPoint*>(p1)[0], static_cast<FPoint*>(p2)[0], static_cast<FPoint*>(CircCenter)[0], radius);
}

__declspec(dllexport) bool circHitCirc(float x1, float x2, float y1, float y2, float r1, float r2) {
    return ((((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))) < ((r1 + r2) * (r1 + r2)));
}
__declspec(dllexport) bool circHitCircSFML(float x1, float x2, float y1, float y2, float r1, float r2) {
    return circHitCirc(x1+r1, x2+r2, y1+r1, y2+r2, r1, r2);
}
__declspec(dllexport) bool get_line_intersection(float p0_x, float p0_y, float p1_x, float p1_y,
    float p2_x, float p2_y, float p3_x, float p3_y)
{
    return MinPhys::get_line_intersection(p0_x, p0_y, p1_x, p1_y, p2_x, p2_y, p3_x, p3_y);
}

__declspec(dllexport) void* get_line_intersection_point(float p0_x, float p0_y, float p1_x, float p1_y,
    float p2_x, float p2_y, float p3_x, float p3_y)
{
    auto pair = MinPhys::get_line_intersection_point(p0_x, p0_y, p1_x, p1_y, p2_x, p2_y, p3_x, p3_y);
    return new(std::nothrow) FPoint(pair.first, pair.second);
}

__declspec(dllexport) float getRange(float x1, float x2, float y1, float y2) {
    float X, Y, RANGE;
    if(x1 > x2) {
        X = x1 - x2;
    } else {
        X = x2 - x1;
    }
    if(y1 > y2) {
        Y = y1 - y2;
    } else {
        Y = y2 - y1;
    }
    RANGE = X + Y;
    return RANGE;
}
__declspec(dllexport) float getDistance(float x1, float  x2, float  y1, float y2) {
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)); // +((z2-z1)*(z2-z1))
}
__declspec(dllexport) void* getPointOnCirc(float radius, float angle, float X, float Y) {
   return new(std::nothrow) FPoint(radius*cos(angle*3.14f/180.0f)+X, radius*sin(angle*3.14f/180.0f)+Y);
}

__declspec(dllexport) void* PPoint_new(float XCenter, float YCenter, float Radius, float Angle) {
    return new(std::nothrow) PPoint(XCenter, YCenter, Radius, Angle);
}
__declspec(dllexport) void* getFPoint_PPoint(void* obj) {
    FPoint* point = new FPoint(static_cast<PPoint*>(obj)[0].getFPoint());
    return point;
}
__declspec(dllexport) void* getCenter_PPoint(void* obj) {
    FPoint* point = new FPoint(static_cast<PPoint*>(obj)[0].getCenter());
    return point;
}
__declspec(dllexport) void setCenter_PPoint(void* obj, void* point) {
    static_cast<PPoint*>(obj)[0].setCenter(static_cast<FPoint*>(point)[0]);
}
__declspec(dllexport) float getPDistance_PPoint(void* obj, void* point) {
    return static_cast<PPoint*>(obj)[0].getPDistance(static_cast<FPoint*>(point)[0]);
}
__declspec(dllexport) float getDistanceToCenter_PPoint(void* obj, void* point) {
    return static_cast<PPoint*>(obj)[0].getDistanceToCenter(static_cast<FPoint*>(point)[0]);
}


__declspec(dllexport) void* PCirc_new(void* center, float centerRad, void* circ, float angle) {
    return new(std::nothrow) PCirc(static_cast<FPoint*>(center)[0], centerRad, static_cast<Circ*>(circ)[0], angle);
}
__declspec(dllexport) void PCirc_setAngle(void *obj, float Angle) {
    static_cast<PCirc*>(obj)[0].setAngle(Angle);
}
__declspec(dllexport) float PCirc_angle(void* obj) {
    return static_cast<PCirc*>(obj)[0].angle();
}
__declspec(dllexport) void PCirc_reMath(void* obj) {
    static_cast<PCirc*>(obj)[0].reMath();
}
__declspec(dllexport) void PCirc_rotate(void* obj, float Angle) {
    static_cast<PCirc*>(obj)[0].rotate(Angle);
}


__declspec(dllexport) void*  getLine_PLine(void* obj) {
    FLine* line = new FLine(static_cast<PLine*>(obj)[0].getLine());
    return line;
}
__declspec(dllexport) void rotate_PLine(void* obj, float angle) {
    static_cast<PLine*>(obj)[0].rotate(angle);
}
__declspec(dllexport) void reMath_PLine(void* obj) {
    static_cast<PLine*>(obj)[0].reMath();
}
__declspec(dllexport) void* PLine_new(void* CENTER, float Rad1, float Ang1, float Rad2, float Ang2) {
    return new(std::nothrow) PLine(static_cast<FPoint*>(CENTER)[0], Rad1, Ang1, Rad2, Ang2);
}

__declspec(dllexport) void rotate_PVEC(void* obj, float angle) {
    static_cast<PVEC*>(obj)[0].rotate(angle);
}
__declspec(dllexport) void* getVec_PVEC(void* obj) {
    MVec* vec = new MVec(static_cast<PVEC*>(obj)[0].getVec());
    return vec;
}
__declspec(dllexport) void PVEC_fromMVec(void* obj, void* vec) {
    static_cast<PVEC*>(obj)[0].fromMVec(static_cast<MVec*>(vec)[0]);
}
__declspec(dllexport) void PVEC_reMath(void* obj) {
    static_cast<PVEC*>(obj)[0].reMath();
}
__declspec(dllexport) void* PVEC_new(float angle, float radius) {
    return new(std::nothrow) PVEC(angle, radius);
}

__declspec(dllexport) void* PObjLine_new(float ANGLE, float radius, FPoint CENTER, float Rad1, float Ang1, float Rad2, float Ang2) {
    return new(std::nothrow) PObjLine(ANGLE, radius, CENTER, Rad1, Ang1, Rad2, Ang2);
}

__declspec(dllexport) void PObjLine_reMath(void *obj) {
    static_cast<PObjLine*>(obj)[0].ReMath();
}

__declspec(dllexport) void PObjLine_rotateObj(void *obj, float ANGLE) {
    static_cast<PObjLine*>(obj)[0].rotateObj(ANGLE);
}

__declspec(dllexport) void PObjLine_rotateVec(void *obj, float ANGLE) {
    static_cast<PObjLine*>(obj)[0].rotateObj(ANGLE);
}

__declspec(dllexport) void move_PObjLine(void *obj) {
    static_cast<PObjLine*>(obj)[0].move();
}
__declspec(dllexport) void* getMiddlePointOfLine(float x1, float x2, float y1, float y2) {
    FPoint *point = new FPoint();
    point[0].x = (x1+x2)/2;
    point[0].y = (y1+y2)/2;
    return point;
}
__declspec(dllexport) void* findPerpendicularPoint(float x1,float x2,float x3,float y1,float y2,float y3) {
    FPoint* coords = new FPoint();
    float dx = x2 - x1;
    float dy = y2 - y1;
    float mag = sqrt(dx*dx+dy*dy);
    dx /= mag;
    dy /= mag;
    float lambda  = (dx * (x3 - x1)) + (dy * (y3 - y1));
    coords[0].x  = (dx * lambda) + x1;
    coords[0].y = (dy * lambda) + y1;
    return coords;
}
__declspec(dllexport) bool lineHitCirc(void* perpendicularPoint, float xc, float yc, float radius) {
    if(getDistance(static_cast<FPoint*>(perpendicularPoint)[0].x, xc, static_cast<FPoint*>(perpendicularPoint)[0].y, yc)<=radius) {
        return true;
    } else {
        return false;
    }
}


__declspec(dllexport) void* PObjCirc_new(float angle, float radius, void* center, float centerRad, void* circ, float angl) {
    return new(std::nothrow) PObjCirc(angle, radius, static_cast<FPoint*>(center)[0], centerRad, static_cast<Circ*>(circ)[0], angl);
}
__declspec(dllexport) void reMath_PObjCirc(void *obj) {
    static_cast<PObjCirc*>(obj)[0].ReMath();
}
__declspec(dllexport) void move_PObjCirc(void *obj) {
    static_cast<PObjCirc*>(obj)[0].mov();
}
__declspec(dllexport) void rotateObj_PObjCirc(void *obj, float angle) {
    static_cast<PObjCirc*>(obj)[0].rotateObj(angle);
}
__declspec(dllexport) void rotateVec_PObjCirc(void *obj, float angle) {
    static_cast<PObjCirc*>(obj)[0].rotateVec(angle);
}
__declspec(dllexport) float percentOf(float part, float all) {
    float onePer = all/100;
    return part/onePer;
}
__declspec(dllexport) float onePer(float all) {
    return all/100;
}
__declspec(dllexport) float hundredOf(float onePercent) {
    return onePercent*100;
}
__declspec(dllexport) float valueOf(float percent, float all) {
    return onePer(all)*percent;
}

__declspec(dllexport) float MVec_xv(void* obj) {
    return static_cast<MVec*>(obj)[0].xv;
}

__declspec(dllexport) float MVec_yv(void* obj) {
    return static_cast<MVec*>(obj)[0].yv;
}

__declspec(dllexport) float FPoint_x(void* obj) {
    return static_cast<FPoint*>(obj)[0].x;
}

__declspec(dllexport) float FPoint_y(void* obj) {
    return static_cast<FPoint*>(obj)[0].y;
}

__declspec(dllexport) float Circ_x(void* obj) {
    return static_cast<Circ*>(obj)[0].x;
}

__declspec(dllexport) float Circ_y(void* obj) {
    return static_cast<Circ*>(obj)[0].y;
}

__declspec(dllexport) float CircObj_x(void* obj) {
    return static_cast<CircObj*>(obj)[0].x;
}

__declspec(dllexport) float CircObj_y(void* obj) {
    return static_cast<CircObj*>(obj)[0].y;
}

__declspec(dllexport) float CircObj_xv(void* obj) {
    return static_cast<CircObj*>(obj)[0].xv;
}

__declspec(dllexport) float CircObj_yv(void* obj) {
    return static_cast<CircObj*>(obj)[0].yv;
}

__declspec(dllexport) void* FLine_p1(void* obj) {
    return new(std::nothrow) FPoint(static_cast<FLine*>(obj)[0].p1);
}

__declspec(dllexport) void* FLine_p2(void* obj) {
    return new(std::nothrow) FPoint(static_cast<FLine*>(obj)[0].p2);
}

__declspec(dllexport) void* lineObj_p1(void* obj) {
    return new(std::nothrow) FPoint(static_cast<lineObj*>(obj)[0].p1);
}

__declspec(dllexport) void* lineObj_p2(void* obj) {
    return new(std::nothrow) FPoint(static_cast<lineObj*>(obj)[0].p2);
}
__declspec(dllexport) float lineObj_xv(void* obj) {
    return static_cast<lineObj*>(obj)[0].xv;
}

__declspec(dllexport) float lineObj_yv(void* obj) {
    return static_cast<lineObj*>(obj)[0].yv;
}

__declspec(dllexport) float PPoint_xc(void* obj) {
    return static_cast<PPoint*>(obj)[0].x;
}

__declspec(dllexport) float PPoint_yc(void* obj) {
    return static_cast<PPoint*>(obj)[0].y;
}
__declspec(dllexport) float PPoint_radius(void* obj) {
    return static_cast<PPoint*>(obj)[0].radius;
}

__declspec(dllexport) float PPoint_angle(void* obj) {
    return static_cast<PPoint*>(obj)[0].angle;
}
__declspec(dllexport) float PCirc_x(void* obj) {
    return static_cast<PCirc*>(obj)[0].Circ::x;
}

__declspec(dllexport) float PCirc_y(void* obj) {
    return static_cast<PCirc*>(obj)[0].Circ::y;
}
__declspec(dllexport) float PCirc_PPoint_radius(void* obj) {
    return static_cast<PCirc*>(obj)[0].PPoint::radius;
}

__declspec(dllexport) float PCirc_PPoint_angle(void* obj) {
    return static_cast<PCirc*>(obj)[0].PPoint::angle;
}

__declspec(dllexport) float PCirc_xc(void* obj) {
    return static_cast<PCirc*>(obj)[0].PPoint::x;
}

__declspec(dllexport) float PCirc_yc(void* obj) {
    return static_cast<PCirc*>(obj)[0].PPoint::y;
}

__declspec(dllexport) float PLine_angle(void* obj) {
    return static_cast<PLine*>(obj)[0].angle;
}

__declspec(dllexport) float PVEC_xv(void* obj) {
    return static_cast<PVEC*>(obj)[0].xv;
}

__declspec(dllexport) float PVEC_yv(void* obj) {
    return static_cast<PVEC*>(obj)[0].yv;
}
__declspec(dllexport) float PVEC_ang(void* obj) {
    return static_cast<PVEC*>(obj)[0].ang;
}
__declspec(dllexport) float PVEC_rad(void* obj) {
    return static_cast<PVEC*>(obj)[0].rad;
}

__declspec(dllexport) float PObjLine_angle(void* obj) {
    return static_cast<PObjLine*>(obj)[0].angle;
}

__declspec(dllexport) float PObjLine_xv(void* obj) {
    return static_cast<PObjLine*>(obj)[0].xv;
}

__declspec(dllexport) float PObjLine_yv(void* obj) {
    return static_cast<PObjLine*>(obj)[0].yv;
}
__declspec(dllexport) float PObjLine_ang(void* obj) {
    return static_cast<PObjLine*>(obj)[0].ang;
}
__declspec(dllexport) float PObjLine_rad(void* obj) {
    return static_cast<PObjLine*>(obj)[0].rad;
}

/*__declspec(dllexport) float PObjCirc_xv(PObjCirc* obj) {
    //return PObjCirc[0]::;// .xv;

}

__declspec(dllexport) float PObjCirc_yv(PObjCirc* obj) {
    return PObjCirc[0].yv;
}
__declspec(dllexport) float PObjCirc_ang(PObjCirc* obj) {
    return PObjCirc[0].ang;
}
__declspec(dllexport) float PObjCirc_rad(PObjCirc* obj) {
    return PObjCirc[0].rad;
}

__declspec(dllexport) float PObjCirc_x(PObjCirc* obj) {
    return PObjCirc[0].Circ::x;
}

__declspec(dllexport) float PObjCirc_y(PObjCirc* obj) {
    return PObjCirc[0].Circ::y;
}
__declspec(dllexport) float PObjCirc_PPoint_radius(PObjCirc* obj) {
    return PObjCirc[0].PPoint::radius;
}

__declspec(dllexport) float PObjCirc_PPoint_angle(PObjCirc* obj) {
    return PObjCirc[0].PPoint::angle;
}

__declspec(dllexport) float PObjCirc_xc(PObjCirc* obj) {
    return PObjCirc[0].PPoint::x;
}

__declspec(dllexport) float PObjCirc_yc(PObjCirc* obj) {
    return PObjCirc[0].PPoint::y;
}*/














__declspec(dllexport) void set_MVec_xv(void* obj, float value) {
     static_cast<MVec*>(obj)[0].xv = value;
}

__declspec(dllexport) void set_MVec_yv(void* obj, float value) {
     static_cast<MVec*>(obj)[0].yv = value;
}

__declspec(dllexport) void set_FPoint_x(void* obj, float value) {
     static_cast<FPoint*>(obj)[0].x = value;
}

__declspec(dllexport) void set_FPoint_y(void* obj, float value) {
    static_cast<FPoint*>(obj)[0].y = value;
}

__declspec(dllexport) void set_Circ_x(void* obj, float value) {
     static_cast<Circ*>(obj)[0].x = value;
}

__declspec(dllexport) void set_Circ_y(void* obj, float value) {
     static_cast<Circ*>(obj)[0].y = value;

}

__declspec(dllexport) void set_CircObj_x(void* obj, float value) {
     static_cast<CircObj*>(obj)[0].x = value;
}

__declspec(dllexport) void set_CircObj_y(void* obj, float value) {
     static_cast<CircObj*>(obj)[0].y = value;
}

__declspec(dllexport) void set_CircObj_xv(void* obj, float value) {
     static_cast<CircObj*>(obj)[0].xv = value;
}

__declspec(dllexport) void set_CircObj_yv(void* obj, float value) {
     static_cast<CircObj*>(obj)[0].yv = value;
}

__declspec(dllexport) void set_FLine_p1(void* obj, void* value) {
     static_cast<FLine*>(obj)[0].p1 = static_cast<FPoint*>(value)[0];
}

__declspec(dllexport) void set_FLine_p2(void* obj, void* value) {
     static_cast<FLine*>(obj)[0].p2 = static_cast<FPoint*>(value)[0];
}

__declspec(dllexport) void set_lineObj_p1(void* obj, void* value) {
     static_cast<lineObj*>(obj)[0].p1 = static_cast<FPoint*>(value)[0];
}

__declspec(dllexport) void set_lineObj_p2(void* obj, void* value) {
     static_cast<lineObj*>(obj)[0].p2 = static_cast<FPoint*>(value)[0];
}
__declspec(dllexport) void set_lineObj_xv(void* obj, float value) {
     static_cast<lineObj*>(obj)[0].xv = value;
}

__declspec(dllexport) void set_lineObj_yv(void* obj, float value) {
     static_cast<lineObj*>(obj)[0].yv = value;
}

__declspec(dllexport) void set_PPoint_xc(void* obj, float value) {
     static_cast<PPoint*>(obj)[0].x = value;
}

__declspec(dllexport) void set_PPoint_yc(void* obj, float value) {
     static_cast<PPoint*>(obj)[0].y = value;
}
__declspec(dllexport) void set_PPoint_radius(void* obj, float value) {
     static_cast<PPoint*>(obj)[0].radius = value;
}

__declspec(dllexport) void set_PPoint_angle(void* obj, float value) {
     static_cast<PPoint*>(obj)[0].angle = value;
}
__declspec(dllexport) void set_PCirc_x(void* obj, float value) {
     static_cast<PCirc*>(obj)[0].Circ::x = value;
}

__declspec(dllexport) void set_PCirc_y(void* obj, float value) {
     static_cast<PCirc*>(obj)[0].Circ::y = value;
}
__declspec(dllexport) void set_PCirc_PPoint_radius(void* obj, float value) {
     static_cast<PCirc*>(obj)[0].PPoint::radius = value;
}

__declspec(dllexport) void set_PCirc_PPoint_angle(void* obj, float value) {
     static_cast<PCirc*>(obj)[0].PPoint::angle = value;
}

__declspec(dllexport) void set_PCirc_xc(void* obj, float value) {
     static_cast<PCirc*>(obj)[0].PPoint::x = value;
}

__declspec(dllexport) void set_PCirc_yc(void* obj, float value) {
     static_cast<PCirc*>(obj)[0].PPoint::y = value;
}

__declspec(dllexport) void set_PLine_angle(void* obj, float value) {
     static_cast<PLine*>(obj)[0].angle = value;
}

__declspec(dllexport) void set_PVEC_xv(void* obj, float value) {
     static_cast<PVEC*>(obj)[0].xv = value;
}

__declspec(dllexport) void set_PVEC_yv(void* obj, float value) {
     static_cast<PVEC*>(obj)[0].yv = value;
}
__declspec(dllexport) void set_PVEC_ang(void* obj, float value) {
     static_cast<PVEC*>(obj)[0].ang = value;
}
__declspec(dllexport) void set_PVEC_rad(void* obj, float value) {
     static_cast<PVEC*>(obj)[0].rad = value;
}

__declspec(dllexport) void set_PObjLine_angle(void* obj, float value) {
     static_cast<PObjLine*>(obj)[0].angle = value;
}

__declspec(dllexport) void set_PObjLine_xv(void* obj, float value) {
     static_cast<PObjLine*>(obj)[0].xv = value;
}

__declspec(dllexport) void set_PObjLine_yv(void* obj, float value) {
     static_cast<PObjLine*>(obj)[0].yv = value;
}
__declspec(dllexport) void set_PObjLine_ang(void* obj, float value) {
     static_cast<PObjLine*>(obj)[0].ang = value;
}
__declspec(dllexport) void set_PObjLine_rad(void* obj, float value) {
     static_cast<PObjLine*>(obj)[0].rad = value;
}


}

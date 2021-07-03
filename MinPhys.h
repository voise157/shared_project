#ifndef MINPHYS_H
#define MINPHYS_H

#include <cmath>
#include <memory>
#include <vector>
#include <new>



class MinPhys {
public:
    static bool circHitCirc(int x1, int x2, int y1, int y2, int r1, int r2) {
        return ((((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))) < ((r1 + r2) * (r1 + r2)));
    }
    static bool circHitCircSFML(int x1, int x2, int y1, int y2, int r1, int r2) {
        return circHitCirc(x1+r1, x2+r2, y1+r1, y2+r2, r1, r2);
    }
    static char get_line_intersection(float p0_x, float p0_y, float p1_x, float p1_y,
        float p2_x, float p2_y, float p3_x, float p3_y, float *i_x, float *i_y)
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
            if (i_x != NULL)
                *i_x = p0_x + (t * s1_x);
            if (i_y != NULL)
                *i_y = p0_y + (t * s1_y);
            return 1;
        }

        return 0; // No collision
    }
    static int getRange(int x1, int x2, int y1, int y2) {
        int X, Y, RANGE;
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
    static float getDistance(float x1, float  x2, float  y1, float y2, float z1 = 0, float  z2 = 0) {
        return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)); // +((z2-z1)*(z2-z1))
    }
    static void getPointOnCirc(float radius, float angle, float *X, float *Y) {
       X[0] = radius*cos(angle*3.14/180)+X[0];
       Y[0] = radius*sin(angle*3.14/180)+Y[0];
   }

    static void getAngleFromPointOnCirc(float radius, float X, float Y, float XC, float YC, float *angle) {
       //X = radius*cos(angle[0]*3.14/180)+X;
       //Y = radius*sin(angle[0]*3.14/180)+Y;
       float sideA = radius;
       float xc = XC, yc = YC;
       getPointOnCirc(radius, 0, &xc, &yc);
       float sideB = getDistance(xc,X, yc, Y);
       float notAngle = acos(sideB/(2*sideA));
       angle[0] = 180 - notAngle*2;
   }
    static std::pair<float ,float> getMiddlePointOfLine(float x1, float x2, float y1, float y2) {
        std::pair<float ,float> point;
        point.first = (x1+x2)/2;
        point.second = (y1+y2)/2;
        return point;
    }
    static std::pair<float ,float> findPerpendicularPoint(float x1,float x2,float x3,float y1,float y2,float y3) {
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
    static bool lineHitCirc(std::pair<float ,float> perpendicularPoint, float xc, float yc, float radius) {
        if(getDistance(perpendicularPoint.first, xc, perpendicularPoint.second, yc)<=radius) {
            return true;
        } else {
            return false;
        }
    }
};


class MVec {
public:
    float xv, yv;
    MVec(float XV, float YV) {
        xv=XV;
        yv=YV;
    }
    MVec getMVec() {
        return MVec(xv, yv);
    }
    MVec vecCollision(MVec vec) {
        return MVec((xv+vec.xv)/2, (yv+vec.yv)/2);
    }
};

class FPoint {
public:
    float x, y;
    FPoint(float X, float Y) {
        x=X;
        y=Y;
    }
    FPoint() {
        x=0;
        y=0;
    }
    static float getDistance(FPoint p1, FPoint p2) {
        return MinPhys::getDistance(p1.x, p2.x,p1.y,p2.y);
    }
    virtual void move(MVec vector) {
        x+=vector.xv;
        y+=vector.yv;
    }
    virtual void antiMove(MVec vector) {
        x-=vector.xv;
        y-=vector.yv;
    }
    FPoint getPoint() {
        FPoint point(x, y);
        return point;
    }
};

class Circ: public FPoint {
public:
    float radius;
    Circ(FPoint POINT, float RADIUS) : FPoint(POINT.x, POINT.y) {
        radius = RADIUS;
    }
    float r() {
        return radius;
    }
    void setR(float RADIUS) {
        radius = RADIUS;
    }
    static bool circHitCirc(Circ circ1, Circ circ2) {
        return MinPhys::circHitCirc(circ1.x, circ2.x, circ1.y, circ2.y, circ1.r(), circ2.r());
    }
    Circ getCirc() {
        return Circ(FPoint(x, y), radius);
    }
};
class CircObj: public Circ, public MVec {
public:
    CircObj(FPoint POINT, float RADIUS, float VecX, float VecY) : Circ(POINT, RADIUS), MVec(VecX, VecY) {

    }
    virtual void move(MVec vector) {
        x+=xv;
        y+=yv;

    }
    virtual void antiMove(MVec vector) {
        x-=xv;
        y-=yv;
    }
    virtual bool collisionCirc(Circ circ) {
        if(Circ::circHitCirc(circ, getCirc())) {
            return true;
        } else {
            return false;
        }
    }
    bool friend operator==(CircObj &obj1, CircObj &obj2) {
        if(Circ::circHitCirc(obj1.getCirc(), obj2.getCirc())) {
            return true;
        } else {
            return false;
        }
    }
};

class FLine {
public:
    FPoint p1, p2;
    FLine(FPoint POINT1, FPoint POINT2) {
        p1 = POINT1;
        p2 = POINT2;
    }
    FLine getFLine() {
        return FLine(p1, p2);
    }
    float getDistance() {
        return MinPhys::getDistance(p1.x, p2.x, p1.y, p2.y);
    }
    FPoint getMidPoint() {
        auto T = MinPhys::getMiddlePointOfLine(p1.x, p2.x, p1.y, p2.y);
        return FPoint(T.first, T.second);
    }
    virtual bool hitLine(FLine line) {
        FPoint hitPoint;
        bool isParallel = MinPhys::get_line_intersection(p1.x, p1.y, p2.x, p2.y, line.p1.x, line.p1.y, line.p2.x, line.p2.y, &hitPoint.x, &hitPoint.y);
        FPoint midOne = getMidPoint();
        FPoint midTwo = line.getMidPoint();
        bool isHitOne = (FLine(midOne, hitPoint).getDistance() <= getDistance()/2);
        bool isHitTwo = (FLine(midTwo, hitPoint).getDistance() <= line.getDistance()/2);
        if(!isParallel && isHitOne && isHitTwo) {
            return true;
        } else {
            return false;
        }
    }
    FPoint findPerpPoint(FPoint p1,FPoint p2,FPoint p3) {
        auto point = MinPhys::findPerpendicularPoint(p1.x, p2.x, p3.x, p1.y, p2.y, p3.y);
        return FPoint(point.first, point.second);
    }
    bool lineHitCirc(FPoint  PerpPoint, FPoint CircCenter, float radius) {
            std::pair<float ,float> perpendicularPoint;
            perpendicularPoint.first = PerpPoint.x;
            perpendicularPoint.second = PerpPoint.y;
            float xc = CircCenter.x;
            float yc = CircCenter.y;
            return MinPhys::lineHitCirc(perpendicularPoint, xc, yc, radius);
    }
    virtual bool lineHitCirc(FPoint p1,FPoint p2,FPoint CircCenter, float radius) {
        FPoint point = findPerpPoint(p1, p2, CircCenter);
        bool isLineHitCirc = lineHitCirc(point, CircCenter, radius);
        bool isInSise = hitLine(FLine(CircCenter, point));
        if(isLineHitCirc && isInSise) {
            return true;
        } else {
            return false;
        }
    }
};

class lineObj: public FLine, public MVec {
public:
    lineObj(FPoint POINT1, FPoint POINT2, FPoint Vector) : FLine(POINT1, POINT2) ,MVec(Vector.x, Vector.y) {

    }
    virtual bool lineHitCirc(FPoint p1,FPoint p2,FPoint CircCenter, float radius) {
        if(FLine::lineHitCirc(p1, p2, CircCenter, radius)) {
            return true;
        } else {
            return false;
        }
    }
    virtual bool hitLine(FLine line) {
        if(FLine::hitLine(line)) {
            return true;
        } else {
            return false;
        }
    }
    virtual void move() {
        p1.move(MVec(xv, yv));
        p2.move(MVec(xv, yv));
    }
    virtual void antiMove() {
        p1.move(MVec(-xv, -yv));
        p2.move(MVec(-xv, -yv));
    }
};

class PPoint: public FPoint {
public:
    float radius;
    float angle;
    PPoint(float XCenter, float YCenter, float Radius, float Angle) : FPoint(XCenter, YCenter) {
        radius = Radius;
        angle = Angle;
    }
    FPoint getFPoint() {
        FPoint point;
        MinPhys::getPointOnCirc(radius, angle, &point.x, &point.y);
        return point;
    }
    void setCenter(FPoint center) {
        x = center.x;
        y = center.y;
    }
    FPoint getCenter() {
        return getPoint();
    }
    float getPDistance(FPoint point) {
        return FPoint::getDistance(getFPoint(), point);
    }
    float getDistanceToCenter(FPoint point) {
        return FPoint::getDistance(getCenter(), point);
    }
};

class PCirc: public Circ, public PPoint {
public:
    PCirc(FPoint center, float centerRad, Circ circ, float angle) : Circ(circ.getPoint(), circ.r()), PPoint(center.x, center.y, centerRad, angle) {

    }
    void setAngle(float Angle) {
        PPoint::angle = Angle;
    }
    float angle() {
        return PPoint::angle;
        reMath();
    }
    void reMath() {
        Circ::x = PPoint::getFPoint().x;
        Circ::y = PPoint::getFPoint().y;
    }
    void rotate(float Angle) {
        PPoint::angle += Angle;
        reMath();
    }
};

class PLine: public FLine {
public:
    float radius2;
    float angle2;
    float radius1;
    float angle1;
    float angle = 0;
    FPoint center;
    PLine(FPoint CENTER, float Rad1, float Ang1, float Rad2, float Ang2) : FLine(PPoint(CENTER.x, CENTER.y, Rad1, Ang1).getFPoint(), PPoint(CENTER.x, CENTER.y, Rad2, Ang2).getFPoint()) {
        center.x = CENTER.x;
        center.y = CENTER.y;
        radius1 = Rad1;
        radius2 = Rad2;
        angle1 = Ang1;
        angle2 = Ang2;
    }
    void reMath() {
        p1 = PPoint(center.x, center.y, radius1, angle1+angle).getFPoint();
        p2 = PPoint(center.x, center.y, radius2, angle2+angle).getFPoint();
    }
    void rotate(float rotAngle) {
        angle+=rotAngle;
        reMath();
    }
    FLine getLine() {
        return FLine(p1, p2);
    }
};


class PVEC: public MVec {
public:
    float ang;
    float rad;
    PVEC(float angle, float radius) : MVec(PPoint(0, 0, radius, angle).getFPoint().x, PPoint(0, 0, radius, angle).getFPoint().y) {
        ang = angle;
        rad = radius;
    }
    void reMath() {
        xv = PPoint(0, 0, rad, ang).getFPoint().x;
        yv = PPoint(0, 0, rad, ang).getFPoint().y;
    }
    void fromMVec(MVec vec) {
        rad = MinPhys::getDistance(0, vec.xv, 0, vec.yv);
        MinPhys::getAngleFromPointOnCirc(rad, vec.xv, vec.yv, 0, 0, &ang);
    }
    MVec getVec() {
        return MVec(xv, yv);
    }
    void rotate(float angle) {
        ang+=angle;
        reMath();
    }
};

class PObjLine: public PLine, public PVEC {
public:
    PObjLine(float ANGLE, float radius, FPoint CENTER, float Rad1, float Ang1, float Rad2, float Ang2) : PLine(CENTER, Rad1, Ang1, Rad2, Ang2), PVEC(ANGLE, radius) {
        angle = ANGLE;
    }
    void ReMath() {
        PLine::reMath();
        PVEC::reMath();
        //angle = ang;
    }
    void rotateObj(float ANGLE) {
        angle+=ANGLE;
    }
    void rotateVec(float ANGLE) {
        ang+=ANGLE;
    }
    void move() {
        center.move(getVec());
        ReMath();
    }
};

class PObjCirc: public PCirc, public PVEC {
public:
    PObjCirc(float angle, float radius, FPoint center, float centerRad, Circ circ, float angl) : PCirc(center, centerRad, circ, angl), PVEC(angle, radius) {

    }
    void ReMath() {
        PCirc::reMath();
        PVEC::reMath();
        //angle = ang;
    }
    void mov() {
        PCirc::PPoint::move(this->getVec());
        void ReMath();
    }
    void rotateObj(float ANGLE) {
        PCirc::PPoint::angle+=ANGLE;
        void ReMath();
    }
    void rotateVec(float ANGLE) {
        ang+=ANGLE;
    }
};



extern "C" {

    void PVEC_fromMVec(PVEC* obj, MVec vec) {
        obj[0].fromMVec(vec);
    }

    void PVEC_reMath(PVEC* obj) {
        obj[0].reMath();
    }

    PVEC* PVEC_new(float angle, float radius) {
        return new(std::nothrow) PVEC(angle, radius);
    }

    PObjLine* PObjLine_new(float ANGLE, float radius, FPoint CENTER, float Rad1, float Ang1, float Rad2, float Ang2) {
        return new(std::nothrow) PObjLine(ANGLE, radius, CENTER, Rad1, Ang1, Rad2, Ang2);
    }

    void PObjLine_reMath(PObjLine *obj) {
        obj[0].ReMath();
    }

    void PObjLine_rotateObj(PObjLine *obj, float ANGLE) {
        obj[0].rotateObj(ANGLE);
    }

    void PObjLine_rotateVec(PObjLine *obj, float ANGLE) {
        obj[0].rotateObj(ANGLE);
    }

    void move_PObjLine(PObjLine *obj) {
        obj[0].move();
    }


    PObjCirc* PObjCirc_new(float angle, float radius, FPoint center, float centerRad, Circ circ, float angl) {
        return new(std::nothrow) PObjCirc(angle, radius, center, centerRad, circ, angl);
    }
    void reMath_PObjCirc(PObjCirc *obj) {
        obj[0].ReMath();
    }
    void move_PObjCirc(PObjCirc *obj) {
        obj[0].mov();
    }
    void rotateObj_PObjCirc(PObjCirc *obj, float angle) {
        obj[0].rotateObj(angle);
    }
    void rotateVec_PObjCirc(PObjCirc *obj, float angle) {
        obj[0].rotateVec(angle);
    }
}

#endif // MINPHYS_H

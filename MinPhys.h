#ifndef MINPHYS_H
#define MINPHYS_H

#include "LibPhys_global.h"
#include <cmath>
#include <memory>
#include <vector>
#include <new>

class LIBPHYS_EXPORT MinPhys
{
public:
    static bool circHitCirc(float x1, float x2, float y1, float y2, float r1, float r2);
    static bool circHitCircSFML(float x1, float x2, float y1, float y2, float r1, float r2);
    static bool get_line_intersection(float p0_x, float p0_y, float p1_x, float p1_y,
    float p2_x, float p2_y, float p3_x, float p3_y);
    static std::pair<float, float> get_line_intersection_point(float p0_x, float p0_y, float p1_x, float p1_y,
    float p2_x, float p2_y, float p3_x, float p3_y);
    static float getRange(float x1, float x2, float y1, float y2);
    static float getDistance(float x1, float  x2, float  y1, float y2, float z1 = 0, float  z2 = 0);
    static std::pair<float, float> getPointOnCirc(float radius, float angle, float X, float Y);
    static float getAngleFromPointOnCirc(float radius, float X, float Y, float XC, float YC);
    static std::pair<float ,float> getMiddlePointOfLine(float x1, float x2, float y1, float y2);
    static std::pair<float ,float> findPerpendicularPoint(float x1,float x2,float x3,float y1,float y2,float y3);
    static bool lineHitCirc(std::pair<float ,float> perpendicularPoint, float xc, float yc, float radius);
};

class LIBPHYS_EXPORT MVec {
public:
    float xv, yv;
    MVec(float XV, float YV);
    MVec getMVec();
    MVec vecCollision(MVec vec);
    virtual ~MVec() {

    }
};

class LIBPHYS_EXPORT FPoint {
public:
    float x, y;
    FPoint(float X, float Y);
    FPoint();
    static float getDistance(FPoint p1, FPoint p2);
    virtual void move(MVec vector);
    virtual void antiMove(MVec vector);
    FPoint getPoint();
    virtual ~FPoint() {

    }
};

class LIBPHYS_EXPORT Circ: public FPoint {
public:
    float radius;
    Circ(FPoint POINT, float RADIUS);
    float r();
    void setR(float RADIUS);
    bool circHitCirc(Circ circ);
    Circ getCirc();
    virtual ~Circ()  {

    }
};
class LIBPHYS_EXPORT CircObj: public Circ, public MVec {
public:
    CircObj(FPoint POINT, float RADIUS, float VecX, float VecY);
    virtual void mov();
    virtual void antiMov();
    virtual bool collisionCirc(Circ circ);
    //bool friend operator==(CircObj &obj1, CircObj &obj2);
    virtual ~CircObj() {

    }
};

class LIBPHYS_EXPORT FLine {
public:
    FPoint p1, p2;
    FLine(FPoint POINT1, FPoint POINT2);
    FLine getFLine();
    float getDistance();
    FPoint getMidPoint();
    virtual bool hitLine(FLine line);
    FPoint findPerpPoint(FPoint p1,FPoint p2,FPoint p3);
    bool lineHitCirc(FPoint  PerpPoint, FPoint CircCenter, float radius);
    virtual bool lineHitCirc(FPoint p1,FPoint p2,FPoint CircCenter, float radius);
    virtual ~FLine() {

    }
};

class LIBPHYS_EXPORT lineObj: public FLine, public MVec {
public:
    lineObj(FPoint POINT1, FPoint POINT2, FPoint Vector);
    virtual bool lineHitCirc(FPoint p1,FPoint p2,FPoint CircCenter, float radius);
    virtual bool hitLine(FLine line);
    virtual void move();
    virtual void antiMove();
    virtual ~lineObj() {

    }
};

class LIBPHYS_EXPORT PPoint: public FPoint {
public:
    float radius;
    float angle;
    PPoint(float XCenter, float YCenter, float Radius, float Angle);
    FPoint getFPoint();
    void setCenter(FPoint center);
    FPoint getCenter();
    float getPDistance(FPoint point);
    float getDistanceToCenter(FPoint point);
    virtual ~PPoint() {

    }
};

class LIBPHYS_EXPORT PCirc: public Circ, public PPoint {
public:
    PCirc(FPoint center, float centerRad, Circ circ, float angle);
    void setAngle(float Angle);
    float angle();
    void reMath();
    void rotate(float Angle);
    virtual ~PCirc() {

    }
};

class LIBPHYS_EXPORT PLine: public FLine {
public:
    float radius2;
    float angle2;
    float radius1;
    float angle1;
    float angle = 0;
    FPoint center;
    PLine(FPoint CENTER, float Rad1, float Ang1, float Rad2, float Ang2);
    void reMath();
    void rotate(float rotAngle);
    FLine getLine();
    virtual ~PLine() {

    }
};

class  LIBPHYS_EXPORT PVEC: public MVec {
public:
    float ang;
    float rad;
    PVEC(float angle, float radius);
    void reMath();
    void fromMVec(MVec vec);
    MVec getVec();
    void rotate(float angle);
    virtual ~PVEC() {

    }
};

class LIBPHYS_EXPORT PObjLine: public PLine, public PVEC {
public:
    PObjLine(float ANGLE, float radius, FPoint CENTER, float Rad1, float Ang1, float Rad2, float Ang2);
    void ReMath();
    void rotateObj(float ANGLE);
    void rotateVec(float ANGLE);
    void move();
    virtual ~PObjLine() {

    }
};

class LIBPHYS_EXPORT PObjCirc: public PCirc, public PVEC {
public:
    PObjCirc(float angle, float radius, FPoint center, float centerRad, Circ circ, float angl);
    void ReMath();
    void mov();
    void rotateObj(float ANGLE);
    void rotateVec(float ANGLE);
    virtual ~PObjCirc() {

    }
};


/*
LIBPHYS_EXPORT extern "C" {

     void del_MVec(MVec* obj);

     void del_FPoint(FPoint* obj);

     void del_Circ(Circ* obj);

     void del_CircObj(CircObj* obj);

     void del_FLine(FLine* obj);

     void del_lineObj(lineObj* obj);

     void del_PPoint(PPoint* obj);

     void del_PCirc(PCirc* obj);

     void del_PLine(PLine* obj);

     void del_PVEC(PVEC* obj);

     void del_PObjLine(PObjLine* obj);

     void del_PObjCirc(PObjCirc* obj);

     MVec* MVec_new(float XV, float YV);

     MVec* MVec_getMVec(MVec* obj, MVec* vec);

     MVec* MVec_vecCollsion(MVec* obj);

     float FPoint_getDistance(FPoint* one, FPoint* two);

     void FPoint_move(FPoint* obj, MVec* vector);

     FPoint* FPoint_getPoint(FPoint* obj);

     FPoint* FPoint_new(float X, float Y);

     Circ* Circ_new(FPoint* POINT, float RADIUS);

     float Circ_r(Circ* obj);

     void Circ_setR(Circ* obj, float radius);

     bool Circ_circHitCirc(Circ* circ1, Circ* circ2);

     Circ* Circ_getCirc(Circ* obj);

     CircObj* CircObj_new(FPoint* POINT, float RADIUS, float VecX, float VecY);

     void CircObj_move(CircObj* obj, MVec* vec);

     bool CircObj_collisionCirc(CircObj* obj, Circ* circ);

     FLine* FLine_new(FPoint POINT1, FPoint POINT2);

     FLine* getFLine_FLine(FLine* obj);

     float FLine_getDistance(FLine* obj);

     FPoint* FLine_getMidPoint(FLine* obj);

     bool FLine_hitLine(FLine* obj, FLine* line);

     FPoint* FLine_findPerpPoint(FLine* obj, FPoint* p1,FPoint* p2,FPoint* p3);

     bool FLine_linehitCirc(FLine* obj, FPoint* p1,FPoint* p2,FPoint* CircCenter, float radius);

     lineObj* lineObj_new(FPoint* POINT1, FPoint* POINT2, FPoint* Vector);

     bool lineObj_hitLine(lineObj* obj, FLine* line);

     void lineObj_move(lineObj* obj);
     void lineObj_antiMove(lineObj* obj);

     bool lineObj_lineHitCirc(lineObj* obj, FPoint* p1,FPoint* p2,FPoint* CircCenter, float radius);

     bool circHitCirc(int x1, int x2, int y1, int y2, int r1, int r2);
     bool circHitCircSFML(int x1, int x2, int y1, int y2, int r1, int r2);
     char get_line_intersection(float p0_x, float p0_y, float p1_x, float p1_y,
    float p2_x, float p2_y, float p3_x, float p3_y, float *i_x, float *i_y);
     int getRange(int x1, int x2, int y1, int y2);
     float getDistance(float x1, float  x2, float  y1, float y2, float z1 = 0, float  z2 = 0);
     void getPointOnCirc(float radius, float angle, float *X, float *Y);

     PPoint* PPoint_new(float XCenter, float YCenter, float Radius, float Angle);
     FPoint* getFPoint_PPoint(PPoint* obj);
     FPoint* getCenter_PPoint(PPoint* obj);
     void setCenter_PPoint(PPoint* obj, FPoint* point);
     float getPDistance_PPoint(PPoint* obj, FPoint* point);
     float getDistanceToCenter_PPoint(PPoint* obj, FPoint* point);


     PCirc* PCirc_new(FPoint center, float centerRad, Circ circ, float angle);
     void PCirc_setAngle(PCirc *obj, float Angle);
     float PCirc_angle(PCirc* obj);
     void PCirc_reMath(PCirc* obj);
     void PCirc_rotate(PCirc* obj, float Angle);


     FLine*  getLine_PLine(PLine* obj);
     void rotate_PLine(PLine* obj, float angle);
     void reMath_PLine(PLine* obj);
     PLine* PLine_new(FPoint CENTER, float Rad1, float Ang1, float Rad2, float Ang2);

     void rotate_PVEC(PVEC* obj, float angle);
     MVec* getVec_PVEC(PVEC* obj);
     void PVEC_fromMVec(PVEC* obj, MVec vec);
     void PVEC_reMath(PVEC* obj);
     PVEC* PVEC_new(float angle, float radius);

     PObjLine* PObjLine_new(float ANGLE, float radius, FPoint CENTER, float Rad1, float Ang1, float Rad2, float Ang2);

     void PObjLine_reMath(PObjLine *obj);

     void PObjLine_rotateObj(PObjLine *obj, float ANGLE);

     void PObjLine_rotateVec(PObjLine *obj, float ANGLE);

     void move_PObjLine(PObjLine *obj);
     FPoint* getMiddlePointOfLine(float x1, float x2, float y1, float y2);
     FPoint* findPerpendicularPoint(float x1,float x2,float x3,float y1,float y2,float y3);
     bool lineHitCirc(FPoint* perpendicularPoint, float xc, float yc, float radius);

     PObjCirc* PObjCirc_new(float angle, float radius, FPoint center, float centerRad, Circ circ, float angl);
     void reMath_PObjCirc(PObjCirc *obj);
     void move_PObjCirc(PObjCirc *obj);
     void rotateObj_PObjCirc(PObjCirc *obj, float angle);
     void rotateVec_PObjCirc(PObjCirc *obj, float angle);
     float percentOf(float part, float all);
     float onePer(float all);
     float hundredOf(float onePercent);
     float valueOf(float percent, float all);
}*/

#endif // MINPHYS_H

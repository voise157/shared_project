from ctypes import *

# class FPoint(Structure):
#    _fields_ = [("x", c_float), ("y", c_float)]

LibPhys = CDLL(".\LibPhys.dll")
del_MVec = LibPhys.del_MVec
del_MVec.argtypes = [c_void_p]
del_FPoint = LibPhys.del_FPoint
del_FPoint.argtypes = [c_void_p]
del_CircObj = LibPhys.del_CircObj
del_CircObj.argtypes = [c_void_p]
del_Circ = LibPhys.del_Circ
del_Circ.argtypes = [c_void_p]
del_FLine = LibPhys.del_FLine
del_FLine.argtypes = [c_void_p]
del_lineObj = LibPhys.del_lineObj
del_lineObj.argtypes = [c_void_p]
del_PPoint = LibPhys.del_PPoint
del_PPoint.argtypes = [c_void_p]
del_PCirc = LibPhys.del_PCirc
del_PCirc.argtypes = [c_void_p]
del_PLine = LibPhys.del_PLine
del_PLine.argtypes = [c_void_p]
del_PVEC = LibPhys.del_PVEC
del_PVEC.argtypes = [c_void_p]
del_PObjLine = LibPhys.del_PObjLine
del_PObjLine.argtypes = [c_void_p]
del_PObjCirc = LibPhys.del_PObjCirc
del_PObjCirc.argtypes = [c_void_p]
MVec_new = LibPhys.MVec_new
MVec_new.restype = c_void_p
MVec_new.argtypes = [c_float, c_float]
MVec_getMVec = LibPhys.MVec_getMVec
MVec_getMVec.restype = c_void_p
MVec_getMVec.argtypes = [c_void_p]
MVec_vecCollsion = LibPhys.MVec_vecCollsion
MVec_vecCollsion.restype = c_void_p
MVec_vecCollsion.argtypes = [c_void_p, c_void_p]
FPoint_getDistance = LibPhys.FPoint_getDistance
FPoint_getDistance.restype = c_float
FPoint_getDistance.argtypes = [c_void_p, c_void_p]
FPoint_move = LibPhys.FPoint_move
FPoint_move.argtypes = [c_void_p, c_void_p]
FPoint_getPoint = LibPhys.FPoint_getPoint
FPoint_getPoint.restype = c_void_p
FPoint_getPoint.argtypes = [c_void_p]
FPoint_new = LibPhys.FPoint_new
FPoint_new.restype = c_void_p
FPoint_new.argtypes = [c_float, c_float]
Circ_new = LibPhys.Circ_new
Circ_new.restype = c_void_p
Circ_new.argtypes = [c_void_p, c_float]
Circ_r = LibPhys.Circ_r
Circ_r.restype = c_float
Circ_r.argtypes = [c_void_p]
Circ_setR = LibPhys.Circ_setR
Circ_setR.argtypes = [c_void_p, c_float]
Circ_circHitCirc = LibPhys.Circ_circHitCirc
Circ_circHitCirc.restype = c_bool
Circ_circHitCirc.argtypes = [c_void_p, c_void_p]
Circ_getCirc = LibPhys.Circ_getCirc
Circ_getCirc.restype = c_void_p
Circ_getCirc.argtypes = [c_void_p]
CircObj_new = LibPhys.CircObj_new
CircObj_new.restype = c_void_p
CircObj_new.argtypes = [c_void_p, c_float, c_float, c_float]
CircObj_move = LibPhys.CircObj_move
CircObj_move.argtypes = [c_void_p]
CircObj_collisionCirc = LibPhys.CircObj_collisionCirc
CircObj_collisionCirc.restype = c_bool
CircObj_collisionCirc.argtypes = [c_void_p, c_void_p]
FLine_new = LibPhys.FLine_new
FLine_new.restype = c_void_p
FLine_new.argtypes = [c_void_p, c_void_p]
getFLine_FLine = LibPhys.getFLine_FLine
getFLine_FLine.restype = c_void_p
getFLine_FLine.argtypes = [c_void_p]
FLine_getDistance = LibPhys.FLine_getDistance
FLine_getDistance.restype = c_float
FLine_getDistance.argtypes = [c_void_p]
FLine_getMidPoint = LibPhys.FLine_getMidPoint
FLine_getMidPoint.restype = c_void_p
FLine_getMidPoint.argtypes = [c_void_p]
FLine_hitLine = LibPhys.FLine_hitLine
FLine_hitLine.restype = c_bool
FLine_hitLine.argtypes = [c_void_p, c_void_p]
FLine_findPerpPoint = LibPhys.FLine_findPerpPoint
FLine_findPerpPoint.restype = c_void_p
FLine_findPerpPoint.argtypes = [c_void_p, c_void_p, c_void_p, c_void_p]
FLine_linehitCirc = LibPhys.FLine_linehitCirc
FLine_linehitCirc.restype = c_bool
FLine_linehitCirc.argtypes = [c_void_p, c_void_p]
lineObj_new = LibPhys.lineObj_new
lineObj_new.restype = c_void_p
lineObj_new.argtypes = [c_void_p, c_void_p, c_void_p, c_void_p, c_float]
lineObj_hitLine = LibPhys.lineObj_hitLine
lineObj_hitLine.restype = c_bool
lineObj_hitLine.argtypes = [c_void_p, c_void_p]
lineObj_move = LibPhys.lineObj_move
lineObj_move.argtypes = [c_void_p]
lineObj_antiMove = LibPhys.lineObj_antiMove
lineObj_antiMove.argtypes = [c_void_p]
lineObj_lineHitCirc = LibPhys.lineHitCirc
lineObj_lineHitCirc.restype = c_bool
lineObj_lineHitCirc.argtypes = [c_void_p, c_void_p]
circHitCirc = LibPhys.circHitCirc
circHitCirc.argtypes = [c_float, c_float, c_float, c_float, c_float, c_float]
circHitCirc.restype = c_bool
get_line_intersection = LibPhys.get_line_intersection
get_line_intersection.restype = c_bool
get_line_intersection.argtypes = [c_float, c_float, c_float, c_float, c_float, c_float, c_float, c_float]
get_line_intersection_point = LibPhys.get_line_intersection_point
get_line_intersection_point.restype = c_void_p
get_line_intersection_point.argtypes = [c_float, c_float, c_float, c_float, c_float, c_float, c_float, c_float]
getDistance = LibPhys.getDistance
getDistance.restype = c_float
getDistance.argtypes = [c_float, c_float, c_float, c_float]
getPointOnCirc = LibPhys.getPointOnCirc
getPointOnCirc.restype = c_void_p
getPointOnCirc.argtypes = [c_float, c_float, c_float, c_float]
##########################################################################
PPoint_new = LibPhys.PPoint_new
PPoint_new.restype = c_void_p
PPoint_new.argtypes = [c_float, c_float, c_float, c_float]
getFPoint_PPoint = LibPhys.getFPoint_PPoint
getFPoint_PPoint.restype = c_void_p
getFPoint_PPoint.argtypes = [c_void_p]
getCenter_PPoint = LibPhys.getCenter_PPoint
getCenter_PPoint.restype = c_void_p
getCenter_PPoint.argtypes = [c_void_p]
setCenter_PPoint = LibPhys.setCenter_PPoint
setCenter_PPoint.argtypes = [c_void_p, c_void_p]
getPDistance_PPoint = LibPhys.getPDistance_PPoint
getPDistance_PPoint.restype = c_void_p
getPDistance_PPoint.argtypes = [c_void_p, c_void_p]
getDistanceToCenter_PPoint = LibPhys.getDistanceToCenter_PPoint
getDistanceToCenter_PPoint.restype = c_float
getDistanceToCenter_PPoint.argtypes = [c_void_p, c_void_p]
PCirc_new = LibPhys.PCirc_new
PCirc_new.restype = c_void_p
PCirc_new.argtypes = [c_void_p, c_float, c_void_p, c_float]
PCirc_setAngle = LibPhys.PCirc_setAngle
PCirc_setAngle.argtypes = [c_void_p, c_float]
PCirc_angle = LibPhys.PCirc_angle
PCirc_angle.restype = c_float
PCirc_angle.argtypes = [c_void_p]
PCirc_reMath = LibPhys.PCirc_reMath
PCirc_reMath.argtypes = [c_void_p]
PCirc_rotate = LibPhys.PCirc_rotate
PCirc_rotate.argtypes = [c_void_p, c_float]
getLine_PLine = LibPhys.getLine_PLine
getLine_PLine.restype = c_void_p
getLine_PLine.argtypes = [c_void_p]
rotate_PLine = LibPhys.rotate_PLine
rotate_PLine.argtypes = [c_void_p, c_float]
reMath_PLine = LibPhys.reMath_PLine
reMath_PLine.argtypes = [c_void_p]
PLine_new = LibPhys.PLine_new
PLine_new.restype = c_void_p
PLine_new.argtypes = [c_void_p, c_float, c_float, c_float, c_float]
rotate_PVEC = LibPhys.rotate_PVEC
rotate_PVEC.argtypes = [c_void_p, c_float]
getVec_PVEC = LibPhys.getVec_PVEC
getVec_PVEC.restype = c_void_p
getVec_PVEC.argtypes = [c_void_p]
PVEC_fromMVec = LibPhys.PVEC_fromMVec
PVEC_fromMVec.argtypes = [c_void_p, c_void_p]
PVEC_reMath = LibPhys.PVEC_reMath
PVEC_reMath.argtypes = [c_void_p]
PVEC_new = LibPhys.PVEC_new
PVEC_new.restype = c_void_p
PVEC_new.argtypes = [c_float, c_float]
PObjLine_new = LibPhys.PObjLine_new
PObjLine_new.restype = c_void_p
PObjLine_new.argtypes = [c_float, c_float, c_void_p, c_float, c_float, c_float, c_float]
PObjLine_reMath = LibPhys.PObjLine_reMath
PObjLine_reMath.argtypes = [c_void_p]
PObjLine_rotateObj = LibPhys.PObjLine_rotateObj
PObjLine_rotateObj.argtypes = [c_void_p, c_float]
PObjLine_rotateVec = LibPhys.PObjLine_rotateVec
PObjLine_rotateVec.argtypes = [c_void_p, c_float]
move_PObjLine = LibPhys.move_PObjLine
move_PObjLine.argtypes = [c_void_p]
getMiddlePointOfLine = LibPhys.getMiddlePointOfLine
getMiddlePointOfLine.restype = c_void_p
getMiddlePointOfLine.argtypes = [c_float, c_float, c_float, c_float]
findPerpendicularPoint = LibPhys.findPerpendicularPoint
findPerpendicularPoint.restype = c_void_p
findPerpendicularPoint.argtypes = [c_float, c_float, c_float, c_float, c_float, c_float]
lineHitCirc = LibPhys.lineHitCirc
lineHitCirc.restype = c_bool
lineHitCirc.argtypes = [c_void_p, c_float, c_float, c_float]
PObjCirc_new = LibPhys.PObjCirc_new
PObjCirc_new.restype = c_void_p
PObjCirc_new.argtypes = [c_float, c_float, c_void_p, c_float, c_void_p, c_float]
#####################################################################
reMath_PObjCirc = LibPhys.reMath_PObjCirc
# reMath_PObjCirc.restype =
reMath_PObjCirc.argtypes = [c_void_p]
move_PObjCirc = LibPhys.move_PObjCirc
# move_PObjCirc.restype =
move_PObjCirc.argtypes = [c_void_p]
rotateObj_PObjCirc = LibPhys.rotateObj_PObjCirc
# rotateObj_PObjCirc.restype =
rotateObj_PObjCirc.argtypes = [c_void_p, c_float]
rotateVec_PObjCirc = LibPhys.rotateVec_PObjCirc
# rotateVec_PObjCirc.restype =
rotateVec_PObjCirc.argtypes = [c_void_p, c_float]
percentOf = LibPhys.percentOf
percentOf.restype = c_float
percentOf.argtypes = [c_float, c_float]
onePer = LibPhys.onePer
onePer.restype = c_float
onePer.argtypes = [c_float]
hundredOf = LibPhys.hundredOf
hundredOf.restype = c_float
hundredOf.argtypes = [c_float]
valueOf = LibPhys.valueOf
valueOf.restype = c_float
valueOf.argtypes = [c_float, c_float]
MVec_xv = LibPhys.MVec_xv
MVec_xv.restype = c_float
MVec_xv.argtypes = [c_void_p]
MVec_yv = LibPhys.MVec_yv
MVec_yv.restype = c_float
MVec_yv.argtypes = [c_void_p]
FPoint_x = LibPhys.FPoint_x
FPoint_x.restype = c_float
FPoint_x.argtypes = [c_void_p]
FPoint_y = LibPhys.FPoint_y
FPoint_y.restype = c_float
FPoint_y.argtypes = [c_void_p]
Circ_x = LibPhys.Circ_x
Circ_x.restype = c_float
Circ_x.argtypes = [c_void_p]
Circ_y = LibPhys.Circ_y
Circ_y.restype = c_float
Circ_y.argtypes = [c_void_p]
CircObj_x = LibPhys.CircObj_x
CircObj_x.restype = c_float
CircObj_x.argtypes = [c_void_p]
CircObj_y = LibPhys.CircObj_y
CircObj_y.restype = c_float
CircObj_y.argtypes = [c_void_p]
CircObj_xv = LibPhys.CircObj_xv
CircObj_xv.restype = c_float
CircObj_xv.argtypes = [c_void_p]
CircObj_yv = LibPhys.CircObj_yv
CircObj_yv.restype = c_float
CircObj_yv.argtypes = [c_void_p]
FLine_p1 = LibPhys.FLine_p1
FLine_p1.restype = c_void_p
FLine_p1.argtypes = [c_void_p]
FLine_p2 = LibPhys.FLine_p2
FLine_p2.restype = c_void_p
FLine_p2.argtypes = [c_void_p]
lineObj_p1 = LibPhys.lineObj_p1
lineObj_p1.restype = c_void_p
lineObj_p1.argtypes = [c_void_p]
lineObj_p2 = LibPhys.lineObj_p2
lineObj_p2.restype = c_void_p
lineObj_p2.argtypes = [c_void_p]
lineObj_xv = LibPhys.lineObj_xv
lineObj_xv.restype = c_float
lineObj_xv.argtypes = [c_void_p]
lineObj_yv = LibPhys.lineObj_yv
lineObj_yv.restype = c_float
lineObj_yv.argtypes = [c_void_p]
PPoint_xc = LibPhys.PPoint_xc
PPoint_xc.restype = c_float
PPoint_xc.argtypes = [c_void_p]
PPoint_yc = LibPhys.PPoint_yc
PPoint_yc.restype = c_float
PPoint_yc.argtypes = [c_void_p]
PPoint_radius = LibPhys.PPoint_radius
PPoint_radius.restype = c_float
PPoint_radius.argtypes = [c_void_p]
PPoint_angle = LibPhys.PPoint_angle
PPoint_angle.restype = c_float
PPoint_angle.argtypes = [c_void_p]
PCirc_x = LibPhys.PCirc_x
PCirc_x.restype = c_float
PCirc_x.argtypes = [c_void_p]
PCirc_y = LibPhys.PCirc_y
PCirc_y.restype = c_float
PCirc_y.argtypes = [c_void_p]
PCirc_PPoint_radius = LibPhys.PCirc_PPoint_radius
PCirc_PPoint_radius.restype = c_float
PCirc_PPoint_radius.argtypes = [c_void_p]
PCirc_PPoint_angle = LibPhys.PCirc_PPoint_angle
PCirc_PPoint_angle.restype = c_float
PCirc_PPoint_angle.argtypes = [c_void_p]
PCirc_xc = LibPhys.PCirc_xc
PCirc_xc.restype = c_float
PCirc_xc.argtypes = [c_void_p]
PCirc_yc = LibPhys.PCirc_yc
PCirc_yc.restype = c_float
PCirc_yc.argtypes = [c_void_p]
PLine_angle = LibPhys.PLine_angle
PLine_angle.restype = c_float
PLine_angle.argtypes = [c_void_p]
PVEC_xv = LibPhys.PVEC_xv
PVEC_xv.restype = c_float
PVEC_xv.argtypes = [c_void_p]
PVEC_yv = LibPhys.PVEC_yv
PVEC_yv.restype = c_float
PVEC_yv.argtypes = [c_void_p]
PVEC_ang = LibPhys.PVEC_ang
PVEC_ang.restype = c_float
PVEC_ang.argtypes = [c_void_p]
PVEC_rad = LibPhys.PVEC_rad
PVEC_rad.restype = c_float
PVEC_rad.argtypes = [c_void_p]
PObjLine_angle = LibPhys.PObjLine_angle
PObjLine_angle.restype = c_float
PObjLine_angle.argtypes = [c_void_p]
PObjLine_xv = LibPhys.PObjLine_xv
PObjLine_xv.restype = c_float
PObjLine_xv.argtypes = [c_void_p]
PObjLine_yv = LibPhys.PObjLine_yv
PObjLine_yv.restype = c_float
PObjLine_yv.argtypes = [c_void_p]
PObjLine_ang = LibPhys.PObjLine_ang
PObjLine_ang.restype = c_float
PObjLine_ang.argtypes = [c_void_p]
PObjLine_rad = LibPhys.PObjLine_rad
PObjLine_rad.restype = c_float
PObjLine_rad.argtypes = [c_void_p]
set_MVec_xv = LibPhys.set_MVec_xv
# set_MVec_xv.restype =
set_MVec_xv.argtypes = [c_void_p, c_float]
set_MVec_yv = LibPhys.set_MVec_yv
# set_MVec_yv.restype =
set_MVec_yv.argtypes = [c_void_p, c_float]
set_FPoint_x = LibPhys.set_FPoint_x
# set_FPoint_x.restype =
set_FPoint_x.argtypes = [c_void_p, c_float]
# set_FPoint_x.restype =
set_FPoint_y = LibPhys.set_FPoint_y
# set_FPoint_y.restype =
set_FPoint_y.argtypes = [c_void_p, c_float]
set_Circ_x = LibPhys.set_Circ_x
# set_Circ_x.restype =
set_Circ_x.argtypes = [c_void_p, c_float]
set_Circ_y = LibPhys.set_Circ_y
# set_Circ_y.restype =
set_Circ_y.argtypes = [c_void_p, c_float]
set_CircObj_x = LibPhys.set_CircObj_x
# set_CircObj_x.restype =
set_CircObj_x.argtypes = [c_void_p, c_float]
set_CircObj_y = LibPhys.set_CircObj_y
# set_CircObj_y.restype =
set_CircObj_y.argtypes = [c_void_p, c_float]
set_CircObj_xv = LibPhys.set_CircObj_xv
# set_CircObj_xv.restype =
set_CircObj_xv.argtypes = [c_void_p, c_float]
set_CircObj_yv = LibPhys.set_CircObj_yv
# set_CircObj_yv.restype =
set_CircObj_yv.argtypes = [c_void_p, c_float]
set_FLine_p1 = LibPhys.set_FLine_p1
# set_FLine_p1.restype =
set_FLine_p1.argtypes = [c_void_p, c_void_p]
set_FLine_p2 = LibPhys.set_FLine_p2
# set_FLine_p2.restype =
set_FLine_p2.argtypes = [c_void_p, c_void_p]
set_lineObj_p1 = LibPhys.set_lineObj_p1
# set_lineObj_p1.restype =
set_lineObj_p1.argtypes = [c_void_p, c_void_p]
set_lineObj_p2 = LibPhys.set_lineObj_p2
# set_lineObj_p2.restype =
set_lineObj_p2.argtypes = [c_void_p, c_void_p]
set_lineObj_xv = LibPhys.set_lineObj_xv
# set_lineObj_xv.restype =
set_lineObj_xv.argtypes = [c_void_p, c_float]
set_lineObj_yv = LibPhys.set_lineObj_yv
# set_lineObj_yv.restype =
set_lineObj_yv.argtypes = [c_void_p, c_float]
set_PPoint_xc = LibPhys.set_PPoint_xc
# set_PPoint_xc.restype =
set_PPoint_xc.argtypes = [c_void_p, c_float]
set_PPoint_yc = LibPhys.set_PPoint_yc
# set_PPoint_yc.restype =
set_PPoint_yc.argtypes = [c_void_p, c_float]
set_PPoint_radius = LibPhys.set_PPoint_radius
# set_PPoint_radius.restype =
set_PPoint_radius.argtypes = [c_void_p, c_float]
set_PPoint_angle = LibPhys.set_PPoint_angle
# set_PPoint_angle.restype =
set_PPoint_angle.argtypes = [c_void_p, c_float]
set_PCirc_x = LibPhys.set_PCirc_x
# set_PCirc_x.restype =
set_PCirc_x.argtypes = [c_void_p, c_float]
set_PCirc_y = LibPhys.set_PCirc_y
# set_PCirc_y.restype =
set_PCirc_y.argtypes = [c_void_p, c_float]
set_PCirc_PPoint_radius = LibPhys.set_PCirc_PPoint_radius
# set_PCirc_PPoint_radius.restype =
set_PCirc_PPoint_radius.argtypes = [c_void_p, c_float]
set_PCirc_PPoint_angle = LibPhys.set_PCirc_PPoint_angle
# set_PCirc_PPoint_angle.restype =
set_PCirc_PPoint_angle.argtypes = [c_void_p, c_float]
set_PCirc_xc = LibPhys.set_PCirc_xc
# set_PCirc_xc.restype =
set_PCirc_xc.argtypes = [c_void_p, c_float]
set_PCirc_yc = LibPhys.set_PCirc_yc
# set_PCirc_yc.restype =
set_PCirc_yc.argtypes = [c_void_p, c_float]
set_PLine_angle = LibPhys.set_PLine_angle
# set_PLine_angle.restype =
set_PLine_angle.argtypes = [c_void_p, c_float]
set_PVEC_xv = LibPhys.set_PVEC_xv
# set_PVEC_xv.restype =
set_PVEC_xv.argtypes = [c_void_p, c_float]
set_PVEC_yv = LibPhys.set_PVEC_yv
# set_PVEC_yv.restype =
set_PVEC_yv.argtypes = [c_void_p, c_float]
set_PVEC_ang = LibPhys.set_PVEC_ang
# set_PVEC_ang.restype =
set_PVEC_ang.argtypes = [c_void_p, c_float]
set_PVEC_rad = LibPhys.set_PVEC_rad
# set_PVEC_rad.restype =
set_PVEC_rad.argtypes = [c_void_p, c_float]
set_PObjLine_angle = LibPhys.set_PObjLine_angle
# set_PObjLine_angle.restype =
set_PObjLine_angle.argtypes = [c_void_p, c_float]
set_PObjLine_xv = LibPhys.set_PObjLine_xv
# set_PObjLine_xv.restype =
set_PObjLine_xv.argtypes = [c_void_p, c_float]
set_PObjLine_yv = LibPhys.set_PObjLine_yv
# set_PObjLine_yv.restype =
set_PObjLine_yv.argtypes = [c_void_p, c_float]
set_PObjLine_ang = LibPhys.set_PObjLine_ang
# set_PObjLine_ang.restype =
set_PObjLine_ang.argtypes = [c_void_p, c_float]
set_PObjLine_rad = LibPhys.set_PObjLine_rad
# set_PObjLine_rad.restype =
set_PObjLine_rad.argtypes = [c_void_p, c_float]


class FPoint(object):
    def __init__(self, x=0, y=0):
        self.obj = FPoint_new(x, y)

    def getPoint(self):
        value = FPoint()
        del_FPoint(value.obj)
        value.obj = FPoint_getPoint(self.obj)
        return value

    def getDistance(self, point):
        return FPoint_getDistance(self.obj, point.obj)

    def move(self, vec):
        FPoint_move(self.obj, vec.obj)

    def getX(self):
        return FPoint_x(self.obj)

    def getY(self):
        return FPoint_y(self.obj)

    def setX(self, X):
        set_FPoint_x(self.obj, X)

    def setY(self, Y):
        set_FPoint_y(self.obj, Y)

    def __del__(self):
        del_FPoint(self.obj)


class MVec(object):
    def __init__(self, x=0, y=0):
        self.obj = MVec_new(x, y)

    def getMVec(self):
        value = MVec()
        del_MVec(value.obj)
        value.obj = MVec_getMVec(self.obj)
        return value

    def getXV(self):
        return MVec_xv(self.obj)

    def getYV(self):
        return MVec_yv(self.obj)

    def setXV(self, X):
        set_MVec_xv(self.obj, X)

    def setYV(self, Y):
        set_MVec_yv(self.obj, Y)

    def vecCollsion(self, vec):
        value = MVec()
        del_MVec(value.obj)
        value.obj = MVec_vecCollsion(self.obj, vec.obj)
        return value
    def __del__(self):
        del_MVec(self.obj)


class Circ(object):
    def __init__(self, point=FPoint(0, 0), radius=0):
        self.obj = Circ_new(point, radius)

    def __del__(self):
        del_Circ(self.obj)

    def getCirc(self):
        value = Circ()
        del_Circ(value.obj)
        value.obj = Circ_getCirc(self.obj)
        return value

    def circHitCirc(self, circ):
        return Circ_circHitCirc(self.obj, circ).obj

    def getX(self):
        return Circ_x(self.obj)

    def getY(self):
        return Circ_y(self.obj)

    def setX(self, X):
        set_Circ_x(self.obj, X)

    def setY(self, Y):
        set_Circ_y(self.obj, Y)

    def setR(self, R):
        Circ_setR(self.obj, R)


class CircObj(object):
    def __init__(self, point, radius, XV, YV):
        self.obj = CircObj_new(point.obj, radius, XV, YV)

    def __del__(self):
        del_CircObj(self.obj)

    def collisionCirc(self, circ):
        return CircObj_collisionCirc(self.obj, circ.obj)

    def move(self):
        CircObj_move(self.obj)

    def getX(self):
        return CircObj_x(self.obj)

    def getY(self):
        return CircObj_y(self.obj)

    def getXV(self):
        return CircObj_xv(self.obj)

    def getYV(self):
        return CircObj_yv(self.obj)

    def setX(self, value):
        set_CircObj_x(self.obj, value)

    def setY(self, value):
        set_CircObj_y(self.obj, value)

    def setXV(self, value):
        set_CircObj_xv(self.obj, value)

    def setYV(self, value):
        set_CircObj_yv(self.obj, value)

    def getCirc(self):
        value = Circ()
        del_Circ(value.obj)
        value.obj = Circ_getCirc(self.obj)
        return value


class FLine(object):
    def __init__(self, p1, p2):
        self.obj = FLine_new(p1.obj, p2.obj)

    def __del__(self):
        del_FLine(self.obj)

    def getP1(self):
        value = FPoint()
        del_FPoint(value.obj)
        value.obj = FLine_p1(self.obj)
        return value

    def getP2(self):
        value = FPoint()
        del_FPoint(value.obj)
        value.obj = FLine_p2(self.obj)
        return value

    def setP1(self, point):
        set_FLine_p1(self.obj, point.obj)

    def setP2(self, point):
        set_FLine_p2(self.obj, point.obj)

    def findPerpPoint(self, p1, p2, p3):
        value = FPoint()
        del_FPoint(value.obj)
        value.obj = FLine_findPerpPoint(self.obj, p1.obj, p2.obj, p3.obj)
        return value


    def getDistance(self):
        return FPoint_getDistance(self.obj)

    def getMidPoint(self):
        value = FPoint()
        del_FPoint(value.obj)
        value.obj = FLine_getMidPoint(self.obj)
        return value

    def hitLine(self, line):
        return FLine_hitLine(self.obj, line.obj)

    def linehitCirc(self, perpPoint, circCenter, radius):
        return FLine_linehitCirc(self.obj, perpPoint.obj, circCenter.obj, radius)


class lineObj(object):
    def __init__(self, p1, p2, vec):
        self.obj = lineObj_new(p1.obj, p2.obj, vec.obj)

    def __del__(self):
        del_lineObj(self.obj)

    def move(self):
        lineObj_move(self.obj)

    def hitLine(self, line):
        lineObj_hitLine(self.obj, line.obj)

    def lineHitCirc(self, circ):
        lineObj_lineHitCirc(self.obj, circ.obj)

    def setP1(self, p1):
        set_lineObj_p1(self.obj, p1.obj)

    def setP2(self, p2):
        set_lineObj_p2(self.obj, p2.obj)

    def setXV(self, xv):
        set_lineObj_xv(self.obj, xv)

    def setYV(self, yv):
        set_lineObj_xv(self.obj, yv)

    def getP1(self, p1):
        value = FPoint()
        del_FPoint(value.obj)
        value.obj = lineObj_p1(self.obj)
        return value

    def getP2(self, p2):
        value = FPoint()
        del_FPoint(value.obj)
        value.obj = lineObj_p2(self.obj)
        return value

    def getXV(self, xv):
        lineObj_xv(self.obj)

    def getYV(self, yv):
        lineObj_xv(self.obj)


class PPoint(object):
    def __init__(self, xc, yc, rad, ang):
        self.obj = PPoint_new(xc, yc, rad, ang)

    def __del__(self):
        del_PPoint(self.obj)

    def getAngle(self):
        return PPoint_angle(self.obj)

    def getRadius(self):
        return PPoint_radius(self.obj)

    def setAngle(self):
        return set_PPoint_angle(self.obj)

    def setRadius(self):
        return set_PPoint_radius(self.obj)

    def getXC(self):
        return PPoint_xc(self.obj)

    def getYC(self):
        return PPoint_yc(self.obj)

    def setXC(self, value):
        PPoint_xc(self.obj, value)

    def setYC(self, value):
        PPoint_yc(self.obj, value)

    def getCenter(self):
        value = FPoint()
        del_FPoint(value.obj)
        value.obj = getCenter_PPoint(self.obj)
        return value

    def setCenter(self, center):
        setCenter_PPoint(self.obj, center.obj)


class PCirc(object):
    def __init__(self, center, centRad, circ, ang):
        self.obj = PCirc_new(center, centRad, circ, ang)

    def __del__(self):
        del_PCirc(self.obj)

    def getAngle(self):
        return PCirc_angle(self.obj)

    def getXC(self):
        return PPoint_xc(self.obj)

    def getYC(self):
        return PPoint_yc(self.obj)

    def setXC(self, value):
        PPoint_xc(self.obj, value)

    def setYC(self, value):
        PPoint_yc(self.obj, value)

    def getCenter(self):
        value = FPoint()
        del_FPoint(value.obj)
        value.obj = getCenter_PPoint(self.obj)
        return value


    def setCenter(self, center):
        setCenter_PPoint(self.obj, center.obj)

    def reMath(self):
        PCirc_reMath(self.obj)

    def setAngle(self, angle):
        PCirc_setAngle(self.obj, angle)

    def getAngle(self):
        return PCirc_PPoint_angle(self.obj)

    def getRadius(self):
        return PCirc_PPoint_radius(self.obj)


class PLine(object):
    def __init__(self, CENTER, Rad1, Ang1, Rad2, Ang2):
        self.obj = PLine_new(CENTER, Rad1, Ang1, Rad2, Ang2)

    def __del__(self):
        del_PLine(self.obj)

    def setAngle(self, angle):
        set_PLine_angle(self.obj, angle)

    def getAngle(self):
        return PLine_angle(self.obj)

    def getLine(self):
        value = FLine()
        del_FLine(value.obj)
        value.obj = getLine_PLine(self.obj)
        return value

    def reMath(self):
        reMath_PLine(self.obj)


class PVEC(object):
    def __init__(self, ang, rad):
        self.obj = PVEC_new(ang, rad)

    def __del__(self):
        del_PVEC(self.obj)

    def getAng(self):
        return PVEC_ang(self.obj)

    def setAng(self, value):
        set_PVEC_ang(self.obj, value)

    def reMath(self):
        PVEC_reMath(self.obj)

    def getXV(self):
        return PVEC_xv(self.obj)

    def getYV(self):
        return PVEC_yv(self.obj)

    def setXV(self):
        set_PVEC_xv(self.obj)

    def setYV(self):
        set_PVEC_yv(self.obj)

    def fromMVec(self, MVec):
        PVEC_fromMVec(self.obj, MVec.obj)

    def getRad(self):
        return PVEC_rad(self.obj)

    def setRad(self, value):
        set_PVEC_rad(self.obj, value)


class PObjLine(object):
    def __init__(self, ANGLE, radius, CENTER, Rad1, Ang1, Rad2, Ang2):
        self.obj = PVEC_new(ANGLE, radius, CENTER, Rad1, Ang1, Rad2, Ang2)

    def __del__(self):
        del_PObjLine(self.obj)

    def reMath(self):
        PObjLine_reMath(self.obj)

    def rotateObj(self, value):
        PObjLine_rotateObj(self.obj, value)

    def rotateVec(self, value):
        PObjLine_rotateVec(self.obj, value)

    def getXV(self):
        return PObjLine_xv(self.obj)

    def getYV(self):
        return PObjLine_yv(self.obj)

    def setXV(self):
        set_PObjLine_xv(self.obj)

    def setYV(self):
        set_PObjLine_yv(self.obj)

    def getRad(self):
        return PObjLine_rad(self.obj)

    def setRad(self, value):
        set_PObjLine_rad(self.obj, value)

    def getAng(self):
        return PObjLine_ang(self.obj)

    def setAng(self, value):
        set_PObjLine_ang(self.obj, value)

    def getLine(self):
        value = FLine()
        del_FLine(value.obj)
        value.obj = getLine_PLine(self.obj)
        return value


class PObjCirc(object):
    def __init__(self, angle, radius, center, centerRad, circ, angl):
        self.obj = PVEC_new(angle, radius, center, centerRad, circ, angl)

    def __del__(self):
        del_PObjCirc(self.obj)

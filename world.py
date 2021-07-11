import time

import MinPhysBridge
import objects


class World(object):
    def __init__(self, map_w, map_h):
        self.width = map_w
        self.height = map_h
        self.p = MinPhysBridge.FPoint(0, 0)
        MinPhysBridge.del_FPoint(self.p.obj)
        self.ang = 100
        self.p.obj = MinPhysBridge.getPointOnCirc(200, 200, 100, self.ang)

    def loop(self):
        while True:
            self.ang += 1
            if self.ang > 360:
                self.ang = 0
            MinPhysBridge.del_FPoint(self.p.obj)
            self.p.obj = MinPhysBridge.getPointOnCirc(200, 200, 100, self.ang)
            time.sleep(0.1)

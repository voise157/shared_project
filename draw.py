import pygame
import world

class Draw(object):
    def __init__(self, wrld, window):
        self.wrld = world.World(wrld)
        self.window = window


    def draw(self):
        pygame.draw.line(self.window, [124, 33, 63], [0, 0], [1200, 1200])
        pygame.draw.ellipse(self.window, [255, 0, 0], [self.wrld.p.getX(), self.wrld.p.getY()])
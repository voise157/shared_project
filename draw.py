import pygame
import world

class Draw(object):
    def __init__(self, wrld, window):
        self.wrld = wrld
        self.window = window
        print(self.window)

    def draw(self):
        pygame.draw.line(self.window, [124, 33, 63], [0, 0], [1200, 1200])
        pygame.draw.circle(self.window, (0, 0, 255), (250, 250), 75)
        pygame.draw.circle(self.window, (255, 0, 0), (self.wrld.p.getX(), self.wrld.p.getY()), 75)
        #self.wrld.p.getX()
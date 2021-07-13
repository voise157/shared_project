import pygame


class Gui(object):
    def __init__(self, window):
        self.active = True
        self.window = window

    def draw(self):
        if self.active:
            pygame.draw.circle(self.window, (230, 10, 55), (450, 350), 75)

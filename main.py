import threading
import time
import numpy as np
import pygame
import random
import MinPhysBridge
import draw
import gui
import multiplayer
import objects
import world
from ctypes import *


class Main(object):
    def __init__(self):
        pygame.init()
        self.window = pygame.display.set_mode(
            [int(pygame.display.Info().current_w / 1.5), int(pygame.display.Info().current_h / 1.5)])
        self.wrld = world.World(1200, 1200)
        self.drawThread = threading.Thread(target=self.draw, daemon=True)
        self.worldThread = threading.Thread(target=self.wrld.loop, daemon=True)
        self.drawObj = draw.Draw(self.wrld, self.window)
        self.guiObj = gui.Gui(self.window)

    def run(self):
        self.drawThread.start()
        self.worldThread.start()
        while True:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    return 0


    def draw(self):
        while True:
            self.window.fill((134, 134, 255))
            self.drawObj.draw()
            self.guiObj.draw()
            pygame.display.flip()

mainObj = Main()
x = 100
y = 100

mainObj.run()
pygame.quit()
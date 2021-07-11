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


class Main(object):
    def __init__(self):
        pygame.init()
        self.window = pygame.display.set_mode(
            [int(pygame.display.Info().current_w / 1.5), int(pygame.display.Info().current_h / 1.5)])
        self.wrld = world.World(1200, 1200)
        self.drawThread = threading.Thread(target=self.draw, daemon=True)
        self.worldThread = threading.Thread(target=self.wrld.loop, daemon=True)
        self.drawObj = draw.Draw(self.wrld, self.window)

    def run(self):
        self.drawThread.start()
        self.worldThread.start()
        while True:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    return 0


    def draw(self):
        self.window.fill((134, 134, 255))
        pygame.draw.circle(self.window, (0, 0, 255), (250, 250), 75)
        self.drawObj.draw()
        pygame.display.flip()

mainObj = Main()
mainObj.run()
pygame.quit()
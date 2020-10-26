import pygame as pg
import time
import 

pg.init()
screen = pg.display.set_mode((600, 800))
pg.display.set_caption('0527 pygame')
screen.fill((0, 0, 0))
pg.display.flip()

run = True

while run:
    for event in pg.event.get():
        print(event)
        if event.type == pg.QUIT:
            run = False
        elif event.type == pg.KEYDOWN:
            if event.key == pg.K_g:
                screen.fill((0, 255, 0))
            elif event.key == pg.K_r:
                screen.fill((255, 0, 0))
            elif event.key == pg.K_w:
                screen.fill((255, 255, 255))
            elif event.key == pg.K_b:
                screen.fill((0, 0, 255))
            pg.display.flip()
            
pg.quit()
import pygame as pg

pg.init()
screen = pg.display.set_mode((600, 800))
pg.display.set_caption('imageWwwwww')
screen.fill((0, 0, 0))
pg.display.flip()

run = True
while run:
    for event in pg.event.get():
        if event.type == pg.QUIT:
            run = False
    pg.draw.line(screen, color_gry, (150,150), (200, 200), 5)
    pg.draw.lines(screen, color_blu, False, [(100, 300), (150,350), (200,300), (250,350), (300,300)])
    pg.draw.lines(screen, color_gry, Ture, [(200, 200), (255,260), (250,200), (190,240), (260,240)], 5)
    pg.draw.rect(screen, color_blk, pg.Rect(50, 50, 50, 50))
    pg.draw.rect(screen, color_blk, pg.Rect(100, 100, 50, 50), 2)
pg.quit()
import pygame as pg
import Model.main as model
import random
from PIL import *
from EventManager import *
from MainConst import *
from View.const import *

class GraphicalView(object):
    """
    Draws the model state onto the screen.
    """
    def __init__(self, evManager, model):
        """
        evManager (EventManager): Allows posting messages to the event queue.
        model (GameEngine): a strong reference to the game Model.
        """

        self.image = {'background': None,
                      'message': None,
                      'base': None,
                      'bird': None,
                      'lowerPipe': None,
                      'upperPipe': None,
                      'number': None,
                      'gameover': None}

        

        self.evManager = evManager
        evManager.RegisterListener(self)
        self.model = model

        self.isinitialized = False
        self.screen = None
        self.clock = None
        self.smallfont = None
        
        
        

    def notify(self, event):
        """
        Receive events posted to the message queue. 
        """
        if isinstance(event, Event_Initialize):
            self.initialize()
        if isinstance(event, Event_Quit):
            # shut down the pygame graphics
            self.isinitialized = False
            pg.quit()
        if isinstance(event, Event_EveryTick) and self.isinitialized:
            cur_state = self.model.state.peek()
            if cur_state == model.STATE_MENU:
                self.render_menu()
            if cur_state == model.STATE_PLAY:
                self.render_play()
            if cur_state == model.STATE_STOP:
                self.render_stop()
            if cur_state == model.STATE_DEAD:
                self.render_dead()

            self.display_fps()
            # limit the redraw speed to 30 frames per second
            self.clock.tick(FramePerSec)
    
    def render_menu(self):
        
        self.model.wingcount += 1
        self.model.wing = BirdWing[self.model.wingcount % 4]
        self.model.menubird = [1,2,3,4,5,6,7,8,7,6,5,4,3,2]

        """
        Render the game menu.
        """

        self.screen.blit(self.image['background'][self.model.backgroundType], (0,0)) #
        self.screen.blit(self.image['bird'][self.model.birdType][self.model.wing], (self.model.pos['bird']['x'], self.model.pos['bird']['y']-self.model.menubird[self.model.wingcount % 14])) #
        self.screen.blit(self.image['message'], (self.model.pos['message']['x'], self.model.pos['message']['y'])) #
        self.screen.blit(self.image['base'], (self.model.pos['base']['x'], self.model.pos['base']['y'])) #

        # draw backgound
        #self.screen.fill(Color_Black)
        # write some word
        somewords = self.smallfont.render(
                    'You are in the Menu. Space to play. Esc exits.', 
                    True, (0, 255, 0))
        (SurfaceX, SurfaceY) = somewords.get_size()
        pos_x = (ScreenSize[0] - SurfaceX)/2
        pos_y = (ScreenSize[1] - SurfaceY)/2
        #self.screen.blit(somewords, (pos_x, pos_y))
        # update surface
        pg.display.flip()
        
    def render_play(self):


        self.model.wingcount += 1
        self.model.wing = BirdWing[self.model.wingcount % 4]

        """
        Render the game play.
        """

        self.screen.blit(self.image['background'][self.model.backgroundType], (0,0)) #
        self.screen.blit(self.image['bird'][self.model.birdType][self.model.wing], (self.model.pos['bird']['x'], self.model.pos['bird']['y'])) #
        self.screen.blit(self.image['pipe'][self.model.pipeType], (self.model.pipeX, self.model.pipeY + model.PipeGap))
        self.screen.blit(pg.transform.rotate(self.image['pipe'][self.model.pipeType],180), (self.model.pipeX, self.model.pipeY - self.model.pipeheight))
        self.screen.blit(self.image['base'], (self.model.pos['base']['x'], self.model.pos['base']['y'])) #
        self.screen.blit(self.image['number'][self.model.score_hun], (self.model.pos['number']['x'] - self.image['number'][self.model.score_hun].get_width() - 3, self.model.pos['number']['y']))
        self.screen.blit(self.image['number'][self.model.score_ten], (self.model.pos['number']['x']                                                             , self.model.pos['number']['y']))
        self.screen.blit(self.image['number'][self.model.score_one], (self.model.pos['number']['x'] + self.image['number'][self.model.score_ten].get_width() + 3, self.model.pos['number']['y']))

        # draw backgound
        #self.screen.fill(Color_White)
        # write some word
        somewords = self.smallfont.render(
                    'Play game! P to stop. Esc to return menu.', 
                    True, (0, 255, 0))
        (SurfaceX, SurfaceY) = somewords.get_size()
        pos_x = (ScreenSize[0] - SurfaceX)/2
        pos_y = (ScreenSize[1] - SurfaceY)/2
        #self.screen.blit(somewords, (pos_x, pos_y))
        # update surface
        pg.display.flip()
        
    def render_stop(self):
        """
        Render the stop screen.
        """
        self.screen.blit(self.image['background'][self.model.backgroundType], (0,0)) #
        self.screen.blit(self.image['pipe'][self.model.pipeType], (self.model.pipeX, self.model.pipeY + model.PipeGap))
        self.screen.blit(pg.transform.rotate(self.image['pipe'][self.model.pipeType],180), (self.model.pipeX, self.model.pipeY - self.model.pipeheight))
        self.screen.blit(self.image['base'], (self.model.pos['base']['x'], self.model.pos['base']['y'])) #
        self.screen.blit(self.image['bird'][self.model.birdType][self.model.wing], (self.model.pos['bird']['x'], self.model.pos['bird']['y'])) #        
        self.screen.blit(self.image['number'][self.model.score_hun], (self.model.pos['number']['x'] - self.image['number'][self.model.score_hun].get_width() - 3, self.model.pos['number']['y']))
        self.screen.blit(self.image['number'][self.model.score_ten], (self.model.pos['number']['x']                                                             , self.model.pos['number']['y']))
        self.screen.blit(self.image['number'][self.model.score_one], (self.model.pos['number']['x'] + self.image['number'][self.model.score_ten].get_width() + 3, self.model.pos['number']['y']))

        # draw backgound
        #self.screen.fill(Color_Black)
        # write some word
        somewords = self.smallfont.render(
                    'Stop the game. P to return the game.', 
                    True, (0, 255, 0))
        (SurfaceX, SurfaceY) = somewords.get_size()
        pos_x = (ScreenSize[0] - SurfaceX)/2
        pos_y = (ScreenSize[1] - SurfaceY)/2
        self.screen.blit(somewords, (pos_x, pos_y))
        # update surface
        pg.display.flip()

    def render_dead(self):
        """
        Render the dead screen.
        """
        self.model.wing = 2
        self.screen.blit(self.image['background'][self.model.backgroundType], (0,0)) #
        self.screen.blit(self.image['pipe'][self.model.pipeType], (self.model.pipeX, self.model.pipeY + model.PipeGap))
        self.screen.blit(pg.transform.rotate(self.image['pipe'][self.model.pipeType],180), (self.model.pipeX, self.model.pipeY - self.model.pipeheight))
        self.screen.blit(self.image['base'], (self.model.pos['base']['x'], self.model.pos['base']['y'])) #
        self.screen.blit(self.image['gameover'], (self.model.pos['gameover']['x'], self.model.pos['gameover']['y']))
        self.screen.blit(self.image['bird'][self.model.birdType][self.model.wing], (self.model.pos['bird']['x'], self.model.pos['bird']['y'])) #
        self.screen.blit(self.image['number'][self.model.score_hun], (self.model.pos['number']['x'] - self.image['number'][self.model.score_hun].get_width() - 3, self.model.pos['number']['y']))
        self.screen.blit(self.image['number'][self.model.score_ten], (self.model.pos['number']['x']                                                             , self.model.pos['number']['y']))
        self.screen.blit(self.image['number'][self.model.score_one], (self.model.pos['number']['x'] + self.image['number'][self.model.score_ten].get_width() + 3, self.model.pos['number']['y']))

        # draw background
        #self.screen.fill(ColorWhite)
        # write some word
        #somewords = self.smallfont.render(
        #            'Game over! Space to play again.', 
        #            True, ColorGreen)
        #(surfaceX, surfaceY) = somewords.get_size()
        #posX = (ScreenSize[0] - surfaceX)/2
        #posY = (ScreenSize[1] - surfaceY)/2
        #self.screen.blit(somewords, (posX, posY))
        # update surface
        pg.display.flip()

    def display_fps(self):
        """Show the programs FPS in the window handle."""
        caption = "{} - FPS: {:.2f}".format(GameCaption, self.clock.get_fps())
        pg.display.set_caption(caption)
        
    def initialize(self):

        """
        Set up the pygame graphical display and loads graphical resources.
        """
        
        result = pg.init()
        pg.font.init()
        pg.display.set_caption(GameCaption)
        self.screen = pg.display.set_mode(ScreenSize)
        self.clock = pg.time.Clock()
        self.smallfont = pg.font.Font(None, 20)
        self.isinitialized = True


        self.image['message'] = pg.image.load(ImagePath['message']) #
        self.model.pos['message']['x'] = int((ScreenSize[0] - self.image['message'].get_width()) / 2) #
        self.model.pos['message']['y'] = int((ScreenSize[1] - self.image['message'].get_height()) / 4) #


        self.model.backgroundType = random.randint(0,1) #
        self.image['background'] = (pg.image.load(ImagePath['background'][0]),
                                    pg.image.load(ImagePath['background'][1])) #


        self.image['gameover'] = (pg.image.load(ImagePath['gameover'])) #
        self.model.pos['gameover']['x'] = int((ScreenSize[0] - self.image['gameover'].get_width()) / 2) #
        self.model.pos['gameover']['y'] = int((ScreenSize[1] - self.image['gameover'].get_height()) / 2) #


        self.image['base'] = (pg.image.load(ImagePath['base'])) #
        self.model.pos['base']['x'] = 0
        self.model.pos['base']['y'] = ScreenSize[1] - self.image['base'].get_height()
        self.model.basewidth = self.image['base'].get_width()


        self.model.pipeType = random.randint(0,1) #
        self.image['pipe'] =   (pg.image.load(ImagePath['pipe'][0]).convert_alpha(),
                                pg.image.load(ImagePath['pipe'][1]).convert_alpha()) 
        self.model.pipewidth = self.image['pipe'][self.model.pipeType].get_width()
        self.model.pipeheight = self.image['pipe'][self.model.pipeType].get_height()



        self.model.birdType = random.randint(0,2) #
        self.image['bird'] =  ((pg.image.load(ImagePath['bird'][0][0]).convert_alpha(),
                                pg.image.load(ImagePath['bird'][0][1]).convert_alpha(),
                                pg.image.load(ImagePath['bird'][0][2]).convert_alpha()),
                               (pg.image.load(ImagePath['bird'][1][0]).convert_alpha(),
                                pg.image.load(ImagePath['bird'][1][1]).convert_alpha(),
                                pg.image.load(ImagePath['bird'][1][2]).convert_alpha()),
                               (pg.image.load(ImagePath['bird'][2][0]).convert_alpha(),
                                pg.image.load(ImagePath['bird'][2][1]).convert_alpha(),
                                pg.image.load(ImagePath['bird'][2][2]).convert_alpha())) #
        self.model.size['bird'] = self.image['bird'][0][0].get_size() #
        self.model.pos['bird']['x'] = int(ScreenSize[0] * 0.2) #
        self.model.pos['bird']['y'] = int((ScreenSize[1] - self.image['bird'][0][0].get_height()) / 2) #
        self.model.birdwidth = self.image['bird'][0][self.model.birdType].get_width()
        self.model.birdheight = self.image['bird'][0][self.model.birdType].get_height()

        self.image['number'] = (pg.image.load(ImagePath['number'][0]).convert_alpha(),
                                pg.image.load(ImagePath['number'][1]).convert_alpha(),
                                pg.image.load(ImagePath['number'][2]).convert_alpha(),
                                pg.image.load(ImagePath['number'][3]).convert_alpha(),
                                pg.image.load(ImagePath['number'][4]).convert_alpha(),
                                pg.image.load(ImagePath['number'][5]).convert_alpha(),
                                pg.image.load(ImagePath['number'][6]).convert_alpha(),
                                pg.image.load(ImagePath['number'][7]).convert_alpha(),
                                pg.image.load(ImagePath['number'][8]).convert_alpha(),
                                pg.image.load(ImagePath['number'][9]).convert_alpha()) 

        self.model.pos['number']['x'] = int((ScreenSize[0] - self.image['number'][self.model.score_ten].get_width())* 0.5) #
        self.model.pos['number']['y'] = int(ScreenSize[1] * 0.1)


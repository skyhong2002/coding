import pygame as pg
import random
from EventManager import *
from Model.GameObject import *
from Model.StateMachine import *
from Model.const import *
from MainConst import *

class GameEngine(object):
    """
    Tracks the game state.
    """
    def __init__(self, evManager, AIList):
        """
        evManager (EventManager): Allows posting messages to the event queue.

        Attributes:
            running (bool): True while the engine is online. Changed via Event_Quit().
            state (StateMachine()): control state change, stack data structure.
            AIList (list.str): all AI name list.
            player (list.player()): all player object.
        """
        self.evManager = evManager
        evManager.RegisterListener(self)

        self.running = False
        self.restartonce = False
        self.state = StateMachine()
        self.AIList = AIList
        self.player = []

        self.size = {'bird': None,
                     'lowerPipe': None}
        self.pos = {'message': {'x': 0, 'y': 0},
                    'bird': {'x': 0, 'y': 0},
                    'base': {'x': 0, 'y': 0},
                    'gameover': {'x': 0, 'y': 0},
                    'number': {'x': 0, 'y': 0},
                    'lowerPipe': None,
                    'upperPipe': None}
        self.menubird = []
        self.baseShift = 0
        self.vel = FlapVel
        self.score = 0
        self.score_hun = 0
        self.score_ten = 0
        self.score_one = 0

        self.pipeX = ScreenSize[0]
        self.pipeY = 100
        self.basewidth = 0
        self.pipewidth = 0
        self.birdwidth = 0
        self.birdheight = 0
        self.birdType = random.randint(0,2)
        self.pipeType = random.randint(0,1)
        self.backgroundType = random.randint(0,1)

        self.wing = 0
        self.wingcount = 0

        

    def notify(self, event):
        """
        Called by an event in the message queue. 
        """
        if isinstance(event, Event_Initialize):
            self.initialize()
        elif isinstance(event, Event_Quit):
            self.running = False
        elif isinstance(event, Event_StateChange):
            # pop request
            if not event.state:
                # false if no more states are left
                if not self.state.pop():
                    self.evManager.Post(Event_Quit())
            else:
                # push a new state on the stack
                self.state.push(event.state)

        elif isinstance(event, Event_EveryTick): ###
            cur_state = self.state.peek()

            if cur_state == STATE_MENU:
                #print('cur_state == STATE_MENU')
                self.updateBase()
                self.restart()
                

            elif cur_state == STATE_PLAY: 
                #print('cur_state == STATE_PLAY')
                self.updateBase()
                self.updatePipe()
                self.updateBird()
                if self.checkcrash():
                    self.evManager.Post(Event_StateChange(STATE_DEAD))
                self.checkscore()
                self.updateScore()

            elif cur_state == STATE_STOP:
                #print('cur_state == STATE_STOP')
                pass

            elif cur_state == STATE_DEAD: 
                #print('cur_state == STATE_DEAD')
                self.updateBird()
                
        elif isinstance(event, Event_Jump):
            self.vel = FlapVel


    def getRandomPipe(self):
        """
        TASK 2
        """
        self.pipeX = ScreenSize[0] + 10
        self.pipeY = random.randint(10, self.pos['base']['y'] - PipeGap - 10)

    def updateBase(self):
        """
        TASK 2
        """
        self.pos['base']['x'] -= 4
        if self.pos['base']['x'] + self.basewidth <= ScreenSize[0]:
            self.pos['base']['x'] = 0
        
        if self.restartonce :
            print('all restart')
            self.birdType = random.randint(0,2)
            self.pipeType = random.randint(0,1)
            self.backgroundType = random.randint(0,1)
            self.score = 0
            self.score_hun = 0
            self.score_ten = 0
            self.score_one = 0
            self.getRandomPipe()
            self.restartonce = False

    def updatePipe(self):
        """
        TASK 2
        """
        self.pipeX -= 4
        if (-self.pipeX) >= self.pipewidth:
            self.getRandomPipe()
            self.pipeX = ScreenSize[0]


    def updateBird(self):
        """
        TASK 3
        """
        if self.pos['bird']['y'] + self.birdheight > self.pos['base']['y']:
            self.vel = 0
        elif self.vel <= MaxVel:
            self.vel += FlapAcc

        self.pos['bird']['y'] += self.vel

    def checkcrash(self):
        """
        TASK 4
        """

        if  ( self.pos['bird']['x'] + self.birdwidth > self.pipeX and self.pos['bird']['x'] < self.pipeX + self.pipewidth) and ( self.pos['bird']['y'] < self.pipeY or self.pos['bird']['y'] + self.birdheight > self.pipeY + PipeGap ) or ( self.pos['bird']['y'] + self.birdheight > self.pos['base']['y']):
            return True
        else:
            return False

    def restart(self):
        """
        TASK 4 & TASK 5
        """
        self.pos['bird']['y'] = int((ScreenSize[1] - self.birdheight) / 2)
        self.pipeX = ScreenSize[0]
        self.vel = FlapVel

    def updateScore(self):
        """
        TASK 5
        """
        #self.score_hun = int((self.score % 1000 - self.score % 100)/ 100)
        #self.score_ten = int((self.score % 100 - self.score % 10) / 10)
        #self.score_one = int(self.score % 10)

        # 其實放到checkscore(self)就可以了

        pass

    def checkscore(self):
        """
        TASK 5
        """
        if self.pos['bird']['x'] > self.pipeX + self.pipewidth > self.pos['bird']['x'] - 4:
            self.score += 1
            self.score_hun = int((self.score % 1000 - self.score % 100)/ 100)
            self.score_ten = int((self.score % 100 - self.score % 10) / 10)
            self.score_one = int(self.score % 10)
            print('score:', self.score, str(self.score_hun) + str(self.score_ten) + str(self.score_one))

    def initialize(self):
        """
        init pygame event
        """
        print('Game Start')

        """
        TASK 1 & TASK 2 & TASK 3
        """

    def run(self):
        """
        Starts the game engine loop.

        This pumps a Tick event into the message queue for each loop.
        The loop ends when this object hears a QuitEvent in notify(). 
        """
        self.running = True
        self.evManager.Post(Event_Initialize())
        self.state.push(STATE_MENU)
        while self.running:
            newTick = Event_EveryTick()
            self.evManager.Post(newTick)
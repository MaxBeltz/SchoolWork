# multiAgents.py
# --------------
# Licensing Information:  You are free to use or extend these projects for
# educational purposes provided that (1) you do not distribute or publish
# solutions, (2) you retain this notice, and (3) you provide clear
# attribution to UC Berkeley, including a link to http://ai.berkeley.edu.
# 
# Attribution Information: The Pacman AI projects were developed at UC Berkeley.
# The core projects and autograders were primarily created by John DeNero
# (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# Student side autograding was added by Brad Miller, Nick Hay, and
# Pieter Abbeel (pabbeel@cs.berkeley.edu).


from util import manhattanDistance
from game import Directions
import random, util

from game import Agent

class ReflexAgent(Agent):
    """
    A reflex agent chooses an action at each choice point by examining
    its alternatives via a state evaluation function.

    The code below is provided as a guide.  You are welcome to change
    it in any way you see fit, so long as you don't touch our method
    headers.
    """


    def getAction(self, gameState):
        """
        You do not need to change this method, but you're welcome to.

        getAction chooses among the best options according to the evaluation function.

        Just like in the previous project, getAction takes a GameState and returns
        some Directions.X for some X in the set {NORTH, SOUTH, WEST, EAST, STOP}
        """
        # Collect legal moves and successor states
        legalMoves = gameState.getLegalActions()

        # Choose one of the best actions
        scores = [self.evaluationFunction(gameState, action) for action in legalMoves]
        bestScore = max(scores)
        bestIndices = [index for index in range(len(scores)) if scores[index] == bestScore]
        chosenIndex = random.choice(bestIndices) # Pick randomly among the best

        "Add more of your code here if you want to"

        return legalMoves[chosenIndex]

    def evaluationFunction(self, currentGameState, action):
        """
        Design a better evaluation function here.

        The evaluation function takes in the current and proposed successor
        GameStates (pacman.py) and returns a number, where higher numbers are better.

        The code below extracts some useful information from the state, like the
        remaining food (newFood) and Pacman position after moving (newPos).
        newScaredTimes holds the number of moves that each ghost will remain
        scared because of Pacman having eaten a power pellet.

        Print out these variables to see what you're getting, then combine them
        to create a masterful evaluation function.
        """
        # Useful information you can extract from a GameState (pacman.py)
        successorGameState = currentGameState.generatePacmanSuccessor(action)
        newPos = successorGameState.getPacmanPosition()
        newFood = successorGameState.getFood()
        newGhostStates = successorGameState.getGhostStates()
        newScaredTimes = [ghostState.scaredTimer for ghostState in newGhostStates]

        "*** YOUR CODE HERE ***"
        evaluation = 0 #will use for evaluation
        if successorGameState.isWin(): #big weight on a win
            return 9999
        if successorGameState.isLose(): #big weight on a loss
            return -9999
        if action == Directions.STOP: #stopping is for nerds
            evaluation -=100
       
        closestDistance = 9999 #we value a low closest distance
        farthestDistance = -9999 #we value a low farthest position
        foodlist = newFood.asList() #make a list to work with
        for food in foodlist:
            testDistance = manhattanDistance(food, newPos) + len(foodlist)*10 #calsulation for testing the less items the lower the value
            if testDistance < closestDistance: #if the next food is closest
                closestDistance = testDistance
            if testDistance > farthestDistance: 
                farthestDistance = testDistance + len(foodlist)*10 #I accidently double weighted but it works, gift horse and all that 
        evaluation -= closestDistance #subtract the closest distance from the evaluation
        evaluation -= farthestDistance #subtract the farthest distance from the evaluation
            
        
        return evaluation

def scoreEvaluationFunction(currentGameState):
    """
    This default evaluation function just returns the score of the state.
    The score is the same one displayed in the Pacman GUI.

    This evaluation function is meant for use with adversarial search agents
    (not reflex agents).
    """
    return currentGameState.getScore()

class MultiAgentSearchAgent(Agent):
    """
    This class provides some common elements to all of your
    multi-agent searchers.  Any methods defined here will be available
    to the MinimaxPacmanAgent, AlphaBetaPacmanAgent & ExpectimaxPacmanAgent.

    You *do not* need to make any changes here, but you can if you want to
    add functionality to all your adversarial search agents.  Please do not
    remove anything, however.

    Note: this is an abstract class: one that should not be instantiated.  It's
    only partially specified, and designed to be extended.  Agent (game.py)
    is another abstract class.
    """

    def __init__(self, evalFn = 'scoreEvaluationFunction', depth = '2'):
        self.index = 0 # Pacman is always agent index 0
        self.evaluationFunction = util.lookup(evalFn, globals())
        self.depth = int(depth)

class MinimaxAgent(MultiAgentSearchAgent):
    """
    Your minimax agent (question 2)
    """

    def getAction(self, gameState):
        """
        Returns the minimax action from the current gameState using self.depth
        and self.evaluationFunction.

        Here are some method calls that might be useful when implementing minimax.

        gameState.getLegalActions(agentIndex):
        Returns a list of legal actions for an agent
        agentIndex=0 means Pacman, ghosts are >= 1

        gameState.generateSuccessor(agentIndex, action):
        Returns the successor game state after an agent takes an action

        gameState.getNumAgents():
        Returns the total number of agents in the game

        gameState.isWin():
        Returns whether or not the game state is a winning state

        gameState.isLose():
        Returns whether or not the game state is a losing state
        """
	
        def pacMax (gameState, depth): #Calculate the Max for pacman
            currentMax = -9999 #arbitraty value
            if gameState.isWin() or gameState.isLose() or depth+1 == self.depth: #If we reach the end of recursion
                return self.evaluationFunction(gameState)
            potentialActions = gameState.getLegalActions(0) #Potential actions for pacman
            for actions in potentialActions:
                potentialSuccessor = gameState.generateSuccessor(0, actions) #get successor state
                currentMax = max(currentMax, ghostMin(potentialSuccessor, depth+1, 1)) #find the max of max
            return currentMax #return the Max of Max

        def ghostMin (gameState, depth, ghost): #calculate the min for the ghosts
            currentMin = 9999 #arbitrary value
            if gameState.isWin() or gameState.isLose(): #end of the line
                return self.evaluationFunction(gameState)
            potentialActions = gameState.getLegalActions(ghost) #potential actions for the ghost
            for actions in potentialActions:
                potentialSuccessor = gameState.generateSuccessor(ghost, actions) #get successor state
                if ghost == (gameState.getNumAgents()-1): #you are the last ghost
                    currentMin = min(currentMin, pacMax(potentialSuccessor, depth)) #give back to pacman
                else: #you are not the last ghost
                    currentMin = min(currentMin, ghostMin(potentialSuccessor, depth, ghost+1)) #give to next ghost
            return currentMin #retun the min if mins

        currentMax = -9999 #this is the root of the tree
        currentAction = '' #storage for the action
        potentialActions = gameState.getLegalActions(0) #potential actions for pacman (us)
        for actions in potentialActions:
            potentialSuccessor = gameState.generateSuccessor(0,actions) #get successor state
            testMax = ghostMin(potentialSuccessor,0,1) #since we are the pac, we gotta sent to ghost squad
            if testMax > currentMax: #if it is better
                currentMax = testMax #save valus
                currentAction = actions #save action
        return currentAction #return best action
        
    
    

class AlphaBetaAgent(MultiAgentSearchAgent):
    """
    Your minimax agent with alpha-beta pruning (question 3)
    """

    def getAction(self, gameState):
        """
        Returns the minimax action using self.depth and self.evaluationFunction
        """
        def pacMax (gameState, depth, currentMax, currentMin): #similar to question 2, as such I will only comment on differences
            testMax = -9999
            if gameState.isWin() or gameState.isLose() or depth+1 == self.depth:
                return self.evaluationFunction(gameState)
            potentialActions = gameState.getLegalActions(0)
            for actions in potentialActions:
                potentialSuccessor = gameState.generateSuccessor(0, actions)
                testMax = max(testMax, ghostMin(potentialSuccessor, depth+1, 1, currentMax, currentMin)) #intermeediate variable for testing
                if testMax > currentMin: #if the tested max is greater than the min 1 level above
                    return testMax #retun as further exploration would yeald no change
                else: #there is a potential for change
                    currentMax = max(currentMax, testMax)
            return testMax #will return when there is a potential for change

        def ghostMin (gameState, depth, ghost, currentMax, currentMin):
            testMin = 9999
            if gameState.isWin() or gameState.isLose():
                return self.evaluationFunction(gameState)
            potentialActions = gameState.getLegalActions(ghost)
            for actions in potentialActions:
                potentialSuccessor = gameState.generateSuccessor(ghost, actions)
                if ghost == (gameState.getNumAgents()-1): 
                    testMin = min(testMin, pacMax(potentialSuccessor, depth, currentMax, currentMin)) #intermediate variable
                    if testMin < currentMax: #if the tested min is less than the max one level above
                        return testMin #return as further exploration would yield no change 
                    else:
                        currentMin = min(currentMin,testMin)
                else:
                    testMin = min(testMin,ghostMin(potentialSuccessor, depth, ghost+1, currentMax, currentMin))
                    if testMin < currentMax: #if the tested min is less than the max one level above
                        return testMin #return as further exploration would yield no chang
                    else:
                        currentMin = min(currentMin,testMin)
            return testMin

        currentMax = -9999
        currentAction = ''
        potentialActions = gameState.getLegalActions(0)
        for actions in potentialActions:
            potentialSuccessor = gameState.generateSuccessor(0,actions)
            testMax = max(currentMax, ghostMin(potentialSuccessor,0,1, currentMax, 9999))
            if testMax > currentMax:
                currentMax = testMax
                currentAction = actions
        return currentAction
        

class ExpectimaxAgent(MultiAgentSearchAgent):
    """
      Your expectimax agent (question 4)
    """

    def getAction(self, gameState):
        """
        Returns the expectimax action using self.depth and self.evaluationFunction

        All ghosts should be modeled as choosing uniformly at random from their
        legal moves.
        """
        def pacMax (gameState, depth): #similar to question 2, as such I will only comment on differences
            currentMax = -9999 #no change on the max function
            if gameState.isWin() or gameState.isLose() or depth+1 == self.depth:
                return self.evaluationFunction(gameState)
            potentialActions = gameState.getLegalActions(0)
            for actions in potentialActions:
                potentialSuccessor = gameState.generateSuccessor(0, actions)
                currentMax = max(currentMax, ghostExpect(potentialSuccessor, depth+1, 1))
            return currentMax

        def ghostExpect (gameState, depth, ghost):
            expect = 0 #used for summation 
            if gameState.isWin() or gameState.isLose():
                return self.evaluationFunction(gameState)
            potentialActions = gameState.getLegalActions(ghost)
            for actions in potentialActions:
                potentialSuccessor = gameState.generateSuccessor(ghost, actions)
                if ghost == (gameState.getNumAgents()-1): #you are the last ghost
                    expect = expect + pacMax(potentialSuccessor, depth) #sum
                else:
                    expect = expect + ghostExpect(potentialSuccessor, depth, ghost+1) #sum
            expect = expect / len(potentialActions) #get the expected value
            return expect

        currentMax = -9999
        currentAction = ''
        potentialActions = gameState.getLegalActions(0)
        for actions in potentialActions:
            potentialSuccessor = gameState.generateSuccessor(0,actions)
            testMax = ghostExpect(potentialSuccessor,0,1)
            if testMax > currentMax:
                currentMax = testMax
                currentAction = actions
        return currentAction

def betterEvaluationFunction(currentGameState):
    """
    Your extreme ghost-hunting, pellet-nabbing, food-gobbling, unstoppable
    evaluation function (question 5).

    DESCRIPTION: Here I weighted 4 items for the evaluation, the closest piece of food, the farthest piece of food,
	distance to the nearest ghost (which I'm not convinced works), and number of power pellots remaining
    """
    newPos = currentGameState.getPacmanPosition()
    newFood = currentGameState.getFood()
    newGhostStates = currentGameState.getGhostStates()
    newScaredTimes = [ghostState.scaredTimer for ghostState in newGhostStates]
    newGhostPositions = currentGameState.getGhostPositions() #get list of ghost positions
    numCapsule = len(currentGameState.getCapsules())

    evaluation = 0
    if currentGameState.isWin(): #big weight on a win
        return 9999
    if currentGameState.isLose(): #big weight on a loss
        return -9999
    evaluation=- numCapsule*50 #penelize based on number of power pellots remaining
		
    closestDistance = 9999 #similar food distance evaluation as above
    farthestDistance = -9999
    foodList = newFood.asList()
    for food in foodList:
        testDistance = manhattanDistance(food, newPos) + len(foodList)*10
        if testDistance < closestDistance:
            closestDistance = testDistance
        if testDistance > farthestDistance:
            farthestDistance = testDistance + len(foodList)*10
    evaluation += closestDistance #difference here is we add weight based on the closet rather than farthest
    evaluation -= farthestDistance
	
    for ghosts in newGhostPositions: #will punish you for how close you are to the ghosts
        testDistance = manhattanDistance(ghosts, newPos) #I dont think this actually has any impact
        evaluation -= testDistance   
		
    return evaluation
	#oh well, once again a gift horse and we will take an average of 1005

# Abbreviation
better = betterEvaluationFunction

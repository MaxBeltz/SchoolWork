# search.py
# ---------
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


"""
In search.py, you will implement generic search algorithms which are called by
Pacman agents (in searchAgents.py).
"""

import util

class SearchProblem:
    """
    This class outlines the structure of a search problem, but doesn't implement
    any of the methods (in object-oriented terminology: an abstract class).

    You do not need to change anything in this class, ever.
    """

    def getStartState(self):
        """
        Returns the start state for the search problem.
        """
        util.raiseNotDefined()

    def isGoalState(self, state):
        """
          state: Search state

        Returns True if and only if the state is a valid goal state.
        """
        util.raiseNotDefined()

    def getSuccessors(self, state):
        """
          state: Search state

        For a given state, this should return a list of triples, (successor,
        action, stepCost), where 'successor' is a successor to the current
        state, 'action' is the action required to get there, and 'stepCost' is
        the incremental cost of expanding to that successor.
        """
        util.raiseNotDefined()

    def getCostOfActions(self, actions):
        """
         actions: A list of actions to take

        This method returns the total cost of a particular sequence of actions.
        The sequence must be composed of legal moves.
        """
        util.raiseNotDefined()

    def getGoalState(self):
	
        return self.goal


def tinyMazeSearch(problem):
    """
    Returns a sequence of moves that solves tinyMaze.  For any other maze, the
    sequence of moves will be incorrect, so only use this for tinyMaze.
    """
    from game import Directions
    s = Directions.SOUTH
    w = Directions.WEST
    return  [s, s, w, s, w, w, s, w]

def depthFirstSearch(problem):
    """
    Search the deepest nodes in the search tree first.

    Your search algorithm needs to return a list of actions that reaches the
    goal. Make sure to implement a graph search algorithm.

    To get started, you might want to try some of these simple commands to
    understand the search problem that is being passed in:

    print("Start:", problem.getStartState())
    print("Is the start a goal?", problem.isGoalState(problem.getStartState()))
    print("Start's successors:", problem.getSuccessors(problem.getStartState()))
    """
    front = util.Stack() #create a stack for nodes we can cisit
    front.push(problem.getStartState()) #add the start state to the stack
    path = [] #our eventual path to the goal
    tempPath = util.Stack() #how we will hold paths until we find the right one
    prevVis = [] #a list of previously visited nodes so we dont visit them again
    currentPos = front.pop() #get the current, starting, postition from the stack
    while not problem.isGoalState(currentPos): #while we have not won
        if currentPos not in prevVis: #If we have not visited this node
            prevVis.append(currentPos) #record that we visited
            successors = problem.getSuccessors(currentPos) #get a list of potential next visits
            for successor, action, stepCost in successors: #run through the successors
                front.push(successor) #add the successors to the stack
                helperPath = path + [action] #create a helper temp path
                tempPath.push(helperPath) #add this potential path to the path stack
        path = tempPath.pop() #get the most updated path
        currentPos = front.pop() #get the next node
    return path

def breadthFirstSearch(problem): #this was bassiclly the same as dfs but use=ing queues insead of stacks
    """Search the shallowest nodes in the search tree first."""
    front = util.Queue() #for explination look above and replace stack with queue
    front.push(problem.getStartState())
    path = []
    prevVis = []
    tempPath = util.Queue()
    currentPos = front.pop()
    while not problem.isGoalState(currentPos):
        if currentPos not in prevVis:
            prevVis.append(currentPos)
            successors = problem.getSuccessors(currentPos)
            for successor, action, stepCost in successors:
                front.push(successor)
                helperPath = path + [action] 
                tempPath.push(helperPath)
        path = tempPath.pop()
        currentPos = front.pop()
    return path

def uniformCostSearch(problem): #mostly the same as above with a few differences
    #I'll make comments on the differences, for everything else look to dfs and replace stack with priority queue where necessary
    """Search the node of least total cost first."""
    front = util.PriorityQueue() #using a priority queue nw that costs are a factor
    front.push(problem.getStartState(),0) #the current state has a cost of 0 to move there
    path = []
    tempPath = util.PriorityQueue()
    helperPath = []
    prevVis = []
    currentPos = front.pop()
    while not problem.isGoalState(currentPos):
        if currentPos not in prevVis:
            prevVis.append(currentPos)
            successors = problem.getSuccessors(currentPos)
            for successor, action, stepCost in successors:
                helperPath = path + [action]
                currentCost = problem.getCostOfActions(helperPath) #helper variaple to calculate the cost of current actions
                if successor not in prevVis: #since our order depends on cost we need to put in this second check to prevent illigal moves
                    front.push(successor, currentCost)
                    tempPath.push(helperPath, currentCost)
        path = tempPath.pop()
        currentPos = front.pop()
    return path

def nullHeuristic(state, problem=None):
    """
    A heuristic function estimates the cost from the current state to the nearest
    goal in the provided SearchProblem.  This heuristic is trivial.
    """
    return 0

def aStarSearch(problem, heuristic=nullHeuristic): #I tried changing this to manhatton and caling heuristic
    #it kept chucking errors so I did it this way and it works soooooooo
    """Search the node that has the lowest combined cost and heuristic first."""
    front = util.PriorityQueue() #very similar to ucs so I'll only comment on the differences
    front.push(problem.getStartState(),0)
    path = []
    tempPath = util.PriorityQueue()
    helperPath = []
    prevVis = []
    currentPos = front.pop()
    finish = problem #I have no idea why this works. This was the only call that somehow didn't throw an error
    while not problem.isGoalState(currentPos):
        if currentPos not in prevVis:
            prevVis.append(currentPos)
            successors = problem.getSuccessors(currentPos)
            for successor, action, stepCost in successors:
                helperPath = path + [action]
                helperHeuristic = 0
                helperHeuristic = heuristic(successor,finish) #I deffo feel like this shouldn't work but it does
				#what I wanted to do was calculate the manhatton but I don't think I actually am
				#we will just call this a happy accident from me changing the heuristic back to try and see if my code could run at all
                helperActCost = problem.getCostOfActions(helperPath)
                currentCost = helperActCost + helperHeuristic
                if successor not in prevVis:
                    front.push(successor, currentCost)
                    tempPath.push(helperPath, currentCost)
        path = tempPath.pop()
        currentPos = front.pop()
    return path 

# Abbreviations
bfs = breadthFirstSearch
dfs = depthFirstSearch
astar = aStarSearch
ucs = uniformCostSearch

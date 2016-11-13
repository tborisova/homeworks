from __future__ import division
import numpy as np
from copy import copy, deepcopy


class Sliding_blocks():

    def __init__(self):
        self.size = 4
        self.block = self.generate_block()


    def generate_block(self):
        """Goal state"""

        block = np.arange(1,self.size**2)
        block.resize(self.size,self.size)
        return block


    def move(self, piece):
        """Moves the piece with index "piece" to free place, if possible"""

        if list(piece) in self.find_moves():
            self.block[tuple( self.find_free() )] = self.block[tuple(piece)]
            self.block[tuple(piece)] = 0
            return "success"
        else:
            return "error"


    def find_free(self):
        """Returns array of indices of the free cell"""

        free_position = np.where(self.block == 0)
        free_position = np.array(free_position).flatten()
        return free_position


    def find_moves(self):
        """Returns list of allowed indices to move"""

        from itertools import product
        free_position = self.find_free()
        return [list(free_position+i) for i in [[0,1],[1,0],[-1,0],[0,-1]] if tuple(i+free_position) in product(range(self.size),repeat=2)]


    def shuffle(self):
        steps = 30
        for i in xrange(steps):
            self.rand_move()


    def rand_move(self):
        from random import choice

        self.move(choice(self.find_moves()))


    #The following functions are used to find the solution

    def isWin(self):
        return (self.block == self.generate_block()).all()


    def total_misplaced(self):
        return np.sum( self.block != self.generate_block() )


def tree_search():#
    Game = Sliding_blocks()
    Game.shuffle()

    frontier = [[Game]]
    explored = []

    while 1:
        if frontier==[]: return "Error"

        path, frontier = remove_choice(frontier)
        endnode = path[-1]
        explored.append(endnode)
        if endnode.isWin(): return path

        #Iterate over all possible actions at endnode
        for action in allactions(endnode):
            if not action in explored and not action in frontier or action.isWin():
                pathtem=copy(path)
                pathtem.append(action)
                frontier.append(pathtem)


def allactions(obj):
    possible = obj.find_moves()
    actions = []
    for i in range(len(possible)): 
        actions.append(deepcopy(obj))
        actions[i].move(possible[i])
    return actions


#A*
def a_star(frontier):
    #Calculates the cost (lenght + number misplaced cells)
    #of all paths in frontier, returns the frontier
    #without the least expensive path and also returns that path

    lengths = [f[-1].total_misplaced()+cost(f) for f in frontier]
    shortest=[i for i,l in enumerate(lengths) if l<=min(lengths)]
    return frontier.pop(shortest[0]), frontier 



def cost(path): return len(path)

if __name__ == "__main__":

    remove_choice = a_star
    sol = tree_search()
    for s in sol: 
        print s.block
        print "\n"

# Created on : 8 May, 2020

# Title : Check If It Is a Straight Line

# Author : Shiwangi Garg

class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        x1,y1 = coordinates[0]
        x2,y2 = coordinates[1]
        if (x2 - x1) == 0:
            for points in coordinates:
                if points[0] != x1:
                    return False
            return True
        else:
            m = (y2 - y1)/(x2 - x1)
            c = (y1*x2 - y2*x1)/(x2 - x1)
            for points in coordinates:
                x = points[0]
                y = points[1]
                ypred = m * x + c
                if ypred != y:
                    return False
            return True
        

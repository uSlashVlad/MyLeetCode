import imp
from typing import List

class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        res = [""]*n
        
        for i in range(1, n+1):
            if i % 15 == 0:
                res[i-1] = "FizzBuzz"
            elif i % 5 == 0:
                res[i-1] = "Buzz"
            elif i % 3 == 0:
                res[i-1] = "Fizz"
            else:
                res[i-1] = str(i)
        
        return res

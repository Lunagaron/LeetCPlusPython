class Solution(object):
    def dailyTemperatures(self, temperatures):
        """
        Given an array of integers temperatures represents the daily
        temperatures, return an array answer such that answer[i] is
        the number of days you have to wait after the ith day to get a
        warmer temperature. If there is no future day for which this is
        possible, keep answer[i] == 0 instead. This algorithm works by
        maintaining two stacks, one to store the temperature values and
        another that stores the index of the temperature. While the next
        number added to the stack is not greater then the top element of
        the stack, push it on, otherwise repeatedly pop out the top of the
        stack and append the index onto the solutions array. Time Complexity
        O(n) as the temperature list is iterated through only once.

        :type temperatures: List[int]
        :rtype: List[int]
        """
        tempStack = []  # Keep temperatures on a stack
        indexStack = []  # Keep indexes of temperatures also on a stack
        order = [0] * len(temperatures)  # Initialise order of temperatures

        for index, temp in enumerate(temperatures):
            while tempStack and temp > tempStack[-1]:
                last_index = indexStack.pop()
                tempStack.pop()
                order[last_index] = index - last_index
            tempStack.append(temp)
            indexStack.append(index)
        return order

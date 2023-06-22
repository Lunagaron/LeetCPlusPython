class Solution(object):
    def numRescueBoats(self, people, limit):
        """
        :type people: List[int]
        :type limit: int
        :rtype: int
        """
        # Sort the people in non-decreasing order of their weights
        people.sort()

        # Initialize variables for the start and end indices of the current boat
        num_boats = 0
        start, end = 0, len(people) - 1

        # Loop through the people and pair them up as appropriate
        while start <= end:
            # Check if the heaviest person can fit with the lightest person
            if people[start] + people[end] <= limit:
                start += 1
            end -= 1

            # Increment the boat count for each pair or individual person
            num_boats += 1

        return num_boats

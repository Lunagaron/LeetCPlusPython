class Solution(object):
    def minEatingSpeed(self, piles, h):
        """
        Koko loves to eat bananas. There are n piles of bananas, the ith
        pile has piles[i] bananas. The guards have gone and will come back
        in h hours.

        Koko can decide her bananas-per-hour eating speed of k. Each hour,
        she chooses some pile of bananas and eats k bananas from that pile.
        If the pile has less than k bananas, she eats all of them instead
        and will not eat any more bananas during this hour.

        Koko likes to eat slowly but still wants to finish eating all the
        bananas before the guards return.

        Return the minimum integer k such that she can eat all the bananas
        within h hours.

        :type piles: List[int]
        :type h: int
        :rtype: int
        """
        left = 1
        right = max(piles)
        while left < right:
            middle = (left + right) // 2
            if not self.finishEating(piles, h, middle):
                left = middle + 1
            else:
                right = middle
        return left

    def finishEating(self, piles, h, k):
        # Keep a counter to see how many hours are needed to finish pile
        total_hours = 0
        for pile in piles:
            # Finds out how many hours Koko would need to finish off the pile.
            hours_needed = pile // k
            # If there is leftover after consuming k groups of the pile, add another hour
            if pile % k != 0:
                hours_needed += 1
            total_hours += hours_needed
            if total_hours > h:
                return False
        return True

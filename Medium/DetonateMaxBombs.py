class Solution:
    def __init__(self):
        self.count = 0
        self.max_count = 0
        self.bss = []

    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        bombz = list(enumerate(bombs))
        num_bombs = len(bombs)
        for i, b in bombz:
            self.count = 1
            self.bss = []
            bs = Solution.remove_i(bombz, i)
            self.branch(bs, b)
            if self.max_count == num_bombs:
                return num_bombs
        return self.max_count

    @staticmethod
    def does_detonate(b1, b2):
        """true if b1 detonates b2"""
        x1, y1, _ = b1
        x2, y2, _ = b2
        dx = (x1-x2)
        dy = (y1-y2)
        if b1[2]*b1[2] >= (dx*dx + dy*dy):
            # if b1[2]**2>=((b1[0]-b2[0])**2 + (b1[1]-b2[1])**2):
            return True
        return False

    @staticmethod
    def remove_i(a, i):
        """remove item with label i from list a"""
        return a[:i] + a[i+1:]

    def branch(self, bs, b):
        for j, bbz in enumerate(bs):
            if bbz[0] not in self.bss:
                bb = bbz[1]
                new_bs = Solution.remove_i(bs, j)
                if Solution.does_detonate(b, bb):
                    self.count += 1
                    self.bss.append(bbz[0])
                    if len(new_bs) > 0:
                        self.branch(new_bs, bb)
        self.max_count = max(self.count, self.max_count)

    # def end_branch(self):
    #     self.max_count = max(self.count, self.max_count)

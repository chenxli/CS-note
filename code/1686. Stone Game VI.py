class Solution:
    def stoneGameVI(self, aliceValues: List[int], bobValues: List[int]) -> int:
        v = []
        for i in range(len(aliceValues)):
            v.append([-(aliceValues[i] + bobValues[i]), -aliceValues[i], -bobValues[i]])
        v.sort(key=lambda x : x[0])
        alice = 0
        bob = 0
        for i, (tot, a, b) in enumerate(v):
            #print(i, -tot, -a, -b)
            if i % 2 == 0:
                alice += -a
            else:
                bob += -b
        if alice == bob:
            return 0
        elif alice > bob:
            return 1
        else:
            return -1
        
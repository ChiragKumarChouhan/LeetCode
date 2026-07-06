class Solution:
    def removeCoveredIntervals(self, intervals):
        # Sort by start ascending, and if starts are same,
        # end descending
        intervals.sort(key=lambda x: (x[0], -x[1]))

        count = 0
        maxEnd = 0

        for start, end in intervals:
            if end > maxEnd:
                count += 1
                maxEnd = end

        return count
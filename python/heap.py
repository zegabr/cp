import heapq
class MinHeap:
    def __init__(self):
        self.minheap = []

    def from_list(self, li):
        self.minheap = [v for v in li]
        heapq.heapify(self.minheap)

    def push(self, val):
        heapq.heappush(self.minheap, val)

    def top(self):
        return self.minheap[0]

    def pop(self):
        return heapq.heappop(self.minheap)


class MaxHeap:
    def __init__(self):
        self.minheap = []

    def from_list(self, li):
        self.minheap = [-1 * v for v in li]
        heapq.heapify(self.minheap)

    def push(self, val):
        heapq.heappush(self.minheap, -1 * val)

    def top(self):
        return -1 * self.minheap[0]

    def pop(self):
        return -1 * heapq.heappop(self.minheap)

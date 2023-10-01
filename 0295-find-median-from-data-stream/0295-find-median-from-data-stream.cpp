class MedianFinder {
public:
    std::priority_queue<int> maxHeap;    // Stores the smaller half of numbers
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // Stores the larger half of numbers

    MedianFinder() {
    }

    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // Balance the heaps if necessary
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return static_cast<double>(maxHeap.top());
        } else {
            return (static_cast<double>(maxHeap.top()) + minHeap.top()) / 2.0;
        }
    }
};
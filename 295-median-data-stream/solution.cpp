class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (numbers_.empty()) {
            numbers_.insert(num);
            left = right = numbers_.begin();
        } else {
            if (numbers_.size() % 2 == 0) {
                numbers_.emplace(num);
                // was even, now it's odd
                if (num < *left) {
                    right--;
                } else if (num > *right) {
                    left++;
                } else if (num > *left && num < *right) {
                    left++;
                    right--;
                } else if (num == *left) {
                    right--;
                    if (right != left) {
                        left++;
                    }
                } else {
                    // num == *right 
                    left++;
                    if (right != left) {
                        right--;
                    }
                }
            } else {
                // was odd, now it's even
                if (num == *right) {
                    auto it = numbers_.emplace_hint(right, num);
                    left = it;
                } else {
                    numbers_.emplace(num);
                    if (num > *right) {
                        right++;
                    } else if (num < *left) {
                        left--;
                    }
                }
            }
            
        }
    }
    
    double findMedian() {
        if (numbers_.empty()) return 0;
        
        auto size = numbers_.size();
        if (size % 2 == 1) {
            return *left;
        } else {
            return (*left + *right) / 2.;
        }
    }
private:
    multiset<int> numbers_;
    multiset<int>::const_iterator left;
    multiset<int>::const_iterator right;
    
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
class Solution {
public:
    template<typename T>
    class SegmentTree {
    private:
        int size;
        vector<T> tree;
        function<T(T, T)> operation;

        void build(const vector<T>& source, int nodeIndex, int start, int end) {
            if (start == end) {
                tree[nodeIndex] = source[start];
            } else {
                int mid = start + (end - start) / 2;
                int leftNodeIndex = nodeIndex * 2;
                int rightNodeIndex = nodeIndex * 2 + 1;

                build(source, leftNodeIndex, start, mid);
                build(source, rightNodeIndex, mid + 1, end);

                tree[nodeIndex] = operation(tree[leftNodeIndex], tree[rightNodeIndex]);
            }
        }

        void updateHelper(int nodeIndex, int start, int end, int index, T newValue) {
            if (start == end) {
                tree[nodeIndex] = newValue;
            } else {
                int mid = start + (end - start) / 2;
                int leftNodeIndex = nodeIndex * 2;
                int rightNodeIndex = nodeIndex * 2 + 1;

                if (index <= mid) {
                    updateHelper(leftNodeIndex, start, mid, index, newValue);
                } else {
                    updateHelper(rightNodeIndex, mid + 1, end, index, newValue);
                }

                tree[nodeIndex] = operation(tree[leftNodeIndex], tree[rightNodeIndex]);
            }
        }

        T queryRange(int nodeIndex, int start, int end, int queryStart, int queryEnd) {
            if (queryStart > queryEnd) {
                return 0;
            }
            if (queryStart == start && queryEnd == end) {
                return tree[nodeIndex];
            }
            int mid = start + (end - start) / 2;
            T leftResult = queryRange(nodeIndex * 2, start, mid, queryStart, min(queryEnd, mid));
            T rightResult = queryRange(nodeIndex * 2 + 1, mid + 1, end, max(queryStart, mid + 1), queryEnd);
            if (queryStart > mid) {
                return rightResult;
            }
            if (queryEnd <= mid) {
                return leftResult;
            }
            return operation(leftResult, rightResult);
        }

    public:
        SegmentTree(const vector<T>& source, function<T(T, T)> op) : size(source.size()), operation(op) {
            tree.resize(size * 4);
            if (!source.empty()) {
                build(source, 1, 0, size - 1);
            }
        }

        T get(int start, int end) {
            if (size == 0 || start < 0 || end >= size) {
                return 0;
            }
            return queryRange(1, 0, size - 1, start, end);
        }

        void update(int index, T newValue) {
            updateHelper(1, 0, size - 1, index, newValue);
        }
    };

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        SegmentTree<int> tree(baskets, [](int a, int b) { return max(a, b); });

        function<int(int, int, int)> binSearch = [&](int left, int right, int target) -> int {
            if (left >= right) return right;
            int mid = left + (right - left) / 2;
            if (tree.get(left, mid) >= target) {
                return binSearch(left, mid, target);
            } else {
                return binSearch(mid + 1, right, target);
            }
        };

        int ans = 0;
        for (int fruit : fruits) {
            if (tree.get(0, n - 1) >= fruit) {
                int index = binSearch(0, n, fruit);
                tree.update(index, 0);
            } else {
                ans++;
            }
        }

        return ans;
    }
};
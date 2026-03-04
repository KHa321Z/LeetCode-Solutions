class Solution {
public:
    struct CartesianTree {
        int root;
        vector<int> left_child;
        vector<int> right_child;
        vector<int> parent;
        CartesianTree(const vector<int>& a) {
            int n = a.size();
            left_child.assign(n, -1);
            right_child.assign(n, -1);
            parent.assign(n, -1);
            root = -1;

            vector<int> st;
            for (int i = 0; i < n; i++) {
                int last = -1;
                //for min-tree: a[st.back()] > a[i]
                while (!st.empty() && a[st.back()] > a[i]) {
                    last = st.back();
                    st.pop_back();
                }
                if (last != -1) {
                    left_child[i] = last;
                    parent[last] = i;
                }
                if (!st.empty()) {
                    right_child[st.back()] = i;
                    parent[i] = st.back();
                }
                st.push_back(i);
            }
            root = st.front(); 
        }
    };

    int largestRectangleArea(vector<int>& heights) {
        
        long long area = 0;
        CartesianTree tree(heights);

        stack<tuple<int, int, int>> st;
        st.push({ tree.root, 0, heights.size() - 1 });

        while (st.size()) {

            auto [idx, l, r] = st.top();
            st.pop();

            if (tree.left_child[idx] != -1)
                st.push({ tree.left_child[idx], l, idx - 1 });
            
            if (tree.right_child[idx] != -1)
                st.push({ tree.right_child[idx], idx + 1, r });

            area = max(area, 1LL * heights[idx] * (r - l + 1));

        }

        return area;

    }
};
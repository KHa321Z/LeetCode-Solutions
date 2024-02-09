class Solution {
public:
    int numSquares(int n) {

        struct Node {

            int depth;
            int number;
            int squareNumber;
            vector <Node> children;

        };

        queue <Node> nodes;
        unordered_map <int, bool> visited;

        Node root = {0, n, (int)sqrt(n), {}};
        Node currentNode = root;

        visited[n] = true;

        while (true) {

            for (int i = 1; i <= currentNode.squareNumber; i++) {

                Node child = {currentNode.depth + 1, currentNode.number - (i * i), i, {}};

                if (child.number == 0)
                    return child.depth;

                if (child.number > 0 && !visited[child.number]) {
                    nodes.push(child);
                    currentNode.children.push_back(child);
                    visited[child.number] = true;
                }

            }

            currentNode = nodes.front();
            nodes.pop();

        }

    }
};
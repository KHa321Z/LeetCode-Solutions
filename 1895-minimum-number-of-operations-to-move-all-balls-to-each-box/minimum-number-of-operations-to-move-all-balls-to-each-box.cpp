class Solution {
public:
    vector<int> minOperations(string boxes) {

        int numOfBalls = 0;
        vector<int> moves(boxes.length());
        vector<int> movesright(boxes.length());

        for (int i = 0; i < boxes.length(); i++) {
            if (i != 0)
                moves[i] += moves[i - 1] + numOfBalls;

            if (boxes[i] == '1')
                numOfBalls++;
        }

        numOfBalls = 0;

        for (int i = boxes.length() - 1; i >= 0; i--) {
            if (i != boxes.length() - 1)
                movesright[i] += movesright[i + 1] + numOfBalls;

            if (boxes[i] == '1')
                numOfBalls++;

            moves[i] += movesright[i];
        }

        return moves;
        
    }
};
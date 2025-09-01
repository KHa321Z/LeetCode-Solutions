class Solution {
public:
    float gain(int p, int t){
        return (float)(p+1)/(t+1) - (float)p/t;
    }

    float currentRatio(int p, int t){
        return (float)p/t;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<float,float>>heap;

        vector<float> ratio(classes.size(),0);

        for(int i = 0; i < classes.size(); i++){
            int p = classes[i][0], t = classes[i][1];
            ratio[i] = currentRatio(p,t);
            heap.push({gain(p,t), i});
        }

        while(extraStudents>0){
            pair<float,float> maxx = heap.top();
            heap.pop();
            int np = ++classes[maxx.second][0];
            int nt = ++classes[maxx.second][1];
            ratio[maxx.second] = (float)np/nt;
            maxx.first = gain(np,nt);
            heap.push(maxx);
            extraStudents--;
        }

        return (float)accumulate(ratio.begin(),ratio.end(),0.0)/classes.size();
        
    }
};
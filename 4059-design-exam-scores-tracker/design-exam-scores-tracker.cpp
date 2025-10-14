class ExamTracker {
public:
    vector<long long> scores;
    map<long long, long long> mep;
    
    ExamTracker() {
        
    }
    
    void record(long long time, long long score) {
        if (scores.size() > 0)
            score += scores[scores.size() - 1];

        scores.push_back(score);
        mep.insert({ time, scores.size() - 1 });
    }
    
    long long totalScore(long long startTime, long long endTime) {

        auto sTime = mep.lower_bound(startTime);
        auto eTime = mep.upper_bound(endTime);

        if (eTime != mep.begin())
            eTime--;

        if (sTime == mep.end() || sTime->first > endTime || eTime->first < startTime)
            return 0;
    
        long long sT = sTime->second - 1, eT = eTime->second;
        
        if (sT >= 0)
            return scores[eT] - scores[sT];

        return scores[eT];
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */
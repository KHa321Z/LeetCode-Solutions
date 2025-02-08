class NumberContainers {
public:
    unordered_map<int, int> mep;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mip;

    NumberContainers() {
        //this->mep = new unordered_map<int, int>();
        //this->mip = new unordered_map<int, priority_queue<int, vector<int>, greater<int>>>();
    }
    
    void change(int index, int number) {

        if (this->mep.count(index))
            if (this->mep[index] == number)
                return;

        this->mep[index] = number;
        this->mip[number].push(index);

    }
    
    int find(int number) {
        while (!this->mip[number].empty() && this->mep[this->mip[number].top()] != number)
            this->mip[number].pop();

        return (this->mip[number].empty() ? -1 : this->mip[number].top());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
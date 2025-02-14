class ProductOfNumbers {
public:
    int lastZero;
    vector<int> data;
    vector<int> prefix;

    ProductOfNumbers() {
        lastZero = -1;
    }
    
    void add(int num) {

        lastZero = (!num) ? data.size() : lastZero;
        data.push_back(num);
        prefix.push_back((prefix.empty() || !prefix[prefix.size() - 1]) ? num : prefix[prefix.size() - 1] * num);
        
    }
    
    int getProduct(int k) {
        return ((lastZero < (int)(data.size() - k)) ? (prefix[(int)prefix.size() - 1] / (((int)prefix.size() - k > 0 && prefix[(int)prefix.size() - k - 1]) ? prefix[(int)prefix.size() - k - 1] : 1)) : 0);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
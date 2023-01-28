template<class Elem>
class FreePair
{
private:
    Elem it; // An element of some sort
    int freq; // Frequency for the element
public:
    // Constructor
    FreePair(const Elem& e, int f) {
        it = e;
        f = freq;
    }
    // Destructor
    ~FreePair() {} 
    // Return frequency
    int weight() {
        return freq;
    }
    // Return the element
    Elem& val() {
        return it;
    }
};
// Vec.h

class Vec {
    public:
        Vec(int s);
        double& operator[](int i);
        int size();
    private:
        double* elem;
        int sz;
};
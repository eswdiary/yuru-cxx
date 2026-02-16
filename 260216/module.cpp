export module Vec;

export class Vec {
    public:
        Vec(int i);
        double& operator[](int i);
        int size();

    private:
        double* elem;
        int sz;
};

Vec::Vec(int i) : elem{ new double[i] }, sz{i} {}

double& Vec::operator[](int i) {
    return elem[i];
}

int Vec::size() {
    return sz;
}